// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FatalException.cpp
 */

// Header
#include "FatalException.hpp"

static CGUL::String result;

_CGUL_EXPORT CGUL::FatalException::~FatalException() throw()
{
}

_CGUL_EXPORT CGUL::FatalException::FatalException(const CGUL::String& error, UInt16 code) :
    Exception(code, 0, ExceptionType::FATAL),
    error(error)
{
}

_CGUL_EXPORT CGUL::String CGUL::FatalException::GetString() const
{
    return U8("Fatal runtime error: ") + this->error;
}

_CGUL_EXPORT CGUL::String CGUL::FatalException::GetReason() const
{
    return U8("User defined error.");
}

_CGUL_EXPORT const char* CGUL::FatalException::what() const throw()
{
    result = GetString();
    return result.GetCString();
}
