/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "HostError.h"

_JATTA_EXPORT Jatta::PortAudio::HostError::HostError(const ::PaHostErrorInfo* info)
{
    this->info = info;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::HostError::GetType()
{
    return (SInt32)info->hostApiType;
}

_JATTA_EXPORT Jatta::SInt64 Jatta::PortAudio::HostError::GetErrorCode()
{
    return (SInt64)info->errorCode;
}

_JATTA_EXPORT Jatta::String Jatta::PortAudio::HostError::GetErrorText()
{
    return String(info->errorText);
}
