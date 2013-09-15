/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "BMP.h"
#include "../ImageFormats.h"
#include "../../Utility/File.h"
#include "../../Exceptions/ImageException.h"

struct _bmp_header
{
public:
    short magic_number;
    unsigned int size;
    short reserved1;
    short reserved2;
    unsigned int offset;

    void ReadBytes(Jatta::Byte* data, Jatta::UInt32 size)
    {
        if (size < 14)
            throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_DATA_FORMAT);

        memcpy(&magic_number, &data[0], 2);
        memcpy(&size, &data[2], 4);
        memcpy(&reserved1, &data[6], 2);
        memcpy(&reserved2, &data[8], 2);
        memcpy(&offset, &data[10], 4);
    }
};

struct _bmp_dib_header
{
public:
    unsigned int size;
    int width;
    int height;
    short colorPlaneCount;
    short bpp;
    unsigned int compressionMethod;
    unsigned int imageSize;
    int horizontalResolution;
    int verticalResolution;
    unsigned int colors;
    unsigned int importantColors;
    
    void ReadBytes(Jatta::Byte* data, Jatta::UInt32 size)
    {
        if (size < 12)
            throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_DATA_FORMAT);

        memcpy(&size, &data[0], 4);

        if (size == 12)
        {
            memcpy(&width, &data[4], 2);
            memcpy(&height, &data[6], 2);
            memcpy(&colorPlaneCount, &data[8], 2);
            memcpy(&bpp, &data[10], 2);
        }
        else if (size == 40)
        {
            memcpy(&width, &data[4], 4);
            memcpy(&height, &data[8], 4);
            memcpy(&colorPlaneCount, &data[12], 2);
            memcpy(&bpp, &data[14], 2);
            memcpy(&compressionMethod, &data[16], 4);
            memcpy(&imageSize, &data[20], 4);
            memcpy(&horizontalResolution, &data[24], 4);
            memcpy(&verticalResolution, &data[28], 4);
            memcpy(&colors, &data[32], 4);
            memcpy(&importantColors, &data[36], 4);
        }

        if (colorPlaneCount != 1)
            throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_COLOR_PLANE_COUNT);
    }
};

_JATTA_EXPORT Jatta::ImageLoaders::BMP::BMP(const String& filename) : ImageLoader(filename)
{
    file = filename;
}
_JATTA_EXPORT Jatta::ImageLoaders::BMP::~BMP()
{
    Free();
}

_JATTA_EXPORT void Jatta::ImageLoaders::BMP::Free()
{

}

_JATTA_EXPORT bool Jatta::ImageLoaders::BMP::CanLoad()
{
    Byte* buffer = new Byte[2];
    File::ReadData(file, buffer, 2);

    if (buffer[0] == 0x42 && buffer[1] == 0x4D)
        return true;
    return false;
}

_JATTA_EXPORT Jatta::ImageInfo Jatta::ImageLoaders::BMP::GetImageInfo()
{
    ImageInfo ret;
    ret.Format = ImageFormats::NONE;
    ret.Width = ret.Height = 0;
    ret.MipmapCount = 0;

    if (!CanLoad())
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::NOT_A_BMP_FILE);

    unsigned int fileSize = File::GetFileSize(file);
    if (fileSize < 56)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_DATA_FORMAT);

    Byte* buffer = new Byte[56];
    File::ReadData(file, buffer, 56);

    _bmp_header header;
    _bmp_dib_header dibHeader;

    header.ReadBytes(buffer, 14);
    dibHeader.ReadBytes(&buffer[14], 40);
}

_JATTA_EXPORT Jatta::Image* Jatta::ImageLoaders::BMP::Load()
{
    if (!CanLoad())
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::NOT_A_BMP_FILE);

    unsigned int fileSize = File::GetFileSize(file);
    Byte* buffer = new Byte[fileSize];
    File::ReadData(file, buffer, fileSize);

    _bmp_header header;
    _bmp_dib_header dibHeader;

    header.ReadBytes(buffer, 14);
    dibHeader.ReadBytes(&buffer[14], 40);

    int rowSize = ((int) ((dibHeader.bpp * dibHeader.width + 31) / 32)) * 4;
    int index = header.offset;
    Byte* data = new Byte[dibHeader.height * dibHeader.width * (dibHeader.bpp / 8)];

    for (int y = dibHeader.height-1; y >= 0; y--)
    {
        int count = (dibHeader.bpp / 8);
        for (int x = 0; x < dibHeader.width; x++)
        {
            memcpy(&data[y*dibHeader.width*count+x*count], &buffer[index], count);
            index += count;
        }

        index += (rowSize - (count * dibHeader.width));
    }

    ImageFormat format = ImageFormats::BGR8;
    if (dibHeader.bpp == 32)
        format = ImageFormats::BGRA8;

    return new Image(format, dibHeader.width, dibHeader.height, (void*)data);
}