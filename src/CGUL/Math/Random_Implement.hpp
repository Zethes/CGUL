// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Random_Implement.hpp
 */

#include <ctime>
#include <cmath>

_CGUL_INLINE_IMPLEMENT float CGUL::Random::UniformDist(float a, float b, float u)
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

_CGUL_INLINE_IMPLEMENT float CGUL::Random::ExponentialDist(float beta, float u)
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

_CGUL_INLINE_IMPLEMENT float CGUL::Random::WeibullDist(float a, float b, float c, float u)
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

_CGUL_INLINE_IMPLEMENT float CGUL::Random::TriangularDist(float xmin, float xmax, float c, float u)
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

_CGUL_INLINE_IMPLEMENT float CGUL::Random::Normal(float mean, float variance, float x)
{
    return (1 / (float)std::sqrt(2 * 3.14159 * variance)) * std::exp(-(std::pow(x - mean, 2) / (2 * variance)));
}

_CGUL_INLINE_IMPLEMENT CGUL::Random::Random()
{
    this->seed = (unsigned int)std::time(0);
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

_CGUL_INLINE_IMPLEMENT CGUL::Random::Random(unsigned int seed)
{
    this->seed = seed;
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

_CGUL_INLINE_IMPLEMENT CGUL::Random::Random(unsigned int seed, unsigned int multiplier, unsigned int addition, unsigned int modulus)
{
    this->seed = seed;
    this->multiplier = multiplier;
    this->addition = addition;
    this->modulus = modulus;
}

_CGUL_INLINE_IMPLEMENT void CGUL::Random::SetSeed(unsigned int seed)
{
    this->seed = seed;
}

_CGUL_INLINE_IMPLEMENT unsigned int CGUL::Random::GetInteger()
{
    seed = (multiplier * seed + addition) % modulus;
    return seed;
}

_CGUL_INLINE_IMPLEMENT float CGUL::Random::GetDecimal()
{
    return GetInteger() / float(modulus);
}

_CGUL_INLINE_IMPLEMENT float CGUL::Random::GetUniform(float a, float b)
{
    return GetDecimal() * (b - a) + a;
}

_CGUL_INLINE_IMPLEMENT float CGUL::Random::GetExponential(float beta)
{
    return ExponentialDist(beta, GetDecimal());
}

_CGUL_INLINE_IMPLEMENT float CGUL::Random::GetWeibull(float a, float b, float c)
{
    return WeibullDist(a, b, c, GetDecimal());
}
