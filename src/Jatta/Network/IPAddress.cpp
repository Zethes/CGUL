/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "IPAddress.h"
#include "../Exceptions/NetworkException.h"

#ifdef JATTA_WINDOWS
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

#ifndef DOXYGEN
namespace Jatta
{
    namespace Network
    {
        void __jatta_network_initiate();
        void __jatta_network_clean();
    }
}
#endif

/** @details The broadcast address can only be calculated on a IPv4 network.  While it is
 *  technically possible to calculate an IPv6 broadcast address, the IPv6 protocol has dropped
 *  support for broadcasting.  Since broadcasting is not supported in IPv6, this method will result
 *  in an exception given an IPv6 address.
 *  @param ip An IP address on the network.
 *  @param netmask The netmask defining the network range.
 *  @returns The broadcast address.
 */
_JATTA_EXPORT Jatta::Network::IPAddress Jatta::Network::IPAddress::CalculateBroadcast(const IPAddress& ip, const IPAddress& netmask)
{
    if (ip.GetType() == IPAddressType::IPV6 || netmask.GetType() == IPAddressType::IPV6)
    {
        throw NetworkException(NetworkExceptionCode::FAILED_CALCULATE_ADDRESS, NetworkExceptionReason::ADDRESS_INVALID);
    }
    if (!ip.IsValid() || ip.GetType() != netmask.GetType())
    {
        throw NetworkException(NetworkExceptionCode::FAILED_CALCULATE_ADDRESS, NetworkExceptionReason::ADDRESS_MISMATCH);
    }

    return IPAddress(ip.ToUInt32() | (~netmask.ToUInt32()));
}

/** @details A network address defines the "bottom-most" address for a given network.
 *  @param ip An IP address on the network.
 *  @param netmask The netmask defining the network range.
 *  @returns The network address.
 */
_JATTA_EXPORT Jatta::Network::IPAddress Jatta::Network::IPAddress::CalculateNetwork(const IPAddress& ip, const IPAddress& netmask)
{
    if (!ip.IsValid() || ip.GetType() != netmask.GetType())
    {
        throw NetworkException(NetworkExceptionCode::FAILED_CALCULATE_ADDRESS, NetworkExceptionReason::ADDRESS_MISMATCH);
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

/**
 */
_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress()
{
    __jatta_network_initiate();
    this->type = IPAddressType::INVALID;
    this->address[0] = 0;
    this->address[1] = 0;
}

/** @param address The 32 bit unsigned integer for IPv4.
 */
_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(UInt32 address)
{
    __jatta_network_initiate();
    this->type = IPAddressType::IPV4;
    this->address[0] = address;
    this->address[1] = 0;
}

/** @param address The array of two 64 bit unsigned integers for IPv6.
 */
_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(UInt64* address)
{
    __jatta_network_initiate();
    this->type = IPAddressType::IPV6;
    this->address[0] = address[0];
    this->address[1] = address[1];
}

/** @details This constructor can be used to convert an unknown IP address into an IPv4 address or
 *  an IPv6 address.  First it attempts to convert the string in IPv4, and if that fails it
 *  attempts to convert to an IPv6.  If neither conversion succeeds, the resulting address is
 *  invalid.
 *  @param ip A parsable ip address, either IPv4 or IPv6.
 */
_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(const Jatta::String& ip)
{
    __jatta_network_initiate();
    this->type = IPAddressType::INVALID;
#   ifdef JATTA_WINDOWS
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

/** @details This constructor attempts to parse a string into the given IP address version.  The
 *  type given can either be IPAddressType::IPV4 or IPAddressType::IPV6.  If the conversion fails,
 *  the resulting address is invalid.
 *  @param ip A parsable IP address of the given type.
 *  @param type The type of address to attempt to parse.
 */
_JATTA_EXPORT Jatta::Network::IPAddress::IPAddress(const Jatta::String& ip, UInt32 type)
{
    __jatta_network_initiate();
    this->type = IPAddressType::INVALID;
    if (type == IPAddressType::IPV4)
    {
#       ifdef JATTA_WINDOWS
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
#       ifdef JATTA_WINDOWS
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

/** @param address The 32 bit unsigned integer.
 *  @see IPAddress(UInt32)
 */
_JATTA_EXPORT void Jatta::Network::IPAddress::Set(UInt32 address)
{
    *this = IPAddress(address);
}

/** @param address The array of two 64 bit unsigned integers.
 *  @see IPAddress(UInt64*)
 */
_JATTA_EXPORT void Jatta::Network::IPAddress::Set(UInt64* address)
{
    *this = IPAddress(address);
}

/** @param ip A parsable ip address, either IPv4 or IPv6.
 *  @see IPAddress(const Jatta::String&)
 */
_JATTA_EXPORT void Jatta::Network::IPAddress::Set(const Jatta::String& ip)
{
    *this = IPAddress(ip);
}

/** @param ip A parsable IP address of the given type.
 *  @param type The type of address to attempt to parse.
 *  @see IPAddress(const Jatta::String&, UInt32)
 */
_JATTA_EXPORT void Jatta::Network::IPAddress::Set(const Jatta::String& ip, UInt32 type)
{
    *this = IPAddress(ip, type);
}

namespace Jatta
{
    namespace Network
    {
        /** @param stream The output stream.
         *  @param ip The IP address to output.
         *  @returns A reference to the stream passed in.
         */
        _JATTA_EXPORT std::ostream& operator<<(std::ostream& stream, const Jatta::Network::IPAddress& ip)
        {
            stream << ip.ToString();
            return stream;
        }
    }
}

/** @returns The address type.
 */
_JATTA_EXPORT Jatta::UInt32 Jatta::Network::IPAddress::GetType() const
{
    return type;
}

/** @returns True if the address is valid, false otherwise.
 */
_JATTA_EXPORT bool Jatta::Network::IPAddress::IsValid() const
{
    return type != IPAddressType::INVALID;
}

/** @details The conversion is based on the current IP address type (as returned by GetType).  This
 *  method uses internal network functions to do the conversion, and upon failure will return a
 *  string of "Invalid" followed by the IP address type.  If the IP address type is
 *  IPAddressType::INVALID then this method simply returns "Invalid."
 *  @returns A string of the human readable IP address.
 */
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
#       ifdef JATTA_WINDOWS
        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = (ULONG)address[0]; // this will truncate the address, which is PROPER functionality
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
#       ifdef JATTA_WINDOWS
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

/** @details While it is possible to call this method on an IPv6 address, the resulting value will
 *  be unreliable since it will only contain part of the actual address.  In the off chance that
 *  the address may be IPv4 or IPv6, consider using @ref ToUInt128 instead.
 *  @returns A 32 bit unsigned integer.
 */
_JATTA_EXPORT Jatta::UInt32 Jatta::Network::IPAddress::ToUInt32() const
{
    return (UInt32)address[0];
}

/** @details This method will reliably capture an IPv4 or IPv6 address as a 128 bit unsigned
 *  integer value.  Since an IPv4 address is only 32 bits, the unused bits will be zerod out.
 *  @param in An array of two 64 bit unsigned integers to store the address into.
 */
_JATTA_EXPORT void Jatta::Network::IPAddress::ToUInt128(UInt64* in) const
{
    memcpy(in, address, sizeof(address));
}
