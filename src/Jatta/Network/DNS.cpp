#if 0
/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "DNS.h"

#include <WinSock2.h>
#include <Ws2tcpip.h>

void __jatta_network_initiate();

static const char* inet_ntop(int af, const void *src, char *dst, socklen_t cnt)
{
  if (af == AF_INET) {
    struct sockaddr_in in;
    memset(&in, 0, sizeof(in));
    in.sin_family = AF_INET;
    memcpy(&in.sin_addr, src, sizeof(struct in_addr));
    getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in), dst, cnt,
                NULL, 0, NI_NUMERICHOST);
    return dst;
  }
  else if (af == AF_INET6) {
    struct sockaddr_in6 in;
    memset(&in, 0, sizeof(in));
    in.sin6_family = AF_INET6;
    memcpy(&in.sin6_addr, src, sizeof(struct in_addr6));
    getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in6), dst, cnt,
                NULL, 0, NI_NUMERICHOST);
    return dst;
  }
  return NULL;
}

Jatta::DNS::DNS()
{
}

Jatta::DNS::~DNS()
{
}

std::vector<std::string> Jatta::DNS::Lookup(const std::string& host, Filter filter)
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
    if ((status = getaddrinfo(host.c_str(), nullptr, &hints, &result)) != 0)
    {
        return std::vector<std::string>();
    }

    unsigned int count = 0;
    for (addrinfo* p = result; p != nullptr; p = p->ai_next)
    {
        count++;
    }

    std::vector<std::string> list;
    char ipstr[INET6_ADDRSTRLEN + 1];
    memset(ipstr, 0, INET6_ADDRSTRLEN + 1);
    ipstr[INET6_ADDRSTRLEN - 1] = 0;
    count = 0;
    for (addrinfo* p = result; p != nullptr; p = p->ai_next)
    {
        void* addr;

        // Determine if the address is an IPv4 or IPv6 address
        if (p->ai_family == AF_INET)
        {
            struct sockaddr_in *ipv4 = (sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            struct sockaddr_in in;
            memset(&in, 0, sizeof(in));
            in.sin_family = AF_INET;
            memcpy(&in.sin_addr, addr, sizeof(struct in_addr));
            getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in), ipstr, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);
        }
        else
        {
            struct sockaddr_in6 *ipv6 = (sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            struct sockaddr_in6 in;
            memset(&in, 0, sizeof(in));
            in.sin6_family = AF_INET6;
            memcpy(&in.sin6_addr, addr, sizeof(struct in_addr6));
            getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in6), ipstr, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);
        }

        list.push_back(std::string(ipstr));
    }

    // Free the linked list
    freeaddrinfo(result);

    //return std::move(list);
    return list;
}

#endif