/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Color.h"

_JATTA_EXPORT Jatta::Color Jatta::Color::MakeHSV(unsigned int hue, unsigned char saturation, unsigned char value)
{
    Color ret;

    int f, p, q, t, h;

    if (saturation == 0)
    {
        ret.r = ret.g = ret.b = value;
        return ret;
    }

    f = ((hue % 60) * 255) / 60;
    h = (hue % 360) / 60;

    p = (value * (256 - saturation)) / 256;
    q = (value * (256 - (saturation * f) / 256 )) / 256;
    t = (value * (256 - (saturation * (256 - f)) / 256)) / 256;

    switch (h)
    {
    case 0:
        ret.r = value;
        ret.g = t;
        ret.b = p;
        break;
    case 1:
        ret.r = q;
        ret.g = value;
        ret.b = p;
        break;
    case 2:
        ret.r = p;
        ret.g = value;
        ret.b = t;
        break;
    case 3:
        ret.r = p;
        ret.g = q;
        ret.b = value;
        break;
    case 4:
        ret.r = t;
        ret.g = p;
        ret.b = value;
        break;
    default:
        ret.r = value;
        ret.g = p;
        ret.b = q;
        break;
    }
    return ret;
}

_JATTA_EXPORT Jatta::Color::Color()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 255;
}

_JATTA_EXPORT Jatta::Color::Color(const Color& copy)
{
    this->r = copy.r;
    this->g = copy.g;
    this->b = copy.b;
    this->a = copy.a;
}

_JATTA_EXPORT Jatta::Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 255;
}

_JATTA_EXPORT Jatta::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
