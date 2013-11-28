// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Mipmap.cpp
 */

#include "Mipmap.hpp"

// TODO: remove this? it's not used
/*_CGUL_EXPORT bool CGUL::Mipmap::IsValid()
{
    return (width != 0 && height != 0);
}*/

_CGUL_EXPORT CGUL::Mipmap::Mipmap() :
    data(NULL),
    format(ImageFormats::NONE),
    width(0),
    height(0)
{
}

_CGUL_EXPORT CGUL::Mipmap::Mipmap(ImageFormat format, UInt32 width, UInt32 height, void* data) :
    data(data),
    format(format),
    width(width),
    height(height)
{
}

_CGUL_EXPORT CGUL::Mipmap::~Mipmap()
{
    //Free();
}

_CGUL_EXPORT void CGUL::Mipmap::Free()
{
    free(data);
    data = NULL;
    width = 0;
    height = 0;
    format = ImageFormats::NONE;
}

_CGUL_EXPORT const void* CGUL::Mipmap::GetData()
{
    return data;
}
_CGUL_EXPORT CGUL::ImageFormat CGUL::Mipmap::GetFormat() const
{
    return format;
}
