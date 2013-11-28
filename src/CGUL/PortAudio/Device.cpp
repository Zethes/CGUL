// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Device.cpp
 */

#include "Device.hpp"
#include "HostApi.hpp"

_CGUL_EXPORT CGUL::PortAudio::Device::Device(UInt32 index, const ::PaDeviceInfo* device)
{
    this->index = index;
    this->device = device;
}

_CGUL_EXPORT CGUL::String CGUL::PortAudio::Device::GetName()
{
    return String(device->name);
}

_CGUL_EXPORT CGUL::UInt32 CGUL::PortAudio::Device::GetIndex()
{
    return index;
}

_CGUL_EXPORT CGUL::PortAudio::HostApi CGUL::PortAudio::Device::GetHostApi()
{
    return HostApi(Pa_GetHostApiInfo(device->hostApi));
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Device::GetMaxInputChannels()
{
    return (SInt32) device->maxInputChannels;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Device::GetMaxOutputChannels()
{
    return (SInt32) device->maxOutputChannels;
}

_CGUL_EXPORT double CGUL::PortAudio::Device::GetDefaultLowInputLatency()
{
    return (double) device->defaultLowInputLatency;
}

_CGUL_EXPORT double CGUL::PortAudio::Device::GetDefaultLowOutputLatency()
{
    return (double) device->defaultLowOutputLatency;
}

_CGUL_EXPORT double CGUL::PortAudio::Device::GetDefaultHightInputLatency()
{
    return (double) device->defaultHighInputLatency;
}

_CGUL_EXPORT double CGUL::PortAudio::Device::GetDefaultHighOutputLatency()
{
    return (double) device->defaultHighOutputLatency;
}

_CGUL_EXPORT double CGUL::PortAudio::Device::GetDefaultSampleRate()
{
    return (double) device->defaultSampleRate;
}
