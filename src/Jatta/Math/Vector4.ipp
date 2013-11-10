/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Vector4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix.h"

#include <cmath>

_JATTA_EXPORT Jatta::Vector4::Vector4()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

_JATTA_EXPORT Jatta::Vector4::Vector4(const Vector4& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    this->w = copy.w;
}

_JATTA_EXPORT Jatta::Vector4::Vector4(float value)
{
    this->x = value;
    this->y = value;
    this->z = value;
    this->w = value;
}

_JATTA_EXPORT Jatta::Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float& Jatta::Vector4::operator[](UInt32 index)
{
    return m[index];
}

_JATTA_EXPORT Jatta::Vector4 Jatta::Vector4::operator*(const Matrix& operand) const
{
    return Vector4(x * operand.m[0][0] + y * operand.m[1][0] + z * operand.m[2][0] + w * operand.m[3][0],
                  x * operand.m[0][1] + y * operand.m[1][1] + z * operand.m[2][1] + w * operand.m[3][1],
                  x * operand.m[0][2] + y * operand.m[1][2] + z * operand.m[2][2] + w * operand.m[3][2],
                  x * operand.m[0][3] + y * operand.m[1][3] + z * operand.m[2][3] + w * operand.m[3][3]);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Vector4::At(UInt32 index) const
{
    return m[index];
}

_JATTA_EXPORT void Jatta::Vector4::Set(Float32 value)
{
    this->x = value;
    this->y = value;
    this->z = value;
    this->w = value;
}

_JATTA_EXPORT void Jatta::Vector4::Set(Float32 x, Float32 y, Float32 z, Float32 w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

_JATTA_EXPORT Jatta::Vector2 Jatta::Vector4::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2(m[x], m[y]);
}

_JATTA_EXPORT Jatta::Vector3 Jatta::Vector4::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3(m[x], m[y], m[z]);
}

_JATTA_EXPORT Jatta::Vector4 Jatta::Vector4::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4(m[x], m[y], m[z], m[w]);
}

_JATTA_EXPORT void Jatta::Vector4::Normalize()
{
    float inverseMagnitude = 1.0f / GetMagnitude();
    x *= inverseMagnitude;
    y *= inverseMagnitude;
    z *= inverseMagnitude;
    w *= inverseMagnitude;
}

_JATTA_EXPORT float Jatta::Vector4::GetMagnitude()
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}
