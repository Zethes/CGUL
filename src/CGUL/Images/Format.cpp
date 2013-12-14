// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Format.cpp
 */

#include "Format.hpp"

namespace CGUL
{
    _CGUL_EXPORT bool ImageFormat::operator==(const ImageFormat& o)
    {
        return (o.name == name && o.dataType == dataType && o.redBits == redBits && 
            o.greenBits == greenBits && o.blueBits == blueBits && o.alphaBits == alphaBits && o.glFormat == glFormat);
    }

    _CGUL_EXPORT ImageFormat CreateImageFormat(String name, UInt32 redBits, UInt32 blueBits, UInt32 greenBits, UInt32 alphaBits, UInt32 type, Enum glFormat) 
    {
        ImageFormat ret;
        ret.name = name;
        ret.dataType = type;
        ret.redBits = redBits;
        ret.blueBits = blueBits;
        ret.greenBits = greenBits;
        ret.alphaBits = alphaBits;
        ret.glFormat = glFormat;
        return ret;
    }

    namespace ImageFormats
    {
#       ifdef CGUL_USE_OPENGL

        ImageFormat RGB        = CreateImageFormat("RGB", 8, 8, 8, 0, DataTypes::UNSIGNED_CHAR, GL_RGB);
        ImageFormat RGBA        = CreateImageFormat("RGBA", 8, 8, 8, 0, DataTypes::UNSIGNED_CHAR, GL_RGBA);
        ImageFormat R8          = CreateImageFormat("R8", 8, 0, 0, 0, DataTypes::UNSIGNED_CHAR, GL_R8);
        ImageFormat R16         = CreateImageFormat("R16", 16, 0, 0, 0, DataTypes::UNSIGNED_CHAR, GL_R16);
        ImageFormat RG8         = CreateImageFormat("RG8", 8, 8, 0, 0, DataTypes::UNSIGNED_CHAR, GL_RG8);
        ImageFormat RG16        = CreateImageFormat("RG16", 16, 16, 0, 0, DataTypes::UNSIGNED_CHAR, GL_RG16);
        ImageFormat R3_G3_B2    = CreateImageFormat("R3_G3_B2", 3, 3, 2, 0, DataTypes::UNSIGNED_CHAR, GL_R3_G3_B2);
        ImageFormat RGB4        = CreateImageFormat("RGB4", 4, 4, 4, 0, DataTypes::UNSIGNED_CHAR, GL_RGB4);
        ImageFormat RGB5        = CreateImageFormat("RGB5", 5, 5, 5, 0, DataTypes::UNSIGNED_CHAR, GL_RGB5);
        ImageFormat RGB8        = CreateImageFormat("RGB8", 8, 8, 8, 0, DataTypes::UNSIGNED_CHAR, GL_RGB8);
        ImageFormat RGB10       = CreateImageFormat("RGB10", 10, 10, 10, 0, DataTypes::UNSIGNED_CHAR, GL_RGB10);
        ImageFormat RGB12       = CreateImageFormat("RGB12", 12, 12, 12, 0, DataTypes::UNSIGNED_CHAR, GL_RGB12);
        ImageFormat RGB16       = CreateImageFormat("RGB16", 16, 16, 16, 0, DataTypes::UNSIGNED_CHAR, GL_RGB16);
        ImageFormat RGBA2       = CreateImageFormat("RGBA2", 2, 2, 2, 2, DataTypes::UNSIGNED_CHAR, GL_RGBA2);
        ImageFormat RGBA4       = CreateImageFormat("RGBA4", 4, 4, 4, 4, DataTypes::UNSIGNED_CHAR, GL_RGBA4);
        ImageFormat RGB5_A1     = CreateImageFormat("RGB5_A1", 5, 5, 5, 1, DataTypes::UNSIGNED_CHAR, GL_RGB5_A1);
        ImageFormat RGBA8       = CreateImageFormat("RGBA8", 8, 8, 8, 8, DataTypes::UNSIGNED_CHAR, GL_RGBA8);
        ImageFormat RGB10_A2    = CreateImageFormat("RGB10_A2", 10, 10, 10, 2, DataTypes::UNSIGNED_CHAR, GL_RGB10_A2);
        ImageFormat RGBA12      = CreateImageFormat("RGBA12", 12, 12, 12, 12, DataTypes::UNSIGNED_CHAR, GL_RGBA12);
        ImageFormat RGBA16      = CreateImageFormat("RGBA16", 16, 16, 16, 16, DataTypes::UNSIGNED_CHAR, GL_RGBA16);

#       else

        ImageFormat RGB        = CreateImageFormat("RGB", 8, 8, 8, 0);
        ImageFormat RGBA        = CreateImageFormat("RGBA", 8, 8, 8, 0);
        ImageFormat R8          = CreateImageFormat("R8", 8, 0, 0);
        ImageFormat R16         = CreateImageFormat("R16", 16, 0, 0);
        ImageFormat RG8         = CreateImageFormat("RG8", 8, 8, 0);
        ImageFormat RG16        = CreateImageFormat("RG16", 16, 16, 0);
        ImageFormat R3_G3_B2    = CreateImageFormat("R3_G3_B2", 3, 3, 2);
        ImageFormat RGB4        = CreateImageFormat("RGB4", 4, 4, 4);
        ImageFormat RGB5        = CreateImageFormat("RGB5", 5, 5, 5);
        ImageFormat RGB8        = CreateImageFormat("RGB4", 8, 8, 8);
        ImageFormat RGB10       = CreateImageFormat("RGB10", 10, 10, 10);
        ImageFormat RGB12       = CreateImageFormat("RGB12", 12, 12, 12);
        ImageFormat RGB16       = CreateImageFormat("RGB16", 16, 16, 16);
        ImageFormat RGBA2       = CreateImageFormat("RGBA2", 2, 2, 2, 2);
        ImageFormat RGBA4       = CreateImageFormat("RGBA4", 4, 4, 4, 4);
        ImageFormat RGBA5_A1    = CreateImageFormat("RGBA5_A1", 5, 5, 5, 1);
        ImageFormat RGBA8       = CreateImageFormat("RGBA8", 8, 8, 8, 8);
        ImageFormat RGBA10_A2   = CreateImageFormat("RGBA10_A2", 10, 10, 10, 2);
        ImageFormat RGBA12      = CreateImageFormat("RGBA12", 12, 12, 12, 12);
        ImageFormat RGBA16      = CreateImageFormat("RGBA16", 16, 16, 16, 16);

#       endif
    };
}