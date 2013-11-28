/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Vector2.h"
#include "../Assimp/Assimp.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class UVTransform
        {
            _JATTA_AIUVTRANSFORM uvTransform;
        public:
            _JATTA_EXPORT UVTransform(_JATTA_AIUVTRANSFORM uvTransform);

            _JATTA_EXPORT Vector2 GetTranslation();
            _JATTA_EXPORT Vector2 GetScaling();
            _JATTA_EXPORT Float32 GetRotation();
        };
    }
}

#include "../External/Undefines.h"
