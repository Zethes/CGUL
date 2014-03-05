// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file WindowException.cpp
 */

// Header
#include "WindowException.hpp"

static CGUL::String result;

_CGUL_EXPORT CGUL::WindowException::WindowException(UInt8 code, UInt8 reason) :
    Exception(code, reason, ExceptionType::WINDOW)
{
}

_CGUL_EXPORT CGUL::WindowException::WindowException(UInt8 code, UInt8 reason, const SystemCode& systemCode) :
    Exception(code, reason, systemCode, ExceptionType::WINDOW)
{
}

_CGUL_EXPORT CGUL::String CGUL::WindowException::GetString() const
{
    switch (info.code)
    {
      case WindowExceptionCode::FAILED_CREATE_WINDOW:
            return U8("Failed to create window.");
        case WindowExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

_CGUL_EXPORT CGUL::String CGUL::WindowException::GetReason() const
{
    switch (info.reason)
    {
        case WindowExceptionReason::FAILED_REGISTER_CLASS:
            return U8("Failed to register window class.");
        case WindowExceptionReason::FAILED_CREATE_WINDOW_CALL:
            return U8("Create window call failed.");
        case WindowExceptionReason::FAILED_OPEN_X_DISPLAY:
            return U8("Failed to open X display.");
        case WindowExceptionReason::UNKNOWN:
        default:
            return U8("Unknown.");
    }
}
