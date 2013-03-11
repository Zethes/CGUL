/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "HostApi.h"
#include "Device.h"

_JATTA_EXPORT Jatta::PortAudio::HostApi::HostApi(const ::PaHostApiInfo* host)
{
    this->host = host;
}

_JATTA_EXPORT Jatta::String Jatta::PortAudio::HostApi::GetName()
{
    return String(host->name);
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::HostApi::GetType()
{
    return (SInt32)host->type;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::HostApi::GetDeviceCount()
{
    return (SInt32)host->deviceCount;
}

_JATTA_EXPORT Jatta::PortAudio::Device Jatta::PortAudio::HostApi::GetDefaultInputDevice()
{
    return Device(host->defaultInputDevice, Pa_GetDeviceInfo(host->defaultInputDevice));
}

_JATTA_EXPORT Jatta::PortAudio::Device Jatta::PortAudio::HostApi::GetDefaultOutputDevice()
{
    return Device(host->defaultOutputDevice, Pa_GetDeviceInfo(host->defaultOutputDevice));
}
