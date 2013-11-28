// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file DNS.cpp
 */

#include "DNS.hpp"
#include "../Exceptions/NetworkException.hpp"

#ifndef DOXYGEN
namespace CGUL
{
    namespace Network
    {
        void __jatta_network_initiate();
        void __jatta_network_clean();
    }
}
#endif

CGUL::Network::DNS::DNS()
{
}

CGUL::Network::DNS::~DNS()
{
}

std::vector<CGUL::String> CGUL::Network::DNS::Lookup(const CGUL::String& host, Filter filter)
{
    __jatta_network_initiate();

    // For error checking
    int status;

    addrinfo hints;
    memset(&hints, 0, sizeof(addrinfo));
    // FIXME: this shit sucks
    hints.ai_family = AF_INET; //hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    addrinfo* result;
    if ((status = getaddrinfo(host.GetCString(), NULL, &hints, &result)) != 0)
    {
        throw NetworkException(NetworkExceptionCode::FAILED_DNS_LOOKUP, status);
        return std::vector<CGUL::String>();
    }

    unsigned int count = 0;
    for (addrinfo* p = result; p != NULL; p = p->ai_next)
    {
        count++;
    }

    std::vector<CGUL::String> list;
    char ipstr[INET6_ADDRSTRLEN + 1];
    memset(ipstr, 0, INET6_ADDRSTRLEN + 1);
    ipstr[INET6_ADDRSTRLEN - 1] = 0;
    count = 0;
    for (addrinfo* p = result; p != NULL; p = p->ai_next)
    {
        void* addr;

        // Determine if the address is an IPv4 or IPv6 address
        if (p->ai_family == AF_INET)
        {
            struct sockaddr_in *ipv4 = reinterpret_cast<sockaddr_in*>(p->ai_addr);
            addr = &(ipv4->sin_addr);
            struct sockaddr_in in;
            memset(&in, 0, sizeof(in));
            in.sin_family = AF_INET;
            memcpy(&in.sin_addr, addr, sizeof(struct in_addr));
            getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in), ipstr, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);
        }
        else
        {
            struct sockaddr_in6 *ipv6 = reinterpret_cast<sockaddr_in6*>(p->ai_addr);
            addr = &(ipv6->sin6_addr);
            struct sockaddr_in6 in;
            memset(&in, 0, sizeof(in));
            in.sin6_family = AF_INET6;
            memcpy(&in.sin6_addr, addr, sizeof(struct in6_addr));
            getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in6), ipstr, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);
        }

        list.push_back(std::string(ipstr));
    }

    // Free the linked list
    freeaddrinfo(result);

    //return std::move(list);
    return list;
}
