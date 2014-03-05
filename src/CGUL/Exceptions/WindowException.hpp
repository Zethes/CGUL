// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file WindowException.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Exceptions/Exception.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace WindowExceptionCode
    {
        enum
        {
            UNKNOWN,
            FAILED_CREATE_WINDOW
        };
    }
    namespace WindowExceptionReason
    {
        enum
        {
            UNKNOWN,
            FAILED_REGISTER_CLASS,
            FAILED_CREATE_WINDOW_CALL,
            FAILED_OPEN_X_DISPLAY
        };
    }
    struct WindowException : public Exception
    {
        _CGUL_EXPORT WindowException(UInt8 code, UInt8 reason);
        _CGUL_EXPORT WindowException(UInt8 code, UInt8 reason, const SystemCode& systemCode);

        _CGUL_EXPORT String GetString() const;
        _CGUL_EXPORT String GetReason() const;
    };
}

// Undefines
#include "../External/Undefines.hpp"
