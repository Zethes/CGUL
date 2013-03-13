/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Image.h"

#include "../Utility/String.h"
#include "../File/File.h"
#include <fstream>
#include <cstring>

#include "Color.h"

#ifndef DOXYGEN
struct _bmp_file_header
{
public:
    unsigned char magicNumber[2];
    unsigned int sizeOfFile;
    unsigned char applicationSpecific[4];
    unsigned int bitmapOffset;

    int write(char*out)
    {
        char buff[14];
        memcpy(&buff[0], magicNumber, 2);
        memcpy(&buff[2], &sizeOfFile, 4);
        memcpy(&buff[6], &applicationSpecific, 4);
        memcpy(&buff[10], &bitmapOffset, 4);

        for (unsigned int i = 0; i < 14; i++)
        {
            out[i] = buff[i];
        }
        return 14;
    }
};
struct _bmp_dib_header
{
public:
    unsigned int headerSize;
    unsigned int bitmapWidth;
    unsigned int bitmapHeight;
    unsigned short planes;
    unsigned short bpp;
    unsigned int compressionMethod;
    unsigned int imageSize;
    unsigned int hResolution;
    unsigned int vResolution;
    unsigned int pallete;
    unsigned int importantColors;
    unsigned int redBitmask;
    unsigned int greenBitmask;
    unsigned int blueBitmask;
    unsigned int alphaBitmask;
    unsigned int colorSpaceType;
    unsigned int redGamma;
    unsigned int greenGamma;
    unsigned int blueGamma;
    unsigned int intent;
    unsigned int iccProfileData;
    unsigned int iccProfileSize;
    unsigned int reserved;
    int write(char*out)
    {
        char*buff = new char[headerSize];
        memcpy(&buff[0], &headerSize, 4);
        memcpy(&buff[4], &bitmapWidth, 4);
        memcpy(&buff[8], &bitmapHeight, 4);
        memcpy(&buff[12], &planes, 2);
        memcpy(&buff[14], &bpp, 2);
        memcpy(&buff[16], &compressionMethod, 4);
        memcpy(&buff[20], &imageSize, 4);
        memcpy(&buff[24], &hResolution, 4);
        memcpy(&buff[28], &vResolution, 4);
        memcpy(&buff[32], &pallete, 4);
        memcpy(&buff[36], &importantColors, 4);
        if (headerSize > 40)
        {
            memcpy(&buff[40], &redBitmask, 4);
            memcpy(&buff[44], &greenBitmask, 4);
            memcpy(&buff[48], &blueBitmask, 4);
            memcpy(&buff[52], &alphaBitmask, 4);
            memcpy(&buff[56], &colorSpaceType, 4);
        }

        for (unsigned int i = 0; i < headerSize; i++)
        {
            out[i] = buff[i];
        }
        return headerSize;
    }
};

struct _bmp_pixel_data
{
public:
    unsigned int w, h;
    unsigned char* colors;
    int write(char*out, int bpp, unsigned int padding)
    {
        //unsigned int rowSize = ((bpp*w+31)/32)*4;
        unsigned int size = w*h*(bpp/8)+padding*h;//rowSize*h;

        if (bpp == 32)
        {
            int wPos = 0;
            for (int y = h-1; y >= 0; y--)
            {
                for (unsigned int x = 0; x < w*4; x+=4)
                {
                    out[wPos++] = colors[y*w*4+x+2];
                    out[wPos++] = colors[y*w*4+x+1];
                    out[wPos++] = colors[y*w*4+x];
                    out[wPos++] = colors[y*w*4+x+4];
                }

                //If end of row: add padding.
                for (unsigned int i = 0; i < padding; i++)
                    out[wPos++] = 0;
            }
        }
        else if (bpp == 24)
        {
            int wPos = 0;
            for (int y = h-1; y >= 0; y--)
            {
                for (unsigned int x = 0; x < w*4; x+=4)
                {
                    out[wPos++] = colors[y*w*4+x+2];
                    out[wPos++] = colors[y*w*4+x+1];
                    out[wPos++] = colors[y*w*4+x];
                }

                //If end of row: add padding.
                for (unsigned int i = 0; i < padding; i++)
                    out[wPos++] = 0;
            }
        }

        //TODO: 8,4,2 and 1 bit

        return size;
    }
};

#ifndef MSVC
#   define BI_RGB 0
#   define BI_RLE8 1
#   define BI_RLE4 2
#   define BI_BITFIELDS 3
#   define BI_JPEG 4
#   define BI_PNG 5
#   define BI_ALPHABITFIELDS 6
#endif

#endif // DOXYGEN

_JATTA_EXPORT bool Jatta::Image::IsBmp(const char* buffer, Jatta::UInt32 size)
{
    if (size < 2)
        return false;

    if (buffer[0] == 0x42 && buffer[1] == 0x4D)
        return true;
    return false;
}

_JATTA_EXPORT bool Jatta::Image::LoadBmp(const char* data, Jatta::UInt32 size)
{
    //TODO: Loading BMPs
    return false;
}
_JATTA_EXPORT bool Jatta::Image::SaveBmp(const Jatta::String& fileName, int bpp, int hRes, int vRes)
{
    _bmp_file_header fileHeader;
    fileHeader.magicNumber[0] = 0x42; fileHeader.magicNumber[1] = 0x4D;
    fileHeader.sizeOfFile = 0;//size of file
    fileHeader.applicationSpecific[0] = fileHeader.applicationSpecific[1] = fileHeader.applicationSpecific[2] = fileHeader.applicationSpecific[3] = 0;
    fileHeader.bitmapOffset = 54;//start of pixel data

    int padding = width%4;

    _bmp_dib_header dibHeader;
    dibHeader.headerSize = 40;
    dibHeader.bitmapWidth = width;
    dibHeader.bitmapHeight = height;
    dibHeader.planes = 1;
    dibHeader.bpp = bpp;
    if (bpp == 8)
        dibHeader.compressionMethod = BI_RLE8; //RLE 8-bit/pixel
    else if (bpp == 4)
        dibHeader.compressionMethod = BI_RLE4; //RLE 4-bit/pixel
    else
        dibHeader.compressionMethod = BI_RGB; //No compression
    dibHeader.imageSize = 0; //Size of pixel data
    dibHeader.hResolution = hRes;
    dibHeader.vResolution = vRes;
    dibHeader.pallete = 0;
    dibHeader.importantColors = 0;

    //Load the pixels.
    _bmp_pixel_data pixelData;
    pixelData.w = width;
    pixelData.h = height;
    pixelData.colors = new unsigned char[this->width * this->height * 4];
    memcpy(pixelData.colors, this->GetData(), this->width * this->height * 4);
    //pixelData.colors = colors;

    //Create buffers.
    char*dibHeaderBuffer = new char[40];
    char*fileHeaderBuffer = new char[14];
    char*pixelDataBuffer = new char[width*height*(bpp/8)+padding*height];
    int pixelDataSize = pixelData.write(pixelDataBuffer, bpp, padding);

    dibHeader.imageSize = pixelDataSize;
    int dibHeaderSize = dibHeader.write(dibHeaderBuffer);

    fileHeader.sizeOfFile = pixelDataSize + dibHeaderSize + 14;
    fileHeader.bitmapOffset = dibHeaderSize+14;
    int fileHeaderSize = fileHeader.write(fileHeaderBuffer);

    //Write the file.
    std::ofstream outfile(fileName.GetData().c_str(), std::ios::out | std::ios::binary);
    outfile.write(fileHeaderBuffer, fileHeaderSize);
    outfile.write(dibHeaderBuffer, dibHeaderSize);
    outfile.write(pixelDataBuffer,pixelDataSize);
    outfile.close();

    return true;
}
