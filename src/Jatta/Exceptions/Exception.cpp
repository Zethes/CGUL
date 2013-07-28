/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Exception.h"

static Jatta::String result;

Jatta::Exception::~Exception() throw()
{
}

const char* Jatta::Exception::what() const throw()
{
    result = GetString();
    result += U8(" (Reason: ") + GetReason() + U8(")");
    return result.GetCString();
}

Jatta::Exception::Exception(UInt8 code, UInt8 reason, UInt16 type)
{
    this->code = code;
    this->reason = reason;
    this->type = type;
}
