/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    struct Float2;
    struct Float4;

    struct Float3
    {
        union
        {
            struct
            {
                Float32 x, y, z;
            };
            Float32 m[3];
        };

        _JATTA_EXPORT static float DotProduct(const Float3& valueA, const Float3& valueB);
        _JATTA_EXPORT static Float3 CrossProduct(const Float3& valueA, const Float3& valueB);
        _JATTA_EXPORT static Float3 Normalized(const Float3& value);

        _JATTA_EXPORT Float3();
        _JATTA_EXPORT Float3(const Float3& copy);
        _JATTA_EXPORT Float3(float value);
        _JATTA_EXPORT Float3(float x, float y, float z);

        _JATTA_EXPORT Float3 operator-() const;
        _JATTA_EXPORT Float3 operator+(const Float3& operand) const;
        _JATTA_EXPORT Float3& operator+=(const Float3& operand);
        _JATTA_EXPORT Float3 operator-(const Float3& operand) const;
        _JATTA_EXPORT Float3& operator-=(const Float3& operand);
        _JATTA_EXPORT Float3 operator*(float operand) const;
        _JATTA_EXPORT Float3& operator*=(float operand);
        friend std::ostream& operator<<(std::ostream& stream, const Float3& vector)
        {
            stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
            return stream;
        }

        _JATTA_EXPORT Jatta::Float32 At(UInt32 index) const;

        _JATTA_EXPORT void Set(Float32 value);
        _JATTA_EXPORT void Set(Float32 x, Float32 y, Float32 z);

        _JATTA_EXPORT Float2 Swizzle(UInt32 x, UInt32 y) const;
        _JATTA_EXPORT Float3 Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        _JATTA_EXPORT Float4 Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        _JATTA_EXPORT void Normalize();

        _JATTA_EXPORT float GetMagnitude() const;
    };
}

#include "../External/Undefines.h"
