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
    namespace FileExceptionCode
    {
        enum
        {
            UNKNOWN,
            FAILED_FILE_READ,
        };
    }
    namespace FileExceptionReason
    {
        enum
        {
            UNKNOWN,
            FILE_DOESNT_EXIST,
            PERMISSION_DENIED,
        };
    }
    struct FileException : public Exception
    {
        Jatta::String fileName;

        FileException(const Jatta::String& fileName, UInt8 code, UInt8 reason);

        Jatta::String GetString() const;
        Jatta::String GetReason() const;
    };
}

#include "../External/Undefines.h"
