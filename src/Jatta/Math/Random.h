/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Random
    {
        unsigned int seed;
        unsigned int multiplier;
        unsigned int addition;
        unsigned int modulus;
    public:
        _JATTA_EXPORT static float UniformDist(float a, float b, float u);
        _JATTA_EXPORT static float ExponentialDist(float beta, float u);
        _JATTA_EXPORT static float WeibullDist(float a, float b, float c, float u);
        _JATTA_EXPORT static float TriangularDist(float xmin, float xmax, float c, float u);
        _JATTA_EXPORT static float Normal(float mean, float variance, float x);

        _JATTA_EXPORT Random();
        _JATTA_EXPORT Random(unsigned int seed);
        _JATTA_EXPORT Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus);

        _JATTA_EXPORT unsigned int GetInteger();
        _JATTA_EXPORT float GetDecimal();

        _JATTA_EXPORT float GetUniform(float a, float b);
        _JATTA_EXPORT float GetExponential(float beta);
        _JATTA_EXPORT float GetWeibull(float a, float b, float c);
        _JATTA_EXPORT float GetNormal(float mean, float variance);

        // TODO: clean this up and maybe add functionality
    };
}

#include "../External/Undefines.h"
