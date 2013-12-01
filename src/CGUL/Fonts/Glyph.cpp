// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Glyph.cpp
 */

#include "Glyph.hpp"
#include "../Images/Format.hpp"
#include "../Math/Math.hpp"

_CGUL_EXPORT CGUL::Glyph::Glyph(::FT_Face face, UInt32 utf8Character)
{
    FT_Matrix matrix;
    matrix.xx = (FT_Fixed)(1 * 0x10000L);
    matrix.xy = (FT_Fixed)(0 * 0x10000L);
    matrix.yx = (FT_Fixed)(0 * 0x10000L);
    matrix.yy = (FT_Fixed)(1 * 0x10000L);
    FT_Vector pen;
    pen.x = 0;
    pen.y = 0;

    if (face->style_flags & FontStyles::OBLIQUE)
    {
        double pi = 3.1415926535;;
        double rads = pi * 0.0f / 180.0;
        double skew = pi * 35.0f/ 180.0;

        // set up transform (a rotation here)
        matrix.xx = (FT_Fixed)( Math::Cos(rads)*0x10000L);
        matrix.xy = (FT_Fixed)( Math::Sin(rads + skew)*0x10000L);
        matrix.yx = (FT_Fixed)( Math::Sin(rads)*0x10000L);
        matrix.yy = (FT_Fixed)( Math::Cos(rads)*0x10000L);
    }

    FT_Set_Transform(face, &matrix, &pen);

    FT_Error error = FT_Load_Char(face, utf8Character, FT_LOAD_RENDER);
    if (error)
    {
        std::runtime_error("Failed to load glyph");
    }

    character = utf8Character;
    width = face->glyph->bitmap.width;
    height = face->glyph->bitmap.rows;
    advance = Vector2(2,0);//Vector2(face->glyph->advance.x/64.0, face->glyph->advance.y/64.0);
    offset = Vector2(face->glyph->bitmap_left, face->glyph->bitmap_top);
    data = (Byte*)new unsigned char[width*height];
    memcpy(data, face->glyph->bitmap.buffer, width*height);
}
_CGUL_EXPORT CGUL::Glyph::~Glyph()
{

}

_CGUL_EXPORT CGUL::UInt32 CGUL::Glyph::GetWidth()
{
    return width;
}
_CGUL_EXPORT CGUL::UInt32 CGUL::Glyph::GetHeight()
{
    return height;
}
_CGUL_EXPORT CGUL::Vector2 CGUL::Glyph::GetAdvance()
{
    return advance;
}
_CGUL_EXPORT CGUL::Vector2 CGUL::Glyph::GetOffset()
{
    return offset;
}

_CGUL_EXPORT CGUL::Byte* CGUL::Glyph::GetData()
{
    return data;
}

_CGUL_EXPORT CGUL::Image CGUL::Glyph::GetImage(Color color, UInt32 styleFlags)
{
    //TODO: Speed this up.
    Color* buffer = reinterpret_cast<Color*>(new char[width*height*sizeof(Color)]);
    memset(buffer, 0, width*height*sizeof(Color));
    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            buffer[y*width+x].r = color.r;
            buffer[y*width+x].g = color.g;
            buffer[y*width+x].b = color.b;

            buffer[y*width+x].a |= (FT_Int)(data[y*width+x] * (color.a / 255.0f));
        }
    }

    //Apply styling.
    if (styleFlags & FontStyles::UNDERLINED)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            buffer[(height-1)*width+x].r = color.r;
            buffer[(height-1)*width+x].g = color.g;
            buffer[(height-1)*width+x].b = color.b;
            buffer[(height-1)*width+x].a = color.a;
        }
    }
    if (styleFlags & FontStyles::STRIKED)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            buffer[(height/2)*width+x].r = color.r;
            buffer[(height/2)*width+x].g = color.g;
            buffer[(height/2)*width+x].b = color.b;
            buffer[(height/2)*width+x].a = color.a;
        }
    }
    if (styleFlags & FontStyles::OVERLINED)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            buffer[0*width+x].r = color.r;
            buffer[0*width+x].g = color.g;
            buffer[0*width+x].b = color.b;
            buffer[0*width+x].a = color.a;
        }
    }

    return Image(ImageFormats::RGBA8, width, height, buffer);
}
