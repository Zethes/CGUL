// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file StreamData.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
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
            bool (*inputCallback)(std::vector<Float32*>, UInt32, Stream*);
        };
    }
}
#include "../External/Undefines.hpp"
