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

        void normalize();

        float getMagnitude();
    };
}

#include "../External/Undefines.h"