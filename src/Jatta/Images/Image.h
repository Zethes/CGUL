/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    struct Color;

    /** @brief A container capable of loading and manipulating RGBA images.
     *  @todo Support other types of images besides just RGBA.
     */
    class Image
    {
    protected:
        Color* colors;
        unsigned int width, height;
    public:
        _JATTA_EXPORT Image();
        _JATTA_EXPORT Image(Color* colors, unsigned int width, unsigned int height);
        _JATTA_EXPORT Image(const Image& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        _JATTA_EXPORT Image(Image&& move);
#       endif
        _JATTA_EXPORT ~Image();

        _JATTA_EXPORT Jatta::Image& operator=(const Image& copy);
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        _JATTA_EXPORT Jatta::Image& operator=(Image&& move);
#       endif

        _JATTA_EXPORT bool Create(UInt32 width, UInt32 height);
        _JATTA_EXPORT bool Create(UInt32 width, UInt32 height, const Color& color);

        _JATTA_EXPORT void Free();

        _JATTA_EXPORT bool Load(const Jatta::String& fileName);
        _JATTA_EXPORT bool LoadFromMemory(const char* data, Jatta::UInt32 size);

        _JATTA_EXPORT static bool IsBmp(const char* data, Jatta::UInt32 size);
#       ifdef PNG_FOUND
        _JATTA_EXPORT static bool IsPng(const char* data, Jatta::UInt32 size);
#       endif
#       ifdef JPEG_FOUND
        _JATTA_EXPORT static bool IsJpg(const char* data, Jatta::UInt32 size);
#       endif
        _JATTA_EXPORT static bool IsDds(const char* data, Jatta::UInt32 size);

#       ifdef PNG_FOUND
        _JATTA_EXPORT bool LoadPng(const char* data, Jatta::UInt32 size);
        _JATTA_EXPORT void SavePng(const Jatta::String& fileName, Boolean alpha = true);
#       endif

#       ifdef JPEG_FOUND
        _JATTA_EXPORT bool LoadJpg(const char* data, Jatta::UInt32 size);
        _JATTA_EXPORT bool SaveJpg(const Jatta::String& fileName);
#       endif

        _JATTA_EXPORT bool LoadBmp(const char* data, Jatta::UInt32 size);
        _JATTA_EXPORT bool SaveBmp(const Jatta::String& fileName, int bpp = 24, int hRes = 2835, int vRes = 2835);

        _JATTA_EXPORT bool LoadDds(const char* data, Jatta::UInt32 size);
        _JATTA_EXPORT bool SaveDds(const Jatta::String& fileName);

        _JATTA_EXPORT unsigned char* GetData();
        _JATTA_EXPORT const unsigned char* GetData() const;
        _JATTA_EXPORT unsigned int GetWidth() const;
        _JATTA_EXPORT unsigned int GetHeight() const;
        _JATTA_EXPORT Size GetSize() const;

        _JATTA_EXPORT void Mirror();
        _JATTA_EXPORT void Flip();
        _JATTA_EXPORT void MirrorFlip();
    };
}

#include "../External/Undefines.h"
