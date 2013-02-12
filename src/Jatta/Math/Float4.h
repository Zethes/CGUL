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
    struct Float3;
    struct Matrix;

    struct Float4
    {
        union
        {
            struct
            {
                Float32 x, y, z, w;
            };
            Float32 m[4];
        };

        _JATTA_EXPORT Float4();
        _JATTA_EXPORT Float4(const Float4& copy);
        _JATTA_EXPORT Float4(float value);
        _JATTA_EXPORT Float4(float x, float y, float z, float w);

        _JATTA_EXPORT float& operator[](UInt32 index);
        _JATTA_EXPORT Float4 operator*(const Matrix& operand) const;
        friend std::ostream& operator<<(std::ostream& stream, const Float4& vector)
        {
            stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";
            return stream;
        }

        _JATTA_EXPORT Jatta::Float32 At(UInt32 index) const;

        _JATTA_EXPORT void Set(Float32 value);
        _JATTA_EXPORT void Set(Float32 x, Float32 y, Float32 z, Float32 w);

        _JATTA_EXPORT Float2 Swizzle(UInt32 x, UInt32 y) const;
        _JATTA_EXPORT Float3 Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        _JATTA_EXPORT Float4 Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        _JATTA_EXPORT void Normalize();

        _JATTA_EXPORT float GetMagnitude();
    };
}

#include "../External/Undefines.h"
