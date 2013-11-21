/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "FileException.h"

Jatta::FileException::FileException(const Jatta::String& fileName, UInt8 code, UInt8 reason) :
    Exception(code, reason, ExceptionType::FILE),
    fileName(fileName)
{
}

Jatta::FileException::~FileException() throw()
{
}

Jatta::String Jatta::FileException::GetString() const
{
    switch (code)
    {
        case FileExceptionCode::FAILED_FILE_READ:
            return U8("Failed to read file \"") + fileName + U8("\".");
        case FileExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

Jatta::String Jatta::FileException::GetReason() const
{
    switch (reason)
    {
        case FileExceptionReason::FILE_DOESNT_EXIST:
            return U8("File doesn't exist.");
        case FileExceptionReason::PERMISSION_DENIED:
            return U8("Permission denied.");
        case FileExceptionReason::UNKNOWN:
        default:
            return U8("Unknown.");
    }
}
