/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
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
        _JATTA_INLINE_DEFINE static float UniformDist(float a, float b, float u);
        _JATTA_INLINE_DEFINE static float ExponentialDist(float beta, float u);
        _JATTA_INLINE_DEFINE static float WeibullDist(float a, float b, float c, float u);
        _JATTA_INLINE_DEFINE static float TriangularDist(float xmin, float xmax, float c, float u);
        _JATTA_INLINE_DEFINE static float Normal(float mean, float variance, float x);

        _JATTA_INLINE_DEFINE Random();
        _JATTA_INLINE_DEFINE Random(unsigned int seed);
        _JATTA_INLINE_DEFINE Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus);

        _JATTA_INLINE_DEFINE void SetSeed(unsigned int seed);

        _JATTA_INLINE_DEFINE unsigned int GetInteger();
        _JATTA_INLINE_DEFINE float GetDecimal();

        _JATTA_INLINE_DEFINE float GetUniform(float a, float b);
        _JATTA_INLINE_DEFINE float GetExponential(float beta);
        _JATTA_INLINE_DEFINE float GetWeibull(float a, float b, float c);

        // TODO: clean this up and maybe add functionality
    };
}

#include "../External/Undefines.h"
