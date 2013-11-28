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
    struct Color
    {
        //! @brief Creates a color given a hue, saturation, luminance, and (optionally) alpha.
        _CGUL_EXPORT static Color MakeHSL(UInt32 hue, Byte saturation, Byte luminance, Byte alpha = 255);

        //! @brief The red value.
        Byte r;
        //! @brief The green value.
        Byte g;
        //! @brief The blue value.
        Byte b;
        //! @brief The alpha value.
        Byte a;

        //! @brief Initializes a black color (0, 0, 0, 255).
        _CGUL_EXPORT Color();
        //! @brief Copies a color into a new color.
        _CGUL_EXPORT Color(const Color& copy);
        //! @brief Initializes a color from red, green, and blue values.
        _CGUL_EXPORT Color(unsigned char r, unsigned char g, unsigned char b);
        //! @brief Initializes a color from red, green, blue, and alpha values.
        _CGUL_EXPORT Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        //! @brief Checks if two colors are the same.
        _CGUL_EXPORT Boolean operator==(const Color& operand);
        //! @brief Checks if two colors are not the same.
        _CGUL_EXPORT Boolean operator!=(const Color& operand);
        //! @brief Assigns one color into another.
        _CGUL_EXPORT Color& operator=(const Color& operand);
        //! @brief Operator to output this color into an output stream.
        friend std::ostream& operator<<(std::ostream& stream, const Color& color)
        {
            stream << "[" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ", " << (int)color.a << "]";
            return stream;
        }

        //! @brief Calculates RGB values from 0.0f to 1.0f and returns a Vector3 with the result.
        template< typename Type >
        _CGUL_EXPORT Vector3T< Type > ToVector3() const;
        //! @brief Calculates RGBA values from 0.0f to 1.0f and returns a Vector4 with the result.
        template< typename Type >
        _CGUL_EXPORT Vector4T< Type > ToVector4() const;
    };
}

#include "../External/Undefines.hpp"
#include "Color_Implement.hpp"
