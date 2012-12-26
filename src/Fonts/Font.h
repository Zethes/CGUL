//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Utility/String.h"
#include "../Images/Image.h"
#include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Font
    {
        std::vector<_JATTA_FT_FACE> faces;
        unsigned int size;
        Color color;
    public:
        Font();
        void load(const std::string& fileName);

        void setSize(unsigned int size);
        unsigned int getSize();

        void setColor(const Color& color);
        Color getColor();

        Image generateText(const Jatta::String& text, bool beginningSpacer = false);
    };
}

#include "../External/Undefines.h"