// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file StreamInfo.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class StreamInfo
        {
            const _CGUL_PASTREAM_INFO info;
        public:
            _CGUL_EXPORT StreamInfo(const _CGUL_PASTREAM_INFO info);

            _CGUL_EXPORT double GetInputLatency();
            _CGUL_EXPORT double GetOutputLatency();
            _CGUL_EXPORT double GetSampleRate();
        };
    }
}
#include "../External/Undefines.hpp"
