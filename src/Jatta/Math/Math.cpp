/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Math.h"
#include <cmath>

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Abs(Float32 x)
{
    return std::abs(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Cos(Float32 x)
{
    return std::cos(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Sin(Float32 x)
{
    return std::sin(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Tan(Float32 x)
{
    return std::tan(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::ACos(Float32 x)
{
    return std::acos(x);
}
_JATTA_EXPORT Jatta::Float32 Jatta::Math::ASin(Float32 x)
{
    return std::asin(x);
}
_JATTA_EXPORT Jatta::Float32 Jatta::Math::ATan(Float32 x)
{
    return std::atan(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::DegToRad(Float32 deg)
{
    return deg / 180.0f * pi;
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::RadToDeg(Float32 rad)
{
    return rad * (180.0f / pi);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Min(Float32 a, Float32 b)
{
    return (a < b ? a : b);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Max(Float32 a, Float32 b)
{
    return (a > b ? a : b);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Floor(Float32 x)
{
    return std::floor(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Mod(Float32 x, Float32 div)
{
    return x - Math::Floor(x / 360.0f) * 360.0f;
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Sqrt(Float32 x)
{
    return std::sqrt(x);
}

_JATTA_EXPORT bool Jatta::Math::InEpsilon(Float32 value, Float32 compare, Float32 epsilon)
{
    return (Math::Abs(value - compare) <= epsilon);
}