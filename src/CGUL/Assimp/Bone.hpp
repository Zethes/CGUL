// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Bone.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "VertexWeight.hpp"
#include "../Math/Matrix.hpp"
#include "../Math/Vector3.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Bone
        {
        private:
            _CGUL_AIBONE bone;
        public:
            _CGUL_EXPORT Bone(_CGUL_AIBONE bone);

            _CGUL_EXPORT String GetName();
            _CGUL_EXPORT UInt32 GetWeightCount();
            _CGUL_EXPORT Assimp::VertexWeight GetWeight(CGUL::UInt32 id);
            _CGUL_EXPORT Matrix GetOffsetMatrix();
        };
    }
}

#include "../External/Undefines.hpp"
