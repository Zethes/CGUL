/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Stream.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace PortAudio
    {
        class OutputStream : public Stream
        {
        protected:
            _JATTA_EXPORT virtual SInt32 OpenStream(Device device);
        public:
            _JATTA_EXPORT OutputStream(Device device);
            _JATTA_EXPORT OutputStream(Device device, Float32* data, UInt32 length, UInt32 sampleRate = 0); //Mono-sound
            _JATTA_EXPORT OutputStream(Device device, std::vector<Float32*> data, UInt32 length, UInt32 sampleRate = 0); //Channel specific sound (Stereo+)
            _JATTA_EXPORT OutputStream(const OutputStream& copy);
#           ifdef CPP_HAS_MOVE_CONSTRUCTOR
            _JATTA_EXPORT OutputStream(OutputStream&& move);
#           endif           
        };
    }
}
#include "../External/Undefines.h"