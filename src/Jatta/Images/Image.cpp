/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Image.h"
#include "../Exceptions/ImageException.h"

_JATTA_EXPORT bool Jatta::Image::IsValid()
{
    return (width != 0 && height != 0);
}

_JATTA_EXPORT Jatta::Image::Image() :
    format(ImageFormats::NONE),
    width(0),
    height(0)
{
}

_JATTA_EXPORT Jatta::Image::Image(ImageFormat format, UInt32 width, UInt32 height, const void* data) :
    format(format),
    width(width),
    height(height)
{
    PushMipmap(width, height, data);
}

_JATTA_EXPORT Jatta::Image::~Image()
{
    Free();
}

_JATTA_EXPORT void Jatta::Image::Free()
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

_JATTA_EXPORT bool Jatta::Image::GenerateMipmaps()
{
    if (!IsValid())
        throw ImageException(ImageExceptionCode::GENERATE_MIPMAPS, ImageExceptionReason::IMAGE_IS_NOT_VALID);
    if (mipmaps.size() <= 0)
        throw ImageException(ImageExceptionCode::GENERATE_MIPMAPS, ImageExceptionReason::NO_BASE_MIPMAP);

    //TODO: Mipmap generation.
}

_JATTA_EXPORT Jatta::Mipmap& Jatta::Image::GetBaseMipmap()
{
    if (mipmaps.size() <= 0)
        throw ImageException(ImageExceptionCode::GET_MIPMAP, ImageExceptionReason::NO_BASE_MIPMAP);

    return mipmaps[0];
}

_JATTA_EXPORT Jatta::Mipmap& Jatta::Image::GetMipmap(UInt32 index)
{
    if (mipmaps.size() <= index)
        throw ImageException(ImageExceptionCode::GET_MIPMAP, ImageExceptionReason::INDEX_OUT_OF_RANGE);

    return mipmaps[index];
}

_JATTA_EXPORT const void* Jatta::Image::GetData()
{
    if (mipmaps.size() <= 0)
        throw ImageException(ImageExceptionCode::GET_MIPMAP, ImageExceptionReason::NO_BASE_MIPMAP);

    return mipmaps[0].GetData();
}

_JATTA_EXPORT Jatta::ImageFormat Jatta::Image::GetFormat() const
{
    return format;
}

_JATTA_EXPORT int Jatta::Image::GetMipmapCount() const
{
    return mipmaps.size();
}

_JATTA_EXPORT int Jatta::Image::GetWidth() const
{
    return width;
}

_JATTA_EXPORT int Jatta::Image::GetHeight() const
{
    return height;
}

_JATTA_EXPORT void Jatta::Image::PushMipmap(UInt32 width, UInt32 height, const void* data)
{
    mipmaps.push_back(Mipmap(format, width, height, (void*)data));
}

_JATTA_EXPORT void Jatta::Image::PopMipmap()
{
    mipmaps.pop_back();
}
