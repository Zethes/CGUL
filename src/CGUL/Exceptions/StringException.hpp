// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file StringException.hpp
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
    namespace StringExceptionCode
    {
        enum
        {
            UNKNOWN,
            INVALID_PRINTF_FORMAT
        };
    }
    namespace StringExceptionReason
    {
        enum
        {
            UNKNOWN,
            BAD_FORMAT
        };
    }
    struct StringException : public Exception
    {
        _CGUL_EXPORT StringException(UInt8 code, UInt8 reason);
        _CGUL_EXPORT StringException(UInt8 code, UInt8 reason, const SystemCode& systemCode);

        _CGUL_EXPORT String GetString() const;
        _CGUL_EXPORT String GetReason() const;
    };
}

// Undefines
#include "../External/Undefines.hpp"
