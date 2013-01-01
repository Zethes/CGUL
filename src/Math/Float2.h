//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float2
    {
        float x, y;

        _JATTA_EXPORT Float2();
        _JATTA_EXPORT Float2(const Float2& copy);
        _JATTA_EXPORT Float2(float value);
        _JATTA_EXPORT Float2(float x, float y);

        _JATTA_EXPORT Float2 operator+(const Float2& operand) const;
        _JATTA_EXPORT Float2& operator+=(const Float2& operand);
        _JATTA_EXPORT Float2 operator-(const Float2& operand) const;
        _JATTA_EXPORT Float2& operator-=(const Float2& operand);
        _JATTA_EXPORT Float2 operator*(float operand) const;
        _JATTA_EXPORT Float2& operator*=(float operand);

        _JATTA_EXPORT void normalize();

        _JATTA_EXPORT float getMagnitude();
    };
}

#include "../External/Undefines.h"