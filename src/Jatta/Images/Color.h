/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Color
    {
        _JATTA_EXPORT static Color MakeHSV(unsigned int hue, unsigned char saturation, unsigned char value);

        unsigned char r, g, b, a;

        _JATTA_EXPORT Color();
        _JATTA_EXPORT Color(const Color& copy);
        _JATTA_EXPORT Color(unsigned char r, unsigned char g, unsigned char b);
        _JATTA_EXPORT Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    };
}

#include "../External/Undefines.h"
