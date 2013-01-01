//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    namespace Math
    {
        const float pi = 3.14159f;

        _JATTA_EXPORT float cos(float x);
        _JATTA_EXPORT float sin(float x);
        _JATTA_EXPORT float tan(float x);

        _JATTA_EXPORT float degToRad(float deg);

        _JATTA_EXPORT float min(float a, float b);
        _JATTA_EXPORT float max(float a, float b);

        _JATTA_EXPORT float floor(float x);

        _JATTA_EXPORT float mod(float x, float div);
    }
}

#include "../External/Undefines.h"