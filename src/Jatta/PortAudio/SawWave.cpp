/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "SawWave.h"

_JATTA_EXPORT Jatta::PortAudio::SawWave::SawWave(Device device) : Stream()
{
   OpenStream(device);
}

_JATTA_EXPORT bool Jatta::PortAudio::SawWave::Update(StreamData* data)
{
    data->Channels[0] += 0.01f;
    if (data->Channels[0] >= 1.0f) data->Channels[0] -= 2.0f;

    data->Channels[1] += 0.03f;
    if (data->Channels[1] >= 1.0f) data->Channels[1] -= 2.0f;

    return true;
}
