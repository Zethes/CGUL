/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Image.h"
#include "Color.h"

_JATTA_EXPORT Jatta::Image::Image()
{
    this->colors = nullptr;
    this->width = 0;
    this->height = 0;
}

_JATTA_EXPORT Jatta::Image::Image(Color* colors, unsigned int width, unsigned int height)
{
    this->colors = colors;
    this->width = width;
    this->height = height;
}

_JATTA_EXPORT Jatta::Image::Image(const Image& copy)
{
    this->width = copy.width;
    this->height = copy.height;
    this->colors = (Color*)new char[this->width * this->height * 4];
    memcpy(this->colors, copy.colors, this->width * this->height * 4);
}

_JATTA_EXPORT Jatta::Image::Image(Image&& move)
{
    this->width = move.width;
    this->height = move.height;
    this->colors = move.colors;
    move.width = 0;
    move.height = 0;
    move.colors = nullptr;
}

_JATTA_EXPORT Jatta::Image::~Image()
{
    //delete[] colors;
}

_JATTA_EXPORT Jatta::Image& Jatta::Image::operator=(const Image& copy)
{
    this->width = copy.width;
    this->height = copy.height;
    this->colors = (Color*)new char[this->width * this->height * 4];
    memcpy(this->colors, copy.colors, this->width * this->height * 4);
    return *this;
}

_JATTA_EXPORT Jatta::Image& Jatta::Image::operator=(Image&& move)
{
    this->width = move.width;
    this->height = move.height;
    this->colors = move.colors;
    move.width = 0;
    move.height = 0;
    move.colors = nullptr;
    return *this;
}

_JATTA_EXPORT unsigned char* Jatta::Image::GetData()
{
    return (unsigned char*)colors;
}

_JATTA_EXPORT const unsigned char* Jatta::Image::GetData() const
{
    return (const unsigned char*)colors;
}

_JATTA_EXPORT unsigned int Jatta::Image::GetWidth() const
{
    return width;
}

_JATTA_EXPORT unsigned int Jatta::Image::GetHeight() const
{
    return height;
}

_JATTA_EXPORT void Jatta::Image::Free()
{
    // TODO: figure out why this crashes in linux
    //delete[] colors;
    //colors = nullptr;
}

_JATTA_EXPORT bool Jatta::Image::Load(const Jatta::String& fileName, UInt32 flags)
{
#   ifdef JATTA_USE_PNG
    if (IsPng(fileName))
        return LoadPng(fileName, flags);
#   else
    if (false) {}
#   endif
#   ifdef JATTA_USE_JPEG
    else if (IsJpg(fileName))
        return LoadJpg(fileName, flags);
#   endif
    else
        return false;
}
