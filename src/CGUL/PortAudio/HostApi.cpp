// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HostApi.cpp
 */

#include "HostApi.hpp"
#include "Device.hpp"

_CGUL_EXPORT CGUL::PortAudio::HostApi::HostApi(const ::PaHostApiInfo* host)
{
    this->host = host;
}

_CGUL_EXPORT CGUL::String CGUL::PortAudio::HostApi::GetName()
{
    return String(host->name);
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::HostApi::GetType()
{
    return (SInt32)host->type;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::HostApi::GetDeviceCount()
{
    return (SInt32)host->deviceCount;
}

_CGUL_EXPORT CGUL::PortAudio::Device CGUL::PortAudio::HostApi::GetDefaultInputDevice()
{
    return Device(host->defaultInputDevice, Pa_GetDeviceInfo(host->defaultInputDevice));
}

_CGUL_EXPORT CGUL::PortAudio::Device CGUL::PortAudio::HostApi::GetDefaultOutputDevice()
{
    return Device(host->defaultOutputDevice, Pa_GetDeviceInfo(host->defaultOutputDevice));
}
