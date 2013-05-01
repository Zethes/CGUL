/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Math.h"
#include "Float2.h"
#include "Float3.h"
#include "Float4.h"
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

_JATTA_EXPORT Jatta::Float32 Jatta::Math::ACosh(Float32 x)
{
    return std::acosh(x);
}
_JATTA_EXPORT Jatta::Float32 Jatta::Math::ASinh(Float32 x)
{
    return std::asinh(x);
}
_JATTA_EXPORT Jatta::Float32 Jatta::Math::ATanh(Float32 x)
{
    return std::atanh(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::ATan2(Float32 y, Float32 x)
{
    return std::atan2(y, x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Cosh(Float32 x)
{
    return std::cosh(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Sinh(Float32 x)
{
    return std::sinh(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Tanh(Float32 x)
{
    return std::tanh(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::DegToRad(Float32 deg)
{
    return deg / 180.0f * pi;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Math::DegToRad(const Float2& deg)
{
    return Float2(DegToRad(deg.x), DegToRad(deg.y));
}

_JATTA_EXPORT Jatta::Float3 Jatta::Math::DegToRad(const Float3& deg)
{
    return Float3(DegToRad(deg.x), DegToRad(deg.y), DegToRad(deg.z));
}

_JATTA_EXPORT Jatta::Float4 Jatta::Math::DegToRad(const Float4& deg)
{
    return Float4(DegToRad(deg.x), DegToRad(deg.y), DegToRad(deg.z), DegToRad(deg.w));
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::RadToDeg(Float32 rad)
{
    return rad * (180.0f / pi);
}

_JATTA_EXPORT Jatta::Float2 Jatta::Math::RadToDeg(const Float2& rad)
{
    return Float2(RadToDeg(rad.x), RadToDeg(rad.y));
}

_JATTA_EXPORT Jatta::Float3 Jatta::Math::RadToDeg(const Float3& rad)
{
    return Float3(RadToDeg(rad.x), DegToRad(rad.y), RadToDeg(rad.z));
}

_JATTA_EXPORT Jatta::Float4 Jatta::Math::RadToDeg(const Float4& rad)
{
    return Float4(RadToDeg(rad.x), RadToDeg(rad.y), RadToDeg(rad.z), RadToDeg(rad.w));
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Ln(Float32 x)
{
    return std::log(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Log(Float32 x, Float32 b)
{
    return std::log(x) / std::log(b); //Change of base: log(x,b) = ln(x)/ln(b)
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Min(Float32 a, Float32 b)
{
    return (a < b ? a : b);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Max(Float32 a, Float32 b)
{
    return (a > b ? a : b);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Ceil(Float32 x)
{
    return std::ceil(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Floor(Float32 x)
{
    return std::floor(x);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Mod(Float32 x, Float32 div)
{
    return x - Math::Floor(x / 360.0f) * 360.0f;
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Sqr(Float32 x)
{
    return x * x;
}

_JATTA_EXPORT Jatta::Float32 Jatta::Math::Sqrt(Float32 x)
{
    return std::sqrt(x);
}

_JATTA_EXPORT bool Jatta::Math::InEpsilon(Float32 value, Float32 compare, Float32 epsilon)
{
    return (Math::Abs(value - compare) <= epsilon);
}
