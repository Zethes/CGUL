// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Color.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
    template< typename Type >
    struct Vector3T;
    template< typename Type >
    struct Vector4T;

    /** @brief An RGBA (red, green, blue, alpha) color.
     */
    template< typename Type >
    struct ColorT
    {
        // TODO: this should really be LLU instead of LU for 64bit support, but visual studio
        // doesn't like that
        static const Type maxValue = (Type)((2LU << (sizeof(Type) * 8LU)) - 1LU);

        //! @brief Creates a color given a hue, saturation, luminance, and (optionally) alpha.
        _CGUL_INLINE_DEFINE static ColorT MakeHSL(Float32 hue, Float32 saturation, Float32 luminance, Type alpha = maxValue);
        //! @brief Creates a color given a hue, saturation, value, and (optionally) alpha.
        _CGUL_INLINE_DEFINE static ColorT MakeHSV(Float32 hue, Float32 saturation, Float32 value, Type alpha = maxValue);

        //! @brief The red value.
        Type r;
        //! @brief The green value.
        Type g;
        //! @brief The blue value.
        Type b;
        //! @brief The alpha value.
        Type a;

        //! @brief Initializes a black color (0, 0, 0, 255).
        _CGUL_INLINE_DEFINE ColorT();
        //! @brief Copies a color into a new color.
        _CGUL_INLINE_DEFINE ColorT(const ColorT& copy);
        //! @brief Initializes a color from red, green, and blue values.
        _CGUL_INLINE_DEFINE ColorT(Type r, Type g, Type b);
        //! @brief Initializes a color from red, green, blue, and alpha values.
        _CGUL_INLINE_DEFINE ColorT(Type r, Type g, Type b, Type a);

        //! @brief Checks if two colors are the same.
        _CGUL_INLINE_DEFINE Boolean operator==(const ColorT& operand);
        //! @brief Checks if two colors are not the same.
        _CGUL_INLINE_DEFINE Boolean operator!=(const ColorT& operand);
        //! @brief Assigns one color into another.
        _CGUL_INLINE_DEFINE ColorT& operator=(const ColorT& operand);
        //! @brief Operator to output this color into an output stream.
        friend std::ostream& operator<<(std::ostream& stream, const ColorT& color)
        {
            stream << "[" << (UInt64)color.r << ", " << (UInt64)color.g << ", " << (UInt64)color.b << ", " << (UInt64)color.a << "]";
            return stream;
        }

        //! @brief Calculates RGB values from 0.0f to 1.0f and returns a Vector3 with the result.
        template< typename VectorType >
        _CGUL_INLINE_DEFINE Vector3T< VectorType > ToVector3() const;
        //! @brief Calculates RGBA values from 0.0f to 1.0f and returns a Vector4 with the result.
        template< typename VectorType >
        _CGUL_INLINE_DEFINE Vector4T< VectorType > ToVector4() const;

        _CGUL_INLINE_DEFINE void SetRedFloat(Float32 red);
        _CGUL_INLINE_DEFINE void SetGreenFloat(Float32 green);
        _CGUL_INLINE_DEFINE void SetBlueFloat(Float32 blue);
        _CGUL_INLINE_DEFINE void SetAlphaFloat(Float32 alpha);

        _CGUL_INLINE_DEFINE Float32 GetRedFloat() const;
        _CGUL_INLINE_DEFINE Float32 GetGreenFloat() const;
        _CGUL_INLINE_DEFINE Float32 GetBlueFloat() const;
        _CGUL_INLINE_DEFINE Float32 GetAlphaFloat() const;

        _CGUL_INLINE_DEFINE void SetHSV(Float32 hue, Float32 saturation, Float32 luminance);
        _CGUL_INLINE_DEFINE void SetHSL(Float32 hue, Float32 saturation, Float32 value);
        _CGUL_INLINE_DEFINE void GetHSL(Float32* hue, Float32* saturation, Float32* luminance) const;
        _CGUL_INLINE_DEFINE void GetHSV(Float32* hue, Float32* saturation, Float32* value) const;
    };

    typedef ColorT< Byte > Color;
}

#include "../External/Undefines.hpp"
#include "Color_Implement.hpp"
