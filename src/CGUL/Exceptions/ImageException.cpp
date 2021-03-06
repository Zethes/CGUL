// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ImageException.cpp
 */

// Header
#include "ImageException.hpp"

_CGUL_EXPORT CGUL::ImageException::ImageException(UInt8 code, UInt8 reason) : Exception(code, reason, ExceptionType::IMAGE)
{
}

_CGUL_EXPORT CGUL::String CGUL::ImageException::GetString() const
{
    switch (info.code)
    {
        case ImageExceptionCode::MIX_IMAGES:
            return U8("Failed to mix images together.");
        case ImageExceptionCode::TRANSFORM:
            return U8("Failed to transform image.");
        case ImageExceptionCode::BMP:
            return U8("Failed to load BMP file.");
        case ImageExceptionCode::PNG:
            return U8("Failed to load PNG file.");
        case ImageExceptionCode::JPEG:
            return U8("Failed to load JPEG file.");
        case ImageExceptionCode::BMP_WRITE:
            return U8("Failed to save BMP file.");
        case ImageExceptionCode::PNG_WRITE:
            return U8("Failed to save PNG file.");
        case ImageExceptionCode::JPEG_WRITE:
            return U8("Failed to save JPEG file.");
        case ImageExceptionCode::PPM:
            return U8("Failed to load PPM file.");
        case ImageExceptionCode::PPM_WRITE:
            return U8("Failed to save JPEG file.");
        case ImageExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

_CGUL_EXPORT CGUL::String CGUL::ImageException::GetReason() const
{
    switch (info.reason)
    {
        case ImageExceptionReason::IMAGE_IS_NOT_VALID:
            return U8("Image is invalid/not loaded.");
        case ImageExceptionReason::NO_BASE_MIPMAP:
            return U8("No base mipmap found.");
        case ImageExceptionReason::INDEX_OUT_OF_RANGE:
            return U8("Index is out of range.");
        case ImageExceptionReason::INVALID_DATA_FORMAT:
            return U8("Data is in an invalid format.");
        case ImageExceptionReason::INVALID_COLOR_PLANE_COUNT:
            return U8("Invalid number of color planes being used. (Must be one)");
        case ImageExceptionReason::NOT_A_BMP_FILE:
            return U8("File is not a BMP file.");
        case ImageExceptionReason::UNSUPPORTED_FORMAT:
            return U8("Unsupported format.");
        case ImageExceptionReason::NOT_A_PNG_FILE:
            return U8("File is not a PNG file.");
        case ImageExceptionReason::PNG_CREATE_READ_STRUCT_FAILED:
            return U8("png_create_read_struct failed.");
        case ImageExceptionReason::PNG_CREATE_INFO_STRUCT_FAILED:
            return U8("png_create_info_struct failed.");
        case ImageExceptionReason::PNG_INIT_IO_ERROR:
            return U8("Error during init_io.");
        case ImageExceptionReason::FAILED_TO_OPEN:
            return U8("Failed to open file.");
        case ImageExceptionReason::PNG_READ_IMAGE_ERROR:
            return U8("Error during read_image.");
        case ImageExceptionReason::NOT_A_JPEG_FILE:
            return U8("File is not a JPEG file.");
        case ImageExceptionReason::JPEG_FAILED_TO_START_DECOMPRESSOR:
            return U8("Failed to start the decompressor.");
        case ImageExceptionReason::NULL_POINTER:
            return U8("A null pointer was passed in.");
        case ImageExceptionReason::FAILED_WRITE_HEADER:
            return U8("Failed to write header.");
        case ImageExceptionReason::FAILED_WRITE_IMAGE:
            return U8("Failed to write image data.");
        case ImageExceptionReason::INVALID_MIXING_METHOD:
            return U8("Invalid image mixing method.");
        case ImageExceptionReason::UNKNOWN:
        default:
            return U8("Unknown.");
    }
}
