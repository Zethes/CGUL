// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Angle.hpp
 */

#include "Vector2.hpp"

namespace CGUL
{
    class Angle
    {
        CGUL::Float32 radians;
public:
        static Angle Inverse(const Angle& angle);
        static Angle Difference(const Angle& a, const Angle& b);
        static Angle Center(const Angle& a, const Angle& b);
        static Angle InverseCenter(const Angle& a, const Angle& b);
        static Angle Lerp(const Angle& from, const Angle& to, CGUL::Float32 t);

        Angle();
        Angle(CGUL::Float32 radians);
        Angle(const Vector2& direction);

        void SetRadians(CGUL::Float32 radians);
        CGUL::Float32 GetRadians() const;
        CGUL::Float32 GetRadiansPositive() const;

        void SetDegrees(CGUL::Float32 degrees);
        CGUL::Float32 GetDegrees() const;
        CGUL::Float32 GetDegreesPositive() const;

        void SetDirection(const Vector2& direction);
        Vector2 GetDirection() const;

        void Constrain(Angle from, Angle to);
    };
}
