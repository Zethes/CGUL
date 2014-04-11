// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Exception.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Exceptions/SystemCode.hpp"
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace ExceptionType
    {
        enum
        {
            USER,
            FATAL,
            IMAGE,
            NETWORK,
            FILE,
            OPENGL,
            WINDOW,
            STRING
        };
    }
    struct Exception : public std::exception
    {
        union
        {
            struct
            {
                UInt16 reason;
                UInt16 code;
                UInt32 type;
            } info;
            UInt64 unique;
        };

        SystemCode systemCode;

        _CGUL_EXPORT ~Exception() throw();

        _CGUL_EXPORT virtual String GetString() const = 0;
        _CGUL_EXPORT virtual String GetReason() const = 0;

        _CGUL_EXPORT virtual const char* what() const throw();
    protected:
        _CGUL_EXPORT Exception(UInt16 code, UInt16 reason);
        _CGUL_EXPORT Exception(UInt16 code, UInt16 reason, const SystemCode& systemCode);
        _CGUL_EXPORT Exception(UInt16 code, UInt16 reason, UInt32 type);
        _CGUL_EXPORT Exception(UInt16 code, UInt16 reason, const SystemCode& systemCode, UInt32 type);
    };
}

// Undefines
#include "../External/Undefines.hpp"
