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
        static float uniformDist(float a, float b, float u);
        static float exponentialDist(float beta, float u);
        static float weibullDist(float a, float b, float c, float u);
        static float triangularDist(float xmin, float xmax, float c, float u);
        static float normal(float mean, float variance, float x);

        Random();
        Random(unsigned int seed);
        Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus);

        unsigned int getInteger();
        float getDecimal();

        float getUniform(float a, float b);
        float getExponential(float beta);
        float getWeibull(float a, float b, float c);
        float getNormal(float mean, float variance);
    };
}

#include "../External/Undefines.h"