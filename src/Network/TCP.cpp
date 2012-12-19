#include "TCP.h"
#include <WinSock2.h>

void __jatta_network_initiate();

Jatta::SocketTCP::SocketTCP()
{
    __jatta_network_initiate();
}

void Jatta::SocketTCP::connect(const std::string& ip, unsigned short port)
{

}