/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Image.h"
#include "Color.h"

 #include "../File/File.h"

_JATTA_EXPORT Jatta::Image::Image()
{
    this->colors = NULL;
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

#ifdef _CPP_MOVE_CONSTRUCTOR
_JATTA_EXPORT Jatta::Image::Image(Image&& move)
{
    this->width = move.width;
    this->height = move.height;
    this->colors = move.colors;
    move.width = 0;
    move.height = 0;
    move.colors = nullptr;
}
#endif

_JATTA_EXPORT Jatta::Image::~Image()
{
    delete[] colors;
}

_JATTA_EXPORT Jatta::Image& Jatta::Image::operator=(const Image& copy)
{
    this->width = copy.width;
    this->height = copy.height;
    this->colors = (Color*)new char[this->width * this->height * 4];
    memcpy(this->colors, copy.colors, this->width * this->height * 4);
    return *this;
}

#ifdef _CPP_DOUBLE_REFERENCE
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
#endif

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

_JATTA_EXPORT bool Jatta::Image::Create(UInt32 width, UInt32 height)
{
    colors = (Color*)new char[height * width * sizeof(Color)];
    this->width = width;
    this->height = height;
    return true;
}

_JATTA_EXPORT bool Jatta::Image::Create(UInt32 width, UInt32 height, const Color& color)
{
    if (!Create(width, height))
    {
        return false;
    }
    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            colors[x + y * width] = color;
        }
    }
    return true;
}

_JATTA_EXPORT void Jatta::Image::Free()
{
    // TODO: figure out why this crashes in linux
    delete[] colors;
    colors = nullptr;
}

_JATTA_EXPORT bool Jatta::Image::Load(const Jatta::String& fileName)
{
    unsigned int size;
    File::GetFileSize(fileName.GetData(), &size);
    Byte* buffer = new Byte[size];
    File::ReadData(fileName.GetData(), buffer, size);

#   ifdef JATTA_USE_PNG
    if (IsPng((const char*)buffer, size))
        return LoadPng((const char*)buffer, size);
#   else
    if (false) {}
#   endif
#   ifdef JATTA_USE_JPEG
    else if (IsJpg((const char*)buffer, size))
        return LoadJpg((const char*)buffer, size);
#   endif
    else if (IsDds((const char*)buffer, size))
        return LoadDds((const char*)buffer, size);
    else
        return false;
}

_JATTA_EXPORT bool Jatta::Image::LoadFromMemory(const char* buffer, Jatta::UInt32 size)
{
#   ifdef JATTA_USE_PNG
    if (IsPng(buffer, size))
        return LoadPng(buffer, size);
#   else
    if (false) {}
#   endif
#   ifdef JATTA_USE_JPEG
    else if (IsJpg(buffer, size))
        return LoadJpg(buffer, size);
#   endif
    else if (IsDds(buffer, size))
        return LoadDds(buffer, size);
    else
        return false;
}

_JATTA_EXPORT void Jatta::Image::Mirror()
{
    for (UInt32 w = 0; w < width / 2; w++)
    {
        for (UInt32 h = 0; h < height; h++)
        {
            Color swap;
            swap = colors[w + h * width];
            colors[w + h * width] = colors[(width - (w + 1)) + h * width];
            colors[(width - (w + 1)) + h * width] = swap;
        }
    }
}

_JATTA_EXPORT void Jatta::Image::Flip()
{
    for (UInt32 h = 0; h < height / 2; h++)
    {
        for (UInt32 w = 0; w < width; w++)
        {
            Color swap;
            swap = colors[w + h * width];
            colors[w + h * width] = colors[w + (height - (h + 1)) * width];
            colors[w + (height - (h + 1)) * width] = swap;
        }
    }
}

_JATTA_EXPORT void Jatta::Image::MirrorFlip()
{
    for (UInt32 h = 0; h < height / 2; h++)
    {
        for (UInt32 w = 0; w < width; w++)
        {
            Color swap;
            swap = colors[w + h * width];
            colors[w + h * width] = colors[(width - (w + 1)) + (height - (h + 1)) * width];
            colors[(width - (w + 1)) + (height - (h + 1)) * width] = swap;
        }
    }
}