// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Random.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A linear congruential generator capable of generating pseudorandom numbers.
     *  @details This class works similarly to C++'s built in rand() function but provides more
     *  control (and thus more room for error).  Also included are common probability
     *  distributions.
     *  @todo Redo distributions since they are largely untested.
     */
    class Random
    {
        UInt32 seed;
        UInt32 multiplier;
        UInt32 addition;
        UInt32 modulus;
    public:
        _CGUL_INLINE_DEFINE static Float32 UniformDist(Float32 a, Float32 b, Float32 u);
        _CGUL_INLINE_DEFINE static Float32 ExponentialDist(Float32 beta, Float32 u);
        _CGUL_INLINE_DEFINE static Float32 WeibullDist(Float32 a, Float32 b, Float32 c, Float32 u);
        _CGUL_INLINE_DEFINE static Float32 TriangularDist(Float32 xmin, Float32 xmax, Float32 c, Float32 u);
        _CGUL_INLINE_DEFINE static Float32 Normal(Float32 mean, Float32 variance, Float32 x);

        _CGUL_INLINE_DEFINE Random();
        _CGUL_INLINE_DEFINE Random(UInt32 seed);
        _CGUL_INLINE_DEFINE Random(UInt32 seed, UInt32 multiplier, UInt32 addition, UInt32 modulus);

        _CGUL_INLINE_DEFINE void SetSeed(UInt32 seed);

        _CGUL_INLINE_DEFINE UInt32 GetInteger();
        _CGUL_INLINE_DEFINE Float32 GetDecimal();

        _CGUL_INLINE_DEFINE Float32 GetUniform(Float32 a, Float32 b);
        _CGUL_INLINE_DEFINE Float32 GetExponential(Float32 beta);
        _CGUL_INLINE_DEFINE Float32 GetWeibull(Float32 a, Float32 b, Float32 c);

        // TODO: clean this up and maybe add functionality
    };
}

#include "../External/Undefines.hpp"
#include "Random_Implement.hpp"
