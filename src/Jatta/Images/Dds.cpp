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

typedef unsigned int u32;

#ifndef MAKEFOURCC
#define MAKEFOURCC( ch0, ch1, ch2, ch3 ) \
    (( u32 ) ( unsigned char ) ( ch0 ) | (( u32 ) ( unsigned char ) ( ch1 ) << 8 ) | \
    (( u32 ) ( unsigned char ) ( ch2 ) << 16 ) | (( u32 ) ( unsigned char )( ch3 ) << 24 ))
#endif

#define FF_S3TC_DXT1    0x31545844
#define FF_S3TC_DXT3    0x33545844

#ifndef AV_RL16
#define AV_RL16(x)  ((((const uint8_t*)(x))[1] << 8) | \
                    ((const uint8_t*)(x))[0])
#endif

#ifndef AV_RL32
#define AV_RL32(x) ((((const uint8_t*)(x))[3] << 24) | \
                    (((const uint8_t*)(x))[2] << 16) | \
                    (((const uint8_t*)(x))[1] <<  8) | \
                     ((const uint8_t*)(x))[0])
#endif

#ifndef AV_RL64
#define AV_RL64(x)  (((uint64_t)((const uint8_t*)(x))[7] << 56) | \
                     ((uint64_t)((const uint8_t*)(x))[6] << 48) | \
                     ((uint64_t)((const uint8_t*)(x))[5] << 40) | \
                     ((uint64_t)((const uint8_t*)(x))[4] << 32) | \
                     ((uint64_t)((const uint8_t*)(x))[3] << 24) | \
                     ((uint64_t)((const uint8_t*)(x))[2] << 16) | \
                     ((uint64_t)((const uint8_t*)(x))[1] <<  8) | \
                      (uint64_t)((const uint8_t*)(x))[0])
#endif

enum DDS_FLAGS
{
    DDS_CAPS          = 0x00000001,
    DDS_HEIGHT        = 0x00000002,
    DDS_WIDTH         = 0x00000004,
    DDS_PITCH         = 0x00000008,
    DDS_PIXELFORMAT   = 0x00001000,
    DDS_MIPMAPCOUNT   = 0x00002000,
    DDS_LINEARSIZE    = 0x00008000,
    DDS_DEPTH         = 0x00800000,

    DDS_FOURCC        = 0x00000004,
    DDS_ALPHAPIXELS   = 0x00000001
};

enum DDS_FOURCC
{
    DDS_FOURCC_DXT1   = MAKEFOURCC( 'D', 'X', 'T', '1' ),
    DDS_FOURCC_DXT3   = MAKEFOURCC( 'D', 'X', 'T', '3' )
};

struct PixelFormat
{
    u32 Size;
    u32 Flags;
    u32 FourCC;
    u32 RGBBitCount;
    u32 RBitMask;
    u32 GBitMask;
    u32 BBitMask;
    u32 ABitMask;
};

struct DdsHeader
{
    u32 Magic;
    u32 Size;
    u32 Flags;
    u32 Height;
    u32 Width;
    u32 PitchOrLinearSize;
    u32 Depth;
    u32 MipMapCount;
    u32 Reserved1[11];
    PixelFormat PF;
    u32 Caps1;
    u32 Caps2;
    u32 Reserved2[3];
};

void dxt1_decode_pixels(const Jatta::UInt8 *s, Jatta::UInt32 *d, unsigned int qstride, unsigned int flag, Jatta::UInt64 alpha)
{
    unsigned int x, y, c0, c1, a = (!flag * 255) << 24;
    unsigned int rb0, rb1, rb2, rb3, g0, g1, g2, g3;
    Jatta::UInt32 colors[4], pixels;

    c0 = AV_RL16(s);
    c1 = AV_RL16(s+2);

    rb0 = (c0 << 3 | c0 << 8) & 0xf800f8;
    rb1 = (c1 << 3 | c1 << 8) & 0xf800f8;
    rb0 +=         (rb0 >> 5) & 0x070007;
    rb1 +=         (rb1 >> 5) & 0x070007;
    g0  =          (c0 <<  5) & 0x00fc00;
    g1  =          (c1 <<  5) & 0x00fc00;
    g0 +=          (g0 >>  6) & 0x000300;
    g1 +=          (g1 >>  6) & 0x000300;

    colors[0] = rb0 + g0 + a;
    colors[1] = rb1 + g1 + a;

    if (c0 > c1 || flag)
    {
        rb2 = (((2*rb0+rb1) * 21) >> 6) & 0xff00ff;
        rb3 = (((2*rb1+rb0) * 21) >> 6) & 0xff00ff;
        g2 = (((2*g0+g1) * 21) >> 6) & 0x00ff00;
        g3 = (((2*g1+g0) * 21) >> 6) & 0x00ff00;
        colors[3] = rb3 + g3 + a;
    }
    else
    {
        rb2 = ((rb0 + rb1) >> 1) & 0xff00ff;
        g2 = ((g0 + g1) >> 1) & 0x00ff00;
        colors[3] = 0;
    }

    colors[2] = rb2 + g2 + a;

    pixels = AV_RL32(s+4);
    for (y=0; y<4; y++) 
    {
        for (x=0; x<4; x++) 
        {
            a        = (alpha & 0x0f) << 28;
            a       += a >> 4;
            d[x]     = a + colors[pixels&3];
            pixels >>= 2;
            alpha  >>= 4;
        }
        d += qstride;
    }
}

void ff_decode_dxt1(const Jatta::UInt8 *s, Jatta::UInt8 *dst, const unsigned int w, const unsigned int h, const unsigned int stride)
{
    unsigned int bx, by, qstride = stride/4;
    Jatta::UInt32 *d = (Jatta::UInt32*) dst;

    for (by = 0; by < h/4; by++, d += stride-w)
    {
        for (bx = 0; bx < w/4; bx++, s+=8, d+=4)
        {
            dxt1_decode_pixels(s, d, qstride, 0, 0LL);
        }
    }
}

void ff_decode_dxt3(const Jatta::UInt8 *s, Jatta::UInt8 *dst, const unsigned int w, const unsigned int h, const unsigned int stride)
{
    unsigned int bx, by, qstride = stride/4;
    Jatta::UInt32 *d = (Jatta::UInt32 *) dst;

    for (by=0; by < h/4; by++, d += stride-w)
    {
        for (bx=0; bx < w/4; bx++, s+=16, d+=4)
        {
            dxt1_decode_pixels(s+8, d, qstride, 1, AV_RL64(s));
        }
    }
}


_JATTA_EXPORT bool Jatta::Image::IsDds(const Jatta::String& fileName)
{
    std::ifstream inFile(fileName.GetData().c_str(), std::ios::in | std::ios::binary);

    int len = 4;

    unsigned char* rawBytes = new unsigned char[len];
    inFile.read((char*)rawBytes, len);
    inFile.close();

    DdsHeader * header = (DdsHeader*) rawBytes;

    if (header->Magic != MAKEFOURCC( 'D', 'D', 'S', ' ' ))
        return false;

    return true;
}

_JATTA_EXPORT bool Jatta::Image::LoadDds(const Jatta::String& fileName, UInt32 flags)
{
    std::ifstream inFile(fileName.GetData().c_str(), std::ios::in | std::ios::binary);

    inFile.seekg(0, std::ios::end);
    int len = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    unsigned char* rawBytes = new unsigned char[len];
    inFile.read((char*)rawBytes, len);
    inFile.close();

    DdsHeader * header = (DdsHeader*) rawBytes;

    if (header->Magic != MAKEFOURCC( 'D', 'D', 'S', ' ' ))
        return false;

    Jatta::UInt8 * dest = new Jatta::UInt8[header->Width*header->Height*4];
    Jatta::UInt8 * src = (Jatta::UInt8*) rawBytes + 128;

    if (header->PF.FourCC == DDS_FOURCC_DXT1)
        ff_decode_dxt1(src, dest, header->Width, header->Height, header->Width*4);
    else if (header->PF.FourCC == DDS_FOURCC_DXT3)
        ff_decode_dxt3(src, dest, header->Width, header->Height, header->Width*4);

    //Decode the data into the image:
    width = header->Width;
    height = header->Height;
    int index = 0;
    colors = new Jatta::Color[width*height];
    for (unsigned int i = 0; i < width*height*4; i+=4)
    {
        colors[index].a = dest[i+3];
        colors[index].r = dest[i+2];
        colors[index].g = dest[i+1];
        colors[index].b = dest[i]; 

        index++;
    }

    return true;
}
_JATTA_EXPORT bool Jatta::Image::SaveDds(const Jatta::String& fileName)
{
    //TODO: Saving DDS images
    return false;
}
