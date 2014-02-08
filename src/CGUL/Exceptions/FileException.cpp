// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FileException.cpp
 */

#include "FileException.hpp"

CGUL::FileException::FileException(const CGUL::String& fileName, UInt8 code, UInt8 reason) :
    Exception(code, reason, ExceptionType::FILE),
    fileName(fileName)
{
}

CGUL::FileException::~FileException() throw()
{
}

CGUL::String CGUL::FileException::GetString() const
{
    switch (info.code)
    {
        case FileExceptionCode::FAILED_FILE_READ:
            return U8("Failed to read file \"") + fileName + U8("\".");
        case FileExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

CGUL::String CGUL::FileException::GetReason() const
{
    switch (info.reason)
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
