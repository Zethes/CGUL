/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Font.h"
#include "../Images/ImageFormats.h"
#include <string.h>

static FT_Library __jatta_ttf_library;

_JATTA_EXPORT void __jatta_ttf_initialize()
{
    static bool initialized = false;
    if (!initialized)
    {
        FT_Error error = FT_Init_FreeType(&__jatta_ttf_library);
        if (error)
        {
            // todo: error checking
        }
        initialized = true;
    }
}

_JATTA_EXPORT Jatta::Font::Font() :
    size(0)
{
    __jatta_ttf_initialize();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Font::Load(const std::string& fileName)
{
    ::FT_Face face;
    FT_Error error = FT_New_Face(__jatta_ttf_library, fileName.c_str(), 0, &face);
    if (error == FT_Err_Unknown_File_Format)
    {
        throw std::runtime_error("Unknown font file format.");
        return -1;
    }
    else if (error)
    {
        throw std::runtime_error("Unknown error with fonts.");
        return -1;
    }

    faces.push_back(face);

    return faces.size()-1;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Font::LoadFromMemory(const unsigned char* data, UInt64 size)
{
    ::FT_Face face;
    FT_Error error = FT_New_Memory_Face(__jatta_ttf_library, data, size, 0, &face);
    if (error == FT_Err_Unknown_File_Format)
    {
        throw std::runtime_error("Unknown font file format.");
        return -1;
    }
    else if (error)
    {
        throw std::runtime_error("Unknown error with fonts.");
        return -1;
    }

    faces.push_back(face);

    return faces.size()-1;
}

_JATTA_EXPORT void Jatta::Font::PreloadGlyphs(UInt32 start, UInt32 end)
{
    for (unsigned int i = start; i <= end; i++)
    {
        glyphCache.insert(std::pair<UInt32, Glyph*>(i, GetGlyph(i)));
    }
}

_JATTA_EXPORT void Jatta::Font::ClearCache()
{
    for (std::map<UInt32, Glyph*>::iterator i = glyphCache.begin(); i != glyphCache.end(); ++i)
    {
        delete i->second;
    }
    glyphCache.clear();
}

_JATTA_EXPORT void Jatta::Font::SetSize(UInt32 size)
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        FT_Error error = FT_Set_Pixel_Sizes(faces[i], 0, size);
        if (error)
        {
            // TODO: error checking
        }
    }
    this->size = size;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Font::GetSize()
{
    return size;
}

_JATTA_EXPORT void Jatta::Font::SetStyle(UInt32 style)
{
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        faces[i]->style_flags = style;
    }
}

_JATTA_EXPORT Jatta::Image Jatta::Font::GenerateText(Jatta::Color color, const String& text)
{
    //Calculate size
    UInt32 width = 0;
    UInt32 height = 0;
    UInt32 maxWidth = 0;
    UInt32 maxDown = 0;
    UInt32 yOffset = 0;
    for (Jatta::Size i = 0; i < text.GetSize();)
    {
        UInt32 utf8Character;
        i += text.GetCodePoint(i, &utf8Character);

        Glyph* glyph = GetGlyph(utf8Character);
        if (glyph == NULL)
        {
            glyph = GetGlyph(0);
        }

        UInt32 w = 0, h = 0;
        w = glyph->GetWidth() + glyph->GetAdvance().x + glyph->GetOffset().x;
        h = glyph->GetHeight() + yOffset;
        if (h > height)
        {
            height = h;
        }

        UInt32 down = (glyph->GetHeight() - glyph->GetOffset().y);
        if (down > maxDown)
        {
            maxDown = down;
        }

        width += w;
        if (width > maxWidth)
        {
            maxWidth = width;
        }
    }
    width = maxWidth;
    height += maxDown;

    //Generate the image by merging all the data generated by glyphs into one large image.
    Vector2 pen = Vector2(0);
    Color* buffer = reinterpret_cast<Color*>(new char[width*height*sizeof(Color)]);
    memset(buffer, 0, width*height*sizeof(Color));
    for (Jatta::Size i = 0; i < text.GetSize();)
    {
        UInt32 utf8Character;
        i += text.GetCodePoint(i, &utf8Character);

        Glyph* glyph = GetGlyph(utf8Character);
        if (glyph == NULL)
        {
            glyph = GetGlyph(0);
        }

        UInt32 w = 0, h = 0;
        w = glyph->GetWidth();
        h = glyph->GetHeight();
        Byte* data = glyph->GetData();

        UInt32 down = glyph->GetHeight() - glyph->GetOffset().y;
        UInt32 startY = (((height - maxDown) - glyph->GetHeight()) + down) + pen.y;

        for (unsigned int y = 0; y < h; y++)
        {
            for (unsigned int x = 0; x < w; x++)
            {
                buffer[(y+startY)*width+x+(int)pen.x].r = color.r;
                buffer[(y+startY)*width+x+(int)pen.x].g = color.g;
                buffer[(y+startY)*width+x+(int)pen.x].b = color.b;
                buffer[(y+startY)*width+x+(int)pen.x].a |= (FT_Int)(data[y*w+x] * (color.a / 255.0f));
            }
        }
        pen.x += w + glyph->GetAdvance().x + glyph->GetOffset().x;
    }

    //Apply styling.
    if (faces[0]->style_flags & FontStyles::UNDERLINED)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            buffer[(height-1)*width+x].r = color.r;
            buffer[(height-1)*width+x].g = color.g;
            buffer[(height-1)*width+x].b = color.b;
            buffer[(height-1)*width+x].a = color.a;
        }
    }
    if (faces[0]->style_flags & FontStyles::STRIKED)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            buffer[(height/2)*width+x].r = color.r;
            buffer[(height/2)*width+x].g = color.g;
            buffer[(height/2)*width+x].b = color.b;
            buffer[(height/2)*width+x].a = color.a;
        }
    }
    if (faces[0]->style_flags & FontStyles::OVERLINED)
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

_JATTA_EXPORT Jatta::UInt64 Jatta::Font::GetCharacterIndex(UInt32 face, UInt64 characterCode)
{
    return FT_Get_Char_Index(this->faces[face], (FT_ULong)characterCode);
}
_JATTA_EXPORT Jatta::Glyph* Jatta::Font::GetGlyph(UInt32 utf8Character, bool useCache)
{
    if (useCache)
    {
        std::map<UInt32, Glyph*>::iterator it;
        it=glyphCache.find(utf8Character);
        if (it != glyphCache.end())
        {
            return it->second;
        }
    }
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        if (GetCharacterIndex(i, utf8Character) != 0)
        {
            return new Glyph(this->faces[i], utf8Character);
        }
    }
    return NULL;
}
