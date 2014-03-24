// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Image.cpp
 */

#include "Image.hpp"
#include "../Utility/Memory.hpp"
#include "../Exceptions/ImageException.hpp"

_CGUL_EXPORT CGUL::Image* CGUL::Image::AdjustBrightness(Image* img, Float32 amt)
{
    Image* out = new Image(*img);

    Byte* data = new Byte[img->dataSize];
    data = img->GetData<Byte>();

    for (UInt32 i = 0; i < img->dataSize; i += img->pixelSize)
    {
        for (UInt32 j = 0; j < img->pixelSize; ++j)
        {
            if (j < 4) //Ignore alpha channel
            {
                ((Byte*)out->data)[i+j] = (Byte)Math::Max(Math::Min(data[i+j] * amt, 255.0f), 0.0f);
            }
        }
    }

    return out;
}

_CGUL_EXPORT CGUL::Image* CGUL::Image::GetNegative(Image* img)
{
    Image* out = new Image(*img);

    Byte* data = new Byte[img->dataSize];
    data = img->GetData<Byte>();

    for (UInt32 i = 0; i < img->dataSize; i += img->pixelSize)
    {
        for (UInt32 j = 0; j < img->pixelSize; ++j)
        {
            if (j < 4) //Ignore alpha channel
            {
                ((Byte*)out->data)[i+j] = (Byte)Math::Max(Math::Min(255.0f - data[i+j], 255.0f), 0.0f);
            }
        }
    }

    return out;
}

_CGUL_EXPORT CGUL::Image* CGUL::Image::GetGrayscale(Image* img)
{
    Image* out = new Image();

    Byte* data = new Byte[img->dataSize];
    data = img->GetData<Byte>();

    Byte* newdata = new Byte[img->GetWidth() * img->GetHeight()];
    UInt32 writeIndex = 0;

    for (UInt32 i = 0; i < img->dataSize; i += img->pixelSize)
    {
        Float32 c = 0;
        Float32 total = 0;
        for (UInt32 j = 0; j < img->pixelSize; ++j)
        {
            if (j < 4) //Ignore alpha channel
            {
                total += data[i+j];
                c++;
            }
        }
        newdata[writeIndex++] = (Byte)Math::Max(Math::Min((total / c), 255.0f), 0.0f);
    }

    out->Setup(ImageFormats::GRAYSCALE, UCoord32(img->GetWidth(), img->GetHeight()), newdata);
    return out;
}

_CGUL_EXPORT CGUL::Image* CGUL::Image::SwapColors(Image* img, Color pre, Color post)
{
    Image* out = new Image(*img);

    Byte* data = new Byte[img->dataSize];
    data = img->GetData<Byte>();

    Byte* oldColor = new Byte[img->pixelSize];
    Byte* newColor = new Byte[img->pixelSize];
    oldColor[0] = pre.r;
    newColor[0] = post.r;
    if (img->pixelSize == 2)
    {
        //?
    }
    else if (img->pixelSize >= 3)
    {
        oldColor[1] = pre.g;
        oldColor[2] = pre.b;
        newColor[1] = post.g;
        newColor[2] = post.b;
    }

    if (img->pixelSize >= 4)
    {
        oldColor[3] = pre.a;
        newColor[3] = post.a;
    }

    for (UInt32 i = 0; i < img->dataSize; i += img->pixelSize)
    {
        Float32 c = 0;
        Float32 total = 0;
        bool good = true;
        for (UInt32 j = 0; j < img->pixelSize; ++j)
        {
            if (oldColor[j] != data[i+j])
            {
                good = false;
                break;
            }
        }
        if (good)
        {
            for (UInt32 j = 0; j < img->pixelSize; ++j)
            {
                ((Byte*)out->data)[i+j] = newColor[j];
            }
        }
    }

    return out;
}

_CGUL_EXPORT CGUL::Image* CGUL::Image::Mix(Image* one, Image* two, UInt32 method)
{
    if (one->pixelSize != two->pixelSize)
    {
        //Adjust to work with it?
        return NULL;
    }

    Image* out = new Image(*one);

    Byte* data1 = new Byte[one->dataSize];
    data1 = one->GetData<Byte>();
    Byte* data2 = new Byte[two->dataSize];
    data2 = two->GetData<Byte>();

    for (UInt32 i = 0; i < one->dataSize && i < two->dataSize;  i += one->pixelSize)
    {
        for (UInt32 j = 0; j < one->pixelSize; ++j)
        {
            if (j < 4) //Ignore alpha channel
            {
                Byte x = data1[i+j];
                Byte y = data2[i+j];
                Byte res = 0;
                switch (method)
                {
                    case ImageMixMethods::ADD:
                        res = Math::Min(x + y, 255);
                    break;
                    case ImageMixMethods::AMPLITUDE:
                        res = (Byte)Math::Floor(Math::Sqrt(Float32(x * x + x * x)) / (Float32)Math::Sqrt2);
                    break;
                    case ImageMixMethods::AND:
                        res = x & y;
                    break;
                    case ImageMixMethods::AVERAGE:
                        res = (x + y) / 2;
                    break;
                    case ImageMixMethods::CROSS_FADING:
                        res = (Byte)Math::Floor(Float32(x) * 0.75f + Float32(y) * 0.25f);
                    break;
                    case ImageMixMethods::DIFF:
                        res = (Byte)Math::Abs(Float32(x) - Float32(y));
                    break;
                    case ImageMixMethods::MAX:
                        res = Math::Max(x, y);
                    break;
                    case ImageMixMethods::MIN:
                        res = Math::Min(x, y);
                    break;
                    case ImageMixMethods::MULTIPLY:
                        res = (Byte)Math::Floor(255.0f * (Float32(x) / 255.0f * Float32(y) / 255.0f));
                    break;
                    case ImageMixMethods::OR:
                        res = x | y;
                    break;
                    case ImageMixMethods::SUBTRACT:
                        res = (Byte)Math::Max(Float32(x) - Float32(y), 0.0f);
                    break;
                    case ImageMixMethods::XOR:
                        res = x ^ y;
                    break;
                    default:
                        res = (x + y) / 2;
                }

                ((Byte*)out->data)[i+j] = res;
            }
        }
    }

    return out;
}

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
    dataSize(0),
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
    dataSize(0), // TODO: set this to something meaningful?
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
    this->dataSize = size.x * size.y * pixelSize;
}

_CGUL_INLINE_IMPLEMENT CGUL::Color CGUL::Image::GetPixel(UInt32 x, UInt32 y)
{
    if (y*size.x*pixelSize + x*pixelSize + pixelSize-1 > dataSize)
    {
        return Color(0,0,0,0);
    }

    Byte* v = new Byte[pixelSize];
    for (UInt32 i = 0; i < pixelSize; ++i)
    {
        v[i] = ((Byte*)data)[y*size.x*pixelSize + x*pixelSize + i];
    }

    Color ret(0,0,0,255);
    ret.r = v[0];
    if (pixelSize == 1)
    {
        ret.g = v[0];
    }
    else if (pixelSize == 2)
    {
        //?
    }
    else if (pixelSize >= 3)
    {
        ret.g = v[1];
        ret.b = v[2];
    }

    if (pixelSize >= 4)
    {
        ret.a = v[3];
    }

    return ret;
}

_CGUL_INLINE_IMPLEMENT void CGUL::Image::SetPixel(UInt32 x, UInt32 y, Color pixel)
{
    if (y*size.x*pixelSize + x*pixelSize + pixelSize-1 > dataSize)
    {
        return;
    }

    Byte * v = new Byte[pixelSize];
    if (pixelSize == 1)
    {
        v[0] = pixel.r;
    }
    else if (pixelSize == 2)
    {
        //?
    }
    else if (pixelSize >= 3)
    {
        v[0] = pixel.r;
        v[1] = pixel.g;
        v[2] = pixel.b;
    }

    if (pixelSize >= 4)
    {
        v[3] = pixel.a;
    }

    for (UInt32 i = 0; i < pixelSize; ++i)
    {
        ((Byte*)data)[y*size.x*pixelSize + x*pixelSize + i] = v[i];
    }
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
