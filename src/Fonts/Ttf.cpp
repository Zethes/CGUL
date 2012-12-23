#include "Ttf.h"
#include "../Images/Color.h"
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

Jatta::Ttf::Ttf()
{
    __jatta_ttf_initialize();
}

void Jatta::Ttf::load(const std::string& fileName, unsigned int size)
{
    FT_Error error = FT_New_Face(__jatta_ttf_library, fileName.c_str(), 0, &face);
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
    //error = FT_Set_Char_Size(face, 40 * size, 0, 100, 0);
    FT_Set_Pixel_Sizes(face, 0, size);
    if (error)
    {
        // @TODO error checking
        std::cout << "Failed to set character size." << std::endl;
    }
    std::cout << FT_Get_X11_Font_Format(face) << std::endl;
    this->size = size;
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

Jatta::Image&& Jatta::Ttf::blurg(const std::string& text)
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
        pen.x = 0;
        pen.y = 0;

        // transform the font character
        FT_Set_Transform(face, &matrix, &pen);

        // load glyph image into the slot
        //FT_Error error = FT_Load_Char(face, text[n], FT_LOAD_RENDER);
        FT_Error error = FT_Load_Char(face, 12353, FT_LOAD_RENDER);
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
}

Jatta::Image&& Jatta::Ttf::blurg(const std::string& text, const Color& color)
{
    Image img = blurg(text);
    unsigned int size = img.getWidth() * img.getHeight();
    Color* data = (Color*)img.getData();
    for (unsigned int i = 0; i < size; i++)
    {
        /*data[i].r = color.r;
        data[i].g = color.g;
        data[i].b = color.b;*/
        data[i].r = data[i].a;
        data[i].g = data[i].a;
        data[i].b = data[i].a;
        data[i].a = 255;
    }
    return std::move(img);
}
