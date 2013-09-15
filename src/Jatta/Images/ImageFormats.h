/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>

#ifdef Jatta_USE_OPENGL
#include "../OpenGL/GL.h"
#endif

#include "../External/Defines.h"

namespace Jatta
{
    namespace ImageFormatDataTypes
    {
        enum
        {
            BYTE        = 1,
            INTEGER     = 2,
            FLOAT       = 3
        };
    }

    /** @brief A container containing an image format's information.
     */
    struct ImageFormat
    {
    public:
        int Format;
        UInt32 GLFormat;

        ImageFormat(int format = -1)
        {
            Format = format;
        }
    };

    namespace ImageFormats
    {
        static ImageFormat GenerateImageFormat(int componentCount, int componentSize, int dataType, int gl = 0)
        {
            ImageFormat format((componentCount << 24) | (componentSize << 16) | (dataType << 8));
            format.GLFormat = gl;
            return format;
        }

        static int GetComponentCount(ImageFormat format)
        {
            return (format.Format & 0xFF000000) >> 24;
        }

        static int GetComponentSize(ImageFormat format)
        {
            return (format.Format & 0x00FF0000) >> 16;
        }

        static int GetDataType(ImageFormat format)
        {
            return (format.Format & 0x0000FF00) >> 8;
        }

        static bool HasAlphaComponent(ImageFormat format)
        {
            return GetComponentCount(format.Format) == 4;
        }

        static int GetPixelSize(ImageFormat format)
        {
            return GetComponentCount(format.Format) * GetComponentSize(format.Format);
        }

        static const ImageFormat NONE     = ImageFormat(-1);
        static const ImageFormat AUTO     = ImageFormat(0);
        static const ImageFormat R8       = GenerateImageFormat(1, 1, ImageFormatDataTypes::BYTE);
        static const ImageFormat RG8      = GenerateImageFormat(2, 1, ImageFormatDataTypes::BYTE);

        #ifdef Jatta_USE_OPENGL
        static const ImageFormat RGB8     = GenerateImageFormat(3, 1, ImageFormatDataTypes::BYTE, Jatta::GL::RGB);
        static const ImageFormat RGBA8    = GenerateImageFormat(4, 1, ImageFormatDataTypes::BYTE, Jatta::GL::RGBA);
        #else
        static const ImageFormat RGB8     = GenerateImageFormat(3, 1, ImageFormatDataTypes::BYTE);
        static const ImageFormat RGBA8    = GenerateImageFormat(4, 1, ImageFormatDataTypes::BYTE);
        #endif

        static const ImageFormat RGBA16   = GenerateImageFormat(4, 2, ImageFormatDataTypes::BYTE);
        static const ImageFormat RGBA32   = GenerateImageFormat(4, 4, ImageFormatDataTypes::BYTE);

        #ifdef Jatta_USE_OPENGL
        static const ImageFormat BGR8     = GenerateImageFormat(3, 1, ImageFormatDataTypes::BYTE, Jatta::GL::BGR);
        static const ImageFormat BGRA8    = GenerateImageFormat(4, 1, ImageFormatDataTypes::BYTE, Jatta::GL::BGRA);
        #else
        static const ImageFormat BGR8     = GenerateImageFormat(3, 1, ImageFormatDataTypes::BYTE);
        static const ImageFormat BGRA8    = GenerateImageFormat(4, 1, ImageFormatDataTypes::BYTE);
        #endif


        static const ImageFormat BGRA16   = GenerateImageFormat(4, 2, ImageFormatDataTypes::BYTE);
        static const ImageFormat BGRA32   = GenerateImageFormat(4, 4, ImageFormatDataTypes::BYTE);
    }
}

#include "../External/Undefines.h"
