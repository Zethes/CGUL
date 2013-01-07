#if 0
/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "TCP.h"
#include <WinSock2.h>

void __jatta_network_initiate();

Jatta::SocketTCP::SocketTCP()
{
    __jatta_network_initiate();
}

void Jatta::SocketTCP::Connect(const std::string& ip, unsigned short port)
{

}

#endif
