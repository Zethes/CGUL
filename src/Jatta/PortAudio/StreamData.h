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
        class Stream;

        struct StreamData
        {
        public:
            UInt32 CurrentPosition;
            UInt32 Length;
            UInt32 NumberOfChannels;
            std::vector<Float32*> OutputChannels;
            Stream* StreamPtr;
            bool (*inputCallback)(std::vector<Float32*>, Jatta::UInt32, Stream*);
        };
    }
}
#include "../External/Undefines.h"