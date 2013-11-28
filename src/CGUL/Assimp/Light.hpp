// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Light.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "LightTypes.hpp"
#include "../Utility/String.hpp"
#include "../Math/Vector3.hpp"
#include "../Images/Color.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Light
        {
            const _CGUL_AILIGHT light;
        public:
            _CGUL_EXPORT Light(_CGUL_AILIGHT light);

            _CGUL_EXPORT String GetName();

            _CGUL_EXPORT UInt32 GetType();

            _CGUL_EXPORT Vector3 GetPosition();
            _CGUL_EXPORT Vector3 GetDirection();
            _CGUL_EXPORT Float32 GetAngleInnerCone();
            _CGUL_EXPORT Float32 GetAngleOuterCone();

            _CGUL_EXPORT Float32 GetAttenuationConstant();
            _CGUL_EXPORT Float32 GetAttenuationLinear();
            _CGUL_EXPORT Float32 GetAttenuationQuadratic();

            _CGUL_EXPORT Color GetColorDiffuse();
            _CGUL_EXPORT Color GetColorSpecular();
            _CGUL_EXPORT Color GetColorAmbient();
        };
    }
}

#include "../External/Undefines.hpp"
