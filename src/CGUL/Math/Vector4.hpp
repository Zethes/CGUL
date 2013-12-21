// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Vector4.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

// Without this here you would need a human sacrifice each time you wanted to use operator<<
namespace CGUL
{
    template< typename Type >
    struct Vector4T;
    template< typename Type >
    _CGUL_INLINE_DEFINE std::ostream& operator<<(std::ostream&, const CGUL::Vector4T< Type >&);
}

namespace CGUL
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

        _CGUL_INLINE_DEFINE static Type DotProduct(const Vector4T& valueA, const Vector4T& valueB);
        _CGUL_INLINE_DEFINE static Vector4T Normalized(const Vector4T& value);

        _CGUL_INLINE_DEFINE static Type Distance(const Vector4T& vectorA, const Vector4T& vectorB);
        _CGUL_INLINE_DEFINE static Type DistanceSquared(const Vector4T& valueA, const Vector4T& vectorB);
        _CGUL_INLINE_DEFINE static Type DistanceManhattan(const Vector4T& valueA, const Vector4T& vectorB);

        //! @brief Initializes to (0, 0, 0, 0).
        _CGUL_INLINE_DEFINE Vector4T();
        //! @brief Copies a vector into this vector.
        _CGUL_INLINE_DEFINE Vector4T(const Vector4T& copy);
        //! @brief Initializes all components to a given value.
        _CGUL_INLINE_DEFINE Vector4T(Type value);
        //! @brief Initializes the vector with individual component values.
        _CGUL_INLINE_DEFINE Vector4T(Type x, Type y, Type z, Type w);

        //! @brief Assigns another vector into this vector.
        _CGUL_INLINE_DEFINE Vector4T& operator=(const Vector4T& operand);
        //! @brief Accesses an individual component in this vector.
        _CGUL_INLINE_DEFINE Type& operator[](UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _CGUL_INLINE_DEFINE Type operator[](UInt32 index) const;
        //! @brief Gets the inverse of the vector.
        _CGUL_INLINE_DEFINE Vector4T operator-() const;
        //! @brief Checks if two vectors are @em exactly equal.
        _CGUL_INLINE_DEFINE bool operator==(const Vector4T& operand) const;
        //! @brief Checks if two vectors are not @em exactly equal.
        _CGUL_INLINE_DEFINE bool operator!=(const Vector4T& operand) const;
        //! @brief Performs component-based addition on two vectors.
        _CGUL_INLINE_DEFINE Vector4T operator+(const Vector4T& operand) const;
        //! @brief Adds the individual components of another vector to this vector's components.
        _CGUL_INLINE_DEFINE Vector4T& operator+=(const Vector4T& operand);
        //! @brief Performs component-based subtraction on two vectors.
        _CGUL_INLINE_DEFINE Vector4T operator-(const Vector4T& operand) const;
        //! @brief Subtracts the individual components of another vector from this vector's
        //! components.
        _CGUL_INLINE_DEFINE Vector4T& operator-=(const Vector4T& operand);
        //! @brief Performs component-based multiplication on two vectors.
        _CGUL_INLINE_DEFINE Vector4T operator*(Type operand) const;
        _CGUL_INLINE_DEFINE Vector4T operator*(const MatrixT< Type >& operand) const;
        //! @brief Multiplies the individual components of another vector onto this vector's
        //! components.
        _CGUL_INLINE_DEFINE Vector4T& operator*=(Type operand);
        _CGUL_INLINE_DEFINE Vector4T& operator*=(const MatrixT< Type >& operand);
        //! @brief Performs component-based division on two vectors.
        _CGUL_INLINE_DEFINE Vector4T operator/(Type operand) const;
        //! @brief Divides the individual components of another vector onto this vector's
        //! components.
        _CGUL_INLINE_DEFINE Vector4T& operator/=(Type operand);
        //! @brief An operator to output this vector on an output stream.
        friend std::ostream& operator<< <>(std::ostream& stream, const Vector4T< Type >& vector);
        template< typename OtherType >
        _CGUL_INLINE_DEFINE operator Vector4T< OtherType >();

        //! @brief Accesses an individual component in this vector.
        _CGUL_INLINE_DEFINE Type& At(UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _CGUL_INLINE_DEFINE Type At(UInt32 index) const;

        //! @brief Sets all components to a given value.
        _CGUL_INLINE_DEFINE void Set(Type value);
        //! @brief Sets all components to the given values.
        _CGUL_INLINE_DEFINE void Set(Type x, Type y, Type z, Type w);

        //! @brief Clears the vector to (0, 0, 0, 0).
        _CGUL_INLINE_DEFINE void Clear();

        //! @brief Performs a two dimensional swizzle.
        _CGUL_INLINE_DEFINE Vector2T< Type > Swizzle(UInt32 x, UInt32 y) const;
        //! @brief Performs a three dimensional swizzle.
        _CGUL_INLINE_DEFINE Vector3T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        //! @brief Performs a four dimensional swizzle.
        _CGUL_INLINE_DEFINE Vector4T< Type > Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        //! @brief Normalizes the vector resulting in a length of 1.
        _CGUL_INLINE_DEFINE void Normalize();
        //! @brief Checks if the vector is normalizes within a given epsilon.
        _CGUL_INLINE_DEFINE Boolean IsNormalized(Type epsilon = 0.00001f) const;
        //! @brief Gets the magnitude of the vector.
        _CGUL_INLINE_DEFINE Type GetMagnitude() const;
        //! @brief Gets the squared magnitude of the vector.
        _CGUL_INLINE_DEFINE Type GetSquaredMagnitude() const;
        //! @brief Gets the manhattan magnitude of the vector.
        _CGUL_INLINE_DEFINE Type GetManhattanMagnitude() const;
        //! @brief Gets the distance between two vectors.
        _CGUL_INLINE_DEFINE Type GetDistance(const Vector4T& other) const;
        //! @brief Gets the squared distance between two vectors.
        _CGUL_INLINE_DEFINE Type GetSquaredDistance(const Vector4T& other) const;
        //! @brief Gets the manhattan distance between two vectors.
        _CGUL_INLINE_DEFINE Type GetManhattanDistance(const Vector4T& other) const;

        //! @brief Rounds down each component to the nearest whole number.
        _CGUL_INLINE_DEFINE void Floor();
        //! @brief Rounds each component to the nearest whole number.
        _CGUL_INLINE_DEFINE void Round();
        //! @brief Rounds up each component to the nearest whole number.
        _CGUL_INLINE_DEFINE void Ceil();

        //! @brief Returns a vector with each component rounded down.
        _CGUL_INLINE_DEFINE Vector4T Floored() const;
        //! @brief Returns a vector with each component rounded.
        _CGUL_INLINE_DEFINE Vector4T Rounded() const;
        //! @brief Returns a vector with each component rounded up.
        _CGUL_INLINE_DEFINE Vector4T Ceiled() const;

        //! @brief Gets the sum of the elements.
        _CGUL_INLINE_DEFINE Type SumComponents() const;
        //! @brief Gets the product of the elements.
        _CGUL_INLINE_DEFINE Type MultiplyComponents() const;
    };

    typedef Vector4T< Float32 > Vector4;
    typedef Vector4T< Float32 > Vector4D;
    typedef Vector4T< SInt16  > SRect16;
    typedef Vector4T< SInt32  > SRect32;
    typedef Vector4T< SInt64  > SRect64;
    typedef Vector4T< UInt16  > URect16;
    typedef Vector4T< UInt32  > URect32;
    typedef Vector4T< UInt64  > URect64;
}

#include "../External/Undefines.hpp"
#include "Vector4_Implement.hpp"
