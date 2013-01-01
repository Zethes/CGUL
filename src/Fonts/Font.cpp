#ifdef JATTA_FONTS
#include "Font.h"
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
            _JATTA_DEBUG_LN("Could not initialize FreeType");
        }
        initialized = true;
    }
}

_JATTA_EXPORT Jatta::Font::Font()
{
    __jatta_ttf_initialize();
}

_JATTA_EXPORT void Jatta::Font::load(const std::string& fileName)
{
    FT_Face face;
    FT_Error error = FT_New_Face(__jatta_ttf_library, fileName.c_str(), 0, &face);
    if (error == FT_Err_Unknown_File_Format)
    {
        // @TODO error checking
        _JATTA_DEBUG_LN("Font is an unknown format.");
    }
    else if (error)
    {
        // @TODO error checking
        _JATTA_DEBUG_LN("Failed to load font.");
    }
    faces.push_back(face);
    _JATTA_DEBUG_LN(FT_Get_X11_Font_Format(face));
    //error = FT_Set_Char_Size(face, 40 * size, 0, 100, 0);
}

_JATTA_EXPORT void Jatta::Font::setSize(unsigned int size)
{
    for (auto f = faces.begin(); f != faces.end(); f++)
    {
        FT_Error error = FT_Set_Pixel_Sizes(*f, 0, size);
        if (error)
        {
            // @TODO error checking
            _JATTA_DEBUG_LN("Failed to set character size.");
        }
    }
    this->size = size;
}

_JATTA_EXPORT unsigned int Jatta::Font::getSize()
{
    return this->size;
}

_JATTA_EXPORT void Jatta::Font::setColor(const Color& color)
{
    this->color = color;
}

_JATTA_EXPORT Jatta::Color Jatta::Font::getColor()
{
    return this->color;
}

/*Jatta::Image Jatta::Font::generateText(const Jatta::String& text, bool beginningSpacer)
{
    // set our transform matrix (to the identity matrix)
    FT_Matrix matrix;
    matrix.xx = (FT_Fixed)(1 * 0x10000L);
    matrix.xy = (FT_Fixed)(0 * 0x10000L);
    matrix.yx = (FT_Fixed)(0 * 0x10000L);
    matrix.yy = (FT_Fixed)(1 * 0x10000L);

    // set the position of the font
    FT_Vector pen;
    pen.x = 0;
    pen.y = 0;

    // render each character
    unsigned int buffWidth = 0, buffHeight = 0;
    for (Jatta::Size n = 0; n < text.getSize();)
    {
        // transform the font character
        FT_Set_Transform(faces[0], &matrix, &pen);

        // load glyph image into the slot
        UInt32 utf8Character;
        n += text.getCodePoint(n, &utf8Character);
        FT_Error error = FT_Load_Char(faces[0], utf8Character, FT_LOAD_RENDER);
        if (error)
        {
            continue; // @TODO ignore errors?
        }

        // now, draw to our surface
        FT_Int i, j, p, q;
        FT_Int x_max = faces[0]->glyph->bitmap_left + faces[0]->glyph->bitmap.width;
        FT_Int y_max = size - faces[0]->glyph->bitmap_top + faces[0]->glyph->bitmap.rows;
        for (i = faces[0]->glyph->bitmap_left, p = 0; i < x_max; i++, p++)
        {
            for (j = size - faces[0]->glyph->bitmap_top, q = 0; j < y_max; j++, q++)
            {
                if (i > buffWidth)
                {
                    buffWidth = i;
                }
                if (x_max > buffWidth)
                {
                    buffWidth = x_max;
                }
                if (j > buffHeight)
                {
                    buffHeight = j;
                }
                if (y_max > buffHeight)
                {
                    buffHeight = y_max;
                }
            }
        }

        // increment pen position
        pen.x += faces[0]->glyph->advance.x;
        pen.y += faces[0]->glyph->advance.y;
    }

    // reset pen
    pen.x = 0;
    pen.y = 0;

    // create the texture buffer
    unsigned char* data = new unsigned char[buffWidth * buffHeight * sizeof(Color)];
    Color* buffer = (Color*)data;
    memset(buffer, 0, buffWidth * buffHeight * sizeof(Color));

    for (Jatta::Size n = 0; n < text.getSize();)
    {
        // transform the font character
        FT_Set_Transform(faces[0], &matrix, &pen);

        // load glyph image into the slot
        UInt32 utf8Character;
        n += text.getCodePoint(n, &utf8Character);
        FT_Error error = FT_Load_Char(faces[0], utf8Character, FT_LOAD_RENDER);
        if (error)
        {
            continue; // @TODO ignore errors?
        }

        // now, draw to our surface
        FT_Int i, j, p, q;
        FT_Int x_max = faces[0]->glyph->bitmap_left + faces[0]->glyph->bitmap.width;
        FT_Int y_max = size - faces[0]->glyph->bitmap_top + faces[0]->glyph->bitmap.rows;
        for (i = faces[0]->glyph->bitmap_left, p = 0; i < x_max; i++, p++)
        {
            for (j = size - faces[0]->glyph->bitmap_top, q = 0; j < y_max; j++, q++)
            {
                buffer[j * buffWidth + i].a |= faces[0]->glyph->bitmap.buffer[q * faces[0]->glyph->bitmap.width + p];
            }
        }

        // increment pen position
        pen.x += faces[0]->glyph->advance.x;
        pen.y += faces[0]->glyph->advance.y;
    }

    return std::move(Image((Color*)data, buffWidth, buffHeight));

    return std::move(Image((Color*)data, 512, 512));
}*/

_JATTA_EXPORT Jatta::Image Jatta::Font::generateText(const Jatta::String& text, bool beginningSpacer)
{
    bool kerning = true;

    // set our transform matrix (to the identity matrix)
    FT_Matrix matrix;
    matrix.xx = (FT_Fixed)(1 * 0x10000L);
    matrix.xy = (FT_Fixed)(0 * 0x10000L);
    matrix.yx = (FT_Fixed)(0 * 0x10000L);
    matrix.yy = (FT_Fixed)(1 * 0x10000L);
    FT_Vector pen;
    pen.x = 0;
    pen.y = 0;
    FT_Int bufferWidth = 0, bufferHeight = 0;

    FT_Int maxDown = 0;
    for (Jatta::Size i = 0; i < text.getSize();)
    {
        _JATTA_DEBUG_LN("FT_ULong: " << sizeof(FT_ULong));
        UInt32 utf8Character;
        i += text.getCodePoint(i, &utf8Character);
        FT_Face face;
        for (auto f = faces.begin(); f != faces.end(); f++)
        {
            face = *f;
            if (FT_Get_Char_Index(face, utf8Character) != 0)
            {
                break;
            }
        }
        FT_Set_Transform(face, &matrix, &pen);
        FT_Error error = FT_Load_Char(face, utf8Character, FT_LOAD_RENDER);
        if (error)
        {
            continue; // TODO: ignore errors?
        }
        FT_Int height = face->glyph->bitmap.rows;
        if (height > bufferHeight)
        {
            bufferHeight = height;
        }
        FT_Int down = (face->glyph->bitmap.rows - face->glyph->bitmap_top);
        if (down > maxDown)
        {
            maxDown = down;
        }
        if (i == 0 && !beginningSpacer)
        {
            face->glyph->bitmap_left = 1;
        }
        if (face->glyph->bitmap_left + face->glyph->bitmap.width > bufferWidth)
        {
            bufferWidth = face->glyph->bitmap_left + face->glyph->bitmap.width;
        }
        pen.x += face->glyph->advance.x;
        pen.y += face->glyph->advance.y;
    }
    bufferHeight += maxDown;

    pen.x = 0;
    pen.y = 0;

    // create the texture buffer
    unsigned char* data = new unsigned char[bufferWidth * bufferHeight * sizeof(Color)];
    Color* buffer = (Color*)data;
    memset(buffer, 0, bufferWidth * bufferHeight * sizeof(Color));

    for (Jatta::Size i = 0; i < text.getSize();)
    {
        //pen.x = 0;
        //pen.y = 0;

        // load glyph image into the slot
        //FT_Error error = FT_Load_Char(face, text[n], FT_LOAD_RENDER);
        UInt32 utf8Character;
        i += text.getCodePoint(i, &utf8Character);
        _JATTA_DEBUG_LN(std::hex << utf8Character << std::dec);
        FT_Face face;
        for (auto f = faces.begin(); f != faces.end(); f++)
        {
            face = *f;
            if (FT_Get_Char_Index(face, utf8Character) != 0)
            {
                break;
            }
        }
        FT_Set_Transform(face, &matrix, &pen);
        FT_Error error = FT_Load_Char(face, utf8Character, FT_LOAD_RENDER);
        if (error)
        {
            continue; // TODO: ignore errors?
        }

        if (i == 0 && !beginningSpacer)
        {
            face->glyph->bitmap_left = 1;
        }

        // now, draw to our surface
        FT_Int n, p, q;
        FT_Int x_max = face->glyph->bitmap_left + face->glyph->bitmap.width;
        FT_Int y_max = face->glyph->bitmap_top + face->glyph->bitmap.rows;
        FT_Int down = (face->glyph->bitmap.rows - face->glyph->bitmap_top);
        FT_Int startY = (((bufferHeight - maxDown) - face->glyph->bitmap.rows) + down);
        for (n = face->glyph->bitmap_left, p = 0; n < x_max; n++, p++)
        {
            for (q = 0; q < face->glyph->bitmap.rows; q++)
            {
                buffer[(q + startY) * bufferWidth + n].r = this->color.r;
                buffer[(q + startY) * bufferWidth + n].g = this->color.g;
                buffer[(q + startY) * bufferWidth + n].b = this->color.b;
                buffer[(q + startY) * bufferWidth + n].a |= (FT_Int)(face->glyph->bitmap.buffer[q * face->glyph->bitmap.width + p] * (color.a / 255.0f));
            }
        }

        // increment pen position
        pen.x += face->glyph->advance.x;
        pen.y += face->glyph->advance.y;
    }
    return Image((Color*)data, bufferWidth, bufferHeight - 1);
}
#endif