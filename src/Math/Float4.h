//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float4
    {
        float x, y, z, w;

        _JATTA_EXPORT Float4();
        _JATTA_EXPORT Float4(const Float4& copy);
        _JATTA_EXPORT Float4(float value);
        _JATTA_EXPORT Float4(float x, float y, float z, float w);

        _JATTA_EXPORT void normalize();

        _JATTA_EXPORT float getMagnitude();
    };
}

#include "../External/Undefines.h"