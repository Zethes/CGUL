// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Color_Implement.hpp
 */

#include "../Math/Math.hpp"
#include "../Math/Vector3.hpp"
#include "../Math/Vector4.hpp"

static CGUL::Float32 HueToRGB(CGUL::Float32 p, CGUL::Float32 q, CGUL::Float32 t)
{
    if (t < 0.0f)
    {
        t += 1;
    }
    if (t > 1.0f)
    {
        t -= 1;
    }
    if (t < 1.0f / 6.0f)
    {
        return p + (q - p) * 6.0f * t;
    }
    if (t < 1.0f / 2.0f)
    {
        return q;
    }
    if (t < 2.0f / 3.0f)
    {
        return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;
    }
    return p;
}

/** @param hue Hue value from 0-1.
 *  @param saturation Saturation value from 0-1.
 *  @param luminance Luminance value from 0-1.
 *  @param alpha Optional alpha value from 0-MAX.
 *  @returns The resulting color.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::ColorT< Type > CGUL::ColorT< Type >::MakeHSL(Float32 hue, Float32 saturation, Float32 luminance, Type alpha)
{
    Float32 r, g, b;

    if (saturation == 0)
    {
        r = g = b = luminance;
    }
    else
    {
        hue /= 360.0f;
        Float32 q = luminance < 0.5 ? luminance * (1.0f + saturation) : luminance + saturation - luminance * saturation;
        Float32 p = 2.0f * luminance - q;
        r = HueToRGB(p, q, hue + 1.0f / 3.0f);
        g = HueToRGB(p, q, hue);
        b = HueToRGB(p, q, hue - 1.0f / 3.0f) ;
    }  

    return ColorT((Type)(r * maxValue), (Type)(g * maxValue), (Type)(b * maxValue), alpha);
}

/** @param hue Hue value from 0-1.
 *  @param saturation Saturation value from 0-1.
 *  @param value Color value from 0-1.
 *  @param alpha Optional alpha value from 0-MAX.
 *  @returns The resulting color.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::ColorT< Type > CGUL::ColorT< Type >::MakeHSV(Float32 hue, Float32 saturation, Float32 value, Type alpha)
{
    Float32 r, g, b;

    Float32 i = Math::Floor(hue * 6.0f);
    Float32 f = hue * 6.0f - i;
    Float32 p = value * (1.0f - saturation);
    Float32 q = value * (1.0f - f * saturation);
    Float32 t = value * (1.0f - (1.0f - f) * saturation);

    switch ((UInt32)Math::Mod(i, 6.0f))
    {
        case 0:
        {
            r = value;
            g = t;
            b = p;
            break;
        }
        case 1:
        {
            r = q;
            g = value;
            b = p;
            break;
        }
        case 2:
        {
            r = p;
            g = value;
            b = t;
            break;
        }
        case 3:
        {
            r = p;
            g = q;
            b = value;
            break;
        }
        case 4:
        {
            r = t;
            g = p;
            b = value;
            break;
        }
        case 5:
        {
            r = value;
            g = p;
            b = q;
            break;
        }
    }

    return ColorT((Type)(r * maxValue), (Type)(g * maxValue), (Type)(b * maxValue), alpha);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::ColorT< Type >::ColorT()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = maxValue;
}

/** @param copy The color to copy.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::ColorT< Type >::ColorT(const ColorT& copy)
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
_CGUL_INLINE_IMPLEMENT CGUL::ColorT< Type >::ColorT(Type r, Type g, Type b)
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
_CGUL_INLINE_IMPLEMENT CGUL::ColorT< Type >::ColorT(Type r, Type g, Type b, Type a)
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
_CGUL_INLINE_IMPLEMENT CGUL::Boolean CGUL::ColorT< Type >::operator==(const ColorT& operand)
{
    return r == operand.r && b == operand.b && g == operand.g && a == operand.a;
}

/** @param operand The other color.
 *  @returns True if the colors are not the same, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Boolean CGUL::ColorT< Type >::operator!=(const ColorT& operand)
{
    return r != operand.r || b != operand.b || g != operand.g || a != operand.a;
}

/** @param operand The other color.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::ColorT< Type >& CGUL::ColorT< Type >::operator=(const ColorT& operand)
{
    this->r = operand.r;
    this->g = operand.g;
    this->b = operand.b;
    this->a = operand.a;
    return *this;
}

/** @details Each element is calculated by taking their respective values and dividing by MAX.
 *  This is useful when colors need to be represented as floating point numbers rather than byte
 *  values, as is the case in a lot of API's (especially graphical ones, such as OpenGL).
 *  @returns A vector containing the r, g, b values as floating point x, y, z.
 */
template< typename Type >
template< typename VectorType >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< VectorType > CGUL::ColorT< Type >::ToVector3() const
{
    return Vector3T< Type >(this->r / (Float32)maxValue, this->g / (Float32)maxValue, this->b / (Float32)maxValue);
}

/** @details Same as @ref ToVector3 except it contains the alpha value as well.
 *  @returns A vector containing the r, g, b, a values as floating point x, y, z, w.
 */
template< typename Type >
template< typename VectorType >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< VectorType > CGUL::ColorT< Type >::ToVector4() const
{
    return Vector4T< VectorType >(this->r / (Float32)maxValue, this->g / (Float32)maxValue, this->b / (Float32)maxValue, this->a / (Float32)maxValue);
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

template< typename Type >
_CGUL_INLINE_DEFINE void CGUL::ColorT< Type >::SetHSL(Float32 hue, Float32 saturation, Float32 luminance)
{
    *this = MakeHSL(hue, saturation, luminance);
}

template< typename Type >
_CGUL_INLINE_DEFINE void CGUL::ColorT< Type >::SetHSV(Float32 hue, Float32 saturation, Float32 value)
{
    *this = MakeHSV(hue, saturation, value);
}

template< typename Type >
_CGUL_INLINE_DEFINE void CGUL::ColorT< Type >::GetHSL(Float32* hue, Float32* saturation, Float32* luminance) const
{
    Float32 red = r / (Float32)maxValue;
    Float32 green = g / (Float32)maxValue;
    Float32 blue = b / (Float32)maxValue;
    Float32 max = Math::Max(red, green, blue);
    Float32 min = Math::Min(red, green, blue);
    *luminance = (max + min) / 2.0f;

    if(max == min)
    {
        *hue = 0.0f;
        *saturation = 0.0f;
    }
    else
    {
        Float32 d = max - min;
        *saturation = *luminance > 0.5f ? d / (2.0f - max - min) : d / (max + min);
        if (max == red)
        {
            *hue = (green - blue) / d + (green < blue ? 6.0f : 0.0f);
        }
        else if (max == green)
        {
            *hue = (blue - red) / d + 2.0f;
        }
        else
        {
            *hue = (red - green) / d + 4.0f;
        }
        *hue = *hue / 6.0f;
    }
}

template< typename Type >
_CGUL_INLINE_DEFINE void CGUL::ColorT< Type >::GetHSV(Float32* hue, Float32* saturation, Float32* value) const
{
    Float32 red = r / (Float32)maxValue;
    Float32 green = g / (Float32)maxValue;
    Float32 blue = b / (Float32)maxValue;
    Float32 max = Math::Max(red, green, blue);
    Float32 min = Math::Min(red, green, blue);
    *value = max;

    Float32 d = max - min;
    *saturation = max == 0.0f ? 0.0f : d / (Float32)max;

    if (max == min)
    {
        *hue = 0.0f;
    }
    else
    {
        if (max == red)
        {
            *hue = (green - blue) / d + (green < blue ? 6.0f : 0.0f);
        }
        else if (max == green)
        {
            *hue = (blue - red) / d + 2.0f;
        }
        else
        {
            *hue = (red - green) / d + 4.0f;
        }
        *hue = *hue / 6.0f;
    }
}

