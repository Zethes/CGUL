// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file UVTransform.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Vector2.hpp"
#include "../Assimp/Assimp.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class UVTransform
        {
            _CGUL_AIUVTRANSFORM uvTransform;
        public:
            _CGUL_EXPORT UVTransform(_CGUL_AIUVTRANSFORM uvTransform);

            _CGUL_EXPORT Vector2 GetTranslation();
            _CGUL_EXPORT Vector2 GetScaling();
            _CGUL_EXPORT Float32 GetRotation();
        };
    }
}

#include "../External/Undefines.hpp"
