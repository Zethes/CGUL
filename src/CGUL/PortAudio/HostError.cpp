// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HostError.cpp
 */

#include "HostError.hpp"

_CGUL_EXPORT CGUL::PortAudio::HostError::HostError(const ::PaHostErrorInfo* info)
{
    this->info = info;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::HostError::GetType()
{
    return (SInt32)info->hostApiType;
}

_CGUL_EXPORT CGUL::SInt64 CGUL::PortAudio::HostError::GetErrorCode()
{
    return (SInt64)info->errorCode;
}

_CGUL_EXPORT CGUL::String CGUL::PortAudio::HostError::GetErrorText()
{
    return String(info->errorText);
}
