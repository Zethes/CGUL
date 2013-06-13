/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "OutputStream.h"
#include <iostream>

static int paCallback(const void* input, void* output, unsigned long fpb, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags flags, void* udata)
{
    Jatta::PortAudio::StreamData* data = (Jatta::PortAudio::StreamData*)udata;
    std::cout << "CP: " << data->CurrentPosition << std::endl;

    float *out = (float*)output;
    unsigned int i;
    (void) input;

    for (i = 0; i < fpb; i++)
    {
        for (unsigned int j = 0; j < data->NumberOfChannels; j++)
        { *out++ = data->StreamPtr->GetVolume()*data->OutputChannels[j][data->CurrentPosition]; }

        data->CurrentPosition++;
        if (data->CurrentPosition >= data->Length && data->StreamPtr->GetLooping())
            data->CurrentPosition = 0;
        else if (data->CurrentPosition >= data->Length) 
            return paAbort;
    }

    return paContinue;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::OutputStream::OpenStream(Device device)
{
    if (sampleRate == 0)
    { sampleRate = device.GetDefaultSampleRate(); }

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
        paCallback,
        &streamData);
}

//public:
_JATTA_EXPORT Jatta::PortAudio::OutputStream::OutputStream(Device device)
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    streamData.NumberOfChannels = 2;

    sampleRate = 0;
    framesPerBuffer = paFramesPerBufferUnspecified;

    streamData.CurrentPosition = 0;
    streamData.Length = 0;

    OpenStream(device);
}

_JATTA_EXPORT Jatta::PortAudio::OutputStream::OutputStream(Device device, Float32* data, UInt32 length, UInt32 sr)
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    streamData.NumberOfChannels = 2;

    sampleRate = 0;
    framesPerBuffer = paFramesPerBufferUnspecified;

    streamData.OutputChannels.push_back(data);
    streamData.CurrentPosition = 0;
    streamData.Length = length;

    OpenStream(device);
}

_JATTA_EXPORT Jatta::PortAudio::OutputStream::OutputStream(Device device, std::vector<Float32*> data, UInt32 length, UInt32 sr)
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    if (data.size() > device.GetMaxOutputChannels())
        streamData.NumberOfChannels = device.GetMaxOutputChannels();
    else
        streamData.NumberOfChannels = data.size();

    sampleRate = sr;
    framesPerBuffer = paFramesPerBufferUnspecified;

    for (unsigned int i = 0; i < streamData.NumberOfChannels; i++)
    {
        streamData.OutputChannels.push_back(data[i]);
    }
    streamData.CurrentPosition = 0;
    streamData.Length = length;

    OpenStream(device);
}

_JATTA_EXPORT Jatta::PortAudio::OutputStream::~OutputStream()
{
    Close();
}
