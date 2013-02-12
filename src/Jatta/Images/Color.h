/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    struct Float4;

    struct Color
    {
        _JATTA_EXPORT static Color MakeHSL(unsigned int hue, unsigned char saturation, unsigned char luminance);

        unsigned char r, g, b, a;

        _JATTA_EXPORT Color();
        _JATTA_EXPORT Color(const Color& copy);
        _JATTA_EXPORT Color(unsigned char r, unsigned char g, unsigned char b);
        _JATTA_EXPORT Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        Boolean operator==(const Color& operand);
        Boolean operator!=(const Color& operand);
        Color& operator=(const Color& operand);
        friend std::ostream& operator<<(std::ostream& stream, const Color& color)
        {
            stream << "[" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << "]";
            return stream;
        }

        Float4 ToFloat4() const;
    };
}

#include "../External/Undefines.h"
