/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Float2.h"
#include "Float3.h"
#include "Float4.h"
#include "Math.h"

_JATTA_EXPORT const Jatta::Float2 zero(0, 0);
_JATTA_EXPORT const Jatta::Float2 one(1, 1);
_JATTA_EXPORT const Jatta::Float2 unitX(1, 0);
_JATTA_EXPORT const Jatta::Float2 unitY(0, 1);

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::FromAngle(Float32 angle, Float32 magnitude)
{
    return Jatta::Float2(Math::Cos(angle) * magnitude, Math::Sin(angle) * magnitude);
}

_JATTA_EXPORT Jatta::Float2::Float2()
{
    this->x = 0;
    this->y = 0;
}

_JATTA_EXPORT Jatta::Float2::Float2(const Float2& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}

_JATTA_EXPORT Jatta::Float2::Float2(float value)
{
    this->x = value;
    this->y = value;
}

_JATTA_EXPORT Jatta::Float2::Float2(float x, float y)
{
    this->x = x;
    this->y = y;
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator=(const Float2& operand)
{
    this->x = operand.x;
    this->y = operand.y;
    return *this;
}

_JATTA_EXPORT Jatta::Float32& Jatta::Float2::operator[](UInt32 index)
{
    return m[index];
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::operator[](UInt32 index) const
{
    return m[index];
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator-() const
{
    return Float2(-this->x, -this->y);
}

_JATTA_EXPORT bool Jatta::Float2::operator==(const Float2& operand) const
{
    return (this->x == operand.x && this->y == operand.y);
}

_JATTA_EXPORT bool Jatta::Float2::operator!=(const Float2& operand) const
{
    return (this->x != operand.x || this->y != operand.y);
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator+(const Float2& operand) const
{
    return Float2(this->x + operand.x, this->y + operand.y);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator+=(const Float2& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    return *this;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator-(const Float2& operand) const
{
    return Float2(this->x - operand.x, this->y - operand.y);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator-=(const Float2& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    return *this;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator*(float operand) const
{
    return Float2(this->x * operand, this->y * operand);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator*=(float operand)
{
    this->x *= operand;
    this->y *= operand;
    return *this;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator/(Float32 operand) const
{
    return Float2(this->x / operand, this->y / operand);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator/=(Float32 operand)
{
    this->x /= operand;
    this->y /= operand;
    return *this;
}

_JATTA_EXPORT std::ostream& operator<<(std::ostream& stream, const Jatta::Float2& vector)
{
    stream << "[" << vector.x << ", " << vector.y << "]";
    return stream;
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::At(UInt32 index) const
{
    return m[index];
}

_JATTA_EXPORT void Jatta::Float2::Set(Float32 value)
{
    this->x = value;
    this->y = value;
}

_JATTA_EXPORT void Jatta::Float2::Set(Float32 x, Float32 y)
{
    this->x = x;
    this->y = y;
}

_JATTA_EXPORT void Jatta::Float2::Clear()
{
    this->x = 0;
    this->y = 0;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::Swizzle(UInt32 x, UInt32 y) const
{
    return Float2(m[x], m[y]);
}

_JATTA_EXPORT Jatta::Float3 Jatta::Float2::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Float3(m[x], m[y], m[z]);
}

_JATTA_EXPORT Jatta::Float4 Jatta::Float2::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Float4(m[x], m[y], m[z], m[w]);
}

_JATTA_EXPORT void Jatta::Float2::Normalize()
{
    Float32 inverseMagnitude = 1.0f / GetMagnitude();
    x *= inverseMagnitude;
    y *= inverseMagnitude;
}

_JATTA_EXPORT Jatta::Boolean Jatta::Float2::IsNormalized(Float32 epsilon) const
{
    return Math::InEpsilon(GetMagnitude(), 1, epsilon);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::GetMagnitude() const
{
    return Math::Sqrt(x * x + y * y);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::GetMagnitudeSquared() const
{
    return (x * x + y * y);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::GetDistance(const Float2& other) const
{
    return Math::Sqrt(Math::Sqr(other.x - x) + Math::Sqr(other.y - y));
}

_JATTA_EXPORT void Jatta::Float2::SetAngle(Float32 angle)
{
    Float32 magnitude = GetMagnitude();
    x = Math::Cos(angle) * magnitude;
    y = Math::Sin(angle) * magnitude;
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::GetAngle() const
{
    return Math::ATan2(y, x);
}

_JATTA_EXPORT void Jatta::Float2::Floor()
{
    this->x = Math::Floor(this->x);
    this->y = Math::Floor(this->y);
}

_JATTA_EXPORT void Jatta::Float2::Round()
{
    this->x = Math::Round(this->x);
    this->y = Math::Round(this->y);
}

_JATTA_EXPORT void Jatta::Float2::Ceil()
{
    this->x = Math::Ceil(this->x);
    this->y = Math::Ceil(this->y);
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::Floored()
{
    return Float2(Math::Floor(this->x), Math::Floor(this->y));
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::Rounded()
{
    return Float2(Math::Round(this->x), Math::Round(this->y));
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::Ceiled()
{
    return Float2(Math::Ceil(this->x), Math::Ceil(this->y));
}