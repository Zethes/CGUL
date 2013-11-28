// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OutputStream.cpp
 */

#include "OutputStream.hpp"

static int paCallbackOutput(const void* input, void* output, unsigned long fpb, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags flags, void* udata)
{
    CGUL::PortAudio::StreamData* data = (CGUL::PortAudio::StreamData*)udata;

    if (data == NULL)
    {
        return paAbort;
    }
    if (data->StreamPtr == NULL)
    {
        return paAbort;
    }

    float *out = (float*)output;
    unsigned int i;
    (void) input;

    for (i = 0; i < fpb; i++)
    {
        if (data->CurrentPosition >= data->Length && data->StreamPtr->GetLooping())
        {
            data->CurrentPosition = 0;
        }
        else if (data->CurrentPosition >= data->Length)
        {
            return paAbort;
        }

        for (unsigned int j = 0; j < data->NumberOfChannels; j++)
        {
            *out++ = data->StreamPtr->GetVolume()*data->OutputChannels.at(j)[data->CurrentPosition];
        }

        data->CurrentPosition++;//= data->StreamPtr->GetPitch();
    }

    return paContinue;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::PortAudio::OutputStream::OpenStream(Device device)
{
    if (sampleRate == 0)
    {
        sampleRate = device.GetDefaultSampleRate();
    }

    PaStreamParameters outputParameters;
    outputParameters.device = device.GetIndex();
    outputParameters.channelCount = streamData.NumberOfChannels;
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
               paCallbackOutput,
               &streamData);
}

_CGUL_EXPORT CGUL::PortAudio::OutputStream::OutputStream(Device device)
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    streamData.NumberOfChannels = 1;

    sampleRate = 0;
    framesPerBuffer = paFramesPerBufferUnspecified;

    streamData.CurrentPosition = 0;
    streamData.Length = 0;
    streamData.inputCallback = NULL;

    OpenStream(device);
}

_CGUL_EXPORT CGUL::PortAudio::OutputStream::OutputStream(Device device, Float32* data, UInt32 length, UInt32 sr)
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    streamData.NumberOfChannels = 1;

    sampleRate = 0;
    framesPerBuffer = paFramesPerBufferUnspecified;

    streamData.OutputChannels.push_back(data);
    streamData.CurrentPosition = 0;
    streamData.Length = length;
    streamData.inputCallback = NULL;

    OpenStream(device);
}

_CGUL_EXPORT CGUL::PortAudio::OutputStream::OutputStream(Device device, std::vector<Float32*> data, UInt32 length, UInt32 sr)
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    if (data.size() > (unsigned int)device.GetMaxOutputChannels())
    {
        streamData.NumberOfChannels = device.GetMaxOutputChannels();
    }
    else
    {
        streamData.NumberOfChannels = data.size();
    }

    sampleRate = sr;
    framesPerBuffer = paFramesPerBufferUnspecified;

    for (unsigned int i = 0; i < streamData.NumberOfChannels; i++)
    {
        streamData.OutputChannels.push_back(data[i]);
    }
    streamData.CurrentPosition = 0;
    streamData.Length = length;
    streamData.inputCallback = NULL;

    OpenStream(device);
}
