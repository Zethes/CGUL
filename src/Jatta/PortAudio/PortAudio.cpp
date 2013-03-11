/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "PortAudio.h"
#include "Device.h"
#include "HostApi.h"

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Initialize()
{
    return Pa_Initialize();
}
_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Terminate()
{
    return Pa_Terminate();
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::GetVersion()
{
    return Pa_GetVersion();
}

_JATTA_EXPORT Jatta::String Jatta::PortAudio::GetVersionText()
{
    return String(Pa_GetVersionText());
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::GetDeviceCount()
{
    return (SInt32)Pa_GetDeviceCount();
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::GetDefaultInputDeviceIndex()
{
    return (SInt32)Pa_GetDefaultInputDevice();
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::GetDefaultOutputDeviceIndex()
{
    return (SInt32)Pa_GetDefaultOutputDevice();
}

_JATTA_EXPORT Jatta::PortAudio::Device Jatta::PortAudio::GetDefaultInputDevice()
{
    return Device(Pa_GetDefaultInputDevice(), Pa_GetDeviceInfo(Pa_GetDefaultInputDevice()));
}

_JATTA_EXPORT Jatta::PortAudio::Device Jatta::PortAudio::GetDefaultOutputDevice()
{
    return Device(Pa_GetDefaultOutputDevice(), Pa_GetDeviceInfo(Pa_GetDefaultOutputDevice()));
}

_JATTA_EXPORT Jatta::PortAudio::Device Jatta::PortAudio::GetDevice(SInt32 index)
{
    return Device(index, Pa_GetDeviceInfo(index));
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::GetHostApiCount()
{
    return (SInt32)Pa_GetHostApiCount();
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::GetDefaultHostApiIndex()
{
    return (SInt32)Pa_GetDefaultHostApi();
}

_JATTA_EXPORT Jatta::PortAudio::HostApi Jatta::PortAudio::GetDefaultHostApi()
{
    return HostApi(Pa_GetHostApiInfo(Pa_GetDefaultHostApi()));
}

_JATTA_EXPORT Jatta::PortAudio::HostApi Jatta::PortAudio::GetHostApi(SInt32 index)
{
    return HostApi(Pa_GetHostApiInfo(index));
}

_JATTA_EXPORT void Jatta::PortAudio::Sleep(UInt32 miliseconds)
{
    Pa_Sleep(miliseconds);
}