//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class SocketTCP
    {
        int socket;

        _JATTA_EXPORT SocketTCP();

        _JATTA_EXPORT void connect(const std::string& ip, unsigned short port);
    };
};

#include "../External/Undefines.h"