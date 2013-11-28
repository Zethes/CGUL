/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "QuatKey.h"
#include "AnimationStates.h"
#include "VectorKey.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
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
