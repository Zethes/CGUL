#include "Font.h"
#include <string.h>

#include <iostream> // TODO: remove iostream

static FT_Library __jatta_ttf_library;

void __jatta_ttf_initialize()
{
    static bool initialized = false;
    if (!initialized)
    {
        FT_Error error = FT_Init_FreeType(&__jatta_ttf_library);
        if (error)
        {
            std::cout << "Could not initialize FreeType" << std::endl;
        }
        initialized = true;
    }
}

Jatta::Font::Font()
{
    __jatta_ttf_initialize();
}

void Jatta::Font::load(const std::string& fileName)
{
    FT_Error error = FT_New_Face(__jatta_ttf_library, fileName.c_str(), 0, &this->face);
    if (error == FT_Err_Unknown_File_Format)
    {
        // @TODO error checking
        std::cout << "Font is an unknown format." << std::endl;
    }
    else if (error)
    {
        // @TODO error checking
        std::cout << "Failed to load font." << std::endl;
    }
    std::cout << FT_Get_X11_Font_Format(this->face) << std::endl;
    //error = FT_Set_Char_Size(face, 40 * size, 0, 100, 0);
}

void Jatta::Font::setSize(unsigned int size)
{
    FT_Error error = FT_Set_Pixel_Sizes(face, 0, size);
    if (error)
    {
        // @TODO error checking
        std::cout << "Failed to set character size." << std::endl;
    }
    this->size = size;
}

unsigned int Jatta::Font::getSize()
{
    return this->size;
}

void Jatta::Font::setColor(const Color& color)
{
    this->color = color;
}

Jatta::Color Jatta::Font::getColor()
{
    return this->color;
}

/*Jatta::Image&& Jatta::Ttf::blurg(const std::string& text)
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
    for (unsigned int n = 0; n < text.length(); n++)
    {
        // transform the font character
        FT_Set_Transform(face, &matrix, &pen);

        // load glyph image into the slot
        FT_Error error = FT_Load_Char(face, text[n], FT_LOAD_RENDER);
        if (error)
        {
            continue; // @TODO ignore errors?
        }

        // now, draw to our surface
        FT_Int i, j, p, q;
        FT_Int x_max = face->glyph->bitmap_left + face->glyph->bitmap.width;
        FT_Int y_max = size - face->glyph->bitmap_top + face->glyph->bitmap.rows;
        for (i = face->glyph->bitmap_left, p = 0; i < x_max; i++, p++)
        {
            for (j = size - face->glyph->bitmap_top, q = 0; j < y_max; j++, q++)
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
        pen.x += face->glyph->advance.x;
        pen.y += face->glyph->advance.y;
    }

    // reset pen
    pen.x = 0;
    pen.y = 0;

    // create the texture buffer
    unsigned char* data = new unsigned char[buffWidth * buffHeight * sizeof(Color)];
    Color* buffer = (Color*)data;
    memset(buffer, 0, buffWidth * buffHeight * sizeof(Color));

    for (unsigned int n = 0; n < text.length(); n++)
    {
        // transform the font character
        FT_Set_Transform(face, &matrix, &pen);

        // load glyph image into the slot
        FT_Error error = FT_Load_Char(face, text[n], FT_LOAD_RENDER);
        if (error)
        {
            continue; // @TODO ignore errors?
        }

        // now, draw to our surface
        FT_Int i, j, p, q;
        FT_Int x_max = face->glyph->bitmap_left + face->glyph->bitmap.width;
        FT_Int y_max = size - face->glyph->bitmap_top + face->glyph->bitmap.rows;
        for (i = face->glyph->bitmap_left, p = 0; i < x_max; i++, p++)
        {
            for (j = size - face->glyph->bitmap_top, q = 0; j < y_max; j++, q++)
            {
                buffer[j * buffWidth + i].a |= face->glyph->bitmap.buffer[q * face->glyph->bitmap.width + p];
            }
        }

        // increment pen position
        pen.x += face->glyph->advance.x;
        pen.y += face->glyph->advance.y;
    }

    return std::move(Image((Color*)data, buffWidth, buffHeight));

    return std::move(Image((Color*)data, 512, 512));
}*/

Jatta::Image&& Jatta::Font::generateText(const std::string& text, bool beginningSpacer)
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
    for (unsigned int n = 0; n < text.length();)
    {
        FT_Set_Transform(face, &matrix, &pen);
        FT_ULong utf8Character = 0;
        if (((unsigned char)(text[n]) & 0xFC) == 0xFC)
        {
            utf8Character |= (text[n++] & 0x01) << 30;
            utf8Character |= (text[n++] & 0x3F) << 24;
            utf8Character |= (text[n++] & 0x3F) << 18;
            utf8Character |= (text[n++] & 0x3F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xF8) == 0xF8)
        {
            utf8Character |= (text[n++] & 0x03) << 24;
            utf8Character |= (text[n++] & 0x3F) << 18;
            utf8Character |= (text[n++] & 0x3F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xF0) == 0xF0)
        {
            utf8Character |= (text[n++] & 0x07) << 18;
            utf8Character |= (text[n++] & 0x3F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xE0) == 0xE0)
        {
            utf8Character |= (text[n++] & 0x0F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xC0) == 0xC0)
        {
            utf8Character |= (text[n++] & 0x1F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else
        {
            utf8Character |= (text[n++] & 0x7F) << 0;
        }
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
        FT_Int down = (face->glyph->bitmap.rows - face->glyph->bitmap_top) - 1;
        if (down > maxDown)
        {
            maxDown = down;
        }
        if (n == 0 && !beginningSpacer)
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

    for (unsigned int n = 0; n < text.length();)
    {
        //pen.x = 0;
        //pen.y = 0;

        // transform the font character
        FT_Set_Transform(face, &matrix, &pen);

        // load glyph image into the slot
        //FT_Error error = FT_Load_Char(face, text[n], FT_LOAD_RENDER);
        FT_ULong utf8Character = 0;
        if (((unsigned char)(text[n]) & 0xFC) == 0xFC)
        {
            utf8Character |= (text[n++] & 0x01) << 30;
            utf8Character |= (text[n++] & 0x3F) << 24;
            utf8Character |= (text[n++] & 0x3F) << 18;
            utf8Character |= (text[n++] & 0x3F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xF8) == 0xF8)
        {
            utf8Character |= (text[n++] & 0x03) << 24;
            utf8Character |= (text[n++] & 0x3F) << 18;
            utf8Character |= (text[n++] & 0x3F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xF0) == 0xF0)
        {
            utf8Character |= (text[n++] & 0x07) << 18;
            utf8Character |= (text[n++] & 0x3F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xE0) == 0xE0)
        {
            utf8Character |= (text[n++] & 0x0F) << 12;
            utf8Character |= (text[n++] & 0x3F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else if (((unsigned char)(text[n]) & 0xC0) == 0xC0)
        {
            utf8Character |= (text[n++] & 0x1F) << 6;
            utf8Character |= (text[n++] & 0x3F) << 0;
        }
        else
        {
            utf8Character |= (text[n++] & 0x7F) << 0;
        }
        FT_Error error = FT_Load_Char(face, utf8Character, FT_LOAD_RENDER);
        if (error)
        {
            continue; // TODO: ignore errors?
        }

        if (n == 0 && !beginningSpacer)
        {
            face->glyph->bitmap_left = 1;
        }

        // now, draw to our surface
        FT_Int i, p, q;
        FT_Int x_max = face->glyph->bitmap_left + face->glyph->bitmap.width;
        FT_Int y_max = face->glyph->bitmap_top + face->glyph->bitmap.rows;
        FT_Int down = (face->glyph->bitmap.rows - face->glyph->bitmap_top) - 1;
        FT_Int startY = (((bufferHeight - maxDown) - face->glyph->bitmap.rows) + down);
        for (i = face->glyph->bitmap_left, p = 0; i < x_max; i++, p++)
        {
            for (q = 0; q < face->glyph->bitmap.rows; q++)
            {
                buffer[(q + startY) * bufferWidth + i].r = this->color.r;
                buffer[(q + startY) * bufferWidth + i].g = this->color.g;
                buffer[(q + startY) * bufferWidth + i].b = this->color.b;
                buffer[(q + startY) * bufferWidth + i].a |= (FT_Int)(face->glyph->bitmap.buffer[q * face->glyph->bitmap.width + p] * (color.a / 255.0f));
            }
        }

        // increment pen position
        pen.x += face->glyph->advance.x;
        pen.y += face->glyph->advance.y;
    }

    return std::move(Image((Color*)data, bufferWidth, bufferHeight));
}