/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Device.h"
#include "HostApi.h"

_JATTA_EXPORT Jatta::PortAudio::Device::Device(UInt32 index, const ::PaDeviceInfo* device)
{
    this->index = index;
    this->device = device;
}

_JATTA_EXPORT Jatta::String Jatta::PortAudio::Device::GetName()
{
    return String(device->name);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::PortAudio::Device::GetIndex()
{
    return index;
}

_JATTA_EXPORT Jatta::PortAudio::HostApi Jatta::PortAudio::Device::GetHostApi()
{
    return HostApi(Pa_GetHostApiInfo(device->hostApi));
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Device::GetMaxInputChannels()
{
    return (SInt32) device->maxInputChannels;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Device::GetMaxOutputChannels()
{
    return (SInt32) device->maxOutputChannels;
}

_JATTA_EXPORT double Jatta::PortAudio::Device::GetDefaultLowInputLatency()
{
    return (double) device->defaultLowInputLatency;
}

_JATTA_EXPORT double Jatta::PortAudio::Device::GetDefaultLowOutputLatency()
{
    return (double) device->defaultLowOutputLatency;
}

_JATTA_EXPORT double Jatta::PortAudio::Device::GetDefaultHightInputLatency()
{
    return (double) device->defaultHighInputLatency;
}

_JATTA_EXPORT double Jatta::PortAudio::Device::GetDefaultHighOutputLatency()
{
    return (double) device->defaultHighOutputLatency;
}

_JATTA_EXPORT double Jatta::PortAudio::Device::GetDefaultSampleRate()
{
    return (double) device->defaultSampleRate;
}
