// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file AnimationStates.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        namespace AnimationStates
        {
            enum
            {
                DEFAULT = 0x0,
                CONSTANT,
                LINEAR,
                REPEAT
            };
        }
    }
}

#include "../External/Undefines.hpp"
