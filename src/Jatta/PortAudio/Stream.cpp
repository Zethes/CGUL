/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Stream.h"

_JATTA_EXPORT Jatta::PortAudio::Stream::Stream()
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    streamData.NumberOfChannels = 1;

    sampleRate = 0;
    framesPerBuffer = paFramesPerBufferUnspecified;
}

_JATTA_EXPORT Jatta::PortAudio::Stream::~Stream()
{
    Close();
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Stream::Start()
{
    return (SInt32)Pa_StartStream(stream);
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Stream::Stop()
{
    return (SInt32)Pa_StopStream(stream);
}


_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Stream::Close()
{
    return (SInt32)Pa_CloseStream(stream);
}

_JATTA_EXPORT void Jatta::PortAudio::Stream::SetVolume(Float32 volume)
{
    this->volume = volume;
}

_JATTA_EXPORT Jatta::Float32 Jatta::PortAudio::Stream::GetVolume()
{
    return volume;
}

_JATTA_EXPORT bool Jatta::PortAudio::Stream::GetLooping()
{
    return loop;
}

_JATTA_EXPORT void Jatta::PortAudio::Stream::SetLooping(bool loop)
{
    this->loop = loop;
}

_JATTA_EXPORT bool Jatta::PortAudio::Stream::IsStopped()
{
    if (Pa_IsStreamStopped(stream) == 1)
        return true;
    return false;
}

_JATTA_EXPORT bool Jatta::PortAudio::Stream::IsActive()
{
    if (Pa_IsStreamActive(stream) == 1)
        return true;
    return false;
}


_JATTA_EXPORT Jatta::PortAudio::StreamInfo Jatta::PortAudio::Stream::GetInfo()
{
    return StreamInfo(Pa_GetStreamInfo(stream));
}

_JATTA_EXPORT double Jatta::PortAudio::Stream::GetTime()
{
    return (double)Pa_GetStreamTime(stream);
}

_JATTA_EXPORT double Jatta::PortAudio::Stream::GetCpuLoad()
{
    return (double)Pa_GetStreamCpuLoad(stream);
}

_JATTA_EXPORT Jatta::PortAudio::StreamData* Jatta::PortAudio::Stream::GetData()
{
    return &streamData;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Stream::Read(void* buffer, UInt64 frames)
{
    return (SInt32)Pa_ReadStream(stream, buffer, frames);
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Stream::Write(const void* buffer, UInt64 frames)
{
    return (SInt32)Pa_WriteStream(stream, buffer, frames);
}

_JATTA_EXPORT Jatta::SInt64 Jatta::PortAudio::Stream::ReadAvailable()
{
    return (SInt64)Pa_GetStreamReadAvailable(stream);
}

_JATTA_EXPORT Jatta::SInt64 Jatta::PortAudio::Stream::WriteAvailable()
{
    return (SInt64)Pa_GetStreamWriteAvailable(stream);
}
