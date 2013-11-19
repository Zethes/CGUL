/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <cmath>

/** @details The absolute value is defined as the one dimensional distance of a value from 0.  In
 *  other words, the value is always positive.  A value of 5 results in 5, while a value of -4
 *  results in 4.
 *  @param x The number to get the absolute value of.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Abs(Float32 x)
{
    return (x > 0 ? x : -x);
}

/** @details The sign is determined based on if the number is positive, negative, or zero.  A
 *  positive value has a sign of 1, a negative value has a sign of -1, and zero has a sign of 0.
 *  @param x The number to get the sign of.
 *  @returns -1, 0, or 1
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Sign(Float32 x)
{
    return (x > 0 ? 1.0f : (x < 0.0f ? -1 : 0.0f));
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Cos(Float32 x)
{
    return std::cos(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Sin(Float32 x)
{
    return std::sin(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Tan(Float32 x)
{
    return std::tan(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Cosh(Float32 x)
{
    return std::cosh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Sinh(Float32 x)
{
    return std::sinh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Tanh(Float32 x)
{
    return std::tanh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::ACos(Float32 x)
{
    return std::acos(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::ASin(Float32 x)
{
    return std::asin(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::ATan(Float32 x)
{
    return std::atan(x);
}

_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::ATan2(Float32 y, Float32 x)
{
    return std::atan2(y, x);
}

#ifdef CPP_HAS_HYPERBOLIC
/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::ACosh(Float32 x)
{
    return std::acosh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::ASinh(Float32 x)
{
    return std::asinh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::ATanh(Float32 x)
{
    return std::atanh(x);
}
#endif

/** @param deg A value in degrees.
 *  @returns The resulting value in radians.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::DegToRad(Float32 deg)
{
    return deg / 180.0f * pi;
}

_JATTA_INLINE_IMPLEMENT Jatta::Vector2 Jatta::Math::DegToRad(const Vector2& deg)
{
    return Vector2(DegToRad(deg.x), DegToRad(deg.y));
}

_JATTA_INLINE_IMPLEMENT Jatta::Vector3 Jatta::Math::DegToRad(const Vector3& deg)
{
    return Vector3(DegToRad(deg.x), DegToRad(deg.y), DegToRad(deg.z));
}

_JATTA_INLINE_IMPLEMENT Jatta::Vector4 Jatta::Math::DegToRad(const Vector4& deg)
{
    return Vector4(DegToRad(deg.x), DegToRad(deg.y), DegToRad(deg.z), DegToRad(deg.w));
}

/** @param deg A value in radians.
 *  @returns The resulting value in degrees.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::RadToDeg(Float32 rad)
{
    return rad * (180.0f / pi);
}

_JATTA_INLINE_IMPLEMENT Jatta::Vector2 Jatta::Math::RadToDeg(const Vector2& rad)
{
    return Vector2(RadToDeg(rad.x), RadToDeg(rad.y));
}

_JATTA_INLINE_IMPLEMENT Jatta::Vector3 Jatta::Math::RadToDeg(const Vector3& rad)
{
    return Vector3(RadToDeg(rad.x), DegToRad(rad.y), RadToDeg(rad.z));
}

_JATTA_INLINE_IMPLEMENT Jatta::Vector4 Jatta::Math::RadToDeg(const Vector4& rad)
{
    return Vector4(RadToDeg(rad.x), RadToDeg(rad.y), RadToDeg(rad.z), RadToDeg(rad.w));
}

_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Ln(Float32 x)
{
    return std::log(x);
}

_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Log(Float32 x, Float32 b)
{
    return std::log(x) / std::log(b); //Change of base: log(x,b) = ln(x)/ln(b)
}

/** @param a The first value.
 *  @param b The second value.
 *  @returns The smaller of the two values.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Min(Float32 a, Float32 b)
{
    return (a < b ? a : b);
}

/** @param a The first value.
 *  @param b The second value.
 *  @returns The larger of the two values.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Max(Float32 a, Float32 b)
{
    return (a > b ? a : b);
}

/** @param x The number to round.
 *  @return The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Floor(Float32 x)
{
    return std::floor(x);
}

/** @param x The number to round.
 *  @return The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Round(Float32 x)
{
    return std::floor(x + 0.5f);
}

/** @param x The number to round.
 *  @return The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Ceil(Float32 x)
{
    return std::ceil(x);
}

/** @details The modulus is the remainder of long division, but can be useful for floating point
 *  numbers as well.  The resulting value maintains the signage of the dividend.  See @ref Sign.
 *  @param x The dividend.
 *  @param div The divisor.
 *  @returns The resulting value.
 *  @see Sign
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Mod(Float32 x, Float32 div)
{
    return Math::Abs(x - Math::Floor(x / div) * div) * Math::Sign(x);
}

/** @details The square of a number is simply that number multiplied by itself.
 *  @param x The number to square.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Sqr(Float32 x)
{
    return x * x;
}

/** @warning The square root function can be slow!
 *  @param x The number to find the square root of.
 *  @returns The resulting value.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Sqrt(Float32 x)
{
    return std::sqrt(x);
}

/** @details Due to floating point inprecision, it is often difficult to determine when two values
 *  @em should be exactly equal.  A common technique used is to check if, within a given epsilon
 *  (some really small number), the two numbers are @em nearly equal.
 *  @param value The first value.
 *  @param compare A value to compare.
 *  @param epsilon The maximum difference between the values.  Usually something really small like 0.00001f.
 *  @returns True if the two values are within the given epsilon, false otherwise.
 */
_JATTA_INLINE_IMPLEMENT bool Jatta::Math::InEpsilon(Float32 value, Float32 compare, Float32 epsilon)
{
    return (Math::Abs(value - compare) <= epsilon);
}

/** @param x The base value.
 *  @param y The exponent value.
 *  @returns x raised to the power of y.
 */
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Math::Pow(Float32 x, Float32 y)
{
    return std::pow(x, y);
}

/** @details The zero case is handled correctly.  Passing in zero for x will result in false.
 *  @param x Value to check.
 *  @returns True if x is a power of 2, false otherwise.
 */
_JATTA_INLINE_IMPLEMENT bool Jatta::Math::IsPowerOfTwo(UInt32 x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}
