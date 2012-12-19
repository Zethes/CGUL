//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class SocketTCP
    {
        int socket;

        SocketTCP();

        void connect(const std::string& ip, unsigned short port);
    };
};

#include "../External/Undefines.h"