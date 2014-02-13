// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Quaternion_Implement.hpp
 */

// CGUL Includes
#include "../Math/Math.hpp"
#include "../Math/Matrix.hpp"
#include "../Math/Vector2.hpp"
#include "../Math/Vector3.hpp"

template< typename Type >
_CGUL_INLINE_DEFINE CGUL::QuaternionT< Type > CGUL::QuaternionT< Type >::Lerp(const QuaternionT& from, const QuaternionT& to, Type t)
{
    QuaternionT< Type > q = from + (to - from) * t;
    q.Normalize();
    return q;
}

template< typename Type >
CGUL::QuaternionT< Type >::QuaternionT()
{
    w = 1;
    x = y = z = 0;
}

template< typename Type >
CGUL::QuaternionT< Type >::QuaternionT(const Vector3T< Type >& euler)
{
    w = Math::Cos(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0)) + Math::Sin(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0));
    x = Math::Sin(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0)) - Math::Cos(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0));
    y = Math::Cos(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0)) + Math::Sin(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0));
    z = Math::Cos(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0)) - Math::Sin(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0));
    Normalize();
}

template< typename Type >
CGUL::QuaternionT< Type >::QuaternionT(Type w, Type x, Type y, Type z)
{
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator*(const QuaternionT< Type >& operand) const
{
    return QuaternionT< Type >(w * operand.w - x * operand.x - y * operand.y - z * operand.z,
                               w * operand.x + x * operand.w + y * operand.z - z * operand.y,
                               w * operand.y - x * operand.z + y * operand.w + z * operand.x,
                               w * operand.z + x * operand.y - y * operand.x + z * operand.w);
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator*=(const QuaternionT& operand)
{
    *this = (*this) * operand;
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator*(Type operand) const
{
    return QuaternionT< Type >(w * operand,
                               x * operand,
                               y * operand,
                               z * operand);    
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator*=(Type operand)
{
    *this = (*this) * operand;
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator+(const QuaternionT< Type >& operand) const
{
    return QuaternionT< Type >(w + operand.w,
                               x + operand.x,
                               y + operand.y,
                               z + operand.z);
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator+=(const QuaternionT< Type >& operand)
{
    *this = (*this) + operand;
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator-(const QuaternionT< Type >& operand) const
{
    return QuaternionT< Type >(w - operand.w,
                               x - operand.x,
                               y - operand.y,
                               z - operand.z);
}

template< typename Type >
CGUL::QuaternionT< Type >& CGUL::QuaternionT< Type >::operator-=(const QuaternionT< Type >& operand)
{
    *this = (*this) - operand;
}

/** @brief Normalizes the quaternion.
 *  @details In theory, a quaternion should always be normalized.  Due to floating point
 *  inconsistencies, quaternions are hardly ever normalized.  It is imperative that a quaternion be
 *  normalized regularly.  Ideally, you would normalize a quaternion once per tick.
 *  @note "A de-normalized quaternion is NOT a happy quaternion and will cause you problems"
 *  -Professor Nicholson
 */
template< typename Type >
void CGUL::QuaternionT< Type >::Normalize()
{
    Type distance = w * w + x * x + y * y + z * z;
    if (distance == 0)
    {
        w = 1;
    }
    else
    {
        distance = 1.0 / Math::Sqrt(distance);
        w *= distance;
        x *= distance;
        y *= distance;
        z *= distance;
    }
}

template< typename Type >
void CGUL::QuaternionT< Type >::RotateOnAxis(const Vector3T< Type >& axis, Type angle)
{
    x = Math::Sin(angle / Type(2.0)) * axis.x;
    y = Math::Sin(angle / Type(2.0)) * axis.y;
    z = Math::Sin(angle / Type(2.0)) * axis.z;
    w = Math::Cos(angle / Type(2.0));
}


template< typename Type >
void CGUL::QuaternionT< Type >::Set(Type w, Type x, Type y, Type z)
{
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;   
}

template< typename Type >
void CGUL::QuaternionT< Type >::FromEuler(const Vector3T< Type >& euler)
{
    w = Math::Cos(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0)) + Math::Sin(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0));
    x = Math::Sin(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0)) - Math::Cos(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0));
    y = Math::Cos(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0)) + Math::Sin(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0));
    z = Math::Cos(euler.x / Type(2.0)) * Math::Cos(euler.y / Type(2.0)) * Math::Sin(euler.z / Type(2.0)) - Math::Sin(euler.x / Type(2.0)) * Math::Sin(euler.y / Type(2.0)) * Math::Cos(euler.z / Type(2.0));
    Normalize();
}

template< typename Type >
CGUL::Vector3T< Type > CGUL::QuaternionT< Type >::ToEuler()
{
    Type xx, yy, zz;

    xx = Math::ASin(Type(2.0) * (x * z - w * y));
    yy = Math::ATan2(Type(2.0) * x * w + Type(2.0) * y * z, Type(1.0) - Type(2.0) * (z*z + w*w));
    zz = Math::ATan2(Type(2.0) * x * y + Type(2.0) * z * w, Type(1.0) - Type(2.0) * (y*y + z*z));

    return Vector3T< Type >(xx, yy, zz);
}