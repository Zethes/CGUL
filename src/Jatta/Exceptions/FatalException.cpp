/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "FatalException.h"

static Jatta::String result;

Jatta::FatalException::~FatalException() throw()
{
}

Jatta::FatalException::FatalException(const Jatta::String& error, UInt16 code) :
    Exception(code, 0, ExceptionType::FATAL),
    error(error)
{
}

Jatta::String Jatta::FatalException::GetString() const
{
    return U8("Fatal runtime error: ") + this->error;
}

Jatta::String Jatta::FatalException::GetReason() const
{
    return U8("User defined error.");
}

const char* Jatta::FatalException::what() const throw()
{
    result = GetString();
    return result.GetCString();
}
