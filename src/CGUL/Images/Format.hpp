// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014 Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Format.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief Enum full of basic image data types.
    */
    namespace DataTypes
    {
        enum
        {
            UNSIGNED_CHAR,
            SIGNED_CHAR,
            FLOAT32,
            FLOAT64,
            UINT32,
            UINT64,
            SINT32,
            SINT64
        };
    };

    /** @brief A struct that defines an image format and how to treat it.
     */
    struct ImageFormat
    {
        String name;
        UInt32 dataType;                                   //How should data be stored?
        UInt32 redBits, greenBits, blueBits, alphaBits;    //Bitdepth per component.
        Enum glFormat;                                     //How does OpenGL see this?

        _CGUL_EXPORT bool operator==(const ImageFormat& o);
    };

    /** @brief Method for creating image formats.
     */
    _CGUL_EXPORT ImageFormat CreateImageFormat(String name, UInt32 redBits, UInt32 blueBits, UInt32 greenBits, UInt32 alphaBits = 0, UInt32 type = DataTypes::UNSIGNED_CHAR, Enum glFormat = 0);

    /** @brief Namespace full of pre-defined image formats.  They are named using the same system as OpenGL.  See: http://www.opengl.org/wiki/Image_Format
     *  @todo Add other than Unsigned Char data types.
     */
    namespace ImageFormats
    {
        extern ImageFormat 
        RGB,
        RGBA,
        R8,
        R16,
        RG8,
        RG16,
        R3_G3_B2,
        RGB4,
        RGB5,
        RGB8,
        RGB10,
        RGB12,
        RGB16,
        RGBA2,
        RGBA4,
        RGBA5_A1,
        RGBA8,
        RGBA10_A2,
        RGBA12,
        RGBA16;
    };
}

#include "../External/Undefines.hpp"
