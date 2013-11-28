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

        //! @brief Initializes to (0, 0, 0).
        _JATTA_INLINE_DEFINE Vector3T();
        //! @brief Copies a vector into this vector.
        _JATTA_INLINE_DEFINE Vector3T(const Vector3T& copy);
        //! @brief Initializes all components to a given value.
        _JATTA_INLINE_DEFINE Vector3T(Type value);
        //! @brief Initializes the vector with individual component values.
        _JATTA_INLINE_DEFINE Vector3T(Type x, Type y, Type z);

        //! @brief Assigns another vector into this vector.
        _JATTA_INLINE_DEFINE Vector3T& operator=(const Vector3T& operand);
        //! @brief Accesses an individual component in this vector.
        _JATTA_INLINE_DEFINE Type& operator[](UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _JATTA_INLINE_DEFINE Type operator[](UInt32 index) const;
        //! @brief Gets the inverse of the vector.
        _JATTA_INLINE_DEFINE Vector3T operator-() const;
        //! @brief Checks if two vectors are @em exactly equal.
        _JATTA_INLINE_DEFINE bool operator==(const Vector3T& operand) const;
        //! @brief Checks if two vectors are not @em exactly equal.
        _JATTA_INLINE_DEFINE bool operator!=(const Vector3T& operand) const;
        //! @brief Performs component-based addition on two vectors.
        _JATTA_INLINE_DEFINE Vector3T operator+(const Vector3T& operand) const;
        //! @brief Adds the individual components of another vector to this vector's components.
        _JATTA_INLINE_DEFINE Vector3T& operator+=(const Vector3T& operand);
        //! @brief Performs component-based subtraction on two vectors.
        _JATTA_INLINE_DEFINE Vector3T operator-(const Vector3T& operand) const;
        //! @brief Subtracts the individual components of another vector from this vector's
        //! components.
        _JATTA_INLINE_DEFINE Vector3T& operator-=(const Vector3T& operand);
        //! @brief Performs component-based multiplication on two vectors.
        _JATTA_INLINE_DEFINE Vector3T operator*(Type operand) const;
        //! @brief Multiplies the individual components of another vector onto this vector's
        //! components.
        _JATTA_INLINE_DEFINE Vector3T& operator*=(Type operand);
        //! @brief Performs component-based division on two vectors.
        _JATTA_INLINE_DEFINE Vector3T operator/(Type operand) const;
        //! @brief Divides the individual components of another vector onto this vector's
        //! components.
        _JATTA_INLINE_DEFINE Vector3T& operator/=(Type operand);
        //! @brief An operator to output this vector on an output stream.
        _JATTA_INLINE_DEFINE std::ostream& operator<<(std::ostream& stream) const;

        //! @brief Accesses an individual component in this vector.
        _JATTA_INLINE_DEFINE Type& At(UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _JATTA_INLINE_DEFINE Type At(UInt32 index) const;

        //! @brief Sets all components to a given value.
        _JATTA_INLINE_DEFINE void Set(Type value);
        //! @brief Sets all components to the given values.
        _JATTA_INLINE_DEFINE void Set(Type x, Type y, Type z);

        //! @brief Clears the vector to (0, 0, 0).
        _JATTA_INLINE_DEFINE void Clear();

        //! @brief Performs a two dimensional swizzle.
        _JATTA_INLINE_DEFINE Vector2T< Type > Swizzle(UInt32 x, UInt32 y) const;
        //! @brief Performs a three dimensional swizzle.
        _JATTA_INLINE_DEFINE Vector3T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        //! @brief Performs a four dimensional swizzle.
        _JATTA_INLINE_DEFINE Vector4T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        //! @brief Normalizes the vector resulting in a length of 1.
        _JATTA_INLINE_DEFINE void Normalize();
        //! @brief Checks if the vector is normalizes within a given epsilon.
        _JATTA_INLINE_DEFINE Boolean IsNormalized(Type epsilon = 0.00001f) const;
        //! @brief Gets the magnitude of the vector.
        _JATTA_INLINE_DEFINE Type GetMagnitude() const;
        //! @brief Gets the squared magnitude of the vector.
        _JATTA_INLINE_DEFINE Type GetSquaredMagnitude() const;
        //! @brief Gets the manhattan magnitude of the vector.
        _JATTA_INLINE_DEFINE Type GetManhattanMagnitude() const;
        //! @brief Gets the distance between two vectors.
        _JATTA_INLINE_DEFINE Type GetDistance(const Vector3T& other) const;
        //! @brief Gets the squared distance between two vectors.
        _JATTA_INLINE_DEFINE Type GetSquaredDistance(const Vector3T& other) const;
        //! @brief Gets the manhattan distance between two vectors.
        _JATTA_INLINE_DEFINE Type GetManhattanDistance(const Vector3T& other) const;

        //! @brief Rounds down each component to the nearest whole number.
        _JATTA_INLINE_DEFINE void Floor();
        //! @brief Rounds each component to the nearest whole number.
        _JATTA_INLINE_DEFINE void Round();
        //! @brief Rounds up each component to the nearest whole number.
        _JATTA_INLINE_DEFINE void Ceil();

        //! @brief Returns a vector with each component rounded down.
        _JATTA_INLINE_DEFINE Vector3T Floored();
        //! @brief Returns a vector with each component rounded.
        _JATTA_INLINE_DEFINE Vector3T Rounded();
        //! @brief Returns a vector with each component rounded up.
        _JATTA_INLINE_DEFINE Vector3T Ceiled();
    };

    typedef Vector3T< Float32 > Vector3;
    typedef Vector3T< Float64 > Vector3D;
}

#include "../External/Undefines.h"
#include "Vector3_Implement.hpp"
