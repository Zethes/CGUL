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
        *out++ = data->LeftPhase;
        *out++ = data->RightPhase;

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

    //return Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, device.GetDefaultSampleRate(),
    //    paFramesPerBufferUnspecified, paCallback, &data);
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
    data.StreamPtr = this;
    data.LeftPhase = data.RightPhase = 0;

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