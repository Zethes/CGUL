/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "InputStream.h"
#include <cstdio>

static int paCallbackInput(const void* inputBuffer, void* output, unsigned long fpb, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags flags, void* udata)
{
    Jatta::PortAudio::StreamData* data = (Jatta::PortAudio::StreamData*)udata;
    (void) output;

    const float *rptr = (const float*)inputBuffer;
    std::vector<Jatta::Float32*> inputData;

    unsigned int i, j;
    int ret = paContinue;

    for (i = 0; i < data->NumberOfChannels; i++)
        inputData.push_back(new Jatta::Float32[fpb]);

    if (inputBuffer == NULL)
    {
        for (i = 0; i < fpb; i++)
        {
            for (j = 0; j < data->NumberOfChannels; j++)
                inputData.at(j)[i] = 0.0f;
        }
    }
    else
    {
        for (i = 0; i < fpb; i++)
        {
            for (j = 0; j < data->NumberOfChannels; j++)
                inputData.at(j)[i] = 1.0f*(*rptr++); //data->StreamPtr->GetVolume()
        }
    }
    data->Length++;

    if (!data->inputCallback(inputData, fpb, data->StreamPtr))
    {
        ret = paComplete;
    }

    //Clean-up
    /*for (i = 0; i < data->NumberOfChannels; i++)
        delete[] inputData.at(i);
    inputData.clear();*/

    return ret;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::InputStream::OpenStream(Device device)
{
    if (sampleRate == 0)
    {
        sampleRate = device.GetDefaultSampleRate();
    }

    PaStreamParameters inputParameters;
    inputParameters.device = device.GetIndex();
    inputParameters.channelCount = streamData.NumberOfChannels;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = device.GetDefaultLowInputLatency();
    inputParameters.hostApiSpecificStreamInfo = NULL;

    return Pa_OpenStream(
               &stream,
               &inputParameters,
               NULL,
               sampleRate,
               framesPerBuffer,
               paClipOff,
               paCallbackInput,
               &streamData);
}


_JATTA_EXPORT Jatta::PortAudio::InputStream::InputStream(Device device, bool (*callback)(std::vector<Float32*>, Jatta::UInt32, Stream*))
{
    volume = 1.0f;
    streamData.StreamPtr = this;
    streamData.NumberOfChannels = 1;

    sampleRate = 0;
    framesPerBuffer = 512;

    streamData.CurrentPosition = 0;
    streamData.Length = 0;
    streamData.inputCallback = callback;
    OpenStream(device);
}