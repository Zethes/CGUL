// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file LightTypes.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        enum LightTypes
        {
            UNDEFINED = 0x0,
            DIRECTIONAL = 0x1,
            POINT = 0x2,
            SPOT = 0x3
        };
    }
}

#include "../External/Undefines.hpp"
