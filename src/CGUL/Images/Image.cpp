// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Image.cpp
 */

#include "Image.hpp"
#include "../Exceptions/ImageException.hpp"

_CGUL_EXPORT CGUL::Image::Image()
{
}
_CGUL_EXPORT CGUL::Image::Image(ImageFormat format, UInt32 width, UInt32 height)
{
    this->format = format;
    this->width = width;
    this->height = height;
    this->pixelSize = (format.redBits + format.blueBits + format.greenBits + format.alphaBits) / 8;

    switch (format.dataType)
    {
        case DataTypes::UNSIGNED_CHAR:
            this->data = new unsigned char[this->width * this->height * this->pixelSize];
        break;
        case DataTypes::SIGNED_CHAR:
            this->data = new char[this->width * this->height * this->pixelSize];
        break;
        case DataTypes::FLOAT32:
            this->data = new Float32[this->width * this->height * this->pixelSize];
        break;
        case DataTypes::FLOAT64:
            this->data = new Float64[this->width * this->height * this->pixelSize];
        break;
        case DataTypes::UINT32:
            this->data = new UInt32[this->width * this->height * this->pixelSize];
        break;
        case DataTypes::UINT64:
            this->data = new UInt64[this->width * this->height * this->pixelSize];
        break;
        case DataTypes::SINT32:
            this->data = new SInt32[this->width * this->height * this->pixelSize];
        break; 
        case DataTypes::SINT64:
            this->data = new SInt64[this->width * this->height * this->pixelSize];
        break; 
    }
}

_CGUL_EXPORT CGUL::Image::Image(ImageFormat format, UInt32 width, UInt32 height, void * data)
{
    this->format = format;
    this->width = width;
    this->height = height;
    this->pixelSize = (format.redBits + format.blueBits + format.greenBits + format.alphaBits) / 8;
    this->data = data;
}

_CGUL_EXPORT CGUL::Image::~Image()
{
    free(this->data);
}

_CGUL_EXPORT bool CGUL::Image::CanLoad(const String& file)
{
    return (ImageHandler::GetInstance()->GetLoaderByFile(file) != NULL);
}

_CGUL_EXPORT bool CGUL::Image::Load(const String& file)
{
    ImageLoader* loader = ImageHandler::GetInstance()->GetLoaderByFile(file);
    if (loader == NULL)
        return false;

    Image* img = loader->Load(file);
    if (img == NULL)
        return false;

    this->format = img->GetFormat();
    this->width = img->GetWidth();
    this->height = img->GetHeight();
    this->pixelSize = img->GetPixelSize();
    this->dataSize = img->GetDataSize();
    this->data = img->GetData();

    return true;
}

_CGUL_EXPORT void* CGUL::Image::GetData()
{
    return data;
}

_CGUL_EXPORT CGUL::ImageFormat CGUL::Image::GetFormat()
{
    return this->format;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Image::GetWidth()
{
    return this->width;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Image::GetHeight()
{
    return this->height;
}

_CGUL_EXPORT CGUL::Size CGUL::Image::GetPixelSize()
{
    return this->pixelSize;    
}

_CGUL_EXPORT CGUL::Size CGUL::Image::GetDataSize()
{
    return this->dataSize;
}
