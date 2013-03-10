/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        enum LightTypes
        {
            UNDEFINED = 0x0,
            DIRECTIONAL = 0x1,
            POINT = 0x2,
            SPOT = 0x3
        };
    }
}

#include "../External/Undefines.h"