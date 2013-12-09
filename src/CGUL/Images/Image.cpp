// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Image.cpp
 */

#include "Image.hpp"
#include "../Utility/Memory.hpp"
#include "../Exceptions/ImageException.hpp"

_CGUL_EXPORT CGUL::Image::Image() :
    size(0, 0),
    pixelSize(0),
    dataSize(0),
    data(NULL)
{
}

_CGUL_EXPORT CGUL::Image::Image(const Image& copy) :
    format(copy.format),
    size(copy.size),
    pixelSize(copy.pixelSize),
    dataSize(copy.dataSize),
    data(new char[copy.GetSize().MultiplyComponents() * pixelSize])
{
    Memory::Copy(data, copy.data, copy.GetSize().MultiplyComponents() * pixelSize);
}

_CGUL_EXPORT CGUL::Image::Image(ImageFormat format, UCoord32 size) :
    format(format),
    size(size),
    pixelSize((format.redBits + format.blueBits + format.greenBits + format.alphaBits) / 8),
    data(NULL)
{
    switch (format.dataType)
    {
        case DataTypes::UNSIGNED_CHAR:
        {
            this->data = new unsigned char[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
        case DataTypes::SIGNED_CHAR:
        {
            this->data = new char[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
        case DataTypes::FLOAT32:
        {
            this->data = new Float32[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
        case DataTypes::FLOAT64:
        {
            this->data = new Float64[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
        case DataTypes::UINT32:
        {
            this->data = new UInt32[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
        case DataTypes::UINT64:
        {
            this->data = new UInt64[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
        case DataTypes::SINT32:
        {
            this->data = new SInt32[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
        case DataTypes::SINT64:
        {
            this->data = new SInt64[this->size.MultiplyComponents() * this->pixelSize];
            break;
        }
    }
}

_CGUL_EXPORT CGUL::Image::Image(ImageFormat format, UCoord32 size, void* data) :
    format(format),
    size(size),
    pixelSize((format.redBits + format.blueBits + format.greenBits + format.alphaBits) / 8),
    data(data)
{
}

_CGUL_EXPORT CGUL::Image::~Image()
{
    delete[] (char*)this->data;
}

_CGUL_EXPORT bool CGUL::Image::CanLoad(const String& file) const
{
    return (ImageHandler::GetInstance()->GetLoaderByFile(file) != NULL);
}

_CGUL_EXPORT void CGUL::Image::Load(const String& file)
{
    ImageLoader* loader = ImageHandler::GetInstance()->GetLoaderByFile(file);
    if (loader == NULL)
    {
        throw std::runtime_error("No valid loader for this image file.");
    }

    loader->Load(file, this);
}

_CGUL_EXPORT void CGUL::Image::Setup(ImageFormat format, UCoord32 size, void* data)
{
    Free();

    this->format = format;
    this->size = size;
    this->pixelSize = (format.redBits + format.blueBits + format.greenBits + format.alphaBits) / 8;
    this->data = data;
}

_CGUL_EXPORT void CGUL::Image::Save(const String& file, const String& extension) const
{
    ImageLoader* loader = ImageHandler::GetInstance()->GetLoaderByExtension(extension.GetLower());
    if (loader == NULL)
    {
        throw std::runtime_error("No valid loader for this image extension.");
    }

    loader->Save(file, this);
}

_CGUL_EXPORT CGUL::ImageFormat CGUL::Image::GetFormat() const
{
    return this->format;
}

_CGUL_EXPORT CGUL::UCoord32 CGUL::Image::GetSize() const
{
    return this->size;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Image::GetWidth() const
{
    return this->size.x;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Image::GetHeight() const
{
    return this->size.y;
}

_CGUL_EXPORT CGUL::Size CGUL::Image::GetPixelSize() const
{
    return this->pixelSize;
}

_CGUL_EXPORT CGUL::Size CGUL::Image::GetDataSize() const
{
    return this->dataSize;
}

_CGUL_EXPORT bool CGUL::Image::IsValid() const
{
    return this->data != NULL;
}

_CGUL_EXPORT void CGUL::Image::Free()
{
    delete[] (char*)this->data;
    this->data = NULL;
}
