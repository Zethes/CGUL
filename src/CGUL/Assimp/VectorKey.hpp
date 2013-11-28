// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file VectorKey.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Vector3.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        struct VectorKey
        {
            double time;
            Vector3 value;
        };
    }
}

#include "../External/Undefines.hpp"
