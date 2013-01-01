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
        _JATTA_EXPORT Font();
        _JATTA_EXPORT void load(const std::string& fileName);

        _JATTA_EXPORT void setSize(unsigned int size);
        _JATTA_EXPORT unsigned int getSize();

        _JATTA_EXPORT void setColor(const Color& color);
        _JATTA_EXPORT Color getColor();

        _JATTA_EXPORT Image generateText(const Jatta::String& text, bool beginningSpacer = false);
    };
}

#include "../External/Undefines.h"