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
        class SawWave : public Stream
        {
        public:
            _JATTA_EXPORT SawWave(Device device);

            _JATTA_EXPORT virtual bool Update(StreamData* data);
        };
    }
}
#include "../External/Undefines.h"