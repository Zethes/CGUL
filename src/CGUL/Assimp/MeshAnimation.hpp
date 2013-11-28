// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MeshAnimation.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Matrix.hpp"
#include "../Math/Quaternion.hpp"
#include "../Math/Vector3.hpp"
#include "../Utility/String.hpp"
#include "MeshKey.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class MeshAnimation
        {
        private:
            _CGUL_AIMESHANIM meshAnim;
        public:
            _CGUL_EXPORT MeshAnimation(_CGUL_AIMESHANIM meshAnim);

            _CGUL_EXPORT String GetName();
            _CGUL_EXPORT UInt32 GetKeyCount();
            _CGUL_EXPORT MeshKey* GetKeys();
        };
    }
}

#include "../External/Undefines.hpp"
