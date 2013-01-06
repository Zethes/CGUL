/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class SocketTCP
    {
        int socket;

        _JATTA_EXPORT SocketTCP();

        _JATTA_EXPORT void Connect(const std::string& ip, unsigned short port);
    };
};

#include "../External/Undefines.h"
