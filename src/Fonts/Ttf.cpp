#include "Ttf.h"

#include <iostream> // TODO: remove iostream

FT_Library __jatta_ttf_library;

void __jatta_ttf_initialize()
{
    FT_Error error = FT_Init_FreeType(&__jatta_ttf_library);
    if (error)
    {
        std::cout << "Could not initialize FreeType" << std::endl;
    }
}

Jatta::Ttf::Ttf(const std::string& fileName)
{
    FT_Face face;
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
    error = FT_Set_Char_Size(face, 50 * 18, 0, 100, 0);
    if (error)
    {
        // @TODO error checking
        std::cout << "Failed to set character size." << std::endl;
    }
    std::cout << FT_Get_X11_Font_Format(face) << std::endl;
}