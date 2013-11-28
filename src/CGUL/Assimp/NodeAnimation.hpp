// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file NodeAnimation.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "QuatKey.hpp"
#include "AnimationStates.hpp"
#include "VectorKey.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class NodeAnimation
        {
        private:
            _CGUL_AINODEANIM nodeAnim;
        public:
            _CGUL_EXPORT NodeAnimation(_CGUL_AINODEANIM nodeAnim);

            _CGUL_EXPORT String GetName();
            _CGUL_EXPORT UInt32 GetPositionKeyCount();
            _CGUL_EXPORT UInt32 GetRotationKeyCount();
            _CGUL_EXPORT UInt32 GetScalingKeyCount();

            _CGUL_EXPORT UInt32 GetPreState();
            _CGUL_EXPORT UInt32 GetPostState();

            _CGUL_EXPORT VectorKey* GetPositionKeys();
            _CGUL_EXPORT QuatKey* GetRotationKeys();
            _CGUL_EXPORT VectorKey* GetScalingKeys();
        };
    }
}

#include "../External/Undefines.hpp"
