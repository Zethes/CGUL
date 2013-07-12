    /* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    struct Vector3;
    struct Vector4;

    /** @brief A two dimensional 32 bit floating point vector.
     *  @todo Template this to allow 64 bit floating point or integer as well?
     */
    struct Vector2
    {
        union
        {
            struct
            {
                //! @brief The x component.
                Float32 x;
                //! @brief The y component.
                Float32 y;
            };
            //! @brief An array containing raw data to the components.
            Float32 m[2];
        };

        //! @brief Zero vector, defined as (0, 0).
        _JATTA_EXPORT static const Vector2 zero;
        //! @brief One vector, defined as (1, 1).
        _JATTA_EXPORT static const Vector2 one;
        //! @brief Unit X vector, defined as (1, 0).
        _JATTA_EXPORT static const Vector2 unitX;
        //! @brief Unit Y vector, defined as (0, 1).
        _JATTA_EXPORT static const Vector2 unitY;

        //! @brief Creates a vector based on a given two dimensional angle with an optional
        //! magnitude.
        _JATTA_EXPORT static Vector2 FromAngle(Float32 angle, Float32 magnitude = 1.0f);

        //! @brief Initializes to (0, 0).
        _JATTA_EXPORT Vector2();
        //! @brief Copies a vector into this vector.
        _JATTA_EXPORT Vector2(const Vector2& copy);
        //! @brief Initializes both x and y to a given value.
        _JATTA_EXPORT Vector2(Float32 value);
        //! @brief Initializes the vector with a given x and y value.
        _JATTA_EXPORT Vector2(Float32 x, Float32 y);

        //! @brief Assigns another vector into this vector.
        _JATTA_EXPORT Vector2& operator=(const Vector2& operand);
        //! @brief Accesses an individual component in this vector.
        _JATTA_EXPORT Float32& operator[](UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _JATTA_EXPORT Float32 operator[](UInt32 index) const;
        //! @brief Gets the inverse of the vector.
        _JATTA_EXPORT Vector2 operator-() const;
        //! @brief Checks if two vectors are @em exactly equal.
        _JATTA_EXPORT bool operator==(const Vector2& operand) const;
        //! @brief Checks if two vectors are not @em exactly equal.
        _JATTA_EXPORT bool operator!=(const Vector2& operand) const;
        //! @brief Performs component-based addition on two vectors.
        _JATTA_EXPORT Vector2 operator+(const Vector2& operand) const;
        //! @brief Adds the individual components of another vector to this vector's components.
        _JATTA_EXPORT Vector2& operator+=(const Vector2& operand);
        //! @brief Performs component-based subtraction on two vectors.
        _JATTA_EXPORT Vector2 operator-(const Vector2& operand) const;
        //! @brief Subtracts the individual components of another vector from this vector's
        //! components.
        _JATTA_EXPORT Vector2& operator-=(const Vector2& operand);
        //! @brief Performs component-based multiplication on two vectors.
        _JATTA_EXPORT Vector2 operator*(Float32 operand) const;
        //! @brief Multiplies the individual components of another vector onto this vector's
        //! components.
        _JATTA_EXPORT Vector2& operator*=(Float32 operand);
        //! @brief Performs component-based division on two vectors.
        _JATTA_EXPORT Vector2 operator/(Float32 operand) const;
        //! @brief Divides the individual components of another vector onto this vector's
        //! components.
        _JATTA_EXPORT Vector2& operator/=(Float32 operand);
        //! @brief An operator to output this vector on an output stream.
        _JATTA_EXPORT friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);

        //! @brief Accesses an individual component in this vector.
        _JATTA_EXPORT Jatta::Float32& At(UInt32 index);
        //! @brief Accesses an individual (constant) component in this vector.
        _JATTA_EXPORT Jatta::Float32 At(UInt32 index) const;

        //! @brief Sets both x and y components to a given value.
        _JATTA_EXPORT void Set(Float32 value);
        //! @brief Sets the x and y components to the given values.
        _JATTA_EXPORT void Set(Float32 x, Float32 y);

        //! @brief Clears the vector to (0, 0).
        _JATTA_EXPORT void Clear();

        //! @brief Performs a two dimensional swizzle.
        _JATTA_EXPORT Vector2 Swizzle(UInt32 x, UInt32 y) const;
        //! @brief Performs a three dimensional swizzle.
        _JATTA_EXPORT Vector3 Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        //! @brief Performs a four dimensional swizzle.
        _JATTA_EXPORT Vector4 Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        //! @brief Normalizes the vector resulting in a length of 1.
        _JATTA_EXPORT void Normalize();
        //! @brief Checks if the vector is normalizes within a given epsilon.
        _JATTA_EXPORT Boolean IsNormalized(Float32 epsilon = 0.00001f) const;
        //! @brief Gets the magnitude of the vector.
        _JATTA_EXPORT Float32 GetMagnitude() const;
        //! @brief Gets the squared magnitude of the vector.
        _JATTA_EXPORT Float32 GetSquaredMagnitude() const;
        //! @brief Gets the manhattan magnitude of the vector.
        _JATTA_EXPORT Float32 GetManhattanMagnitude() const;
        //! @brief Gets the distance between two vectors.
        _JATTA_EXPORT Float32 GetDistance(const Vector2& other) const;
        //! @brief Gets the squared distance between two vectors.
        _JATTA_EXPORT Float32 GetSquaredDistance(const Vector2& other) const;
        //! @brief Gets the manhattan distance between two vectors.
        _JATTA_EXPORT Float32 GetManhattanDistance(const Vector2& other) const;

        //! @brief Sets the two dimensional angle of the vector.
        _JATTA_EXPORT void SetAngle(Float32 angle);
        //! @brief Gets the two dimensional angle of the vector.
        _JATTA_EXPORT Float32 GetAngle() const;

        //! @brief Rounds down each component to the nearest whole number.
        _JATTA_EXPORT void Floor();
        //! @brief Rounds each component to the nearest whole number.
        _JATTA_EXPORT void Round();
        //! @brief Rounds up each component to the nearest whole number.
        _JATTA_EXPORT void Ceil();

        //! @brief Returns a vector with each component rounded down.
        _JATTA_EXPORT Vector2 Floored();
        //! @brief Returns a vector with each component rounded.
        _JATTA_EXPORT Vector2 Rounded();
        //! @brief Returns a vector with each component rounded up.
        _JATTA_EXPORT Vector2 Ceiled();
    };
}

#include "../External/Undefines.h"
