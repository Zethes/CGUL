/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Quaternion.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        struct QuatKey
        {
            double time;
            Jatta::Quaternion value;
        };
    }
}

#include "../External/Undefines.h"