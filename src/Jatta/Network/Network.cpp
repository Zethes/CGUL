// TODO: networking

/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include <Jatta/Config.h>
#include "../External/Once.h"

static bool __jatta_network_initiated = false;

namespace Jatta
{
    /** @brief An experimental network namespace.
     */
    namespace Network
    {
        void __jatta_network_initiate()
        {
        #   ifdef WINDOWS
            if (!__jatta_network_initiated)
            {
                WSADATA wsaData;
                if (WSAStartup(MAKEWORD(1,1), &wsaData) != 0)
                {
                    throw std::runtime_error("WSAStartup() failed!");
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
    }
}
