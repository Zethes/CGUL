/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    template< typename Type >
    struct Vector2T;
    template< typename Type >
    struct Vector4T;

    /** @brief A three dimensional 32 bit floating point vector.
     *  @todo Template this to allow 64 bit floating point or integer as well?
     */
    template< typename Type >
    struct Vector3T
    {
        union
        {
            struct
            {
                Type x, y, z;
            };
            Type m[3];
        };

        //! @brief Zero vector, defined as (0, 0, 0).
        static const Vector3T zero;
        //! @brief One vector, defined as (1, 1, 1).
        static const Vector3T one;
        //! @brief Unit X vector, defined as (1, 0, 0).
        static const Vector3T unitX;
        //! @brief Unit Y vector, defined as (0, 1, 0).
        static const Vector3T unitY;
        //! @brief Unit Y vector, defined as (0, 0, 1).
        static const Vector3T unitZ;

        _JATTA_INLINE_DEFINE static Type DotProduct(const Vector3T& valueA, const Vector3T& valueB);
        _JATTA_INLINE_DEFINE static Vector3T CrossProduct(const Vector3T& valueA, const Vector3T& valueB);
        _JATTA_INLINE_DEFINE static Vector3T Normalized(const Vector3T& value);

        _JATTA_INLINE_DEFINE Vector3T();
        _JATTA_INLINE_DEFINE Vector3T(const Vector3T& copy);
        _JATTA_INLINE_DEFINE Vector3T(Type value);
        _JATTA_INLINE_DEFINE Vector3T(Type x, Type y, Type z);

        _JATTA_INLINE_DEFINE Vector3T operator-() const;
        _JATTA_INLINE_DEFINE Vector3T operator+(const Vector3T& operand) const;
        _JATTA_INLINE_DEFINE Vector3T& operator+=(const Vector3T& operand);
        _JATTA_INLINE_DEFINE Vector3T operator-(const Vector3T& operand) const;
        _JATTA_INLINE_DEFINE Vector3T& operator-=(const Vector3T& operand);
        _JATTA_INLINE_DEFINE Vector3T operator*(Type operand) const;
        _JATTA_INLINE_DEFINE Vector3T& operator*=(Type operand);
        //! @brief An operator to output this vector on an output stream.
        _JATTA_INLINE_DEFINE std::ostream& operator<<(std::ostream& stream) const;
        _JATTA_INLINE_DEFINE bool operator==(const Vector3T< Type >& operand) const;

        _JATTA_INLINE_DEFINE Type At(UInt32 index) const;

        _JATTA_INLINE_DEFINE void Set(Type value);
        _JATTA_INLINE_DEFINE void Set(Type x, Type y, Type z);

        _JATTA_INLINE_DEFINE Vector2T< Type > Swizzle(UInt32 x, UInt32 y) const;
        _JATTA_INLINE_DEFINE Vector3T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        _JATTA_INLINE_DEFINE Vector4T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        _JATTA_INLINE_DEFINE void Normalize();

        _JATTA_INLINE_DEFINE Type GetMagnitude() const;
    };

    typedef Vector3T< Float32 > Vector3;
    typedef Vector3T< Float64 > Vector3D;
}

#include "../External/Undefines.h"
#include "Vector3_Implement.hpp"
