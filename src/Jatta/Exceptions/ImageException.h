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
    namespace ImageExceptionCode
    {
        enum
        {
            UNKNOWN,
            GENERATE_MIPMAPS,
            GET_MIPMAP,
            BMP,
        };
    }
    namespace ImageExceptionReason
    {
        enum
        {
            UNKNOWN,
            IMAGE_IS_NOT_VALID,
            NO_BASE_MIPMAP,
            INDEX_OUT_OF_RANGE,
            INVALID_DATA_FORMAT,
            INVALID_COLOR_PLANE_COUNT,
            NOT_A_BMP_FILE,
            UNSUPPORTED_FORMAT,
        };
    }
    struct ImageException : public Exception
    {
        ImageException(UInt8 code, UInt8 reason);

        Jatta::String GetString() const;
        Jatta::String GetReason() const;
    };
}

#include "../External/Undefines.h"