/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Float3.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Collision
    {
        /** @brief 3D Sphere
          */
        struct Sphere
        {
            // TODO: this class
            Float3 position;
            Float32 radius;
            
            _JATTA_EXPORT Sphere();
        };
    }
}

#include "../External/Undefines.h"