/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"

#include <cmath>

template< typename Type >
_JATTA_INLINE_IMPLEMENT Type Jatta::Vector3T< Type >::DotProduct(const Vector3T& valueA, const Vector3T& valueB)
{
    return (valueA.x * valueB.x) + (valueA.y * valueB.y) + (valueA.z * valueB.z);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector3T< Type >::CrossProduct(const Vector3T& valueA, const Vector3T& valueB)
{
    return Vector3T(valueA.y * valueB.z - valueA.z * valueB.y, valueA.z * valueB.x - valueA.x * valueB.z, valueA.x * valueB.y - valueA.y * valueB.x);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector3T< Type >::Normalized(const Vector3T& value)
{
    Type inverseMagnitude = 1.0f / value.GetMagnitude();
    return Vector3T(value.x * inverseMagnitude, value.y * inverseMagnitude, value.z * inverseMagnitude);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type >::Vector3T()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type >::Vector3T(const Vector3T& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type >::Vector3T(Type value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type >::Vector3T(Type x, Type y, Type z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::Vector3T< Type >::Normalize()
{
    Type inverseMagnitude = 1.0f / GetMagnitude();
    this->x *= inverseMagnitude;
    this->y *= inverseMagnitude;
    this->z *= inverseMagnitude;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector3T< Type >::operator-() const
{
    return Vector3(-this->x, -this->y, -this->z);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector3T< Type >::operator+(const Vector3T& operand) const
{
    return Vector3(this->x + operand.x, this->y + operand.y, this->z + operand.z);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type >& Jatta::Vector3T< Type >::operator+=(const Vector3T& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    this->z += operand.z;
    return *this;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector3T< Type >::operator-(const Vector3T& operand) const
{
    return Vector3(this->x - operand.x, this->y - operand.y, this->z - operand.z);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type >& Jatta::Vector3T< Type >::operator-=(const Vector3T& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    this->z -= operand.z;
    return *this;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector3T< Type >::operator*(Type operand) const
{
    return Vector3(this->x * operand, this->y * operand, this->z * operand);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type >& Jatta::Vector3T< Type >::operator*=(Type operand)
{
    this->x *= operand;
    this->y *= operand;
    this->z *= operand;
    return *this;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT bool Jatta::Vector3T< Type >::operator==(const Vector3T& operand) const
{
    return (this->x == operand.x && this->y == operand.y && this->z == operand.z);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Type Jatta::Vector3T< Type >::At(UInt32 index) const
{
    return m[index];
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::Vector3T< Type >::Set(Type value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT void Jatta::Vector3T< Type >::Set(Type x, Type y, Type z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector2T< Type > Jatta::Vector3T< Type >::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2T< Type >(m[x], m[y]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector3T< Type > Jatta::Vector3T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3T< Type >(m[x], m[y], m[z]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Jatta::Vector4T< Type > Jatta::Vector3T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4T< Type >(m[x], m[y], m[z], m[w]);
}

template< typename Type >
_JATTA_INLINE_IMPLEMENT Type Jatta::Vector3T< Type >::GetMagnitude() const
{
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}
