//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float3
    {
        float x, y, z;

        _JATTA_EXPORT static float dotProduct(const Float3& valueA, const Float3& valueB);
        _JATTA_EXPORT static Float3 crossProduct(const Float3& valueA, const Float3& valueB);
        _JATTA_EXPORT static Float3 normalized(const Float3& value);

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

        _JATTA_EXPORT void normalize();

        _JATTA_EXPORT float getMagnitude() const;
    };
}

#include "../External/Undefines.h"