//        JATTA        //
// by Joshua Brookover //

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
        _JATTA_EXPORT static float uniformDist(float a, float b, float u);
        _JATTA_EXPORT static float exponentialDist(float beta, float u);
        _JATTA_EXPORT static float weibullDist(float a, float b, float c, float u);
        _JATTA_EXPORT static float triangularDist(float xmin, float xmax, float c, float u);
        _JATTA_EXPORT static float normal(float mean, float variance, float x);

        _JATTA_EXPORT Random();
        _JATTA_EXPORT Random(unsigned int seed);
        _JATTA_EXPORT Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus);

        _JATTA_EXPORT unsigned int getInteger();
        _JATTA_EXPORT float getDecimal();

        _JATTA_EXPORT float getUniform(float a, float b);
        _JATTA_EXPORT float getExponential(float beta);
        _JATTA_EXPORT float getWeibull(float a, float b, float c);
        _JATTA_EXPORT float getNormal(float mean, float variance);
    };
}

#include "../External/Undefines.h"