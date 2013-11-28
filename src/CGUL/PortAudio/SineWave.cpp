// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SineWave.cpp
 */

#include "SineWave.hpp"

_CGUL_EXPORT CGUL::PortAudio::SineWave::SineWave(Device device) : Stream()
{
    for (unsigned int i = 0; i < 200; i++)
    {
        sine[i] = (float)CGUL::Math::Sin(((double)i/200.0)*CGUL::Math::pi * 2.0);
    }
    position = 0;

    framesPerBuffer = 64;

    OpenStream(device);
}

_CGUL_EXPORT bool CGUL::PortAudio::SineWave::Update(StreamData* data)
{
    data->Channels[0] = sine[position];
    data->Channels[1] = sine[position];

    position++;
    while (position >= 199)
    {
        position -= 200;
    }

    return true;
}
