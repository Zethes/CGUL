// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file PNG.cpp
 */

#include "PNG.hpp"
#include "../Utility/File.hpp"
#include "../Exceptions/ImageException.hpp"

#include <png.h>
#include <stdlib.h>
#define PNGSIGSIZE 8

_CGUL_EXPORT CGUL::ImageLoaders::PNG::PNG() : CGUL::ImageLoader("Portable Network Graphics", "PNG")
{

}

_CGUL_EXPORT CGUL::ImageLoaders::PNG::~PNG()
{

}

_CGUL_EXPORT bool CGUL::ImageLoaders::PNG::CanLoad(const String& file)
{
    UInt32 fileSize = File::GetFileSize(file);
    if (fileSize < PNGSIGSIZE)
    {
        return false;
    }

    Byte* data = new Byte[PNGSIGSIZE];
    File::ReadData(file, data, PNGSIGSIZE);

    return (png_sig_cmp((png_bytep)data, 0, PNGSIGSIZE) == 0);
}

_CGUL_EXPORT void CGUL::ImageLoaders::PNG::Load(const String& file, Image* image)
{
    if (!CanLoad(file))
    {
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::NOT_A_PNG_FILE);
    }

    char header[8];
#   ifdef MSVC
    FILE* fp;
    fopen_s(&fp, file.GetCString(), "rb");
#   else
    FILE* fp = fopen(file.GetCString(), "rb");
#   endif

    if (!fp)
    {
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::FAILED_TO_OPEN);
    }
    fread(header, 1, 8, fp);

    //Inititialize structs
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr)
    {
        fclose(fp);
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_CREATE_READ_STRUCT_FAILED);
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        fclose(fp);
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_CREATE_INFO_STRUCT_FAILED);
    }

    if (setjmp(png_jmpbuf(png_ptr)))
    {
        fclose(fp);
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_INIT_IO_ERROR);
    }

    //Read header.
    png_init_io(png_ptr, fp);
    png_set_sig_bytes(png_ptr, 8);
    png_read_info(png_ptr, info_ptr);

    UInt32 width = (UInt32)png_get_image_width(png_ptr, info_ptr);
    UInt32 height = (UInt32)png_get_image_height(png_ptr, info_ptr);
    int colorType = png_get_color_type(png_ptr, info_ptr);
    int bitDepth = png_get_bit_depth(png_ptr, info_ptr); // TODO: remove this? unused

    //int numberOfPasses = png_set_interlace_handling(png_ptr); // TODO: remove this? unused
    png_read_update_info(png_ptr, info_ptr);

    //Get format information
    ImageFormat format = ImageFormats::RGBA8;
    int pixelSize = 0;
    switch (colorType)
    {
        case PNG_COLOR_TYPE_RGBA:
        {
            if (bitDepth == 8)
            {
                format = ImageFormats::RGBA8;
            }
            else if (bitDepth == 16)
            {
                format = ImageFormats::RGBA16;
            }
            else
            {
                fclose(fp);
                throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::UNSUPPORTED_FORMAT);
            }

            pixelSize = 4;
            break;
        }
        case PNG_COLOR_TYPE_RGB:
        {
            if (bitDepth == 8)
            {
                format = ImageFormats::RGB8;
            }
            else if (bitDepth == 16)
            {
                format = ImageFormats::RGB16;
            }
            else
            {
                fclose(fp);
                throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::UNSUPPORTED_FORMAT);
            }

            pixelSize = 3;
            break;
        }
        default:
        {
            fclose(fp);
            throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::UNSUPPORTED_FORMAT);
        }
    }
    format.dataType = DataTypes::UNSIGNED_CHAR;

    //Read pixels.
    if (setjmp(png_jmpbuf(png_ptr)))
    {
        fclose(fp);
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_READ_IMAGE_ERROR);
    }

    Byte* data = new Byte[width * height * pixelSize];
    png_bytep * rows = new png_bytep[height];
    for (UInt32 y = 0; y < height; y++)
    {
        rows[y] = (png_bytep)(data + width * y * pixelSize);
    }
    png_read_image(png_ptr, rows);
    fclose(fp);

    delete[] rows;

    image->Setup(format, UCoord32(width, height), (void*)data);
}

_CGUL_EXPORT void CGUL::ImageLoaders::PNG::Save(const String& file, const Image* image) const
{
    if (image == NULL)
    {
        throw std::runtime_error("No image provided to save.");
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
        throw std::runtime_error("Failed to open PNG file for saving.");;
    }

    //Setup structs.
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    png_byte ** row_pointers = NULL;

    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL)
    {
        fclose(fp);
        throw std::runtime_error("Failed to create libpng pointer.");
    }

    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL)
    {
        fclose(fp);
        throw std::runtime_error("Failed to create png info struct.");
    }

    //Get depth and type.
    UInt32 depth, type;
    if (image->GetFormat() == ImageFormats::RGB8 || image->GetFormat() == ImageFormats::RGB)
    {
        depth = 8;
        type = PNG_COLOR_TYPE_RGB;
    }
    else if (image->GetFormat() == ImageFormats::RGB16)
    {
        depth = 16;
        type = PNG_COLOR_TYPE_RGB;
    }
    else if (image->GetFormat() == ImageFormats::RGBA8 || image->GetFormat() == ImageFormats::RGBA)
    {
        depth = 8;
        type = PNG_COLOR_TYPE_RGB_ALPHA;
    }
    else if (image->GetFormat() == ImageFormats::RGBA16)
    {
        depth = 16;
        type = PNG_COLOR_TYPE_RGB_ALPHA;
    }
    else
    {
        //TODO: Support PNG_COLOR_TYPE_GRAY, PNG_COLOR_TYPE_GRAY_ALPHA, PNG_COLOR_TYPE_PALLETTE, PNG_COLOR_MASK_PALLETTE, PNG_COLOR_MASK_COLOR, PNG_COLOR_MASK_ALPHA
        //See http://refspecs.linuxbase.org/LSB_3.1.0/LSB-Desktop-generic/LSB-Desktop-generic/libpng12.png.set.ihdr.1.html for more information.
        //As well as non-byte data storage.
        fclose(fp);
        throw std::runtime_error("Image's format not supported.");
    }

    png_set_IHDR(png_ptr, info_ptr, image->GetWidth(), image->GetHeight(), depth, type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    //Save the data.
    const unsigned char* data = image->GetData< unsigned char >();
    UInt32 pixelSize = image->GetPixelSize();
    row_pointers = (png_byte **)png_malloc(png_ptr, image->GetHeight() * sizeof(png_byte *));
    for (UInt32 y = 0; y < image->GetHeight(); ++y)
    {
        png_byte * row = (png_byte *)png_malloc(png_ptr, sizeof(uint8_t) * image->GetWidth() * pixelSize);
        row_pointers[y] = row;
        for (UInt32 x = 0; x < image->GetWidth(); ++x)
        {
            for (UInt32 i = 0; i < pixelSize; ++i)
            {
                *row++ = data[(y*pixelSize*image->GetWidth())+(x*pixelSize)+i];
            }
        }
    }

    png_init_io(png_ptr, fp);
    png_set_rows(png_ptr, info_ptr, row_pointers);
    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

    //Clean up
    for (UInt32 y = 0; y < image->GetHeight(); ++y)
    {
        png_free(png_ptr, row_pointers[y]);
    }
    png_free(png_ptr, row_pointers);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
}
