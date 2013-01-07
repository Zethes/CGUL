/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Float3.h"

#include <cmath>

_JATTA_EXPORT float Jatta::Float3::DotProduct(const Float3& valueA, const Float3& valueB)
{
    return (valueA.x * valueB.x) + (valueA.y * valueB.y) + (valueA.z * valueB.z);
}

_JATTA_EXPORT Jatta::Float3 Jatta::Float3::CrossProduct(const Float3& valueA, const Float3& valueB)
{
    return Float3(valueA.y * valueB.z - valueA.z * valueB.y, valueA.z * valueB.x - valueA.x * valueB.z, valueA.x * valueB.y - valueA.y * valueB.x);
}

_JATTA_EXPORT Jatta::Float3 Jatta::Float3::Normalized(const Float3& value)
{
    float inverseMagnitude = 1.0f / value.GetMagnitude();
    return Float3(value.x * inverseMagnitude, value.y * inverseMagnitude, value.z * inverseMagnitude);
}

_JATTA_EXPORT Jatta::Float3::Float3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

_JATTA_EXPORT Jatta::Float3::Float3(const Float3& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
}

_JATTA_EXPORT Jatta::Float3::Float3(float value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

_JATTA_EXPORT Jatta::Float3::Float3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

_JATTA_EXPORT void Jatta::Float3::Normalize()
{
    float inverseMagnitude = 1.0f / GetMagnitude();
    this->x *= inverseMagnitude;
    this->y *= inverseMagnitude;
    this->z *= inverseMagnitude;
}

_JATTA_EXPORT Jatta::Float3 Jatta::Float3::operator-() const
{
    return Float3(-this->x, -this->y, -this->z);
}

_JATTA_EXPORT Jatta::Float3 Jatta::Float3::operator+(const Float3& operand) const
{
    return Float3(this->x + operand.x, this->y + operand.y, this->z + operand.z);
}

_JATTA_EXPORT Jatta::Float3& Jatta::Float3::operator+=(const Float3& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    this->z += operand.z;
    return *this;
}

_JATTA_EXPORT Jatta::Float3 Jatta::Float3::operator-(const Float3& operand) const
{
    return Float3(this->x - operand.x, this->y - operand.y, this->z - operand.z);
}

_JATTA_EXPORT Jatta::Float3& Jatta::Float3::operator-=(const Float3& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    this->z -= operand.z;
    return *this;
}

_JATTA_EXPORT Jatta::Float3 Jatta::Float3::operator*(float operand) const
{
    return Float3(this->x * operand, this->y * operand, this->z * operand);
}

_JATTA_EXPORT Jatta::Float3& Jatta::Float3::operator*=(float operand)
{
    this->x *= operand;
    this->y *= operand;
    this->z *= operand;
    return *this;
}

_JATTA_EXPORT float Jatta::Float3::GetMagnitude() const
{
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}
