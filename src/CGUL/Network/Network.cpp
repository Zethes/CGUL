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
static bool __cgul_network_initiated = false;
#endif
#endif

namespace CGUL
{
    /** @brief An experimental network namespace.
     */
    namespace Network
    {
#       ifndef DOXYGEN
        void __cgul_network_initiate()
        {
#           ifdef CGUL_WINDOWS
            if (!__cgul_network_initiated)
            {
                WSADATA wsaData;
                if (WSAStartup(MAKEWORD(1,1), &wsaData) != 0)
                {
                    throw NetworkException(NetworkExceptionCode::FAILED_STARTUP, NetworkExceptionReason::FAILED_WINSOCK_INITIALIZE);
                }
                __cgul_network_initiated = true;
            }
#           endif
        }

        void __cgul_network_clean()
        {
#           ifdef CGUL_WINDOWS
            if (__cgul_network_initiated)
            {
                WSACleanup();
                __cgul_network_initiated = false;
            }
#           endif
        }

        UInt8 __cgul_network_error_reason()
        {
#           ifdef CGUL_WINDOWS
            int error = WSAGetLastError();
#           else
            int error = errno;
#           endif

#           ifdef CGUL_WINDOWS
            if (error == WSAECONNABORTED)
#           else
            if (error == ECONNABORTED)
#           endif
            {
                return NetworkExceptionReason::CONNECTION_ABORTED;
            }

#           ifdef CGUL_WINDOWS
            if (error == WSAECONNRESET)
#           else
            if (error == ECONNRESET)
#           endif
            {
                return NetworkExceptionReason::CONNECTION_RESET;
            }

            return NetworkExceptionReason::UNKNOWN;
        }
#       endif
    }
}
