/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float3
    {
        float x, y, z;

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

        _JATTA_EXPORT void Normalize();

        _JATTA_EXPORT float GetMagnitude() const;
    };
}

#include "../External/Undefines.h"
