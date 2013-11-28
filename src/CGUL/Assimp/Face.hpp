// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Face.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Face
        {
            _CGUL_AIFACE face;
        public:
            _CGUL_EXPORT Face();
            _CGUL_EXPORT Face(_CGUL_AIFACE face);

            _CGUL_EXPORT UInt32 GetIndicesCount();
            _CGUL_EXPORT UInt32* GetIndices();
        };
    }
}

#include "../External/Undefines.hpp"
