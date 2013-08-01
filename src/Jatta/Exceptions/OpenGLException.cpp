/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "OpenGLException.h"

Jatta::OpenGLException::OpenGLException(UInt8 code, UInt8 reason) : Exception(code, reason, ExceptionType::OPENGL)
{
}

Jatta::String Jatta::OpenGLException::GetString() const
{
    switch (code)
    {
        case OpenGLExceptionCode::UNKNOWN:
        default:
        return U8("Unknown error occurred.");
    }
}

Jatta::String Jatta::OpenGLException::GetReason() const
{
    switch (reason)
    {
        case OpenGLExceptionReason::UNKNOWN:
        default:
        return U8("Unknown.");
    }
}
