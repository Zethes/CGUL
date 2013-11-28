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
        class InputStream : public Stream
        {
        protected:
            _JATTA_EXPORT SInt32 OpenStream(Device device);
        public:
            _JATTA_EXPORT InputStream(Device device, bool (*callback)(std::vector<Float32*>, Jatta::UInt32, Stream*));
        };
    }
}
#include "../External/Undefines.h"