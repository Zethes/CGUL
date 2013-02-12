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
        /** @brief 3D Axis Aligned Bounding Box
         */
        struct AABB3D
        {
            // TODO: this class
            Float3 position;
            Float3 extents;
            
            _JATTA_EXPORT AABB3D();
        };
    }
}

#include "../External/Undefines.h"