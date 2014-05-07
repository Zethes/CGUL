// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Glyph.cpp
 */

#include "Glyph.hpp"
#include "../Images/Format.hpp"
#include <string.h>

_CGUL_EXPORT bool CGUL::Font::Glyph::Setup(FT_Glyph glyph, void* glyphSlot)
{
    // Cleanup old glyph, if one exists
    Free();

    // Get advance information from glyph slot
    FT_GlyphSlot slot = (FT_GlyphSlot)glyphSlot;
    this->advance.x = slot->advance.x >> 6;
    this->advance.y = slot->advance.y >> 6;

    // Get the bitmap data from the glyph
    FT_Error error = FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, NULL, true);
    if (error)
    {
        return false;
    }
    FT_BitmapGlyph bitmapGlyph = (FT_BitmapGlyph)glyph;
    FT_Bitmap& bitmap = bitmapGlyph->bitmap;

    // Origin is left/top offsets
    this->origin.x = bitmapGlyph->left;
    this->origin.y = bitmapGlyph->top;

    // Get size of bitmap data
    this->size = UCoord32(bitmap.width, bitmap.rows);

    // Save glyph
    this->glyph = glyph;
    return true;
}

_CGUL_EXPORT CGUL::Font::Glyph::Glyph() :
    glyph(NULL)
{
}

_CGUL_EXPORT CGUL::Font::Glyph::~Glyph()
{
    Free();
}

_CGUL_EXPORT void CGUL::Font::Glyph::Free()
{
    // If a glyph exists, clean it up
    if (glyph)
    {
        FT_Done_Glyph(glyph);
        glyph = NULL;
    }
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Font::Glyph::GetWidth() const
{
    return size.x;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Font::Glyph::GetHeight() const
{
    return size.y;
}

_CGUL_EXPORT CGUL::UCoord32 CGUL::Font::Glyph::GetSize() const
{
    return size;
}

_CGUL_EXPORT CGUL::SCoord32 CGUL::Font::Glyph::GetOrigin() const
{
    return origin;
}

_CGUL_EXPORT CGUL::SCoord32 CGUL::Font::Glyph::GetAdvance() const
{
    return advance;
}

_CGUL_EXPORT CGUL::Byte CGUL::Font::Glyph::Get(UInt32 x, UInt32 y) const
{
    // Read individual bitmap data
    return ((FT_BitmapGlyph)glyph)->bitmap.buffer[y * size.x + x];

    // TODO: add a different way to do this?
    // maybe get raw pointer, or copy data to buffer?
}