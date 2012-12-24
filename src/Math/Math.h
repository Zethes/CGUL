//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    namespace Math
    {
        const float pi = 3.14159f;

        float cos(float x);
        float sin(float x);
        float tan(float x);

        float degToRad(float deg);

        float min(float a, float b);
        float max(float a, float b);

        float floor(float x);

        float mod(float x, float div);
    }
}

#include "../External/Undefines.h"