/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Device.h"

_JATTA_EXPORT Jatta::Audio::Device::Device()
{
    deviceName = "Unknown Device";
    maxInputChannels = 0;
    maxOutputChannels = 0;
    defaultSampleRate = 0;
    index = -1;
}
_JATTA_EXPORT Jatta::Audio::Device::Device(int deviceIndex)
{
    index = deviceIndex;
    deviceName = "Unknown Device";

    const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(deviceIndex);
    deviceName = deviceInfo->name;
    maxInputChannels = deviceInfo->maxInputChannels;
    maxOutputChannels = deviceInfo->maxOutputChannels;
    defaultSampleRate =  deviceInfo->defaultSampleRate;
    hostApiInfo = HostApiInfo(deviceInfo->hostApi);
}
_JATTA_EXPORT Jatta::Audio::Device::Device(int dIndex, const PaDeviceInfo* deviceInfo)
{
    index = dIndex;
    deviceName = deviceInfo->name;
    maxInputChannels = deviceInfo->maxInputChannels;
    maxOutputChannels = deviceInfo->maxOutputChannels;
    defaultSampleRate =  deviceInfo->defaultSampleRate;
    hostApiInfo = HostApiInfo(deviceInfo->hostApi);
}
_JATTA_EXPORT Jatta::Audio::Device::~Device()
{

}

_JATTA_EXPORT int Jatta::Audio::Device::GetIndex()
{
    return index;
}
_JATTA_EXPORT Jatta::String Jatta::Audio::Device::GetName()
{
    return deviceName;
}
_JATTA_EXPORT int Jatta::Audio::Device::GetMaxInputChannels()
{
    return maxInputChannels;
}
_JATTA_EXPORT int Jatta::Audio::Device::GetMaxOutputChannels()
{
    return maxOutputChannels;
}
_JATTA_EXPORT double Jatta::Audio::Device::GetSampleRate()
{
    return defaultSampleRate;
}
_JATTA_EXPORT Jatta::Audio::HostApiInfo* Jatta::Audio::Device::GetHostApiInfo()
{
    return &hostApiInfo;
}