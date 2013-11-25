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
    struct Vector3T;
    template< typename Type >
    struct MatrixT;

    /** @brief A four dimensional 32 bit floating point vector.
     *  @todo Template this to allow 64 bit floating point or integer as well?
     */
    template< typename Type >
    struct Vector4T
    {
        union
        {
            struct
            {
                Type x, y, z, w;
            };
            Type m[4];
        };

        //! @brief Zero vector, defined as (0, 0, 0, 0).
        static const Vector4T zero;
        //! @brief One vector, defined as (1, 1, 1, 1).
        static const Vector4T one;
        //! @brief Unit X vector, defined as (1, 0, 0, 0).
        static const Vector4T unitX;
        //! @brief Unit Y vector, defined as (0, 1, 0, 0).
        static const Vector4T unitY;
        //! @brief Unit Y vector, defined as (0, 0, 1, 0).
        static const Vector4T unitZ;
        //! @brief Unit Y vector, defined as (0, 0, 0, 1).
        static const Vector4T unitW;

        _JATTA_INLINE_DEFINE Vector4T();
        _JATTA_INLINE_DEFINE Vector4T(const Vector4T& copy);
        _JATTA_INLINE_DEFINE Vector4T(Type value);
        _JATTA_INLINE_DEFINE Vector4T(Type x, Type y, Type z, Type w);

        _JATTA_INLINE_DEFINE Type& operator[](UInt32 index);
        _JATTA_INLINE_DEFINE Vector4T operator*(const MatrixT< Type >& operand) const;
        //! @brief An operator to output this vector on an output stream.
        _JATTA_INLINE_DEFINE std::ostream& operator<<(std::ostream& stream) const;

        _JATTA_INLINE_DEFINE Jatta::Float32 At(UInt32 index) const;

        _JATTA_INLINE_DEFINE void Set(Float32 value);
        _JATTA_INLINE_DEFINE void Set(Float32 x, Float32 y, Float32 z, Float32 w);

        _JATTA_INLINE_DEFINE Vector2T< Type > Swizzle(UInt32 x, UInt32 y) const;
        _JATTA_INLINE_DEFINE Vector3T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        _JATTA_INLINE_DEFINE Vector4T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        _JATTA_INLINE_DEFINE void Normalize();

        _JATTA_INLINE_DEFINE Type GetMagnitude();
    };

    typedef Vector4T< Float32 > Vector4;
    typedef Vector4T< Float32 > Vector4D;
    typedef Vector4T< SInt16  > Rect16;
    typedef Vector4T< SInt32  > Rect32;
    typedef Vector4T< SInt64  > Rect64;
    typedef Vector4T< UInt16  > URect16;
    typedef Vector4T< UInt32  > URect32;
    typedef Vector4T< UInt64  > URect64;
}

#include "../External/Undefines.h"
#include "Vector4_Implement.hpp"
