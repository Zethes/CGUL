// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file PPM.cpp
 */

// Header
#include "PPM.hpp"

// CGUL Includes
#include "../Exceptions/ImageException.hpp"
#include "../Utility/File.hpp"
#include "../Utility/Memory.hpp"

_CGUL_EXPORT CGUL::ImageLoaders::PPM::PPM() : CGUL::ImageLoader("Portable Pixmap", "PPM")
{
}

_CGUL_EXPORT CGUL::ImageLoaders::PPM::~PPM()
{
}

_CGUL_EXPORT bool CGUL::ImageLoaders::PPM::CanLoad(const String& file)
{
    Byte header[2];
    File::ReadData(file, header, 2);

    if (header[0] != 'P') 
    { 
        return false;
    }

    type = header[1];
    if (type < '1' || type > '6')
    {
        return false;
    }

    return true;
}

_CGUL_EXPORT void CGUL::ImageLoaders::PPM::Load(const String& file, Image* image)
{
    if (!CanLoad(file))
    {
        throw ImageException(ImageExceptionCode::PPM, ImageExceptionReason::FAILED_TO_OPEN);
    }

    UInt32 fileSize = File::GetFileSize(file);
    Byte* data = new Byte[fileSize];
    File::ReadData(file, data, fileSize);

    UInt32 w = 0, h = 0, max = 1;
    UInt32 pixel_size = 1;
    if (type == '3' || type == '6')
    {
        pixel_size = 3;
    }

    String size = "";
    UInt32 index = 3;
    char c = 0;
    UInt32 num = 0;
    while (c != 0x0A)
    {
        c = data[index++];
        if (c == 0x20)
        {
            w = num;
            num = 0;
        }
        else if (c >= '0' && c <= '9')
        {
            num *= 10;
            num += (c - '0'); //Width and Height are stored in ascii.
        }
    }
    h = num;

    if (type != '1' && type != '4') //Graymap and Pixmap have 2nd parameter.
    {
        num = 0;
        c = 0;
        while (c != 0x0A)
        {
            c = data[index++];
            if (c >= '0' && c <= '9')
            {
                num *= 10;
                num += (c - '0'); //Stored in ascii.
            }
        }
        max = num;
    }

    UInt32 actual_pixel_size = pixel_size;
    if (type >= '1' && type <= '3')
    {
        actual_pixel_size += (pixel_size - 1);
    }
    UInt32 write_index = 0;
    Byte* img = new Byte[w * h * pixel_size];
    for (UInt32 i = index; i < fileSize;)
    {
        for (UInt32 j = 0; j < actual_pixel_size; ++j)
        {
            UInt32 v = 0;
            if (type >= '1' && type <= '3')
            {
                c = 0;
                while (c != ' ')
                {
                    c = data[i];
                    if (c >= '0' && c <= '9')
                    {
                        v *= 10;
                        v += (c - '0');
                    }
                }
            }
            else
            {
                v = data[i];
            }
            img[write_index++] = UInt32((Float32(v) / Float32(max)) * 255.0f);
            i++;
        }
    }

    if (pixel_size == 1)
    {
        image->Setup(ImageFormats::GRAYSCALE, UCoord32(w, h), (void*)img);
    }
    else
    {
        image->Setup(ImageFormats::RGB, UCoord32(w, h), (void*)img);
    }
}

_CGUL_EXPORT void CGUL::ImageLoaders::PPM::Save(const String& file, const Image* image) const
{
     if (image == NULL)
    {
        throw ImageException(ImageExceptionCode::PPM_WRITE, ImageExceptionReason::IMAGE_IS_NOT_VALID);
    }

    //Open up file.
#   ifdef MSVC
    FILE* fp;
    fopen_s(&fp, file.GetCString(), "wb");
#   else
    FILE* fp = fopen(file.GetCString(), "wb");
#   endif

    if (fp == NULL)
    {
        throw ImageException(ImageExceptionCode::PPM_WRITE, ImageExceptionReason::FAILED_TO_OPEN);
    }

    UInt32 type = '5';
    UInt32 pixel_size = 1;
    if (image->GetFormat() == ImageFormats::GRAYSCALE)
    {
        pixel_size = 1;
        type = '5';
    }
    else if (image->GetFormat() == ImageFormats::RGB)
    {
        pixel_size = 3;
        type = '6';
    }
    else
    {
        fclose(fp);
        throw ImageException(ImageExceptionCode::PPM_WRITE, ImageExceptionReason::UNSUPPORTED_FORMAT);
    }

    UInt32 w = image->GetWidth();
    UInt32 h = image->GetHeight();

    fputc('P', fp);
    fputc(type, fp);
    fputc(0x0A, fp);
    std::vector<UInt32> sdata;
    while (w > 0)
    {
        UInt32 v = w % 10;
        w /= 10;
        sdata.push_back(v+'0');
    }
    for (SInt32 i = sdata.size()-1; i >= 0; --i)
    {
        fputc(sdata[i], fp);
    }
    sdata.clear();
    fputc(' ', fp);    
    while (h > 0)
    {
        UInt32 v = h % 10;
        h /= 10;
        sdata.push_back(v+'0');
    }
    for (SInt32 i = sdata.size()-1; i >= 0; --i)
    {
        fputc(sdata[i], fp);
    }
    fputc(0x0A, fp);
    fputc('2', fp);
    fputc('5', fp);
    fputc('5', fp);
    fputc(0x0A, fp);

    w = image->GetWidth();
    h = image->GetHeight();

    const Byte * img = new Byte[w * h * pixel_size];
    img = image->GetData<Byte>();

    for (UInt32 i = 0; i < w * h * pixel_size;)
    {
        for (UInt32 j = 0; j < pixel_size; ++j)
        {
            fputc(img[i++], fp);
        }
    }

    fclose(fp);
}
