// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MeshKey.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Matrix.hpp"
#include "../Math/Quaternion.hpp"
#include "../Math/Vector3.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        struct MeshKey
        {
            double time;
            UInt32 index;
        };
    }
}

#include "../External/Undefines.hpp"
