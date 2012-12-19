//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float3
    {
        float x, y, z;

        static float dotProduct(const Float3& valueA, const Float3& valueB);
        static Float3 crossProduct(const Float3& valueA, const Float3& valueB);
        static Float3 normalized(const Float3& value);

        Float3();
        Float3(const Float3& copy);
        Float3(float value);
        Float3(float x, float y, float z);

        Float3 operator-() const;
        Float3 operator+(const Float3& operand) const;
        Float3& operator+=(const Float3& operand);
        Float3 operator-(const Float3& operand) const;
        Float3& operator-=(const Float3& operand);
        Float3 operator*(float operand) const;
        Float3& operator*=(float operand);

        void normalize();

        float getMagnitude() const;
    };
}

#include "../External/Undefines.h"