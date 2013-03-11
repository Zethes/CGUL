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
            Float32 LeftPhase;
            Float32 RightPhase;
            Stream* StreamPtr;
        };
    }
}
#include "../External/Undefines.h"