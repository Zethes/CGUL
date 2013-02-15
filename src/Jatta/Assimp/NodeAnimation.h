/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Float3.h"
#include "../Math/Matrix.h"
#include "../Math/Quaternion.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        namespace AnimationStates
        {
            enum
            {
                DEFAULT = 0x0,
                CONSTANT,
                LINEAR,
                REPEAT
            };
        }

        struct VectorKey
        {
            double time;
            Jatta::Float3 value;
        };

        struct QuatKey
        {
            double time;
            Jatta::Quaternion value;
        };

        class NodeAnimation
        {
        private:
            _JATTA_AINODEANIM nodeAnim;
        public:
            _JATTA_EXPORT NodeAnimation(_JATTA_AINODEANIM nodeAnim);
    
            _JATTA_EXPORT Jatta::String GetName();
            _JATTA_EXPORT Jatta::UInt32 GetPositionKeyCount();
            _JATTA_EXPORT Jatta::UInt32 GetRotationKeyCount();
            _JATTA_EXPORT Jatta::UInt32 GetScalingKeyCount();

            _JATTA_EXPORT Jatta::UInt32 GetPreState();
            _JATTA_EXPORT Jatta::UInt32 GetPostState();

            _JATTA_EXPORT VectorKey* GetPositionKeys();
            _JATTA_EXPORT QuatKey* GetRotationKeys();
            _JATTA_EXPORT VectorKey* GetScalingKeys();
        };
    }
}

#include "../External/Undefines.h"
