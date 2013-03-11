/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "InputStream.h"
#include <cstdio>

static int paCallback(const void* input, void* output, unsigned long fpb, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags flags, void* udata)
{
    Jatta::PortAudio::StreamData* data = (Jatta::PortAudio::StreamData*)udata;
    (void) output;
    unsigned int i;
    const float *in = (const float*)input;

    for (i = 0; i < fpb; i++)
    {
        if (input == NULL)
        {
            for (unsigned int j = 0; j < data->NumberOfChannels; j++)
            { data->InputChannels[j] = 0.0f; }
        }
        else
        {
            for (unsigned int j = 0; j < data->NumberOfChannels; j++)
            { data->InputChannels[j] = data->StreamPtr->GetVolume()*(*in++); }
        }

        if (!data->StreamPtr->Update(data))
        {
            return paAbort;
        }
    }

    return paContinue;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::PortAudio::InputStream::OpenStream(Device device)
{
    if (sampleRate == 0)
    { sampleRate = device.GetDefaultSampleRate(); }

    data.InputChannels = new Float32[data.NumberOfChannels];
    for (unsigned int i = 0; i < data.NumberOfChannels; i++)
    { data.InputChannels[i] = 0.0f; } 

    PaStreamParameters inputParameters;
    inputParameters.device = device.GetIndex();
    inputParameters.channelCount = channelCount;
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
        paCallback,
        &data);
}


_JATTA_EXPORT Jatta::PortAudio::InputStream::InputStream(Device device) : Stream()
{
   OpenStream(device);

   inputs = new std::vector<Float32>[channelCount];
}

_JATTA_EXPORT bool Jatta::PortAudio::InputStream::Update(StreamData* data)
{
    for (unsigned int i = 0; i < channelCount; i++)
    {
        inputs[i].push_back(data->InputChannels[i]);
    }

    return true;
}

_JATTA_EXPORT Jatta::Float32 Jatta::PortAudio::InputStream::GetLastInput(int channel)
{
    return inputs[channel].back();
}
_JATTA_EXPORT std::vector<Jatta::Float32> Jatta::PortAudio::InputStream::GetInput(int channel)
{
    return inputs[channel];
}

_JATTA_EXPORT void Jatta::PortAudio::InputStream::ClearInput()
{
    for (unsigned int i = 0; i < channelCount; i++)
    {
        inputs[i].clear();
    }
}

_JATTA_EXPORT void Jatta::PortAudio::InputStream::WriteToRaw(const char* filename)
{
    FILE *fid;
    fid = fopen(filename, "wb");
    if (fid == NULL)
    {
        return;
    }
    
    for (unsigned int i = 0; i < inputs[0].size(); i++)
    {
        for (unsigned int j = 0; j < channelCount; j++)
        {
            fwrite(&inputs[j][i], sizeof(Float32), 1, fid);
        }
    }
    fclose(fid);
}