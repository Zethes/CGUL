#pragma once

#include <string>

namespace Jatta
{
    class SocketTCP
    {
        int socket;

        SocketTCP();

        void connect(const std::string& ip, unsigned short port);
    };
};