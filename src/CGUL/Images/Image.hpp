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
#include "Color.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief Enum holding the supported image mixing methods.
    */
    namespace ImageMixMethods
    {
        enum
        {
            ADD,
            AMPLITUDE,
            AND,
            AVERAGE,
            CROSS_FADING,
            DIFF,
            MAX,
            MIN,
            MULTIPLY,
            OR,
            SUBTRACT,
            XOR
        };
    };

    /** @brief A container capable of loading and manipulating RGBA images.
     *  @todo Rotation, scaling, mirroring.
     */
    class Image
    {
        ImageFormat format;
        UCoord32 size;
        Size pixelSize;

        Size dataSize;
        void* data;
    public:
        _CGUL_EXPORT static Image* AdjustBrightness(Image* img, Float32 amt);
        _CGUL_EXPORT static Image* GetNegative(Image* img);
        _CGUL_EXPORT static Image* GetGrayscale(Image* img);
        _CGUL_EXPORT static Image* SwapColors(Image* img, Color pre, Color post);

        _CGUL_EXPORT static Image* Mix(Image* one, Image* two, UInt32 method = ImageMixMethods::AVERAGE);

        _CGUL_EXPORT Image();
        _CGUL_EXPORT Image(const Image& copy);
        _CGUL_EXPORT Image(ImageFormat format, UCoord32 size);
        _CGUL_EXPORT Image(ImageFormat format, UCoord32 size, void* data);
        _CGUL_EXPORT ~Image();

        _CGUL_EXPORT bool CanLoad(const String& file) const;
        _CGUL_EXPORT void Load(const String& file);
        _CGUL_EXPORT void Save(const String& file, const String& extension) const;

        _CGUL_EXPORT void Setup(ImageFormat format, UCoord32 size, void* data);

        _CGUL_EXPORT Color GetPixel(UInt32 x, UInt32 y);
        _CGUL_EXPORT void SetPixel(UInt32 x, UInt32 y, Color pixel);

        template< typename Type >
        _CGUL_INLINE_DEFINE Type* GetData();
        template< typename Type >
        _CGUL_INLINE_DEFINE const Type* GetData() const;
        template< typename Type >
        _CGUL_INLINE_DEFINE void SetData(Type* data);

        _CGUL_EXPORT ImageFormat GetFormat()const ;
        _CGUL_EXPORT UCoord32 GetSize() const;
        _CGUL_EXPORT UInt32 GetWidth() const;
        _CGUL_EXPORT UInt32 GetHeight() const;

        _CGUL_EXPORT Size GetPixelSize() const;
        _CGUL_EXPORT Size GetDataSize() const;

        _CGUL_EXPORT bool IsValid() const;
        _CGUL_EXPORT void Free();
    };
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type* CGUL::Image::GetData()
{
    return (Type*)this->data;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT const Type* CGUL::Image::GetData() const
{
    return (const Type*)this->data;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Image::SetData(Type* data)
{
    this->data = data;
}

#include "../External/Undefines.hpp"
