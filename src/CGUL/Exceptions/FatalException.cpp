// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FatalException.cpp
 */

#include "FatalException.hpp"

static CGUL::String result;

CGUL::FatalException::~FatalException() throw()
{
}

CGUL::FatalException::FatalException(const CGUL::String& error, UInt16 code) :
    Exception(code, 0, ExceptionType::FATAL),
    error(error)
{
}

CGUL::String CGUL::FatalException::GetString() const
{
    return U8("Fatal runtime error: ") + this->error;
}

CGUL::String CGUL::FatalException::GetReason() const
{
    return U8("User defined error.");
}

const char* CGUL::FatalException::what() const throw()
{
    result = GetString();
    return result.GetCString();
}
