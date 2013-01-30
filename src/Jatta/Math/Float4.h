/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Matrix;

    struct Float4
    {
        union
        {
            struct
            {
                float x, y, z, w;
            };
            float m[4];
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

        _JATTA_EXPORT void Normalize();

        _JATTA_EXPORT float GetMagnitude();
    };
}

#include "../External/Undefines.h"
