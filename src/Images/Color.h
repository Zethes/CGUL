//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Color
    {
        unsigned char r, g, b, a;

        Color();
        Color(unsigned char r, unsigned char g, unsigned char b);
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    };
}

#include "../External/Undefines.h"