// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SystemCode.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    struct SystemCode
    {
        enum Type
        {
            TYPE_NONE,
            TYPE_WINAPI,
            TYPE_ERRNO,
            TYPE_NETWORK,
            TYPE_SSL,
            TYPE_ADDR_INFO
        };

        SInt64 code;
        UInt16 type;

        _CGUL_EXPORT SystemCode();

        // Uses WinAPI GetLastError()
        _CGUL_EXPORT static SystemCode CheckWinApi();

        // Uses errno
        _CGUL_EXPORT static SystemCode CheckErrno();

        // Uses network code (errno or WSAGetLastError())
        _CGUL_EXPORT static SystemCode CheckNetwork();
        _CGUL_EXPORT static SystemCode UseNetwork(int error);

        // Use SSL errors
        _CGUL_EXPORT static SystemCode UseSSL(int error);

        // Use address info errors (getaddrinfo)
        _CGUL_EXPORT static SystemCode UseAddrInfo(int error);

        _CGUL_EXPORT String GetInfo() const;
    };
}

// Undefines
#include "../External/Undefines.hpp"
