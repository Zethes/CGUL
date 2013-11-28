// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Exception.cpp
 */

#include "Exception.hpp"

static CGUL::String result;

CGUL::Exception::~Exception() throw()
{
}

const char* CGUL::Exception::what() const throw()
{
    result = GetString();
    result += U8(" (Reason: ") + GetReason() + U8(")");
    return result.GetCString();
}

CGUL::Exception::Exception(UInt16 code, UInt16 reason, UInt32 type)
{
    this->code = code;
    this->reason = reason;
    this->type = type;
}
