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
        namespace AnimationStates
        {
            enum
            {
                DEFAULT = 0x0,
                CONSTANT,
                LINEAR,
                REPEAT
            };
        }
    }
}

#include "../External/Undefines.h"