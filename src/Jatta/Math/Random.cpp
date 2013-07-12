/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Random.h"
#include <ctime>
#include <cmath>

_JATTA_EXPORT float Jatta::Random::UniformDist(float a, float b, float u)
{
    if (u < 0)
    {
        return a;
    }
    if (u > 1)
    {
        return b;
    }
    return u * (b - a) + a;
}

_JATTA_EXPORT float Jatta::Random::ExponentialDist(float beta, float u)
{
    if (u < 0)
    {
        u = 0;
    }
    if (u >= .99999f)
    {
        u = .99999f;
    }
    //return  -beta * std::log(u);
    return beta * std::log(-1 / (u - 1));
}

_JATTA_EXPORT float Jatta::Random::WeibullDist(float a, float b, float c, float u)
{
    if (u < 0)
    {
        u = 0;
    }
    if (u >= .99999f)
    {
        u = .99999f;
    }
    return b * std::pow(std::log(-1 / (u - 1)), 1 / c) + a;
}

_JATTA_EXPORT float Jatta::Random::TriangularDist(float xmin, float xmax, float c, float u)
{
    if (u < 0)
    {
        u = 0;
    }
    if (u > 1)
    {
        u = 1;
    }
    if (u < (c - xmin) / (xmax - xmin))
    {
        return sqrt(u * (xmin - xmax) * (xmin - c)) + xmin;
    }
    else
    {
        return xmax - std::sqrt((u - 1) * (xmin - xmax) * (xmax - c));
    }
}

_JATTA_EXPORT float Jatta::Random::Normal(float mean, float variance, float x)
{
    return (1 / (float)std::sqrt(2 * 3.14159 * variance)) * std::exp(-(std::pow(x - mean, 2) / (2 * variance)));
}

_JATTA_EXPORT Jatta::Random::Random()
{
    this->seed = (unsigned int)std::time(0);
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

_JATTA_EXPORT Jatta::Random::Random(unsigned int seed)
{
    this->seed = seed;
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

_JATTA_EXPORT Jatta::Random::Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus)
{
    this->seed = seed;
    this->multiplier = multiplier;
    this->addition = addition;
    this->modulus = modulus;
}

_JATTA_EXPORT void Jatta::Random::SetSeed(unsigned int seed)
{
    this->seed = seed;
}

_JATTA_EXPORT unsigned int Jatta::Random::GetInteger()
{
    seed = (multiplier * seed + addition) % modulus;
    return seed;
}

_JATTA_EXPORT float Jatta::Random::GetDecimal()
{
    return GetInteger() / float(modulus);
}

_JATTA_EXPORT float Jatta::Random::GetUniform(float a, float b)
{
    return GetDecimal() * (b - a) + a;
}

_JATTA_EXPORT float Jatta::Random::GetExponential(float beta)
{
    return ExponentialDist(beta, GetDecimal());
}

_JATTA_EXPORT float Jatta::Random::GetWeibull(float a, float b, float c)
{
    return WeibullDist(a, b, c, GetDecimal());
}
