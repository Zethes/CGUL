/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    struct Vector2;
    struct Vector3;
    struct Vector4;

    /** @brief A namespace containing many common mathematical functions.
     *  @details Some mathematical concepts were ruthlessly stolen from MathGeoLib.  Be sure to
     *  check it out as an awesome standalone math library!
     *  http://clb.demon.fi/MathGeoLib/nightly/reference.html
     */
    namespace Math
    {
        //! @brief The constant PI, defined as 3.14159f
        const Float32 pi = 3.14159f;
        //! @brief The constant e, defined as 2.71828f
        const Float32 e = 2.71828f;

        //! @brief Calculates the absolute value of x.
        _JATTA_EXPORT Float32 Abs(Float32 x);
        //! @brief Gets the sign of the value, returning -1, 0, or 1.
        _JATTA_EXPORT Float32 Sign(Float32 x);

        //! @brief Calculates the cosine of x.
        _JATTA_EXPORT Float32 Cos(Float32 x);
        //! @brief Calculates the sine of x.
        _JATTA_EXPORT Float32 Sin(Float32 x);
        //! @brief Calculates the tangent of x.
        _JATTA_EXPORT Float32 Tan(Float32 x);

        //! @brief Calculates the hyperbolic cosine of x.
        _JATTA_EXPORT Float32 Cosh(Float32 x);
        //! @brief Calculates the hyperbolic sine of x.
        _JATTA_EXPORT Float32 Sinh(Float32 x);
        //! @brief Calculates the hyperbolic tangent of x.
        _JATTA_EXPORT Float32 Tanh(Float32 x);

        //! @brief Calculates the arc cosine of x.
        _JATTA_EXPORT Float32 ACos(Float32 x);
        //! @brief Calculates the arc sine of x.
        _JATTA_EXPORT Float32 ASin(Float32 x);
        //! @brief Calculates the arc tangent of x.
        _JATTA_EXPORT Float32 ATan(Float32 x);

        _JATTA_EXPORT Float32 ATan2(Float32 y, Float32 x);

#       ifdef CPP_HAS_HYPERBOLIC
        //! @brief Calculates the hyperbolic arc cosine of x.
        _JATTA_EXPORT Float32 ACosh(Float32 x);
        //! @brief Calculates the hyperbolic arc sine of x.
        _JATTA_EXPORT Float32 ASinh(Float32 x);
        //! @brief Calculates the hyperbolic arc tangent of x.
        _JATTA_EXPORT Float32 ATanh(Float32 x);
#       endif

        //! @brief Converts degrees to radians.
        _JATTA_EXPORT Float32 DegToRad(Float32 deg);
        _JATTA_EXPORT Vector2 DegToRad(const Vector2& deg);
        _JATTA_EXPORT Vector3 DegToRad(const Vector3& deg);
        _JATTA_EXPORT Vector4 DegToRad(const Vector4& deg);
        //! @brief Converts radians to degrees.
        _JATTA_EXPORT Float32 RadToDeg(Float32 rad);
        _JATTA_EXPORT Vector2 RadToDeg(const Vector2& rad);
        _JATTA_EXPORT Vector3 RadToDeg(const Vector3& rad);
        _JATTA_EXPORT Vector4 RadToDeg(const Vector4& rad);

        _JATTA_EXPORT Float32 Ln(Float32 x);
        _JATTA_EXPORT Float32 Log(Float32 x, Float32 b = 10);

        //! @brief Finds the smaller of the two values.
        _JATTA_EXPORT Float32 Min(Float32 a, Float32 b);
        //! @brief Finds the larger of the two values.
        _JATTA_EXPORT Float32 Max(Float32 a, Float32 b);

        //! @brief Rounds the number down.
        _JATTA_EXPORT Float32 Floor(Float32 x);
        //! @brief Rounds the number.
        _JATTA_EXPORT Float32 Round(Float32 x);
        //! @brief Rounds the number up.
        _JATTA_EXPORT Float32 Ceil(Float32 x);

        //! @brief A modulus function that works with floating point numbers.
        _JATTA_EXPORT Float32 Mod(Float32 x, Float32 div);

        //! @brief Calculates the square of a number.
        _JATTA_EXPORT Float32 Sqr(Float32 x);
        //! @brief Calculates the square root of a number.
        _JATTA_EXPORT Float32 Sqrt(Float32 x);

        //! @brief Checks if two values are equal within a given epsilon.
        _JATTA_EXPORT bool InEpsilon(Float32 value, Float32 compare, Float32 epsilon);

        // TODO: add some more frequently used math functions (maybe reference .NET's math lib?)
    }
}

#include "../External/Undefines.h"
