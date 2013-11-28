// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Animation.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "MeshAnimation.hpp"
#include "NodeAnimation.hpp"
#include "../Math/Matrix.hpp"
#include "../Math/Vector3.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Animation
        {
        private:
            _CGUL_AIANIMATION animation;
        public:
            _CGUL_EXPORT Animation(_CGUL_AIANIMATION animation);

            _CGUL_EXPORT String GetName();
            _CGUL_EXPORT double GetDuration();
            _CGUL_EXPORT double GetTicksPerSecond();
            _CGUL_EXPORT UInt32 GetChannelCount();
            _CGUL_EXPORT UInt32 GetMeshChannelCount();

            _CGUL_EXPORT NodeAnimation* GetChannels();
            _CGUL_EXPORT MeshAnimation* GetMeshChannels();
        };
    }
}

#include "../External/Undefines.hpp"
