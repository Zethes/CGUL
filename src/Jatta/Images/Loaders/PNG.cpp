/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "PNG.h"
#include "../../Utility/File.h"
#include "../ImageFormats.h"
#include "../../Exceptions/ImageException.h"

#include <png.h>
#include <stdlib.h>
#define PNGSIGSIZE 8

_JATTA_EXPORT Jatta::ImageLoaders::PNG::PNG(const String& filename) : ImageLoader(filename)
{
    file = filename;
}
_JATTA_EXPORT Jatta::ImageLoaders::PNG::~PNG()
{
    Free();
}

_JATTA_EXPORT void Jatta::ImageLoaders::PNG::Free()
{

}

_JATTA_EXPORT bool Jatta::ImageLoaders::PNG::CanLoad()
{
    UInt32 fileSize = File::GetFileSize(file);
    if (fileSize < PNGSIGSIZE)
        return false;

    Byte* data = new Byte[PNGSIGSIZE];
    File::ReadData(file, data, PNGSIGSIZE);

    return png_sig_cmp((png_bytep)data, 0, PNGSIGSIZE) == 0;
}

_JATTA_EXPORT Jatta::ImageInfo Jatta::ImageLoaders::PNG::GetImageInfo()
{

}

_JATTA_EXPORT Jatta::Image* Jatta::ImageLoaders::PNG::Load()
{
    //Sanity check
    if (!CanLoad())
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::NOT_A_PNG_FILE);

    char header[8];
    FILE * fp = fopen(file.GetCString(), "rb");
    if (!fp)
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_FAILED_TO_OPEN);
    fread(header, 1, 8, fp);

    //Initialize structs
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr)
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_CREATE_READ_STRUCT_FAILED);

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_CREATE_INFO_STRUCT_FAILED);

    if (setjmp(png_jmpbuf(png_ptr)))
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_INIT_IO_ERROR);

    //Read header.
    png_init_io(png_ptr, fp);
    png_set_sig_bytes(png_ptr, 8);
    png_read_info(png_ptr, info_ptr);

    int width = png_get_image_width(png_ptr, info_ptr);
    int height = png_get_image_height(png_ptr, info_ptr);
    int colorType = png_get_color_type(png_ptr, info_ptr);
    int bitDepth = png_get_bit_depth(png_ptr, info_ptr);

    int numberOfPasses = png_set_interlace_handling(png_ptr);
    png_read_update_info(png_ptr, info_ptr);

    //Get format information
    ImageFormat format = ImageFormats::NONE;
    int pixelSize = 0;
    switch (colorType)
    {
        case PNG_COLOR_TYPE_RGBA:
        format = ImageFormats::RGBA8;
        pixelSize = 4;
        break;
        case PNG_COLOR_TYPE_RGB:
        format = ImageFormats::RGB8;
        pixelSize = 3;
        break;
        default:
            throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::UNSUPPORTED_FORMAT);
    }

    //Read pixels.
    if (setjmp(png_jmpbuf(png_ptr)))
        throw ImageException(ImageExceptionCode::PNG, ImageExceptionReason::PNG_READ_IMAGE_ERROR);

    Byte* data = new Byte[width * height * pixelSize];
    png_bytep * rows = new png_bytep[height];
    for (UInt32 y = 0; y < height; y++)
        rows[y] = (png_bytep)(data + width * y * pixelSize);
    png_read_image(png_ptr, rows);
    fclose(fp);

    delete[] rows;
    return new Image(format, width, height, (void*)data);
}