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
        /** @brief 2D Circle
         */
        struct Circle
        {
            // TODO: this class
            Float2 position;
            Float32 radius;
            
            _JATTA_EXPORT Circle();
        };
    }
}

#include "../External/Undefines.h"