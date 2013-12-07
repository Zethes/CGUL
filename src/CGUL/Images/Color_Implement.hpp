// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Color_Implement.hpp
 */

#include "../Math/Math.hpp"
#include "../Math/Vector3.hpp"
#include "../Math/Vector4.hpp"

/** @param hue Hue value from 0-360.
 *  @param saturation Saturation value from 0-255.
 *  @param luminance Luminance value from 0-255.
 *  @param alpha Optional alpha value from 0-255.
 *  @returns The resulting color.
 */
template< typename Type >
_CGUL_EXPORT CGUL::ColorT< Type > CGUL::ColorT< Type >::MakeHSL(Float32 hue, Float32 saturation, Float32 luminance, Type alpha)
{
    /*Color ret(0, 0, 0, alpha);

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
    return ret;*/
    return ColorT(0, 0, 0, 0);
}

/**
 */
template< typename Type >
_CGUL_EXPORT CGUL::ColorT< Type >::ColorT()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = maxValue;
}

/** @param copy The color to copy.
 */
template< typename Type >
_CGUL_EXPORT CGUL::ColorT< Type >::ColorT(const ColorT& copy)
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
template< typename Type >
_CGUL_EXPORT CGUL::ColorT< Type >::ColorT(Type r, Type g, Type b)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = maxValue;
}

/** @param r The red value.
 *  @param g The green value.
 *  @param b The blue value.
 *  @param a The alpha value.
 */
template< typename Type >
_CGUL_EXPORT CGUL::ColorT< Type >::ColorT(Type r, Type g, Type b, Type a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/** @param operand The other color.
 *  @returns True if the colors are the same, false otherwise.
 */
template< typename Type >
_CGUL_EXPORT CGUL::Boolean CGUL::ColorT< Type >::operator==(const ColorT& operand)
{
    return r == operand.r && b == operand.b && g == operand.g && a == operand.a;
}

/** @param operand The other color.
 *  @returns True if the colors are not the same, false otherwise.
 */
template< typename Type >
_CGUL_EXPORT CGUL::Boolean CGUL::ColorT< Type >::operator!=(const ColorT& operand)
{
    return r != operand.r || b != operand.b || g != operand.g || a != operand.a;
}

/** @param operand The other color.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_EXPORT CGUL::ColorT< Type >& CGUL::ColorT< Type >::operator=(const ColorT& operand)
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
template< typename Type >
template< typename VectorType >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< VectorType > CGUL::ColorT< Type >::ToVector3() const
{
    return Vector3T< Type >(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f);
}

/** @details Same as @ref ToVector3 except it contains the alpha value as well.
 *  @returns A vector containing the r, g, b, a values as floating point x, y, z, w.
 */
template< typename Type >
template< typename VectorType >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< VectorType > CGUL::ColorT< Type >::ToVector4() const
{
    return Vector4T< VectorType >(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f, this->a / 255.0f);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::ColorT< Type >::SetRedFloat(Float32 red)
{
    this->r = (Byte)(maxValue * Math::Clamp(red, 0.0f, 1.0f));
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::ColorT< Type >::SetGreenFloat(Float32 green)
{
    this->g = (Byte)(maxValue * Math::Clamp(green, 0.0f, 1.0f));
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::ColorT< Type >::SetBlueFloat(Float32 blue)
{
    this->b = (Byte)(maxValue * Math::Clamp(blue, 0.0f, 1.0f));
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::ColorT< Type >::SetAlphaFloat(Float32 alpha)
{
    this->a = (Byte)(maxValue * Math::Clamp(alpha, 0.0f, 1.0f));
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::ColorT< Type >::GetRedFloat() const
{
    return r / (Float32)maxValue;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::ColorT< Type >::GetGreenFloat() const
{
    return g / (Float32)maxValue;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::ColorT< Type >::GetBlueFloat() const
{
    return b / (Float32)maxValue;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Float32 CGUL::ColorT< Type >::GetAlphaFloat() const
{
    return a / (Float32)maxValue;
}
