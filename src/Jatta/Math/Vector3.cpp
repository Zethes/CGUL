/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"

#include <cmath>

_JATTA_EXPORT float Jatta::Vector3::DotProduct(const Vector3& valueA, const Vector3& valueB)
{
    return (valueA.x * valueB.x) + (valueA.y * valueB.y) + (valueA.z * valueB.z);
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector3::CrossProduct(const Vector3& valueA, const Vector3& valueB)
{
    return Vector3(valueA.y * valueB.z - valueA.z * valueB.y, valueA.z * valueB.x - valueA.x * valueB.z, valueA.x * valueB.y - valueA.y * valueB.x);
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector3::Normalized(const Vector3& value)
{
    float inverseMagnitude = 1.0f / value.GetMagnitude();
    return Vector3(value.x * inverseMagnitude, value.y * inverseMagnitude, value.z * inverseMagnitude);
}

_JATTA_EXPORT Jatta::Vector3::Vector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

_JATTA_EXPORT Jatta::Vector3::Vector3(const Vector3& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
}

_JATTA_EXPORT Jatta::Vector3::Vector3(float value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

_JATTA_EXPORT Jatta::Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

_JATTA_EXPORT void Jatta::Vector3::Normalize()
{
    float inverseMagnitude = 1.0f / GetMagnitude();
    this->x *= inverseMagnitude;
    this->y *= inverseMagnitude;
    this->z *= inverseMagnitude;
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector3::operator-() const
{
    return Vector3(-this->x, -this->y, -this->z);
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector3::operator+(const Vector3& operand) const
{
    return Vector3(this->x + operand.x, this->y + operand.y, this->z + operand.z);
}

_JATTA_EXPORT Jatta::Vector3& Jatta::Vector3::operator+=(const Vector3& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    this->z += operand.z;
    return *this;
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector3::operator-(const Vector3& operand) const
{
    return Vector3(this->x - operand.x, this->y - operand.y, this->z - operand.z);
}

_JATTA_EXPORT Jatta::Vector3& Jatta::Vector3::operator-=(const Vector3& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    this->z -= operand.z;
    return *this;
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector3::operator*(float operand) const
{
    return Vector3(this->x * operand, this->y * operand, this->z * operand);
}

_JATTA_EXPORT Jatta::Vector3& Jatta::Vector3::operator*=(float operand)
{
    this->x *= operand;
    this->y *= operand;
    this->z *= operand;
    return *this;
}

_JATTA_EXPORT bool Jatta::Vector3::operator==(const Vector3& operand) const
{
    return (this->x == operand.x && this->y == operand.y && this->z == operand.z);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Vector3::At(UInt32 index) const
{
    return m[index];
}

_JATTA_EXPORT void Jatta::Vector3::Set(Float32 value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

_JATTA_EXPORT void Jatta::Vector3::Set(Float32 x, Float32 y, Float32 z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

_JATTA_EXPORT Jatta::Vector2 Jatta::Vector3::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2(m[x], m[y]);
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector3::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3(m[x], m[y], m[z]);
}

_JATTA_EXPORT Jatta::Vector4 Jatta::Vector3::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4(m[x], m[y], m[z], m[w]);
}

_JATTA_EXPORT float Jatta::Vector3::GetMagnitude() const
{
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}
