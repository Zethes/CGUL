// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Image.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "ImageFormats.hpp"
#include "Mipmap.hpp"
#include "../External/Defines.hpp"

namespace CGUL
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

        _CGUL_EXPORT bool IsValid();
    public:
        _CGUL_EXPORT Image();
        _CGUL_EXPORT Image(ImageFormat format, UInt32 width, UInt32 height, const void* data);
        _CGUL_EXPORT ~Image();

        _CGUL_EXPORT void Free();

        _CGUL_EXPORT bool GenerateMipmaps();

        _CGUL_EXPORT Mipmap& GetBaseMipmap();
        _CGUL_EXPORT Mipmap& GetMipmap(UInt32 index);
        _CGUL_EXPORT const void* GetData();
        _CGUL_EXPORT ImageFormat GetFormat() const;
        _CGUL_EXPORT int GetMipmapCount() const;
        _CGUL_EXPORT int GetWidth() const;
        _CGUL_EXPORT int GetHeight() const;

        _CGUL_EXPORT void PushMipmap(UInt32 width, UInt32 height, const void* data);
        _CGUL_EXPORT void PopMipmap();
    };
}

#include "../External/Undefines.hpp"
