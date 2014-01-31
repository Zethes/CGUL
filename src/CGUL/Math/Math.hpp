// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Math.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Containers/FixedList.hpp"

// Defines
#include "../External/Defines.hpp"

//#ifdef CPP_HAS_FUNCTION_TEMPLATE_DEFAULT
//#   define _CGUL_DEFAULT_MATH_TYPE = CGUL::Float32
//#else
#   define _CGUL_DEFAULT_MATH_TYPE
//#endif

namespace CGUL
{
    /** @brief A namespace containing many common mathematical functions.
     *  @details Some mathematical concepts were ruthlessly stolen from MathGeoLib.  Be sure to
     *  check it out as an awesome standalone math library!
     *  http://clb.demon.fi/MathGeoLib/nightly/reference.html
     */
    namespace Math
    {
        //! @brief Calculates the absolute value of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Abs(Type x);
        //! @brief Gets the sign of the value, returning -1, 0, or 1.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Sign(Type x);

        //! @brief Calculates the cosine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Cos(Type x);
        //! @brief Calculates the sine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Sin(Type x);
        //! @brief Calculates the tangent of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Tan(Type x);

        //! @brief Calculates the hyperbolic cosine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Cosh(Type x);
        //! @brief Calculates the hyperbolic sine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Sinh(Type x);
        //! @brief Calculates the hyperbolic tangent of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Tanh(Type x);

        //! @brief Calculates the arc cosine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type ACos(Type x);
        //! @brief Calculates the arc sine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type ASin(Type x);
        //! @brief Calculates the arc tangent of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type ATan(Type x);

        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type ATan2(Type y, Type x);

#       ifdef CPP_HAS_HYPERBOLIC
        //! @brief Calculates the hyperbolic arc cosine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type ACosh(Type x);
        //! @brief Calculates the hyperbolic arc sine of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type ASinh(Type x);
        //! @brief Calculates the hyperbolic arc tangent of x.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type ATanh(Type x);
#       endif

        //! @brief Converts degrees to radians.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type DegToRad(Type deg);
        //! @brief Converts radians to degrees.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type RadToDeg(Type rad);

        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Ln(Type x);
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Log(Type x, Type b = 10);

        //! @brief Finds the smaller of the two values.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Min(Type a, Type b);
        //! @brief Finds the smaller of the three values.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Min(Type a, Type b, Type c);
        //! @brief Finds the larger of the two values.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Max(Type a, Type b);
        //! @brief Finds the larger of the three values.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Max(Type a, Type b, Type c);

        //! @brief Rounds the number down.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Floor(Type x);
        //! @brief Rounds the number.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Round(Type x);
        //! @brief Rounds the number up.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Ceil(Type x);

        //! @brief A modulus function that works with floating point numbers.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Mod(Type x, Type div);

        //! @brief Clamps the value between a minimum and maximum range.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Clamp(Type x, Type min, Type max);

        //! @brief Calculates the square of a number.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Sqr(Type x);
        //! @brief Calculates the square root of a number.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Sqrt(Type x);

        //! @brief Checks if two values are equal within a given epsilon.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE bool InEpsilon(Type value, Type compare, Type epsilon);

        //! @brief Raises x to the power of y.
        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Pow(Type x, Type y);    

        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type Exp(Type x);

        //! @brief Checks if the value is a power of two.
        _CGUL_INLINE_DEFINE bool IsPowerOfTwo(UInt32 x);

        template< typename Type _CGUL_DEFAULT_MATH_TYPE >
        _CGUL_INLINE_DEFINE Type StandardDeviation(const FixedList< Type >& values, Type* mean = NULL);

        // TODO: add some more frequently used math functions (maybe reference .NET's math lib?)
    }
}

// Undefines
#include "../External/Undefines.hpp"

// Implementation
#include "Math_Implement.hpp"
