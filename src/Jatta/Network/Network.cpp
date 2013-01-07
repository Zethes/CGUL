#if 0
/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */
 
#include <WinSock2.h>

bool __jatta_network_initiated = false;

void __jatta_network_initiate()
{
    if (!__jatta_network_initiated)
    {
        WSADATA wsaData;   // if this doesn't work
        if (WSAStartup(MAKEWORD(1,1), &wsaData) != 0)
        {
            // TODO: god help us if this doesn't work
        }
        __jatta_network_initiated = true;
    }
}

void __jatta_network_clean()
{
    if (__jatta_network_initiated)
    {
        WSACleanup();
        __jatta_network_initiated = false;
    }
}

#endif
