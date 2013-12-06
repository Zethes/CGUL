// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Image.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../Math/Vector2.hpp"
#include "Format.hpp"
#include "ImageHandler.hpp"
#include "Loader.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A container capable of loading and manipulating RGBA images.
     *  @todo Support more image modifying/transforming.
     */
    class Image
    {
        ImageFormat format;
        UInt32 width;
        UInt32 height;
        Size pixelSize;

        Size dataSize;
        void* data;
    public:
        _CGUL_EXPORT Image();
        _CGUL_EXPORT Image(ImageFormat format, UInt32 width, UInt32 height);
        _CGUL_EXPORT Image(ImageFormat format, UInt32 width, UInt32 height, void * data);
        _CGUL_EXPORT ~Image();

        _CGUL_EXPORT bool CanLoad(const String& file);
        _CGUL_EXPORT bool Load(const String& file);
        _CGUL_EXPORT bool Save(const String& file, const String& ext);

        /*template <typename T>
        _CGUL_EXPORT T* GetPixel(UInt32 x, UInt32 y);
        template <typename T>
        _CGUL_EXPORT void SetPixel(UInt32 x, UInt32 y, T* pixel);*/

        _CGUL_EXPORT void* GetData();

        _CGUL_EXPORT ImageFormat GetFormat();
        _CGUL_EXPORT UInt32 GetWidth();
        _CGUL_EXPORT UInt32 GetHeight();

        _CGUL_EXPORT Size GetPixelSize();
        _CGUL_EXPORT Size GetDataSize();
    };
}

#include "../External/Undefines.hpp"
