// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Random_Implement.hpp
 */

#include <ctime>
#include <cmath>

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::UniformDist(Float32 a, Float32 b, Float32 u)
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

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::ExponentialDist(Float32 beta, Float32 u)
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

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::WeibullDist(Float32 a, Float32 b, Float32 c, Float32 u)
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

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::TriangularDist(Float32 xmin, Float32 xmax, Float32 c, Float32 u)
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

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::Normal(Float32 mean, Float32 variance, Float32 x)
{
    return (1 / (Float32)std::sqrt(2 * 3.14159 * variance)) * std::exp(-(std::pow(x - mean, 2) / (2 * variance)));
}

_CGUL_INLINE_IMPLEMENT CGUL::Random::Random()
{
    this->seed = (UInt32)std::time(0);
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

_CGUL_INLINE_IMPLEMENT CGUL::Random::Random(UInt32 seed)
{
    this->seed = seed;
    this->multiplier = 16807;
    this->addition = 0;
    this->modulus = 2147483647;
}

_CGUL_INLINE_IMPLEMENT CGUL::Random::Random(UInt32 seed, UInt32 multiplier, UInt32 addition, UInt32 modulus)
{
    this->seed = seed;
    this->multiplier = multiplier;
    this->addition = addition;
    this->modulus = modulus;
}

_CGUL_INLINE_IMPLEMENT void CGUL::Random::SetSeed(UInt32 seed)
{
    this->seed = seed;
}

_CGUL_INLINE_IMPLEMENT CGUL::UInt32 CGUL::Random::GetInteger()
{
    seed = (multiplier * seed + addition) % modulus;
    return seed;
}

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::GetDecimal()
{
    return GetInteger() / Float32(modulus);
}

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::GetUniform(Float32 a, Float32 b)
{
    return GetDecimal() * (b - a) + a;
}

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::GetExponential(Float32 beta)
{
    return ExponentialDist(beta, GetDecimal());
}

_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::Random::GetWeibull(Float32 a, Float32 b, Float32 c)
{
    return WeibullDist(a, b, c, GetDecimal());
}
