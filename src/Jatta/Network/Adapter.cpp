/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Adapter.h"

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

/** @brief This method only returns basic information about the network interface.  Specifically
 *  the local address, netmask and description.  The broadcast address (IPv4 only) and network
 *  address can be derived from the address and netmask.  See IPAddress::CalculateBroadcast and
 *  IPAddress::CalculateNetwork.  The description is not meaningful aside from printing out to a
 *  user and differs from each operating system and network interface.
 *  @todo finish documenting GetAdapters and fixed windows version
 */
void Jatta::Network::GetAdapters(FixedList<Adapter>* adapters)
{
    std::vector<Adapter> result;

#   ifdef JATTA_WINDOWS
    // TODO: this wont work correctly right now (?)
    PIP_ADAPTER_INFO adapterInfo;
    ULONG adapterLength = sizeof(IP_ADAPTER_INFO);

    // Determine the size of the adapter info struct
    if (GetAdaptersInfo(NULL, &adapterLength) != ERROR_BUFFER_OVERFLOW)
    {
        return;
    }

    // Allocate data to fill
    adapterInfo = (IP_ADAPTER_INFO*)new char[adapterLength];
    if (adapterInfo == NULL)
    {
        return;
    }

    // Get the network adapters
    if (GetAdaptersInfo(adapterInfo, &adapterLength) == NO_ERROR)
    {
        Size count = 0;
        for (PIP_ADAPTER_INFO adapter = adapterInfo; adapter != NULL; adapter = adapter->Next)
        {
            UInt64 ipInteger[2];
            IPAddress(adapter->IpAddressList.IpAddress.String).ToUInt128(ipInteger);
            if (ipInteger[0] != 0 && ipInteger[1] != 0)
            {
                count++;
            }
        }
        adapters->SetSize(count);

        // Iterate through the linked list
        count = 0;
        for (PIP_ADAPTER_INFO adapter = adapterInfo; adapter != NULL; adapter = adapter->Next)
        {
            // Fill in the data and add to the list
            Adapter adapterObject;
            adapterObject.description = adapter->Description;
            adapterObject.ip = IPAddress(adapter->IpAddressList.IpAddress.String);
            adapterObject.netmask = IPAddress(adapter->IpAddressList.IpMask.String);

            // Ignore "zero" interfaces (for example, bluetooth)
            UInt64 ipInteger[2];
            adapterObject.ip.ToUInt128(ipInteger);
            if (ipInteger[0] != 0 || ipInteger[1] != 0)
            {
                adapters->Set(count++, adapterObject);
            }
        }
    }

    // Free data
    delete[] (char*)adapterInfo;
#   else
    struct ifaddrs* ifaddr;

    // Query for a linked list of network interfaces
    if (getifaddrs(&ifaddr) == -1)
    {
        return;
    }

    // Iterate through each interface and remove unwanted devices
    Size count = 0;
    for (ifaddrs* ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        // Only accept IPv4 or IPv6 interfaces, ignore others
        if (ifa->ifa_addr == NULL || (ifa->ifa_addr->sa_family != AF_INET && ifa->ifa_addr->sa_family != AF_INET6))
        {
            continue;
        }

        // Ignore local loopback addresses
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            if (((struct sockaddr_in*)ifa->ifa_addr)->sin_addr.s_addr == 16777343)
            {
                continue;
            }
        }
        else
        {
            UInt64 addr[2];
            memcpy(&addr, &((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr, sizeof(in6_addr));
            if (addr[0] == 0 && addr[1] == 72057594037927936)
            {
                continue;
            }
        }
        count++;
    }
    adapters->SetSize(count);

    // Iterate through each interface
    count = 0;
    for (ifaddrs* ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        Adapter adapterObject;

        // Only accept IPv4 or IPv6 interfaces, ignore others
        if (ifa->ifa_addr == NULL || (ifa->ifa_addr->sa_family != AF_INET && ifa->ifa_addr->sa_family != AF_INET6))
        {
            continue;
        }

        // Determine if this is IPv4 or IPv6
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            // Copy over the address and netmask (ipv4)
            UInt32 addr;
            addr = ((struct sockaddr_in*)ifa->ifa_addr)->sin_addr.s_addr;
            if (addr == 16777343)
            {
                continue;
            }
            adapterObject.ip = IPAddress(addr);
            addr = ((struct sockaddr_in*)ifa->ifa_netmask)->sin_addr.s_addr;
            adapterObject.netmask = IPAddress(addr);
        }
        else
        {
            // Copy over the address and netmask (ipv6)
            UInt64 addr[2];
            memcpy(&addr, &((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr, sizeof(in6_addr));
            if (addr[0] == 0 && addr[1] == 72057594037927936)
            {
                continue;
            }
            adapterObject.ip = IPAddress(addr);
            memcpy(&addr, &((struct sockaddr_in6*)ifa->ifa_netmask)->sin6_addr, sizeof(in6_addr));
            adapterObject.netmask = IPAddress(addr);
        }

        // Get the interface name
        adapterObject.description = ifa->ifa_name;

        // Add the result to the list
        adapters->Set(count++, adapterObject);
    }

    // Free the linked list of addresses
    freeifaddrs(ifaddr);
#endif
}
