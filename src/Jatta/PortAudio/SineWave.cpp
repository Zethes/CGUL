/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "SineWave.h"

_JATTA_EXPORT Jatta::PortAudio::SineWave::SineWave(Device device) : Stream()
{
    for (unsigned int i = 0; i < 200; i++)
    {
        sine[i] = (float)Jatta::Math::Sin(((double)i/200.0)*Jatta::Math::pi * 2.0);
    }
    position = 0;

    framesPerBuffer = 64;

    OpenStream(device);
}

_JATTA_EXPORT bool Jatta::PortAudio::SineWave::Update(StreamData* data)
{
    data->Channels[0] = sine[position];
    data->Channels[1] = sine[position];

    position++;
    while (position >= 199)
    { position -= 200; }

    return true;
}
