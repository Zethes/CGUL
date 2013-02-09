/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_AUDIO
#include "Stream.h"
#include "../Math/Math.h"

#include <iostream>

_JATTA_EXPORT Jatta::Audio::Stream::Stream()
{
    playing = false;
    pitch = 1;
    volume = 1;
    pan = 0;

    outDevice = Audio::GetDefaultDevice();
}
_JATTA_EXPORT Jatta::Audio::Stream::Stream(Device* device)
{
    playing = false;
    pitch = 1;
    volume = 1;
    pan = 0;

    outDevice = device;
}
_JATTA_EXPORT Jatta::Audio::Stream::~Stream()
{
    Close();
}

_JATTA_EXPORT Jatta::Audio::AudioError Jatta::Audio::Stream::Start()
{
    if (playing)
        return Errors::STREAM_IS_NOT_STOPPED;

    PaError err = Pa_StartStream(stream);
    if (err != paNoError)
    {
        std::cout << GetErrorText(err) << std::endl;
        return err;
    }
    playing = true;
    return err;
}
_JATTA_EXPORT Jatta::Audio::AudioError Jatta::Audio::Stream::Stop()
{
    if (!playing)
        return Errors::STREAM_IS_STOPPED;

    PaError err = Pa_StopStream(stream);
    if (err != paNoError)
    {
        std::cout << GetErrorText(err) << std::endl;
        return err;
    }
    playing = false;
    return err;
}
_JATTA_EXPORT Jatta::Audio::AudioError Jatta::Audio::Stream::Close()
{
    if (playing)
        Stop();

    PaError err = Pa_CloseStream(stream);
    if (err != paNoError)
    {
        std::cout << GetErrorText(err) << std::endl;
        return err;
    }
    return err;
}

_JATTA_EXPORT float Jatta::Audio::Stream::GetPitch()
{
    return pitch;
}
_JATTA_EXPORT float Jatta::Audio::Stream::GetVolume()
{
    return volume;
}
_JATTA_EXPORT float Jatta::Audio::Stream::GetPan()
{
    return pan;
}

_JATTA_EXPORT void Jatta::Audio::Stream::SetPitch(float p)
{
    p = Math::Min(Math::Max(p, 10), 0);
    pitch = p;
}
_JATTA_EXPORT void Jatta::Audio::Stream::SetVolume(float v)
{
    //v = Math::Min(Math::Max(v, 1), 0);
    volume = v;
}
_JATTA_EXPORT void Jatta::Audio::Stream::SetPan(float p)
{
    p = Math::Min(Math::Max(p, 1), -1);
    pan = p;
}

#endif
