// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Network.cpp
 */

// TODO: networking

#include <CGUL/Config.hpp>
#include "../Exceptions/NetworkException.hpp"
#include "../External/Once.hpp"

#ifndef DOXYGEN
#ifdef CGUL_WINDOWS
static bool __jatta_network_initiated = false;
#endif
#endif

namespace CGUL
{
    /** @brief An experimental network namespace.
     */
    namespace Network
    {
#       ifndef DOXYGEN
        void __jatta_network_initiate()
        {
#           ifdef CGUL_WINDOWS
            if (!__jatta_network_initiated)
            {
                WSADATA wsaData;
                if (WSAStartup(MAKEWORD(1,1), &wsaData) != 0)
                {
                    throw NetworkException(NetworkExceptionCode::FAILED_STARTUP, NetworkExceptionReason::FAILED_WINSOCK_INITIALIZE);
                }
                __jatta_network_initiated = true;
            }
#           endif
        }

        void __jatta_network_clean()
        {
#           ifdef CGUL_WINDOWS
            if (__jatta_network_initiated)
            {
                WSACleanup();
                __jatta_network_initiated = false;
            }
#           endif
        }
#       endif
    }
}
