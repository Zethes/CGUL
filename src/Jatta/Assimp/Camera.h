/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#pragma once
#include "../Utility/String.h"
#include "../Math/Float3.h"
#include "../Assimp/Assimp.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        // TODO: finish importing methods from aiCamera
        class Camera
        {
            _JATTA_AICAMERA camera;
        public:
            _JATTA_EXPORT Camera(_JATTA_AICAMERA camera);

            String GetName();

            Float3 GetLookAt();
            Float3 GetPosition();
            Float3 GetUp();

            Float32 GetAspectRatio();
            Float32 GetClipPlaneFar();
            Float32 GetClipPlaneNear();
            Float32 GetFieldOfView();
        };
    }
}

#include "../External/Undefines.h"
#endif
