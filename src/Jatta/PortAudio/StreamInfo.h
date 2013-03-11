/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    namespace PortAudio
    {
        class StreamInfo
        {
            const _JATTA_PASTREAM_INFO info;
        public:
            _JATTA_EXPORT StreamInfo(const _JATTA_PASTREAM_INFO info);

            _JATTA_EXPORT double GetInputLatency();
            _JATTA_EXPORT double GetOutputLatency();
            _JATTA_EXPORT double GetSampleRate();
        };
    }
}
#include "../External/Undefines.h"