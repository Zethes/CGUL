/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Color.h"
#include "../Math/Vector3.h"
#include "../Math/Vector4.h"

/** @param hue Hue value from 0-360.
 *  @param saturation Saturation value from 0-255.
 *  @param luminance Luminance value from 0-255.
 *  @param alpha Optional alpha value from 0-255.
 *  @returns The resulting color.
 */
_JATTA_EXPORT Jatta::Color Jatta::Color::MakeHSL(UInt32 hue, Byte saturation, Byte luminance, Byte alpha)
{
    Color ret(0, 0, 0, alpha);

    int f, p, q, t, h;

    if (saturation == 0)
    {
        ret.r = ret.g = ret.b = luminance;
        return ret;
    }

    f = ((hue % 60) * 255) / 60;
    h = (hue % 360) / 60;

    p = (luminance * (256 - saturation)) / 256;
    q = (luminance * (256 - (saturation * f) / 256 )) / 256;
    t = (luminance * (256 - (saturation * (256 - f)) / 256)) / 256;

    switch (h)
    {
    case 0:
        ret.r = luminance;
        ret.g = t;
        ret.b = p;
        break;
    case 1:
        ret.r = q;
        ret.g = luminance;
        ret.b = p;
        break;
    case 2:
        ret.r = p;
        ret.g = luminance;
        ret.b = t;
        break;
    case 3:
        ret.r = p;
        ret.g = q;
        ret.b = luminance;
        break;
    case 4:
        ret.r = t;
        ret.g = p;
        ret.b = luminance;
        break;
    default:
        ret.r = luminance;
        ret.g = p;
        ret.b = q;
        break;
    }
    return ret;
}

/**
 */
_JATTA_EXPORT Jatta::Color::Color()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 255;
}

/** @param copy The color to copy.
 */
_JATTA_EXPORT Jatta::Color::Color(const Color& copy)
{
    this->r = copy.r;
    this->g = copy.g;
    this->b = copy.b;
    this->a = copy.a;
}

/** @param r The red value.
 *  @param g The green value.
 *  @param b The blue value.
 */
_JATTA_EXPORT Jatta::Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 255;
}

/** @param r The red value.
 *  @param g The green value.
 *  @param b The blue value.
 *  @param a The alpha value.
 */
_JATTA_EXPORT Jatta::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/** @param operand The other color.
 *  @returns True if the colors are the same, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::Color::operator==(const Color& operand)
{
    return r == operand.r && b == operand.b && g == operand.g && a == operand.a;
}

/** @param operand The other color.
 *  @returns True if the colors are not the same, false otherwise.
 */
_JATTA_EXPORT Jatta::Boolean Jatta::Color::operator!=(const Color& operand)
{
    return r != operand.r || b != operand.b || g != operand.g || a != operand.a;
}

/** @param operand The other color.
 *  @returns A reference to the current object.
 */
_JATTA_EXPORT Jatta::Color& Jatta::Color::operator=(const Color& operand)
{
    this->r = operand.r;
    this->g = operand.g;
    this->b = operand.b;
    this->a = operand.a;
    return *this;
}

/** @details Each element is calculated by taking their respective values and dividing by 255.0f.
 *  This is useful when colors need to be represented as floating point numbers rather than byte
 *  values, as is the case in a lot of API's (especially graphical ones, such as OpenGL).
 *  @returns A vector containing the r, g, b values as floating point x, y, z.
 */
_JATTA_EXPORT Jatta::Vector3 Jatta::Color::ToVector3() const
{
    return Vector3(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f);
}

/** @details Same as @ref ToVector3 except it contains the alpha value as well.
 *  @returns A vector containing the r, g, b, a values as floating point x, y, z, w.
 */
_JATTA_EXPORT Jatta::Vector4 Jatta::Color::ToVector4() const
{
    return Vector4(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f, this->a / 255.0f);
}
