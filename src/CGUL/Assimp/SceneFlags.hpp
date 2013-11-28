// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SceneFlags.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Assimp.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        enum SceneFlags
        {
            INCOMPLETE = 0x1,
            VALIDATED = 0x2,
            VALIDATION_WARNING = 0x4,
            NON_VERBOSE_FORMAT = 0x8,
            TERRAIN = 0x10
        };
    }
}

#include "../External/Undefines.hpp"
