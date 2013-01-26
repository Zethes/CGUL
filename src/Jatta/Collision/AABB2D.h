/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../Math/Float2.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Collision
    {
        /** @brief 2D Axis Aligned Bounding Box
         */
        struct AABB2D
        {
            // TODO: this class
            Float2 position;
            Float2 extents;
            
            _JATTA_EXPORT AABB2D();
        };
    }
}

#include "../External/Undefines.h"