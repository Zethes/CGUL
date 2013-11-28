// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Camera.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../Math/Vector3.hpp"
#include "../Assimp/Assimp.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Camera
        {
            _CGUL_AICAMERA camera;
        public:
            _CGUL_EXPORT Camera(_CGUL_AICAMERA camera);

            String GetName();

            Vector3 GetLookAt();
            Vector3 GetPosition();
            Vector3 GetUp();

            Float32 GetAspectRatio();
            Float32 GetClipPlaneFar();
            Float32 GetClipPlaneNear();
            Float32 GetFieldOfView();
        };
    }
}

#include "../External/Undefines.hpp"
