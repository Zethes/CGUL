/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_AUDIO
#include "Stream.h"
#include "../Math/Math.h"

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 64
#define TABLE_SIZE 200

typedef struct
{
    float sine[TABLE_SIZE];
    int left_phase;
    int right_phase;
    Jatta::Audio::Stream* streamPtr;
}
SineData;

static int SineCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    SineData *data = (SineData*)userData;
    float *out = (float*)outputBuffer;
    unsigned long i;

    (void) timeInfo;
    (void) statusFlags;
    (void) inputBuffer;

    for (i = 0; i < framesPerBuffer; i++)
    {
        *out++ = data->streamPtr->GetVolume()*data->sine[data->left_phase];
        *out++ = data->streamPtr->GetVolume()*data->sine[data->right_phase];
        data->left_phase += 1;
        while (data->left_phase >= TABLE_SIZE-1) data->left_phase -= TABLE_SIZE;
        data->right_phase += 1;
        while (data->right_phase >= TABLE_SIZE-1) data->right_phase -= TABLE_SIZE;
    }

    return paContinue;
}

static void SineFinishedCallback(void * userData)
{
    SineData *data = (SineData*)userData;
    //TODO: Callback
}

_JATTA_EXPORT Jatta::Audio::AudioError Jatta::Audio::Stream::CreateSineWave()
{
    PaStreamParameters outputParameters;
    PaError err;
    SineData*data = new SineData();
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        data->sine[i] = (float)Jatta::Math::Sin(((double)i/200.0)*Jatta::Math::pi * 2.0);
    }
    data->left_phase = data->right_phase = 0;
    data->streamPtr = this;

    if (outDevice != nullptr)
        outputParameters.device = outDevice->GetIndex();
    else
        outputParameters.device = Pa_GetDefaultOutputDevice();
    if (outputParameters.device == paNoDevice)
    {
        return Errors::DEVICE_UNAVAILABLE;
    }
    outputParameters.channelCount = 2;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(
            &stream,
            NULL,
            &outputParameters,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff,
            SineCallback,
            data);
    if (err != paNoError)
    {
        return err;
    }

    err = Pa_SetStreamFinishedCallback(stream, &SineFinishedCallback);
    return err;
}
#endif
