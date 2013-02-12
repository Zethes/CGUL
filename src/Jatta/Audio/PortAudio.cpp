/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "PortAudio.h"

_JATTA_EXPORT Jatta::Audio::AudioError Jatta::Audio::Initilize()
{
    lastError = Pa_Initialize();

    //Get devices.
    int count = Pa_GetDeviceCount();
    for (int i = 0; i < count; i++)
    {
        outputDevices.push_back(new Device(i));
    }

    return lastError;
}
_JATTA_EXPORT Jatta::Audio::AudioError Jatta::Audio::Terminate()
{
    outputDevices.clear();

    lastError = Pa_Terminate();
    return lastError;
}

_JATTA_EXPORT int Jatta::Audio::NumberOfDevices()
{
    return outputDevices.size();
}
_JATTA_EXPORT Jatta::Audio::Device* Jatta::Audio::GetDefaultDevice()
{
    int dev = Pa_GetDefaultOutputDevice();
    if (dev == paNoDevice)
    {
        lastError = Errors::DEVICE_UNAVAILABLE;
        return GetDevice(0);
    }

    return GetDevice(dev);
}
_JATTA_EXPORT Jatta::Audio::Device* Jatta::Audio::GetDevice(int index)
{
    return outputDevices[index];
}

_JATTA_EXPORT void Jatta::Audio::Sleep(unsigned int ms)
{
    Pa_Sleep(ms);
}

_JATTA_EXPORT int Jatta::Audio::GetPAVersion()
{
    return Pa_GetVersion();
}

_JATTA_EXPORT Jatta::Audio::AudioError Jatta::Audio::GetLastError()
{
    AudioError err = lastError;
    lastError = 0;
    return err;
}

_JATTA_EXPORT Jatta::String Jatta::Audio::GetErrorText(AudioError errorCode)
{
    String s = "PortAudio error: ";
    if (errorCode >= Errors::FAILED_TO_LOAD_RAW)
    {
        s += Errors::ErrorMessages[errorCode-Errors::FAILED_TO_LOAD_RAW];
        s += " (";
        s += errorCode;
        s += ")";
    }
    else
    {
        s += Pa_GetErrorText(errorCode);
        s += " (";
        s += errorCode;
        s += ")";
    }
    return s;
}