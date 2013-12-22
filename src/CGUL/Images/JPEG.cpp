// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file JPEG.cpp
 */

#include "JPEG.hpp"
#include "../Exceptions/ImageException.hpp"
#include "../Utility/File.hpp"
#include "../Utility/Memory.hpp"

#ifndef XMD_H //Fixes broken shit.
#   define XMD_H
#endif

#define boolean bool
extern "C"
{
#   include <jpeglib.h>
}
#undef boolean

struct jpegErrorMgr
{
    struct jpeg_error_mgr pub;
    jmp_buf setjmpBuffer;
};

void jpegErrorExit(j_common_ptr cinfo)
{
    jpegErrorMgr * myErr = (jpegErrorMgr *)cinfo->err;
    (*cinfo->err->output_message)(cinfo);
    longjmp(myErr->setjmpBuffer, 1);
}

_CGUL_EXPORT CGUL::ImageLoaders::JPEG::JPEG() : CGUL::ImageLoader("Joint Photographic Experts Group", "JPG")
{

}

_CGUL_EXPORT CGUL::ImageLoaders::JPEG::~JPEG()
{

}

_CGUL_EXPORT bool CGUL::ImageLoaders::JPEG::CanLoad(const String& file)
{
    Byte header[2];
    File::ReadData(file, header, 2);

    return (header[0] == 0xFF && header[1] == 0xD8);
}

_CGUL_EXPORT void CGUL::ImageLoaders::JPEG::Load(const String& file, Image* image)
{
    jpegErrorMgr jerr;
    struct jpeg_decompress_struct cinfo;

    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = jpegErrorExit;
    if (setjmp(jerr.setjmpBuffer))
    {
        jpeg_destroy_decompress(&cinfo);
        throw ImageException(ImageExceptionCode::JPEG, ImageExceptionReason::UNKNOWN);
    }

#   ifdef MSVC
    FILE* fp;
    fopen_s(&fp, file.GetCString(), "rb");
#   else
    FILE* fp = fopen(file.GetCString(), "rb");
#   endif

    JSAMPARRAY buffer;
    UInt32 rowStride;

    if (!fp)
    {
        throw ImageException(ImageExceptionCode::JPEG, ImageExceptionReason::FAILED_TO_OPEN);
    }

    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, fp);

    if (jpeg_read_header(&cinfo, TRUE) != JPEG_HEADER_OK)
    {
        throw ImageException(ImageExceptionCode::JPEG, ImageExceptionReason::NOT_A_JPEG_FILE);
    }
    jpeg_start_decompress(&cinfo);
    rowStride = cinfo.output_width * cinfo.output_components;
    buffer = (*cinfo.mem->alloc_sarray)((j_common_ptr) &cinfo, JPOOL_IMAGE, rowStride, 1);

    ImageFormat format;
    int pixelSize = 0;
    if (cinfo.output_components == 3)
    {
        format = ImageFormats::RGB;
        pixelSize = 3;
    }
    else if (cinfo.output_components == 4)
    {
        format = ImageFormats::RGBA;
        pixelSize = 4;
    }
    format.dataType = DataTypes::UNSIGNED_CHAR;

    Byte* data = new Byte[cinfo.output_width * cinfo.output_height * cinfo.output_components];
    UInt32 writeIndex = 0;
    while (cinfo.output_scanline < cinfo.output_height) 
    {
        jpeg_read_scanlines(&cinfo, buffer, 1);
        Memory::Copy(&data[writeIndex], buffer[0], rowStride);
        writeIndex += rowStride;
        if (writeIndex >= cinfo.output_width * cinfo.output_height * cinfo.output_components)
            break;
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(fp);

    image->Setup(format, UCoord32(cinfo.output_width, cinfo.output_height), (void*)data);
}

_CGUL_EXPORT void CGUL::ImageLoaders::JPEG::Save(const String& file, const Image* image) const
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
        throw std::runtime_error("Failed to open PNG file for saving.");
    }

    struct jpeg_error_mgr jerr;
    struct jpeg_compress_struct cinfo;

    //Get depth and type.
    UInt32 numComponents; 
    J_COLOR_SPACE type;
    if (image->GetFormat() == ImageFormats::RGB)
    {
        numComponents = 3;
        type = JCS_RGB;
    }
    else
    {
        //TODO: Support more?
        fclose(fp);
        throw std::runtime_error("Image's format not supported.");
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, fp);
    cinfo.image_width = image->GetWidth();
    cinfo.image_height = image->GetHeight();
    cinfo.input_components = numComponents;
    cinfo.in_color_space = type;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, 100, TRUE);
    jpeg_start_compress(&cinfo, TRUE);

    UInt32 stride = image->GetWidth() * numComponents;
    while (cinfo.next_scanline < cinfo.image_height)
    {
        unsigned char* data = (unsigned char*)image->GetData< unsigned char >();
        data = data + cinfo.next_scanline * stride;
        JSAMPROW row_pointer = data;
        jpeg_write_scanlines(&cinfo, &row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);

    fclose(fp);
}
