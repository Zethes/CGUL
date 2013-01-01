//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Color
    {
        _JATTA_EXPORT static Color makeHSV(unsigned int hue, unsigned char saturation, unsigned char value);

        unsigned char r, g, b, a;

        _JATTA_EXPORT Color();
        _JATTA_EXPORT Color(const Color& copy);
        _JATTA_EXPORT Color(unsigned char r, unsigned char g, unsigned char b);
        _JATTA_EXPORT Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    };
}

#include "../External/Undefines.h"
