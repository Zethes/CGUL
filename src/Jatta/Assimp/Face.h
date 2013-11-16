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
        class Face
        {
            _JATTA_AIFACE face;
        public:
            _JATTA_EXPORT Face();
            _JATTA_EXPORT Face(_JATTA_AIFACE face);

            _JATTA_EXPORT Jatta::UInt32 GetIndicesCount();
            _JATTA_EXPORT Jatta::UInt32* GetIndices();
        };
    }
}

#include "../External/Undefines.h"
