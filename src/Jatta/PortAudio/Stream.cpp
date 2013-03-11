/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Stream.h"

static int paCallback(const void* input, void* output, unsigned long fpb, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags flags, void* udata)
{
    Jatta::PortAudio::StreamData* data = (Jatta::PortAudio::StreamData*)udata;
    float *out = (float*)output;
    unsigned int i;
    (void) input;

    for (i = 0; i < fpb; i++)
    {
        for (unsigned int j = 0; j < data->NumberOfChannels; j++)
        { *out++ = data->StreamPtr->GetVolume()*data->Channels[j]; }

        if (!data->StreamPtr->Update(data))
        {
            return paAbort;
        }
    }

    return paContinue;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::Stream::OpenStream(Device device)
{
    if (sampleRate == 0)
    { sampleRate = device.GetDefaultSampleRate(); }

    data.Channels = new Float32[data.NumberOfChannels];
    for (unsigned int i = 0; i < data.NumberOfChannels; i++)
    { data.Channels[i] = 0.0f; }

    PaStreamParameters outputParameters;
    outputParameters.device = device.GetIndex();
    outputParameters.channelCount = channelCount;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = device.GetDefaultLowOutputLatency();
    outputParameters.hostApiSpecificStreamInfo = NULL;

    return Pa_OpenStream(
        &stream,
        NULL,
        &outputParameters,
        sampleRate,
        framesPerBuffer,
        paClipOff,
        paCallback,
        &data);
}

//public:
_JATTA_EXPORT Jatta::PortAudio::Stream::Stream()
{
    volume = 1.0f;
    data.StreamPtr = this;
    data.NumberOfChannels = 2;

    sampleRate = 0;
    channelCount = 2;
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
    return &data;
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
    return (SInt64)Pa_GetStreamReadAvailable(stream);
}
