// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Face.cpp
 */

#include "Face.hpp"
#include "../Fonts/Glyph.hpp"
#include "../Images/Format.hpp"
#include <string.h>

static FT_Library __cgul_ttf_library;

static void __cgul_ttf_initialize()
{
    static bool initialized = false;
    if (!initialized)
    {
        FT_Error error = FT_Init_FreeType(&__cgul_ttf_library);
        if (error)
        {
            // TODO: cleanup the throws in this file
            // use proper CGUL exceptions
            throw std::runtime_error("Unknown error with fonts.");
        }
        initialized = true;
    }
}

_CGUL_EXPORT CGUL::Font::Face::Face() :
    face(NULL),
    size(0)
{
    __cgul_ttf_initialize();
}

_CGUL_EXPORT CGUL::Font::Face::~Face()
{
    Free();
}

_CGUL_EXPORT void CGUL::Font::Face::Load(const CGUL::String& fileName)
{
    FT_Error error = FT_New_Face(__cgul_ttf_library, fileName.GetCString(), 0, &face);
    if (error == FT_Err_Unknown_File_Format)
    {
        face = NULL;
        throw std::runtime_error("Unknown font file format.");
    }
    else if (error)
    {
        face = NULL;
        throw std::runtime_error("Unknown error with fonts.");
    }
}

_CGUL_EXPORT void CGUL::Font::Face::Load(const void* data, Size size)
{
    FT_Error error = FT_New_Memory_Face(__cgul_ttf_library, (const FT_Byte*)data, size, 0, &face);
    if (error == FT_Err_Unknown_File_Format)
    {
        face = NULL;
        throw std::runtime_error("Unknown font file format.");
    }
    else if (error)
    {
        face = NULL;
        throw std::runtime_error("Unknown error with fonts.");
    }
}

_CGUL_EXPORT void CGUL::Font::Face::Free()
{
    // Cleanup freetype face
    if (face != NULL)
    {
        FT_Done_Face(face);
        face = NULL;
    }
}

_CGUL_EXPORT void CGUL::Font::Face::SetSize(UInt32 size)
{
    // TODO: support width,height alternative of this function
    // maybe use floats & pts instead? If so, use:
    // SIZE = PT * 64
    FT_Error error = FT_Set_Pixel_Sizes(face, 0, size);
    if (error)
    {
        throw std::runtime_error("Unknown error with fonts.");
    }
    this->size = size;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Font::Face::GetSize() const
{
    return size;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Font::Face::GetMetricHeight() const
{
    return face->size->metrics.height >> 6;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Font::Face::GetNumGlyphs() const
{
    return face->num_glyphs;
}

_CGUL_EXPORT bool CGUL::Font::Face::LoadGlyph(UInt32 character, Glyph* glyph)
{
    // Transform
    FT_Matrix matrix;
    matrix.xx = (FT_Fixed)(1 * 0x10000L);
    matrix.xy = (FT_Fixed)(0 * 0x10000L);
    matrix.yx = (FT_Fixed)(0 * 0x10000L);
    matrix.yy = (FT_Fixed)(1 * 0x10000L);

    // TODO: support custom matrices for fonts
    // no point in only supporting a subset of options
    // Oblique fonts example:
    /*if (oblique)
    {
        double pi = 3.1415926535;;
        double rads = pi * 0.0f / 180.0;
        double skew = pi * 35.0f/ 180.0;

        // set up transform (a rotation here)
        matrix.xx = (FT_Fixed)( Math::Cos(rads)*0x10000L);
        matrix.xy = (FT_Fixed)( Math::Sin(rads + skew)*0x10000L);
        matrix.yx = (FT_Fixed)( Math::Sin(rads)*0x10000L);
        matrix.yy = (FT_Fixed)( Math::Cos(rads)*0x10000L);
    }*/

    // Set transform style
    FT_Set_Transform(face, &matrix, NULL);

    // Get the glyph index
    FT_UInt glyphIndex = FT_Get_Char_Index(face, character);

    if (glyphIndex == 0)
    {
        return false;
    }

    // Load the glyph into memory
    FT_Error error = FT_Load_Glyph(face, glyphIndex, FT_LOAD_DEFAULT);
    if (error)
    {
        return false;
    }

    // Move the face's glyph into a glyph object
    FT_Glyph ftGlyph;
    error = FT_Get_Glyph(face->glyph, &ftGlyph);
    if (error)
    {
        return false;
    }

    // Create the glyph
    if (glyph->Setup(ftGlyph, (void*)face->glyph))
    {
        return true;
    }
    return false;
}