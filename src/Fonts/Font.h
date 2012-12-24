//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Images/Image.h"
#include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Font
    {
        _JATTA_FT_FACE face;
        unsigned int size;
        Color color;
    public:
        Font();
        void load(const std::string& fileName);

        void setSize(unsigned int size);
        unsigned int getSize();

        void setColor(const Color& color);
        Color getColor();

        Image&& generateText(const std::string& text, bool beginningSpacer = false);
    };
}

#include "../External/Undefines.h"