// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Image.cpp
 */

#include "Image.hpp"
#include "../Exceptions/ImageException.hpp"

_CGUL_EXPORT bool CGUL::Image::IsValid()
{
    return (width != 0 && height != 0);
}

_CGUL_EXPORT CGUL::Image::Image() :
    format(ImageFormats::NONE),
    width(0),
    height(0)
{
}

_CGUL_EXPORT CGUL::Image::Image(ImageFormat format, UInt32 width, UInt32 height, const void* data) :
    format(format),
    width(width),
    height(height)
{
    PushMipmap(width, height, data);
}

_CGUL_EXPORT CGUL::Image::~Image()
{
    Free();
}

_CGUL_EXPORT void CGUL::Image::Free()
{
    this->format = ImageFormats::NONE;
    this->width = 0;
    this->height = 0;

    for (UInt32 i = 0; i < mipmaps.size(); i++)
    {
        mipmaps[i].Free();
    }
    mipmaps.clear();
}

_CGUL_EXPORT bool CGUL::Image::GenerateMipmaps()
{
    if (!IsValid())
    {
        throw ImageException(ImageExceptionCode::GENERATE_MIPMAPS, ImageExceptionReason::IMAGE_IS_NOT_VALID);
    }
    if (mipmaps.size() <= 0)
    {
        throw ImageException(ImageExceptionCode::GENERATE_MIPMAPS, ImageExceptionReason::NO_BASE_MIPMAP);
    }

    //TODO: Mipmap generation.
    return false;
}

_CGUL_EXPORT CGUL::Mipmap& CGUL::Image::GetBaseMipmap()
{
    if (mipmaps.size() <= 0)
    {
        throw ImageException(ImageExceptionCode::GET_MIPMAP, ImageExceptionReason::NO_BASE_MIPMAP);
    }

    return mipmaps[0];
}

_CGUL_EXPORT CGUL::Mipmap& CGUL::Image::GetMipmap(UInt32 index)
{
    if (mipmaps.size() <= index)
    {
        throw ImageException(ImageExceptionCode::GET_MIPMAP, ImageExceptionReason::INDEX_OUT_OF_RANGE);
    }

    return mipmaps[index];
}

_CGUL_EXPORT const void* CGUL::Image::GetData()
{
    if (mipmaps.size() <= 0)
    {
        throw ImageException(ImageExceptionCode::GET_MIPMAP, ImageExceptionReason::NO_BASE_MIPMAP);
    }

    return mipmaps[0].GetData();
}

_CGUL_EXPORT CGUL::ImageFormat CGUL::Image::GetFormat() const
{
    return format;
}

_CGUL_EXPORT int CGUL::Image::GetMipmapCount() const
{
    return mipmaps.size();
}

_CGUL_EXPORT int CGUL::Image::GetWidth() const
{
    return width;
}

_CGUL_EXPORT int CGUL::Image::GetHeight() const
{
    return height;
}

_CGUL_EXPORT void CGUL::Image::PushMipmap(UInt32 width, UInt32 height, const void* data)
{
    mipmaps.push_back(Mipmap(format, width, height, (void*)data));
}

_CGUL_EXPORT void CGUL::Image::PopMipmap()
{
    mipmaps.pop_back();
}
