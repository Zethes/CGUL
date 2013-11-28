/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Exception.h"
#include "../External/Defines.h"

namespace Jatta
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

        Jatta::String GetString() const;
        Jatta::String GetReason() const;
    };
}

#include "../External/Undefines.h"
