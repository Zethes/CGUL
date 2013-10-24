// TODO: networking

/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include <Jatta/Config.h>
#include "../Exceptions/NetworkException.h"
#include "../External/Once.h"

#ifndef DOXYGEN
#ifdef JATTA_WINDOWS
static bool __jatta_network_initiated = false;
#endif
#endif

namespace Jatta
{
    /** @brief An experimental network namespace.
     */
    namespace Network
    {
#       ifndef DOXYGEN
        void __jatta_network_initiate()
        {
        #   ifdef JATTA_WINDOWS
            if (!__jatta_network_initiated)
            {
                WSADATA wsaData;
                if (WSAStartup(MAKEWORD(1,1), &wsaData) != 0)
                {
                    throw NetworkException(NetworkExceptionCode::FAILED_STARTUP, NetworkExceptionReason::FAILED_WINSOCK_INITIALIZE);
                }
                __jatta_network_initiated = true;
            }
        #   endif
        }

        void __jatta_network_clean()
        {
        #   ifdef JATTA_WINDOWS
            if (__jatta_network_initiated)
            {
                WSACleanup();
                __jatta_network_initiated = false;
            }
        #   endif
        }
#       endif
    }
}
