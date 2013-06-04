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
    struct Vector3;
    struct Matrix;

    struct Vector4
    {
        union
        {
            struct
            {
                Float32 x, y, z, w;
            };
            Float32 m[4];
        };

        _JATTA_EXPORT Vector4();
        _JATTA_EXPORT Vector4(const Vector4& copy);
        _JATTA_EXPORT Vector4(float value);
        _JATTA_EXPORT Vector4(float x, float y, float z, float w);

        _JATTA_EXPORT float& operator[](UInt32 index);
        _JATTA_EXPORT Vector4 operator*(const Matrix& operand) const;
        friend std::ostream& operator<<(std::ostream& stream, const Vector4& vector)
        {
            stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";
            return stream;
        }

        _JATTA_EXPORT Jatta::Float32 At(UInt32 index) const;

        _JATTA_EXPORT void Set(Float32 value);
        _JATTA_EXPORT void Set(Float32 x, Float32 y, Float32 z, Float32 w);

        _JATTA_EXPORT Vector2 Swizzle(UInt32 x, UInt32 y) const;
        _JATTA_EXPORT Vector3 Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        _JATTA_EXPORT Vector4 Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        _JATTA_EXPORT void Normalize();

        _JATTA_EXPORT float GetMagnitude();
    };
}

#include "../External/Undefines.h"
