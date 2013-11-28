// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Stream.cpp
 */

#include "Stream.hpp"

_CGUL_EXPORT CGUL::PortAudio::Stream::Stream() :
    volume(1.0f),
    pitch(0.0f),
    loop(false),
    sampleRate(0),
    framesPerBuffer(paFramesPerBufferUnspecified)
{
    streamData.StreamPtr = this;
    streamData.NumberOfChannels = 1;
}

_CGUL_EXPORT CGUL::PortAudio::Stream::~Stream()
{
    Close();
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Stream::Start()
{
    return (SInt32)Pa_StartStream(stream);
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Stream::Stop()
{
    return (SInt32)Pa_StopStream(stream);
}


_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Stream::Close()
{
    return (SInt32)Pa_CloseStream(stream);
}

_CGUL_EXPORT void CGUL::PortAudio::Stream::SetVolume(Float32 volume)
{
    this->volume = volume;
}

_CGUL_EXPORT CGUL::Float32 CGUL::PortAudio::Stream::GetVolume()
{
    return volume;
}

_CGUL_EXPORT void CGUL::PortAudio::Stream::SetPitch(Float32 pitch)
{
    this->pitch = pitch;
}

_CGUL_EXPORT CGUL::Float32 CGUL::PortAudio::Stream::GetPitch()
{
    return pitch;
}

_CGUL_EXPORT bool CGUL::PortAudio::Stream::GetLooping()
{
    return loop;
}

_CGUL_EXPORT void CGUL::PortAudio::Stream::SetLooping(bool loop)
{
    this->loop = loop;
}

_CGUL_EXPORT bool CGUL::PortAudio::Stream::IsStopped()
{
    if (Pa_IsStreamStopped(stream) == 1)
    {
        return true;
    }
    return false;
}

_CGUL_EXPORT bool CGUL::PortAudio::Stream::IsActive()
{
    if (Pa_IsStreamActive(stream) == 1)
    {
        return true;
    }
    return false;
}


_CGUL_EXPORT CGUL::PortAudio::StreamInfo CGUL::PortAudio::Stream::GetInfo()
{
    return StreamInfo(Pa_GetStreamInfo(stream));
}

_CGUL_EXPORT double CGUL::PortAudio::Stream::GetTime()
{
    return (double)Pa_GetStreamTime(stream);
}

_CGUL_EXPORT double CGUL::PortAudio::Stream::GetCpuLoad()
{
    return (double)Pa_GetStreamCpuLoad(stream);
}

_CGUL_EXPORT CGUL::PortAudio::StreamData* CGUL::PortAudio::Stream::GetData()
{
    return &streamData;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Stream::Read(void* buffer, UInt64 frames)
{
    return (SInt32)Pa_ReadStream(stream, buffer, frames);
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::Stream::Write(CGUL::Float32* buffer, UInt64 frames)
{
    return (SInt32)Pa_WriteStream(stream, (const void*)buffer, frames);
}

_CGUL_EXPORT CGUL::SInt64 CGUL::PortAudio::Stream::ReadAvailable()
{
    return (SInt64)Pa_GetStreamReadAvailable(stream);
}

_CGUL_EXPORT CGUL::SInt64 CGUL::PortAudio::Stream::WriteAvailable()
{
    return (SInt64)Pa_GetStreamWriteAvailable(stream);
}
