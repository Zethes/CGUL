/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

#ifdef CPP_HAS_FUNCTION_TEMPLATE_DEFAULT
#   define _JATTA_DEFAULT_MATH_TYPE = Jatta::Float32
#else
#   define _JATTA_DEFAULT_MATH_TYPE
#endif

namespace Jatta
{
    /** @brief A namespace containing many common mathematical functions.
     *  @details Some mathematical concepts were ruthlessly stolen from MathGeoLib.  Be sure to
     *  check it out as an awesome standalone math library!
     *  http://clb.demon.fi/MathGeoLib/nightly/reference.html
     */
    namespace Math
    {
        //! @brief The constant Tau, defined as 6.2831853071795864 (or 2 * pi)
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Tau();

        //! @brief The constant Pi, defined as 3.14159265358979323 (or tau / 2)
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Pi();

        //! @brief The constant e, defined as 2.718281828459045235
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type E();

        //! @brief Calculates the absolute value of x.
        template< typename ReturnType _JATTA_DEFAULT_MATH_TYPE, typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE ReturnType Abs(Type x);
        //! @brief Gets the sign of the value, returning -1, 0, or 1.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Sign(Type x);

        //! @brief Calculates the cosine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Cos(Type x);
        //! @brief Calculates the sine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Sin(Type x);
        //! @brief Calculates the tangent of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Tan(Type x);

        //! @brief Calculates the hyperbolic cosine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Cosh(Type x);
        //! @brief Calculates the hyperbolic sine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Sinh(Type x);
        //! @brief Calculates the hyperbolic tangent of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Tanh(Type x);

        //! @brief Calculates the arc cosine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type ACos(Type x);
        //! @brief Calculates the arc sine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type ASin(Type x);
        //! @brief Calculates the arc tangent of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type ATan(Type x);

        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type ATan2(Type y, Type x);

#       ifdef CPP_HAS_HYPERBOLIC
        //! @brief Calculates the hyperbolic arc cosine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type ACosh(Type x);
        //! @brief Calculates the hyperbolic arc sine of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type ASinh(Type x);
        //! @brief Calculates the hyperbolic arc tangent of x.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type ATanh(Type x);
#       endif

        //! @brief Converts degrees to radians.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type DegToRad(Type deg);
        //! @brief Converts radians to degrees.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type RadToDeg(Type rad);

        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Ln(Type x);
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Log(Type x, Type b = 10);

        //! @brief Finds the smaller of the two values.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Min(Type a, Type b);
        //! @brief Finds the larger of the two values.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Max(Type a, Type b);

        //! @brief Rounds the number down.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Floor(Type x);
        //! @brief Rounds the number.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Round(Type x);
        //! @brief Rounds the number up.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Ceil(Type x);

        //! @brief A modulus function that works with floating point numbers.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Mod(Type x, Type div);

        //! @brief Calculates the square of a number.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Sqr(Type x);
        //! @brief Calculates the square root of a number.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE Type Sqrt(Type x);

        //! @brief Checks if two values are equal within a given epsilon.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE bool InEpsilon(Type value, Type compare, Type epsilon);

        //! @brief Raises x to the power of y.
        template< typename Type _JATTA_DEFAULT_MATH_TYPE >
        _JATTA_INLINE_DEFINE bool Pow(Type x, Type y);

        //! @brief Checks if the value is a power of two.
        _JATTA_INLINE_DEFINE bool IsPowerOfTwo(UInt32 x);

        // TODO: add some more frequently used math functions (maybe reference .NET's math lib?)
    }
}

#include "../External/Undefines.h"

#include "Math.ipp"
