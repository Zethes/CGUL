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
    data->LeftPhase += 0.01f;
    if (data->LeftPhase >= 1.0f) data->LeftPhase -= 2.0f;

    data->RightPhase += 0.03f;
    if (data->RightPhase >= 1.0f) data->RightPhase -= 2.0f;

    return true;
}
