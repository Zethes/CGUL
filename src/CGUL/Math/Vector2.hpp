// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Vector2.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

// Without this here you would need a human sacrifice each time you wanted to use operator<<
namespace CGUL
{
    template< typename Type >
    struct Vector2T;
    template< typename Type >
    _CGUL_INLINE_DEFINE std::ostream& operator<<(std::ostream&, const CGUL::Vector2T< Type >&);
}

namespace CGUL
{
    template< typename Type >
    struct Vector3T;
    template< typename Type >
    struct Vector4T;
    template< typename Type >
    struct MatrixT;

    /** @brief A two dimensional 32 bit floating point vector.
     *  @todo Template this to allow 64 bit floating point or integer as well?
     */
    template< typename Type >
    struct Vector2T
    {
        //! @brief The x component.
        Type x;
        //! @brief The y component.
        Type y;

        //! @brief Zero vector, defined as (0, 0).
        static const Vector2T zero;
        //! @brief One vector, defined as (1, 1).
        static const Vector2T one;
        //! @brief Unit X vector, defined as (1, 0).
        static const Vector2T unitX;
        //! @brief Unit Y vector, defined as (0, 1).
        static const Vector2T unitY;
        //! @brief NaN vector, defined as (NaN, NaN).
        static const Vector2T nan;

        //! @brief Creates a vector based on a given two dimensional angle with an optional
        //! magnitude.
        _CGUL_INLINE_DEFINE static Vector2T FromAngle(Type angle, Type magnitude = 1.0f);

        _CGUL_INLINE_DEFINE static Type DotProduct(const Vector2T& valueA, const Vector2T& valueB);
        _CGUL_INLINE_DEFINE static Type CrossProduct(const Vector2T& valueA, const Vector2T& valueB);
        _CGUL_INLINE_DEFINE static Vector2T Normalized(const Vector2T& value);

        _CGUL_INLINE_DEFINE static Type Distance(const Vector2T& vectorA, const Vector2T& vectorB);
        _CGUL_INLINE_DEFINE static Type DistanceSquared(const Vector2T& valueA, const Vector2T& vectorB);
        _CGUL_INLINE_DEFINE static Type DistanceManhattan(const Vector2T& valueA, const Vector2T& vectorB);

        //! @brief Performs linear interpolation on a vector2
        _CGUL_INLINE_DEFINE static Vector2T Lerp(const Vector2T& from, const Vector2T& to, Type t);

        //! @brief Initializes to (0, 0).
        _CGUL_INLINE_DEFINE Vector2T();
        //! @brief Copies a vector into this vector.
        _CGUL_INLINE_DEFINE Vector2T(const Vector2T& copy);
        //! @brief Initializes all components to a given value.
        _CGUL_INLINE_DEFINE Vector2T(Type value);
        //! @brief Initializes the vector with individual component values.
        _CGUL_INLINE_DEFINE Vector2T(Type x, Type y);

        //! @brief Assigns another vector into this vector.
        _CGUL_INLINE_DEFINE Vector2T& operator=(const Vector2T& operand);
        //! @brief Accesses an individual component in this vector.
        _CGUL_INLINE_DEFINE Type& operator[](UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _CGUL_INLINE_DEFINE Type operator[](UInt32 index) const;
        //! @brief Gets the inverse of the vector.
        _CGUL_INLINE_DEFINE Vector2T operator-() const;
        //! @brief Checks if two vectors are @em exactly equal.
        _CGUL_INLINE_DEFINE bool operator==(const Vector2T& operand) const;
        //! @brief Checks if two vectors are not @em exactly equal.
        _CGUL_INLINE_DEFINE bool operator!=(const Vector2T& operand) const;
        //! @brief Performs component-based addition on two vectors.
        _CGUL_INLINE_DEFINE Vector2T operator+(const Vector2T& operand) const;
        //! @brief Adds the individual components of another vector to this vector's components.
        _CGUL_INLINE_DEFINE Vector2T& operator+=(const Vector2T& operand);
        //! @brief Performs component-based subtraction on two vectors.
        _CGUL_INLINE_DEFINE Vector2T operator-(const Vector2T& operand) const;
        //! @brief Subtracts the individual components of another vector from this vector's
        //! components.
        _CGUL_INLINE_DEFINE Vector2T& operator-=(const Vector2T& operand);
        //! @brief Performs component-based multiplication on two vectors.
        _CGUL_INLINE_DEFINE Vector2T operator*(Type operand) const;
        _CGUL_INLINE_DEFINE Vector2T operator*(const MatrixT< Type >& operand) const;
        //! @brief Multiplies the individual components of another vector onto this vector's
        //! components.
        _CGUL_INLINE_DEFINE Vector2T& operator*=(Type operand);
        _CGUL_INLINE_DEFINE Vector2T& operator*=(const MatrixT< Type >& operand);
        //! @brief Performs component-based division on two vectors.
        _CGUL_INLINE_DEFINE Vector2T operator/(Type operand) const;
        //! @brief Divides the individual components of another vector onto this vector's
        //! components.
        _CGUL_INLINE_DEFINE Vector2T& operator/=(Type operand);
        //! @brief An operator to output this vector on an output stream.
        friend std::ostream& operator<< <>(std::ostream& stream, const Vector2T< Type >& vector);
        template< typename OtherType >
        _CGUL_INLINE_DEFINE operator Vector2T< OtherType >();

        //! @brief Accesses an individual component in this vector.
        _CGUL_INLINE_DEFINE Type& At(UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _CGUL_INLINE_DEFINE Type At(UInt32 index) const;

        //! @brief Sets all components to a given value.
        _CGUL_INLINE_DEFINE void Set(Type value);
        //! @brief Sets all components to the given values.
        _CGUL_INLINE_DEFINE void Set(Type x, Type y);

        //! @brief Clears the vector to (0, 0).
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
        _CGUL_INLINE_DEFINE Type GetDistance(const Vector2T& other) const;
        //! @brief Gets the squared distance between two vectors.
        _CGUL_INLINE_DEFINE Type GetSquaredDistance(const Vector2T& other) const;
        //! @brief Gets the manhattan distance between two vectors.
        _CGUL_INLINE_DEFINE Type GetManhattanDistance(const Vector2T& other) const;

        //! @brief Sets the two dimensional angle of the vector.
        _CGUL_INLINE_DEFINE void SetAngle(Type angle);
        //! @brief Gets the two dimensional angle of the vector.
        _CGUL_INLINE_DEFINE Type GetAngle() const;

        //! @brief Gets a vector perpendicular to this one.
        _CGUL_INLINE_DEFINE Vector2T GetPerpendicular() const;

        //! @brief Rounds down each component to the nearest whole number.
        _CGUL_INLINE_DEFINE void Floor();
        //! @brief Rounds each component to the nearest whole number.
        _CGUL_INLINE_DEFINE void Round();
        //! @brief Rounds up each component to the nearest whole number.
        _CGUL_INLINE_DEFINE void Ceil();

        //! @brief Returns a vector with each component rounded down.
        _CGUL_INLINE_DEFINE Vector2T Floored() const;
        //! @brief Returns a vector with each component rounded.
        _CGUL_INLINE_DEFINE Vector2T Rounded() const;
        //! @brief Returns a vector with each component rounded up.
        _CGUL_INLINE_DEFINE Vector2T Ceiled() const;

        //! @brief Gets the sum of the elements.
        _CGUL_INLINE_DEFINE Type SumComponents() const;
        //! @brief Gets the product of the elements.
        _CGUL_INLINE_DEFINE Type MultiplyComponents() const;

        // @brief Checks if this vector contains NaN values.
        _CGUL_INLINE_DEFINE Type IsNaN() const;
    };

    typedef Vector2T< Float32 > Vector2;
    typedef Vector2T< Float64 > Vector2D;
    typedef Vector2T< SInt16  > SCoord16;
    typedef Vector2T< SInt32  > SCoord32;
    typedef Vector2T< SInt64  > SCoord64;
    typedef Vector2T< UInt16  > UCoord16;
    typedef Vector2T< UInt32  > UCoord32;
    typedef Vector2T< UInt64  > UCoord64;
}

// Undefines
#include "../External/Undefines.hpp"

// Implementation
#include "Vector2_Implement.hpp"
