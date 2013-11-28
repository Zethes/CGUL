// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file QuatKey.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Quaternion.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        struct QuatKey
        {
            double time;
            Quaternion value;
        };
    }
}

#include "../External/Undefines.hpp"
