// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SawWave.cpp
 */

#include "SawWave.h"

_CGUL_EXPORT CGUL::PortAudio::SawWave::SawWave(Device device) : Stream()
{
    OpenStream(device);
}

_CGUL_EXPORT bool CGUL::PortAudio::SawWave::Update(StreamData* data)
{
    data->Channels[0] += 0.01f;
    if (data->Channels[0] >= 1.0f)
    {
        data->Channels[0] -= 2.0f;
    }

    data->Channels[1] += 0.03f;
    if (data->Channels[1] >= 1.0f)
    {
        data->Channels[1] -= 2.0f;
    }

    return true;
}
