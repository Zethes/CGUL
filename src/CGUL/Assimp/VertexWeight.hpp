// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file VertexWeight.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Vector3.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class VertexWeight
        {
        private:
            _CGUL_AIVERTEXWEIGHT weight;
        public:
            _CGUL_EXPORT VertexWeight(_CGUL_AIVERTEXWEIGHT weight);

            _CGUL_EXPORT UInt32 GetVertexId();
            _CGUL_EXPORT Float32 GetWeight();
        };
    }
}

#include "../External/Undefines.hpp"
