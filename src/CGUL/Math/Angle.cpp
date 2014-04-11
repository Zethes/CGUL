// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Angle.cpp
 */

#include "Angle.hpp"
#include "Math.hpp"
#include "Constants.hpp"

CGUL::Angle CGUL::Angle::Inverse(const Angle& angle)
{
    return Angle(angle.GetRadians() + (Float32)Math::Tau);
}

CGUL::Angle CGUL::Angle::Difference(const Angle& a, const Angle& b)
{
    return Angle(b.GetRadians() - a.GetRadians());
}

CGUL::Angle CGUL::Angle::Center(const Angle& a, const Angle& b)
{
    if (Difference(a, b).GetDegreesPositive() <= 180)
    {
        return Angle(a.GetRadians() + (Difference(a, b).GetRadians() * .5f));
    }
    else
    {
        return Inverse(Angle(a.GetRadians() + (Difference(a, b).GetRadians() * .5f)));
    }
}

CGUL::Angle CGUL::Angle::InverseCenter(const Angle& a, const Angle& b)
{
    return Inverse(Center(a, b));
}

CGUL::Angle CGUL::Angle::Lerp(const Angle& from, const Angle& to, CGUL::Float32 t)
{
    CGUL::Float32 v = from.GetDegrees() + (to.GetDegrees() - from.GetDegrees()) * t;
    while (v >= 360)
    {
        v -= 360;
    }
    while (v < 0)
    {
        v += 360;
    }

    Angle r;
    r.SetDegrees(v);
    return r;
}

CGUL::Angle::Angle()
{
    radians = 0.0f;
}

CGUL::Angle::Angle(CGUL::Float32 radians)
{
    SetRadians(radians);
}

CGUL::Angle::Angle(const Vector2F& direction)
{
    SetDirection(direction);
}

void CGUL::Angle::SetRadians(Float32 radians)
{
    this->radians = radians - Math::Floor(radians / (Float32)Math::Tau) * ((Float32)Math::Tau);
}

CGUL::Float32 CGUL::Angle::GetRadians() const
{
    if (this->radians > (Float32)Math::Pi)
    {
        return -((Float32)Math::Tau - radians);
    }
    else
    {
        return radians;
    }
}

CGUL::Float32 CGUL::Angle::GetRadiansPositive() const
{
    return radians;
}

void CGUL::Angle::SetDegrees(CGUL::Float32 degrees)
{
    SetRadians(Math::DegToRad(degrees));
}

CGUL::Float32 CGUL::Angle::GetDegrees() const
{
    return Math::RadToDeg(GetRadians());
}

CGUL::Float32 CGUL::Angle::GetDegreesPositive() const
{
    return Math::RadToDeg(GetRadiansPositive());
}

void CGUL::Angle::SetDirection(const Vector2F& direction)
{
    if (direction.GetSquaredMagnitude() == 1)
    {
        radians = Math::ATan2(direction.y, direction.x);
    }
    else
    {
        Vector2F dir = Vector2F::Normalized(direction);
        radians = Math::ATan2(dir.y, dir.x);
    }
}

CGUL::Vector2F CGUL::Angle::GetDirection() const
{
    return Vector2F(Math::Cos(radians), Math::Sin(radians));
}

void CGUL::Angle::Constrain(Angle from, Angle to)
{
    Angle mid = Center(from, to);

    if (Difference(from, *this).GetDegreesPositive() > Difference(from, to).GetDegreesPositive())
    {
        if (Difference(mid, *this).GetDegrees() < 0)
        {
            *this = from;
        }
        else
        {
            *this = to;
        }
    }
}
