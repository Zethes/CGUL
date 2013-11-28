// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file StreamInfo.cpp
 */

#include "StreamInfo.hpp"

_CGUL_EXPORT CGUL::PortAudio::StreamInfo::StreamInfo(const ::PaStreamInfo* info)
{
    this->info = info;
}

_CGUL_EXPORT double CGUL::PortAudio::StreamInfo::GetInputLatency()
{
    return info->inputLatency;
}

_CGUL_EXPORT double CGUL::PortAudio::StreamInfo::GetOutputLatency()
{
    return info->outputLatency;
}

_CGUL_EXPORT double CGUL::PortAudio::StreamInfo::GetSampleRate()
{
    return info->sampleRate;
}
