//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float2
    {
        float x, y;

        Float2();
        Float2(const Float2& copy);
        Float2(float value);
        Float2(float x, float y);

        Float2 operator+(const Float2& operand) const;
        Float2 operator*(float operand) const;
        Float2& operator*=(float operand);

        void normalize();

        float getMagnitude();
    };
}

#include "../External/Undefines.h"