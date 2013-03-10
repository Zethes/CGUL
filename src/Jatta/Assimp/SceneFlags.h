/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Assimp.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        enum SceneFlags
        {
            INCOMPLETE = 0x1,
            VALIDATED = 0x2,
            VALIDATION_WARNING = 0x4,
            NON_VERBOSE_FORMAT = 0x8,
            TERRAIN = 0x10
        };
    }
}

#include "../External/Undefines.h"