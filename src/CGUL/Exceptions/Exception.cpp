// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Exception.cpp
 */

// Header
#include "Exception.hpp"

static CGUL::String result;

_CGUL_EXPORT CGUL::Exception::~Exception() throw()
{
}

_CGUL_EXPORT const char* CGUL::Exception::what() const throw()
{
    result = GetString();
    result += U8("\n  Reason : ") + GetReason();
    result += U8("\n  Details: ") + systemCode.GetInfo();
    return result.GetCString();
}

_CGUL_EXPORT CGUL::Exception::Exception(UInt16 code, UInt16 reason)
{
    this->info.code = code;
    this->info.reason = reason;
    this->info.type = ExceptionType::USER;
}

_CGUL_EXPORT CGUL::Exception::Exception(UInt16 code, UInt16 reason, const SystemCode& systemCode) :
    systemCode(systemCode)
{
    this->info.code = code;
    this->info.reason = reason;
    this->info.type = ExceptionType::USER;
}

_CGUL_EXPORT CGUL::Exception::Exception(UInt16 code, UInt16 reason, UInt32 type)
{
    this->info.code = code;
    this->info.reason = reason;
    this->info.type = type;
}

_CGUL_EXPORT CGUL::Exception::Exception(UInt16 code, UInt16 reason, const SystemCode& systemCode, UInt32 type) :
    systemCode(systemCode)
{
    this->info.code = code;
    this->info.reason = reason;
    this->info.type = type;
}
