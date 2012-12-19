//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Float4
    {
        float x, y, z, w;

        Float4();
        Float4(const Float4& copy);
        Float4(float value);
        Float4(float x, float y, float z, float w);

        void normalize();

        float getMagnitude();
    };
}

#include "../External/Undefines.h"