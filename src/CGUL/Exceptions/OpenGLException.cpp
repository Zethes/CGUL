// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGLException.cpp
 */

#include "OpenGLException.hpp"

CGUL::OpenGLException::OpenGLException(UInt8 code, UInt8 reason) : Exception(code, reason, ExceptionType::OPENGL)
{
}

CGUL::String CGUL::OpenGLException::GetString() const
{
    switch (code)
    {
        case OpenGLExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

CGUL::String CGUL::OpenGLException::GetReason() const
{
    switch (reason)
    {
        case OpenGLExceptionReason::UNKNOWN:
        default:
            return U8("Unknown.");
    }
}
