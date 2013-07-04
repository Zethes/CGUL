/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "IPAddress.h"

#ifdef WINDOWS
#   include <winsock2.h>
#   include <iphlpapi.h>
#else
#   include <arpa/inet.h>
#   include <sys/socket.h>
#   include <netdb.h>
#   include <ifaddrs.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <unistd.h>
#endif

namespace Jatta
{
    namespace Network
    {
        void __jatta_network_initiate();
        void __jatta_network_clean();
    }
}

_JATTA_EXPORT Jatta::Network::IPAddress Jatta::Network::IPAddress::CalculateBroadcast(const IPAddress& ip, const IPAddress& netmask)
{
    if (ip.GetType() == IPAddressType::IPV6 || netmask.GetType() == IPAddressType::IPV6)
    {
        throw std::runtime_error("Cannot calculate broadcast address for ipv6 address.");
    }
    if (!ip.IsValid() || ip.GetType() != netmask.GetType())
    {
        throw std::runtime_error("Incompatible IP addresses.");
    }

    return IPAddress(ip.ToUInt32() | (~netmask.ToUInt32()));
}

_JATTA_EXPORT Jatta::Network::IPAddress Jatta::Network::IPAddress::CalculateNetwork(const IPAddress& ip, const IPAddress& netmask)
{
    if (!ip.IsValid() || ip.GetType() != netmask.GetType())
    {
        throw std::runtime_error("Incompatible IP addresses.");
    }

    if (ip.GetType() == IPAddressType::IPV4)
    {
        return IPAddress(ip.ToUInt32() & netmask.ToUInt32());
    }
    else
    {
        UInt64 network[2];
        network[0] = ip.address[0] & netmask.address[0];
        network[1] = ip.address[1] & netmask.address[1];
        return IPAddress(network);
    }
}

_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress()
{
    __jatta_network_initiate();
    this->type = IPAddressType::INVALID;
    this->address[0] = 0;
    this->address[1] = 0;
}

_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(UInt32 address)
{
    __jatta_network_initiate();
    this->type = IPAddressType::IPV4;
    this->address[0] = address;
    this->address[1] = 0;
}

_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(UInt64* address)
{
    __jatta_network_initiate();
    this->type = IPAddressType::IPV6;
    this->address[0] = address[0];
    this->address[1] = address[1];
}

_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(const Jatta::String& ip)
{
    __jatta_network_initiate();
    this->type = IPAddressType::INVALID;
#   ifdef WINDOWS
    sockaddr_in addr4;
    int length = sizeof(sockaddr_in);
    if (WSAStringToAddressA((char*)ip.GetCString(), AF_INET, NULL, (sockaddr*)&addr4, &length) == 0)
    {
        this->type = IPAddressType::IPV4;
        address[0] = addr4.sin_addr.s_addr;
        address[1] = 0;
    }
    else
    {
        sockaddr_in6 addr6;
        int length = sizeof(sockaddr_in6);
        if (WSAStringToAddressA((char*)ip.GetCString(), AF_INET6, NULL, (sockaddr*)&addr6, &length) == 0)
        {
            this->type = IPAddressType::IPV6;
            memcpy(&address, &addr6.sin6_addr, sizeof(address));
        }
    }
#   else
    if (inet_pton(AF_INET, ip.GetCString(), &address) == 1)
    {
        this->type = IPAddressType::IPV4;
    }
    if (this->type == IPAddressType::INVALID)
    {
        if (inet_pton(AF_INET6, ip.GetCString(), &address) == 1)
        {
            this->type = IPAddressType::IPV6;
        }
    }
#   endif
}

_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(const Jatta::String& ip, UInt32 type)
{
    __jatta_network_initiate();
    this->type = IPAddressType::INVALID;
    if (type == IPAddressType::IPV4)
    {
#       ifdef WINDOWS
        sockaddr_in addr;
        int length = sizeof(sockaddr_in);
        if (WSAStringToAddressA((char*)ip.GetCString(), AF_INET, NULL, (sockaddr*)&addr, &length) == 0)
        {
            this->type = IPAddressType::IPV4;
            address[0] = addr.sin_addr.s_addr;
            address[1] = 0;
        }
#       else
        if (inet_pton(AF_INET, ip.GetCString(), &address) == 1)
        {
            this->type = IPAddressType::IPV4;
        }
#       endif
    }
    if (type == IPAddressType::IPV6)
    {
#       ifdef WINDOWS
        sockaddr_in6 addr;
        int length = sizeof(sockaddr_in6);
        if (WSAStringToAddressA((char*)ip.GetCString(), AF_INET6, NULL, (sockaddr*)&addr, &length) == 0)
        {
            this->type = IPAddressType::IPV6;
            memcpy(&address, &addr.sin6_addr, sizeof(address));
        }
#       else
        if (inet_pton(AF_INET6, ip.GetCString(), &address) == 1)
        {
            this->type = IPAddressType::IPV6;
        }
#       endif
    }
}

_JATTA_EXPORT void Jatta::Network::IPAddress::Set(UInt32 address)
{
    *this = IPAddress(address);
}

_JATTA_EXPORT void Jatta::Network::IPAddress::Set(UInt64* address)
{
    *this = IPAddress(address);
}

_JATTA_EXPORT void Jatta::Network::IPAddress::Set(const Jatta::String& ip)
{
    *this = IPAddress(ip);
}

_JATTA_EXPORT void Jatta::Network::IPAddress::Set(const Jatta::String& ip, UInt32 type)
{
    *this = IPAddress(ip, type);
}

namespace Jatta
{
    namespace Network
    {
        _JATTA_EXPORT std::ostream& operator<<(std::ostream& stream, const Jatta::Network::IPAddress& ip)
        {
            stream << ip.ToString();
            return stream;
        }
    }
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Network::IPAddress::GetType() const
{
    return type;
}

_JATTA_EXPORT bool Jatta::Network::IPAddress::IsValid() const
{
    return type != IPAddressType::INVALID;
}

_JATTA_EXPORT Jatta::String Jatta::Network::IPAddress::ToString() const
{
    char str[INET6_ADDRSTRLEN];
    str[0] = 0;
    if (type == IPAddressType::INVALID)
    {
        return "Invalid";
    }
    if (type == IPAddressType::IPV4)
    {
#       ifdef WINDOWS
        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = address[0];
        DWORD length = INET6_ADDRSTRLEN;
        if (WSAAddressToStringA((sockaddr*)&addr, sizeof(addr), NULL, str, &length) != 0)
        {
            // we should never hit this case
            return "Invalid IPv4";
        }
#       else
        if (inet_ntop(AF_INET, &address, str, sizeof(str)) == NULL)
        {
            // we should never hit this case
            return "Invalid IPv4";
        }
#       endif
    }
    if (type == IPAddressType::IPV6)
    {
#       ifdef WINDOWS
        sockaddr_in6 addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin6_family = AF_INET6;
        memcpy(&addr.sin6_addr, &address, sizeof(address));
        DWORD length = INET6_ADDRSTRLEN;
        if (WSAAddressToStringA((sockaddr*)&addr, sizeof(addr), NULL, str, &length) != 0)
        {
            // we should never hit this case
            return "Invalid IPv6";
        }
#       else
        if (inet_ntop(AF_INET6, &address, str, sizeof(str)) == NULL)
        {
            // we should never hit this case
            return "Invalid IPv6";
        }
#       endif
    }
    return Jatta::String(str);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Network::IPAddress::ToUInt32() const
{
    return (UInt32)address[0];
}

_JATTA_EXPORT void Jatta::Network::IPAddress::ToUInt128(UInt64* in) const
{
    memcpy(in, address, sizeof(address));
}
