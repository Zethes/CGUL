/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    struct Vector2;
    struct Vector4;

    /** @brief A three dimensional 32 bit floating point vector.
     *  @todo Template this to allow 64 bit floating point or integer as well?
     */
    struct Vector3
    {
        union
        {
            struct
            {
                Float32 x, y, z;
            };
            Float32 m[3];
        };

        _JATTA_EXPORT static float DotProduct(const Vector3& valueA, const Vector3& valueB);
        _JATTA_EXPORT static Vector3 CrossProduct(const Vector3& valueA, const Vector3& valueB);
        _JATTA_EXPORT static Vector3 Normalized(const Vector3& value);

        _JATTA_EXPORT Vector3();
        _JATTA_EXPORT Vector3(const Vector3& copy);
        _JATTA_EXPORT Vector3(float value);
        _JATTA_EXPORT Vector3(float x, float y, float z);

        _JATTA_EXPORT Vector3 operator-() const;
        _JATTA_EXPORT Vector3 operator+(const Vector3& operand) const;
        _JATTA_EXPORT Vector3& operator+=(const Vector3& operand);
        _JATTA_EXPORT Vector3 operator-(const Vector3& operand) const;
        _JATTA_EXPORT Vector3& operator-=(const Vector3& operand);
        _JATTA_EXPORT Vector3 operator*(float operand) const;
        _JATTA_EXPORT Vector3& operator*=(float operand);
        friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
        {
            stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
            return stream;
        }

        _JATTA_EXPORT Jatta::Float32 At(UInt32 index) const;

        _JATTA_EXPORT void Set(Float32 value);
        _JATTA_EXPORT void Set(Float32 x, Float32 y, Float32 z);

        _JATTA_EXPORT Vector2 Swizzle(UInt32 x, UInt32 y) const;
        _JATTA_EXPORT Vector3 Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        _JATTA_EXPORT Vector4 Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        _JATTA_EXPORT void Normalize();

        _JATTA_EXPORT float GetMagnitude() const;
    };
}

#include "../External/Undefines.h"
