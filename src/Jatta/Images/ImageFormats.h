/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Exceptions/FatalException.h"
#include "../Math/Math.hpp"
#ifdef Jatta_USE_OPENGL
#   include "../OpenGL/GL.h"
#endif
#include "../External/Defines.h"

namespace Jatta
{
    namespace ImageFormatDataTypes
    {
        enum
        {
            BYTE    = 1,
            INTEGER = 2,
            FLOAT   = 3
        };
    }

    /** @brief Contains an image format's information.
     */
    struct ImageFormat
    {
        union
        {
            UInt32 format;
            struct
            {
                UInt8 componentCount;
                UInt8 componentSize;
                UInt8 dataType;
                UInt8 special;
            };
        };
        UInt32 glFormat;

        ImageFormat(UInt8 special = -1)
        {
            this->componentCount = 0;
            this->componentSize = 0;
            this->dataType = 0;
            this->special = special;
            this->glFormat = 0;
        }

        ImageFormat(UInt8 componentCount, UInt8 componentSize, UInt8 dataType, UInt32 glFormat = 0)
        {
            this->componentCount = componentCount;
            this->componentSize = componentSize;
            this->dataType = dataType;
            this->special = 0;
            this->glFormat = glFormat;
        }

        bool IsNone() const
        {
            return format == 0;
        }

        bool IsAuto() const
        {
            return special == 1;
        }
    };

    namespace ImageFormats
    {
        static const ImageFormat NONE  (0);
        static const ImageFormat AUTO  (1);

        static const ImageFormat R8    (1, 1, ImageFormatDataTypes::BYTE);
        static const ImageFormat RG8   (2, 1, ImageFormatDataTypes::BYTE);

#       ifdef Jatta_USE_OPENGL
        static const ImageFormat RGBA4 (4, 1, ImageFormatDataTypes::BYTE, GL::RGBA4);
#       else
        static const ImageFormat RGBA4 (4, 1, ImageFormatDataTypes::BYTE);
#       endif

#       ifdef Jatta_USE_OPENGL
        static const ImageFormat RGB8  (3, 1, ImageFormatDataTypes::BYTE, GL::RGB);
        static const ImageFormat RGBA8 (4, 1, ImageFormatDataTypes::BYTE, GL::RGBA);
#       else
        static const ImageFormat RGB8  (3, 1, ImageFormatDataTypes::BYTE);
        static const ImageFormat RGBA8 (4, 1, ImageFormatDataTypes::BYTE);
#       endif

        static const ImageFormat RGBA16(4, 2, ImageFormatDataTypes::BYTE);
        static const ImageFormat RGBA32(4, 4, ImageFormatDataTypes::BYTE);

#       ifdef Jatta_USE_OPENGL
        static const ImageFormat BGR8  (3, 1, ImageFormatDataTypes::BYTE, GL::BGR);
        static const ImageFormat BGRA8 (4, 1, ImageFormatDataTypes::BYTE, GL::BGRA);
#       else
        static const ImageFormat BGR8  (3, 1, ImageFormatDataTypes::BYTE);
        static const ImageFormat BGRA8 (4, 1, ImageFormatDataTypes::BYTE);
#       endif

        static const ImageFormat BGRA16(4, 2, ImageFormatDataTypes::BYTE);
        static const ImageFormat BGRA32(4, 4, ImageFormatDataTypes::BYTE);
    }
}

#include "../External/Undefines.h"
