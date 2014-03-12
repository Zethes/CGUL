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
        UCoord32 size;
        Size pixelSize;

        Size dataSize;
        void* data;
    public:
        _CGUL_EXPORT Image();
        _CGUL_EXPORT Image(const Image& copy);
        _CGUL_EXPORT Image(ImageFormat format, UCoord32 size);
        _CGUL_EXPORT Image(ImageFormat format, UCoord32 size, void* data);
        _CGUL_EXPORT ~Image();

        _CGUL_EXPORT bool CanLoad(const String& file) const;
        _CGUL_EXPORT void Load(const String& file);
        _CGUL_EXPORT void Save(const String& file, const String& extension) const;

        _CGUL_EXPORT void Setup(ImageFormat format, UCoord32 size, void* data);

        template < typename Type >
        _CGUL_EXPORT Type* GetPixel(UInt32 x, UInt32 y);
        template < typename Type >
        _CGUL_EXPORT void SetPixel(UInt32 x, UInt32 y, Type* pixel);

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
_CGUL_INLINE_IMPLEMENT Type* CGUL::Image::GetPixel(UInt32 x, UInt32 y)
{
    if (y*size.x*pixelSize + x*pixelSize + pixelSize-1 > dataSize)
    {
        return NULL;
    }

    Type* ret = new Type[pixelSize];
    for (UInt32 i = 0; i < pixelSize; ++i)
    {
        ret[i] = ((Type*)data)[y*size.x*pixelSize + x*pixelSize + i];
    }

    return ret;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Image::SetPixel(UInt32 x, UInt32 y, Type* pixel)
{
    if (y*size.x*pixelSize + x*pixelSize + pixelSize-1 > dataSize)
    {
        return;
    }

    for (UInt32 i = 0; i < pixelSize; ++i)
    {
        ((Type*)data)[y*size.x*pixelSize + x*pixelSize + i] = pixel[i];
    }
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
