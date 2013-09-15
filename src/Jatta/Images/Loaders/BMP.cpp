/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "BMP.h"
#include "../ImageFormats.h"
#include "../../Utility/File.h"
#include "../../Math/Math.h"
#include "../../Exceptions/ImageException.h"

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
    ret.MipmapCount = 1;

    if (!CanLoad())
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::NOT_A_BMP_FILE);

    unsigned int fileSize = File::GetFileSize(file);
    if (fileSize < 14)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_DATA_FORMAT);

    Byte* buffer = new Byte[fileSize];
    File::ReadData(file, buffer, fileSize);

    BITMAPHEADER header = ReadHeader(&buffer[0], fileSize);

    UInt32 dibHeaderSize;
    memcpy(&dibHeaderSize, &buffer[14], 4);
    BITMAPDIBHEADER dibHeader;
    dibHeader = ReadDIBHeader(&buffer[18], dibHeaderSize);
    ret.Width = dibHeader.Width;
    ret.Height = dibHeader.Height;
    return ret;
}

_JATTA_EXPORT Jatta::ImageLoaders::BITMAPHEADER Jatta::ImageLoaders::BMP::ReadHeader(Byte* data, UInt32 size)
{
    BITMAPHEADER header;

    if (size < 14)
       throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::NOT_A_BMP_FILE);
       
    memcpy(&header.MagicNumber, &data[0], 2);
    memcpy(&header.FileSize, &data[2], 4);
    memcpy(&header.Reserved1, &data[6], 2);
    memcpy(&header.Reserved2, &data[8], 2);
    memcpy(&header.Offset, &data[10], 4);

    return header;
}

_JATTA_EXPORT Jatta::ImageLoaders::BITMAPDIBHEADER Jatta::ImageLoaders::BMP::ReadDIBHeader(Byte* data, UInt32 size)
{
    BITMAPDIBHEADER header;
    header.Length = size;

    //Check to make sure it's a supported size.
    //Supported formats: BITMAPCOREHEADER, BITMAPINFOHEADER, BITMAPCOREHEADER2, BITMAPV4HEADER, BITMAPV5HEADER
    if (size != 12 && size != 40 && size != 64 && size != 108 && size != 124)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::UNSUPPORTED_FORMAT);

    //Must atleast be a BITMAPCOREINFO
    if (size < 12)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::UNSUPPORTED_FORMAT);

    int pos = 0;
    if (size == 12) //BITMAPCOREINFO uses shorts for width and height
    {
        memcpy(&header.Width, &data[0], 2);
        memcpy(&header.Height, &data[2], 2);
        memcpy(&header.Planes, &data[4], 2);
        memcpy(&header.BitCount, &data[6], 2);
        header.Compression = BMPCompressionMethods::RGB;
        return header;
    }
    
    memcpy(&header.Width, &data[0], 4);
    memcpy(&header.Height, &data[4], 4);
    memcpy(&header.Planes, &data[8], 2);
    memcpy(&header.BitCount, &data[10], 2);

    //BITMAPINFOHEADER
    if (size < 40)
    { header.Compression = BMPCompressionMethods::RGB; return header; }

    memcpy(&header.Compression, &data[12], 4);
    memcpy(&header.ImageSize, &data[16], 4);
    memcpy(&header.XPelsPerMeter, &data[20], 4);
    memcpy(&header.YPelsPerMeter, &data[24], 4);
    memcpy(&header.Used, &data[28], 4);
    memcpy(&header.Important, &data[32], 4);

    //BITMAPCOREHEADER2+
    if (size < 64)
        return header;

    if (size == 64) //BITMAPCOREHEADER2 has different data here.
    {
        memcpy(&header.ResUnit, &data[36], 2);
        memcpy(&header.Reserved2, &data[38], 2);
        memcpy(&header.Orientation, &data[40], 2);
        memcpy(&header.Halftoning, &data[42], 2);
        memcpy(&header.HalftoneSize1, &data[44], 4);
        memcpy(&header.HalftoneSize2, &data[48], 4);
        memcpy(&header.ColorSpace, &data[52], 4);
        memcpy(&header.AppData, &data[56], 4);
        return header;
    }

    //BITMAPV4HEADER
    memcpy(&header.RedMask, &data[36], 4);
    memcpy(&header.GreenMask, &data[40], 4);
    memcpy(&header.BlueMask, &data[44], 4);
    memcpy(&header.AlphaMask, &data[48], 4);
    memcpy(&header.CSType, &data[52], 4);

    //Read the endpoints in
    memcpy(&header.Endpoints.Red.X, &data[56], 4);
    memcpy(&header.Endpoints.Red.Y, &data[60], 4);
    memcpy(&header.Endpoints.Red.Z, &data[64], 4);
    memcpy(&header.Endpoints.Green.X, &data[68], 4);
    memcpy(&header.Endpoints.Green.Y, &data[72], 4);
    memcpy(&header.Endpoints.Green.Z, &data[76], 4);
    memcpy(&header.Endpoints.Blue.X, &data[80], 4);
    memcpy(&header.Endpoints.Blue.Y, &data[84], 4);
    memcpy(&header.Endpoints.Blue.Z, &data[88], 4);

    memcpy(&header.GammaRed, &data[92], 4);
    memcpy(&header.GammaGreen, &data[96], 4);
    memcpy(&header.GammaBlue, &data[100], 4);

    //BITMAPV5HEADER
    if (size < 124)
        return header;

    memcpy(&header.Intent, &data[104], 4);
    memcpy(&header.ProfileData, &data[108], 4);
    memcpy(&header.ProfileSize, &data[112], 4);
    memcpy(&header.Reserved, &data[116], 4);
}

_JATTA_EXPORT Jatta::Image* Jatta::ImageLoaders::BMP::Load()
{
    if (!CanLoad())
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::NOT_A_BMP_FILE);

    unsigned int fileSize = File::GetFileSize(file);
    if (fileSize < 14)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_DATA_FORMAT);

    Byte* buffer = new Byte[fileSize];
    File::ReadData(file, buffer, fileSize);

    //Load the header information.
    BITMAPHEADER header = ReadHeader(&buffer[0], fileSize);

    UInt32 dibHeaderSize;
    memcpy(&dibHeaderSize, &buffer[14], 4);
    BITMAPDIBHEADER dibHeader = ReadDIBHeader(&buffer[18], dibHeaderSize);

    //Check validitiy of the plane count. (Sanity check)
    if (dibHeader.Planes != 1)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_COLOR_PLANE_COUNT);

    //Check that there is no compression.  (No support atm)
    //TODO: Add compression support.
    if (dibHeader.Compression != BMPCompressionMethods::RGB)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::UNSUPPORTED_FORMAT);

    //Check for valid pixel format.
    if (dibHeader.BitCount != 1 && dibHeader.BitCount != 2 && dibHeader.BitCount != 4 && dibHeader.BitCount != 8 && 
        dibHeader.BitCount != 16 && dibHeader.BitCount != 24 && dibHeader.BitCount != 32)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::UNSUPPORTED_FORMAT);

    //Load the pixel data
    int rowSize = Math::Floor((dibHeader.BitCount*dibHeader.Width+31)/32)*4;
    int pixelArraySize = rowSize * Math::Abs(dibHeader.Height);
    int pixelSize = (dibHeader.BitCount / 8);
    int paddingSize = rowSize - Math::Floor(pixelSize * dibHeader.Width);

    if (dibHeader.BitCount <= 8)
    {
        //TODO: Images with 8 bpp and less
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::UNSUPPORTED_FORMAT);
    }
    else
    {
        int index = header.Offset;

        Byte* data = new Byte[pixelArraySize];

        for (int y = dibHeader.Height-1; y >= 0; y--)
        {
            for (int x = 0; x < dibHeader.Width; x++)
            {
                memcpy(&data[y*dibHeader.Width*pixelSize + x*pixelSize], &buffer[index], pixelSize);
                index += pixelSize;
            }

            index += paddingSize;
        }

        ImageFormat format = ImageFormats::NONE;
        switch (dibHeader.BitCount)
        {
            case 16: format = ImageFormats::RGBA4; break;
            case 24: format = ImageFormats::BGR8; break;
            case 32: format = ImageFormats::BGRA8; break;
        }

        
        return new Image(format, dibHeader.Width, dibHeader.Height, (void*)data);
    }
}

_JATTA_EXPORT Jatta::ImageLoaders::BITMAPHEADER Jatta::ImageLoaders::BMP::GetHeader()
{
    if (!CanLoad())
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::NOT_A_BMP_FILE);

    unsigned int fileSize = File::GetFileSize(file);
    if (fileSize < 14)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_DATA_FORMAT);

    Byte* buffer = new Byte[14];
    File::ReadData(file, buffer, 14);

    return ReadHeader(&buffer[0], fileSize);
}

_JATTA_EXPORT Jatta::ImageLoaders::BITMAPDIBHEADER Jatta::ImageLoaders::BMP::GetDIBHeader()
{
    if (!CanLoad())
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::NOT_A_BMP_FILE);

    unsigned int fileSize = File::GetFileSize(file);
    if (fileSize < 14)
        throw Jatta::ImageException(Jatta::ImageExceptionCode::BMP, Jatta::ImageExceptionReason::INVALID_DATA_FORMAT);

    Byte* buffer = new Byte[fileSize];
    File::ReadData(file, buffer, fileSize);

    UInt32 dibHeaderSize;
    memcpy(&dibHeaderSize, &buffer[14], 4);
    return ReadDIBHeader(&buffer[18], dibHeaderSize);
}