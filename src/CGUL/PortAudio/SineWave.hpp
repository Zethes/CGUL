// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SineWave.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Stream.hpp"
#include "../Math/Math.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class SineWave : public Stream
        {
        private:
            Float32 sine[200];
            SInt32 position;
        public:
            _CGUL_EXPORT SineWave(Device device);

            _CGUL_EXPORT virtual bool Update(StreamData* data);
        };
    }
}
#include "../External/Undefines.hpp"
