/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "JPEG.h"
#include "../../Utility/File.h"
#include "../ImageFormats.h"
#include "../../Exceptions/ImageException.h"

#ifndef XMD_H
#   define XMD_H
#endif
#define boolean bool
extern "C"
{
#   include <jpeglib.h>
}
#undef boolean
#include <setjmp.h>
#include <stdlib.h>

_JATTA_EXPORT bool Jatta::ImageLoaders::JPEG::CanLoad(const String& file)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE * fp;
    fp = fopen(file.GetCString(), "rb");
    if (fp == NULL)
        return false;

    cinfo.err = jpeg_std_error(&jerr);

    jpeg_create_decompress(&cinfo);

    jpeg_stdio_src(&cinfo, fp);
    if (jpeg_read_header(&cinfo, TRUE) != JPEG_HEADER_OK)
    {
        fclose(fp);
        return false;
    }

    fclose(fp);
    return true;
}

_JATTA_EXPORT Jatta::Image* Jatta::ImageLoaders::JPEG::Load(const String& file)
{
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    //Step 1: Create file pointer to file.
    FILE * fp;
    JSAMPARRAY buffer;
    int row_stride;

    fp = fopen(file.GetCString(), "rb");
    if (fp == NULL)
        throw ImageException(ImageExceptionCode::JPEG, ImageExceptionReason::FAILED_TO_OPEN);

    cinfo.err = jpeg_std_error(&jerr);

    //Step 2: Allocate and intitialize JPEG decompression object
    jpeg_create_decompress(&cinfo);

    //Step 3: Get data source and read header.
    jpeg_stdio_src(&cinfo, fp);
    if (jpeg_read_header(&cinfo, TRUE) != JPEG_HEADER_OK)
        throw ImageException(ImageExceptionCode::JPEG, ImageExceptionReason::NOT_A_JPEG_FILE);

    //Step 4: Start decompressor
    if (!jpeg_start_decompress(&cinfo))
    {
        throw ImageException(ImageExceptionCode::JPEG, ImageExceptionReason::JPEG_FAILED_TO_START_DECOMPRESSOR);
    }

    row_stride = cinfo.output_width * cinfo.output_components;
    buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

    //Step 5: Read scan lines
    Byte* data = new Byte[row_stride*cinfo.output_height];
    //int writeIndex = 0; // TODO: is this variable needed?
    while (cinfo.output_scanline < cinfo.output_width)
    {
        (void)jpeg_read_scanlines(&cinfo, buffer, 1);
        //memcpy(&data[writeIndex], &buffer[0], row_stride);
        //writeIndex += row_stride;
    }

    //Step 6: Finish up jpeglib.
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(fp);

    //Step 7: Determine format
    ImageFormat format = ImageFormats::NONE;
    if (cinfo.output_components == 3)
    {
        format = ImageFormats::RGB8;
    }
    else if (cinfo.output_components == 4)
    {
        format = ImageFormats::RGBA8;
    }
    else
    {
        delete[] data;
        throw ImageException(ImageExceptionCode::JPEG, ImageExceptionReason::UNSUPPORTED_FORMAT);
    }

    //Step 8: Return image
    return new Image(format, cinfo.output_width, cinfo.output_height, (void*)data);
}

_JATTA_EXPORT void Jatta::ImageLoaders::JPEG::Save(const String& filename, Jatta::Image* image)
{
    //TODO: JPEG Saving.
}
