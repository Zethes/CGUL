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
_CGUL_EXPORT CGUL::Image* CGUL::ImageLoaders::PNG::Load(const String& file)
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
    return new Image(format, width, height, (void*)data);
}