/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Vector3.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        struct VectorKey
        {
            double time;
            Jatta::Vector3 value;
        };
    }
}

#include "../External/Undefines.h"
