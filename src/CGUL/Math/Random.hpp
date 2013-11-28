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
        unsigned int seed;
        unsigned int multiplier;
        unsigned int addition;
        unsigned int modulus;
    public:
        _CGUL_INLINE_DEFINE static float UniformDist(float a, float b, float u);
        _CGUL_INLINE_DEFINE static float ExponentialDist(float beta, float u);
        _CGUL_INLINE_DEFINE static float WeibullDist(float a, float b, float c, float u);
        _CGUL_INLINE_DEFINE static float TriangularDist(float xmin, float xmax, float c, float u);
        _CGUL_INLINE_DEFINE static float Normal(float mean, float variance, float x);

        _CGUL_INLINE_DEFINE Random();
        _CGUL_INLINE_DEFINE Random(unsigned int seed);
        _CGUL_INLINE_DEFINE Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus);

        _CGUL_INLINE_DEFINE void SetSeed(unsigned int seed);

        _CGUL_INLINE_DEFINE unsigned int GetInteger();
        _CGUL_INLINE_DEFINE float GetDecimal();

        _CGUL_INLINE_DEFINE float GetUniform(float a, float b);
        _CGUL_INLINE_DEFINE float GetExponential(float beta);
        _CGUL_INLINE_DEFINE float GetWeibull(float a, float b, float c);

        // TODO: clean this up and maybe add functionality
    };
}

#include "../External/Undefines.hpp"
