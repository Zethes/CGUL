// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file StringException.cpp
 */

// Header
#include "StringException.hpp"

static CGUL::String result;

_CGUL_EXPORT CGUL::StringException::StringException(UInt8 code, UInt8 reason) :
    Exception(code, reason, ExceptionType::STRING)
{
}

_CGUL_EXPORT CGUL::StringException::StringException(UInt8 code, UInt8 reason, const SystemCode& systemCode) :
    Exception(code, reason, systemCode, ExceptionType::STRING)
{
}

_CGUL_EXPORT CGUL::String CGUL::StringException::GetString() const
{
    switch (info.code)
    {
      case StringExceptionCode::INVALID_PRINTF_FORMAT:
            return U8("Invalid string printf format.");
        case StringExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

_CGUL_EXPORT CGUL::String CGUL::StringException::GetReason() const
{
    switch (info.reason)
    {
        case StringExceptionReason::BAD_FORMAT:
            return U8("Bad format.");
        case StringExceptionReason::UNKNOWN:
        default:
            return U8("Unknown.");
    }
}
