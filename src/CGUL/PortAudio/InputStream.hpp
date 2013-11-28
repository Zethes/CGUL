// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file InputStream.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Stream.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class InputStream : public Stream
        {
        protected:
            _CGUL_EXPORT SInt32 OpenStream(Device device);
        public:
            _CGUL_EXPORT InputStream(Device device, bool (*callback)(std::vector<Float32*>, UInt32, Stream*));
        };
    }
}
#include "../External/Undefines.hpp"
