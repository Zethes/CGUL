// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SawWave.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Stream.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class SawWave : public Stream
        {
        public:
            _CGUL_EXPORT SawWave(Device device);

            _CGUL_EXPORT virtual bool Update(StreamData* data);
        };
    }
}
#include "../External/Undefines.hpp"
