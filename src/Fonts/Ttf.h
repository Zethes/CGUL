//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Images/Image.h"
#include "../Images/Color.h"
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

        Image&& blurg(const std::string& text, const Color& color = Color(0, 0, 0), bool beginningSpacer = false);
    };
}

#include "../External/Undefines.h"