/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "FatalException.h"

Jatta::FatalException::~FatalException() throw()
{
}

Jatta::FatalException::FatalException(const Jatta::String& error, UInt16 code) : Exception(code, ExceptionType::FATAL)
{
    this->error = error;
}

Jatta::String Jatta::FatalException::GetString() const
{
    return U8("Fatal runtime error: ") + this->error;
}
