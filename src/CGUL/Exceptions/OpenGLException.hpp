// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGLException.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Exception.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace OpenGLExceptionCode
    {
        enum
        {
            UNKNOWN,
            FAILED_CREATE_SHADER,
        };
    }
    namespace OpenGLExceptionReason
    {
        enum
        {
            UNKNOWN,
        };
    }
    struct OpenGLException : public Exception
    {
        OpenGLException(UInt8 code, UInt8 reason);

        String GetString() const;
        String GetReason() const;
    };
}

#include "../External/Undefines.hpp"
