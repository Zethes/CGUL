/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Matrix.hpp"

#include <cmath>

/**
 */
template< typename Type >
const Jatta::Vector4T< Type > Jatta::Vector4T< Type >::zero(0, 0, 0, 0);

/**
 */
template< typename Type >
const Jatta::Vector4T< Type > Jatta::Vector4T< Type >::one(1, 1, 1, 1);

/**
 */
template< typename Type >
const Jatta::Vector4T< Type > Jatta::Vector4T< Type >::unitX(1, 0, 0, 0);

/**
 */
template< typename Type >
const Jatta::Vector4T< Type > Jatta::Vector4T< Type >::unitY(0, 1, 0, 0);

/**
 */
template< typename Type >
const Jatta::Vector4T< Type > Jatta::Vector4T< Type >::unitZ(0, 0, 1, 0);

/**
 */
template< typename Type >
const Jatta::Vector4T< Type > Jatta::Vector4T< Type >::unitW(0, 0, 0, 1);

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector4T< Type >::Vector4T()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector4T< Type >::Vector4T(const Vector4T& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    this->w = copy.w;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector4T< Type >::Vector4T(Type value)
{
    this->x = value;
    this->y = value;
    this->z = value;
    this->w = value;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector4T< Type >::Vector4T(Type x, Type y, Type z, Type w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

template< typename Type >
Type& Jatta::Vector4T< Type >::operator[](UInt32 index)
{
    return m[index];
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector4T< Type > Jatta::Vector4T< Type >::operator*(const MatrixT< Type >& operand) const
{
    return Vector4(x * operand.m[0][0] + y * operand.m[1][0] + z * operand.m[2][0] + w * operand.m[3][0],
                   x * operand.m[0][1] + y * operand.m[1][1] + z * operand.m[2][1] + w * operand.m[3][1],
                   x * operand.m[0][2] + y * operand.m[1][2] + z * operand.m[2][2] + w * operand.m[3][2],
                   x * operand.m[0][3] + y * operand.m[1][3] + z * operand.m[2][3] + w * operand.m[3][3]);
}

/** @param stream The output stream.
 *  @returns A reference to the output stream.
 */
template< typename Type >
_JATTA_INLINE_IMPLEMENT std::ostream& Jatta::Vector4T< Type >::operator<<(std::ostream& stream) const
{
    stream << "[" << x << ", " << y << ", " << z << ", " << w << "]";
    return stream;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Float32 Jatta::Vector4T< Type >::At(UInt32 index) const
{
    return m[index];
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::Vector4T< Type >::Set(Float32 value)
{
    this->x = value;
    this->y = value;
    this->z = value;
    this->w = value;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::Vector4T< Type >::Set(Float32 x, Float32 y, Float32 z, Float32 w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector2T< Type > Jatta::Vector4T< Type >::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2(m[x], m[y]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector4T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3(m[x], m[y], m[z]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector4T< Type > Jatta::Vector4T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4(m[x], m[y], m[z], m[w]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::Vector4T< Type >::Normalize()
{
    Type inverseMagnitude = 1.0f / GetMagnitude();
    x *= inverseMagnitude;
    y *= inverseMagnitude;
    z *= inverseMagnitude;
    w *= inverseMagnitude;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Type Jatta::Vector4T< Type >::GetMagnitude()
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}
