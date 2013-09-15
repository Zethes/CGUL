/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "ImageFormats.h"
#include "Mipmap.h"
#include "ImageInfo.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief A container capable of loading and manipulating RGBA images.
     *  @todo Support other types of images besides just RGBA.
     */
    class Image
    {
        ImageFormat format;
        UInt32 width;
        UInt32 height;

        std::vector<Mipmap> mipmaps;

        _JATTA_EXPORT bool IsValid();
    public:
        _JATTA_EXPORT Image();
        _JATTA_EXPORT Image(ImageFormat format, UInt32 width, UInt32 height, const void* data);
        _JATTA_EXPORT ~Image();

        _JATTA_EXPORT void Free();

        _JATTA_EXPORT bool GenerateMipmaps();

        _JATTA_EXPORT Mipmap& GetBaseMipmap();
        _JATTA_EXPORT Mipmap& GetMipmap(UInt32 index);
        _JATTA_EXPORT const void* GetData();
        _JATTA_EXPORT ImageFormat GetFormat() const;
        _JATTA_EXPORT int GetMipmapCount() const;
        _JATTA_EXPORT int GetWidth() const;
        _JATTA_EXPORT int GetHeight() const;
        _JATTA_EXPORT ImageInfo GetInfo() const;

        _JATTA_EXPORT void PushMipmap(UInt32 width, UInt32 height, const void* data);
        _JATTA_EXPORT void PopMipmap();
    };
}

#include "../External/Undefines.h"
