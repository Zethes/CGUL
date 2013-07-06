/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Adapter.h"

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

/** @returns A vector of network adapters.
 */
std::vector<Jatta::Network::Adapter> Jatta::Network::GetAdapters()
{
    std::vector<Adapter> result;

#   ifdef WINDOWS
    PIP_ADAPTER_INFO adapterInfo;
    PIP_ADAPTER_INFO adapter = NULL;
    ULONG adapterLength = sizeof(IP_ADAPTER_INFO);

    // Determine the size of the adapter info struct
    if (GetAdaptersInfo(NULL, &adapterLength) != ERROR_BUFFER_OVERFLOW)
    {
        return result;
    }

    // Allocate data to fill
    adapterInfo = (IP_ADAPTER_INFO*)new char[adapterLength];
    if (adapterInfo == NULL)
    {
        return result;
    }

    // Get the network adapters
    if (GetAdaptersInfo(adapterInfo, &adapterLength) == NO_ERROR)
    {
        // Iterate through the linked list
        adapter = adapterInfo;
        while (adapter)
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
                result.push_back(adapterObject);
            }

            // Next adapter
            adapter = adapter->Next;
        }
    }

    // Free data
    delete[] (char*)adapterInfo;
#   else
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char address[INET6_ADDRSTRLEN];

    if (getifaddrs(&ifaddr) == -1)
    {
        return result;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        Adapter adapterObject;

        if (ifa->ifa_addr == NULL)
        {
            continue;
        }

        if (ifa->ifa_addr->sa_family != AF_INET && ifa->ifa_addr->sa_family != AF_INET6)
        {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET)
        {
            UInt32 addr;
            addr = ((struct sockaddr_in*)ifa->ifa_addr)->sin_addr.s_addr;
            adapterObject.ip = IPAddress(addr);
            addr = ((struct sockaddr_in*)ifa->ifa_netmask)->sin_addr.s_addr;
            adapterObject.netmask = IPAddress(addr);
        }
        else
        {
            UInt64 addr[2];
            memcpy(&addr, &((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr, sizeof(in6_addr));
            adapterObject.ip = IPAddress(addr);
            memcpy(&addr, &((struct sockaddr_in6*)ifa->ifa_netmask)->sin6_addr, sizeof(in6_addr));
            adapterObject.netmask = IPAddress(addr);
        }

        if (adapterObject.ip.ToString() == "127.0.0.1" || adapterObject.ip.ToString() == "::1")
        {
            continue;
        }

        adapterObject.description = ifa->ifa_name;

        result.push_back(adapterObject);
    }

    freeifaddrs(ifaddr);
#endif

    return result;
}
