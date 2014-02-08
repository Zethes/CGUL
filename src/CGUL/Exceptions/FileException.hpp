// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FileException.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Exception.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace FileExceptionCode
    {
        enum
        {
            UNKNOWN,
            FAILED_FILE_READ
        };
    }
    namespace FileExceptionReason
    {
        enum
        {
            UNKNOWN,
            FILE_DOESNT_EXIST,
            PERMISSION_DENIED
        };
    }
    struct FileException : public Exception
    {
        String fileName;

        FileException(const String& fileName, UInt8 code, UInt8 reason);
        ~FileException() throw();

        String GetString() const;
        String GetReason() const;
    };
}

#include "../External/Undefines.hpp"
