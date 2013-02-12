/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "PortAudio.h"
#include "HostApiInfo.h"

_JATTA_EXPORT Jatta::Audio::HostApiInfo::HostApiInfo()
{
    /*int index;
            String name;
            int type;
            int deviceCount;
            int defaultInputDevice;
            int defaultOutputDevice;*/
    index = -1;
    name = "Unknown Host";
    type = -1;
    deviceCount = 0;
    defaultInputDevice = -1;
    defaultOutputDevice = -1;
}
_JATTA_EXPORT Jatta::Audio::HostApiInfo::HostApiInfo(int apiIndex)
{
    HostApiInfo(apiIndex, Pa_GetHostApiInfo(apiIndex));
}
_JATTA_EXPORT Jatta::Audio::HostApiInfo::HostApiInfo(int apiIndex, const PaHostApiInfo* apiInfo)
{
    index = apiIndex;
    name = apiInfo->name;
    type = apiInfo->type;
    deviceCount = apiInfo->deviceCount;
    defaultInputDevice = apiInfo->defaultInputDevice;
    defaultOutputDevice = apiInfo->defaultOutputDevice;
}
_JATTA_EXPORT Jatta::Audio::HostApiInfo::~HostApiInfo()
{

}

_JATTA_EXPORT int Jatta::Audio::HostApiInfo::Index()
{
    return index;
}
_JATTA_EXPORT Jatta::String Jatta::Audio::HostApiInfo::Name()
{
    return name;
}
_JATTA_EXPORT Jatta::String Jatta::Audio::HostApiInfo::Type()
{
    return HostApiTypes[type+1];
}
_JATTA_EXPORT int Jatta::Audio::HostApiInfo::DeviceCount()
{
    return deviceCount;
}
_JATTA_EXPORT Jatta::Audio::Device* Jatta::Audio::HostApiInfo::DefaultDevice()
{
    return Jatta::Audio::GetDevice(defaultOutputDevice);
}