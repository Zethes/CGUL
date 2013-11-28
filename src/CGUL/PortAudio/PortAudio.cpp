// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file PortAudio.cpp
 */

#include "PortAudio.hpp"
#include "Device.hpp"
#include "HostApi.hpp"
#include "HostError.hpp"

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Initialize()
{
    return Pa_Initialize();
}
_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Terminate()
{
    return Pa_Terminate();
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::GetVersion()
{
    return Pa_GetVersion();
}

_CGUL_EXPORT CGUL::String CGUL::PortAudio::GetVersionText()
{
    return String(Pa_GetVersionText());
}

_CGUL_EXPORT CGUL::String CGUL::PortAudio::GetErrorText(SInt32 error)
{
    return String(Pa_GetErrorText(error));
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::GetDeviceCount()
{
    return (SInt32)Pa_GetDeviceCount();
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::GetDefaultInputDeviceIndex()
{
    return (SInt32)Pa_GetDefaultInputDevice();
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::GetDefaultOutputDeviceIndex()
{
    return (SInt32)Pa_GetDefaultOutputDevice();
}

_CGUL_EXPORT CGUL::PortAudio::Device CGUL::PortAudio::GetDefaultInputDevice()
{
    return Device(Pa_GetDefaultInputDevice(), Pa_GetDeviceInfo(Pa_GetDefaultInputDevice()));
}

_CGUL_EXPORT CGUL::PortAudio::Device CGUL::PortAudio::GetDefaultOutputDevice()
{
    return Device(Pa_GetDefaultOutputDevice(), Pa_GetDeviceInfo(Pa_GetDefaultOutputDevice()));
}

_CGUL_EXPORT CGUL::PortAudio::Device CGUL::PortAudio::GetDevice(SInt32 index)
{
    return Device(index, Pa_GetDeviceInfo(index));
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::GetHostApiCount()
{
    return (SInt32)Pa_GetHostApiCount();
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::GetDefaultHostApiIndex()
{
    return (SInt32)Pa_GetDefaultHostApi();
}

_CGUL_EXPORT CGUL::PortAudio::HostApi CGUL::PortAudio::GetDefaultHostApi()
{
    return HostApi(Pa_GetHostApiInfo(Pa_GetDefaultHostApi()));
}

_CGUL_EXPORT CGUL::PortAudio::HostApi CGUL::PortAudio::GetHostApi(SInt32 index)
{
    return HostApi(Pa_GetHostApiInfo(index));
}

_CGUL_EXPORT CGUL::PortAudio::HostError CGUL::PortAudio::GetLastHostError()
{
    return HostError(Pa_GetLastHostErrorInfo());
}

_CGUL_EXPORT void CGUL::PortAudio::Sleep(UInt32 miliseconds)
{
    Pa_Sleep(miliseconds);
}
