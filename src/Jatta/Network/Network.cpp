// TODO: networking

/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */
 
#ifndef JATTA_NO_NETWORK
#include "../External/Defines.h"

bool __jatta_network_initiated = false;

void __jatta_network_initiate()
{
#   ifdef WINDOWS
    if (!__jatta_network_initiated)
    {
        WSADATA wsaData;   // if this doesn't work
        if (WSAStartup(MAKEWORD(1,1), &wsaData) != 0)
        {
            // TODO: god help us if this doesn't work
        }
        __jatta_network_initiated = true;
    }
#   endif
}

void __jatta_network_clean()
{
#   ifdef WINDOWS
    if (__jatta_network_initiated)
    {
        WSACleanup();
        __jatta_network_initiated = false;
    }
#   endif
}

namespace Jatta
{
    /** @brief An experimental network namespace.
     */
    namespace Network
    {
    }
}

#include "../External/Undefines.h"
#endif
