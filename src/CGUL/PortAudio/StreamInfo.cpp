/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "StreamInfo.h"

_JATTA_EXPORT Jatta::PortAudio::StreamInfo::StreamInfo(const ::PaStreamInfo* info)
{
    this->info = info;
}

_JATTA_EXPORT double Jatta::PortAudio::StreamInfo::GetInputLatency()
{
    return info->inputLatency;
}

_JATTA_EXPORT double Jatta::PortAudio::StreamInfo::GetOutputLatency()
{
    return info->outputLatency;
}

_JATTA_EXPORT double Jatta::PortAudio::StreamInfo::GetSampleRate()
{
    return info->sampleRate;
}
