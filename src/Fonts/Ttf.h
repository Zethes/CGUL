//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Images/Image.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Ttf
    {
        _JATTA_FT_FACE face;
        unsigned int size;
    public:
        Ttf();
        void load(const std::string& fileName, unsigned int size);

        Image&& blurg(const std::string& text);
        Image&& blurg(const std::string& text, const Color& color);
    };
}

#include "../External/Undefines.h"