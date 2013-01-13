/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        class Mesh
        {
            _JATTA_AIMESH mesh;
        public:
            _JATTA_EXPORT Mesh(_JATTA_AIMESH mesh);
        };
    }
}

#include "../External/Undefines.h"