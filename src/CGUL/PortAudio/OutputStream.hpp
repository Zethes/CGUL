// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OutputStream.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Stream.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class OutputStream : public Stream
        {
        protected:
            _CGUL_EXPORT virtual SInt32 OpenStream(Device device);
        public:
            _CGUL_EXPORT OutputStream(Device device);
            _CGUL_EXPORT OutputStream(Device device, Float32* data, UInt32 length, UInt32 sampleRate = 0); //Mono-sound
            _CGUL_EXPORT OutputStream(Device device, std::vector<Float32*> data, UInt32 length, UInt32 sampleRate = 0); //Channel specific sound (Stereo+)
            _CGUL_EXPORT OutputStream(const OutputStream& copy);
#           ifdef CPP_HAS_MOVE_CONSTRUCTOR
            _CGUL_EXPORT OutputStream(OutputStream&& move);
#           endif
        };
    }
}
#include "../External/Undefines.hpp"
