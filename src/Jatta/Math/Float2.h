/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float3;
    struct Float4;

    struct Float2
    {
        union
        {
            struct
            {
                Float32 x, y;
            };
            Float32 m[2];
        };

        _JATTA_EXPORT static const Float2 zero;
        _JATTA_EXPORT static const Float2 one;
        _JATTA_EXPORT static const Float2 unitX;
        _JATTA_EXPORT static const Float2 unitY;

        _JATTA_EXPORT static Float2 FromAngle(Float32 angle, Float32 magnitude = 1.0f);

        _JATTA_EXPORT Float2();
        _JATTA_EXPORT Float2(const Float2& copy);
        _JATTA_EXPORT Float2(Float32 value);
        _JATTA_EXPORT Float2(Float32 x, Float32 y);

        _JATTA_EXPORT Float2& operator=(const Float2& operand);
        _JATTA_EXPORT Float32& operator[](UInt32 index);
        _JATTA_EXPORT Float32 operator[](UInt32 index) const;
        _JATTA_EXPORT Float2 operator-() const;
        _JATTA_EXPORT bool operator==(const Float2& operand) const;
        _JATTA_EXPORT bool operator!=(const Float2& operand) const;
        _JATTA_EXPORT Float2 operator+(const Float2& operand) const;
        _JATTA_EXPORT Float2& operator+=(const Float2& operand);
        _JATTA_EXPORT Float2 operator-(const Float2& operand) const;
        _JATTA_EXPORT Float2& operator-=(const Float2& operand);
        _JATTA_EXPORT Float2 operator*(Float32 operand) const;
        _JATTA_EXPORT Float2& operator*=(Float32 operand);
        _JATTA_EXPORT Float2 operator/(Float32 operand) const;
        _JATTA_EXPORT Float2& operator/=(Float32 operand);
        friend std::ostream& operator<<(std::ostream& stream, const Float2& vector)
        {
            stream << "[" << vector.x << ", " << vector.y << "]";
            return stream;
        }

        _JATTA_EXPORT Jatta::Float32 At(UInt32 index) const;

        _JATTA_EXPORT void Set(Float32 value);
        _JATTA_EXPORT void Set(Float32 x, Float32 y);

        _JATTA_EXPORT Float2 Swizzle(UInt32 x, UInt32 y) const;
        _JATTA_EXPORT Float3 Swizzle(UInt32 x, UInt32 y, UInt32 z) const;
        _JATTA_EXPORT Float4 Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const;

        _JATTA_EXPORT void Normalize();
        _JATTA_EXPORT Boolean IsNormalized(Float32 epsilon = 0.00001f) const;
        _JATTA_EXPORT Float32 GetMagnitude() const;
        _JATTA_EXPORT Float32 GetDistance(const Float2& other) const;

        _JATTA_EXPORT void SetAngle(Float32 angle);
        _JATTA_EXPORT Float32 GetAngle() const;
    };
}

#include "../External/Undefines.h"
