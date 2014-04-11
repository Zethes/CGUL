// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGLException.cpp
 */

// Header
#include "OpenGLException.hpp"

_CGUL_EXPORT CGUL::OpenGLException::OpenGLException(UInt8 code, UInt8 reason) : Exception(code, reason, ExceptionType::OPENGL)
{
}

_CGUL_EXPORT CGUL::String CGUL::OpenGLException::GetString() const
{
    switch (info.code)
    {
        case OpenGLExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

_CGUL_EXPORT CGUL::String CGUL::OpenGLException::GetReason() const
{
    switch (info.reason)
    {
        case OpenGLExceptionReason::UNKNOWN:
        default:
            return U8("Unknown.");
    }
}
