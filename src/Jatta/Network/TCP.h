/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
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
