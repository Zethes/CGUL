// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Math_Implement.hpp
 */

// CGUL Includes
#include "../Exceptions/FatalException.hpp"
#include "../Math/Constants.hpp"
#include "../Math/Vector2.hpp"
#include "../Math/Vector3.hpp"
#include "../Math/Vector4.hpp"

// System Includes
#include <cmath>

/** @details The absolute value is defined as the one dimensional distance of a value from 0.  In
 *  other words, the value is always positive.  A value of 5 results in 5, while a value of -4
 *  results in 4.
 *  @param x The number to get the absolute value of.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Abs(Type x)
{
    return (x > 0 ? x : -x);
}

/** @details The sign is determined based on if the number is positive, negative, or zero.  A
 *  positive value has a sign of 1, a negative value has a sign of -1, and zero has a sign of 0.
 *  @param x The number to get the sign of.
 *  @returns -1, 0, or 1
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Sign(Type x)
{
    return (x > 0 ? 1.0f : (x < 0.0f ? -1 : 0.0f));
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Cos(Type x)
{
    return std::cos(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Sin(Type x)
{
    return std::sin(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Tan(Type x)
{
    return std::tan(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Cosh(Type x)
{
    return std::cosh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Sinh(Type x)
{
    return std::sinh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Tanh(Type x)
{
    return std::tanh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::ACos(Type x)
{
    return std::acos(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::ASin(Type x)
{
    return std::asin(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::ATan(Type x)
{
    return std::atan(x);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::ATan2(Type y, Type x)
{
    return std::atan2(y, x);
}

#ifdef CPP_HAS_HYPERBOLIC
/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::ACosh(Type x)
{
    return std::acosh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::ASinh(Type x)
{
    return std::asinh(x);
}

/** @param x The input value.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::ATanh(Type x)
{
    return std::atanh(x);
}
#endif

/** @param deg A value in degrees.
 *  @returns The resulting value in radians.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::DegToRad(Type deg)
{
    return deg / 180.0f * ((Type)Pi);
}

/** @param deg A value in radians.
 *  @returns The resulting value in degrees.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::RadToDeg(Type rad)
{
    return rad * (180.0f / ((Type)Pi));
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Ln(Type x)
{
    return std::log(x);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Log(Type x, Type b)
{
    return std::log(x) / std::log(b); //Change of base: log(x,b) = ln(x)/ln(b)
}

/** @param a The first value.
 *  @param b The second value.
 *  @returns The smaller of the two values.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Min(Type a, Type b)
{
    return (a < b ? a : b);
}

/** @param a The first value.
 *  @param b The second value.
 *  @param c The third value.
 *  @returns The smaller of the three values.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Min(Type a, Type b, Type c)
{
    return (a < b && a < c ? a : (b < c ? b : c));
}

/** @param a The first value.
 *  @param b The second value.
 *  @returns The larger of the two values.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Max(Type a, Type b)
{
    return (a > b ? a : b);
}

/** @param a The first value.
 *  @param b The second value.
 *  @param c The third value.
 *  @returns The larger of the three values.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Max(Type a, Type b, Type c)
{
    return (a > b && a > c ? a : (b > c ? b : c));
}

/** @param x The number to round.
 *  @return The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Floor(Type x)
{
    return std::floor(x);
}

/** @param x The number to round.
 *  @return The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Round(Type x)
{
    return std::floor(x + 0.5f);
}

/** @param x The number to round.
 *  @return The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Ceil(Type x)
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
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Mod(Type x, Type div)
{
    return Math::Abs(x - Math::Floor(x / div) * div) * Math::Sign(x);
}

/** @param x Value to clamp.
 *  @param min Minimum value for x.
 *  @param max Maximum value for x.
 *  @returns x or the clamped value.
 */
template< typename Type >
_CGUL_INLINE_DEFINE Type CGUL::Math::Clamp(Type x, Type min, Type max)
{
#   ifdef CGUL_SANITY_CHECK
    if (min > max)
    {
        throw FatalException(U8("Min value is greater than max for Math::Clamp."));
    }
#   endif
    if (x < min)
    {
        return min;
    }
    if (x > max)
    {
        return max;
    }
    return x;
}

/** @details The square of a number is simply that number multiplied by itself.
 *  @param x The number to square.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Sqr(Type x)
{
    return x * x;
}

/** @warning The square root function can be slow!
 *  @param x The number to find the square root of.
 *  @returns The resulting value.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Sqrt(Type x)
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
template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Math::InEpsilon(Type value, Type compare, Type epsilon)
{
    return (Math::Abs(value - compare) <= epsilon);
}

/** @param x The base value.
 *  @param y The exponent value.
 *  @returns x raised to the power of y.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Pow(Type x, Type y)
{
    return std::pow(x, y);
}

/** @param x The exponent value
 *  @returns e raised to the power of x.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::Exp(Type x)
{
    return Pow(((Type)E), x);
}

/** @details The zero case is handled correctly.  Passing in zero for x will result in false.
 *  @param x Value to check.
 *  @returns True if x is a power of 2, false otherwise.
 */
_CGUL_INLINE_IMPLEMENT bool CGUL::Math::IsPowerOfTwo(UInt32 x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Math::StandardDeviation(const FixedList< Type >& values, Type* mean)
{
    Type average = 0;
    for (Size i = 0, iEnd = values.GetSize(); i < iEnd; ++i)
    {
        average += values.Get(i);
    }
    average /= values.GetSize();

    if (mean != NULL)
    {
        *mean = average;
    }

    Type variance = 0;
    for (Size i = 0, iEnd = values.GetSize(); i < iEnd; ++i)
    {
        variance += Math::Sqr(values.Get(i) - average);
    }
    variance /= values.GetSize();
    return Math::Sqrt(variance);
}
