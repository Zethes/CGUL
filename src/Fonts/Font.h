//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Utility/String.h"
#include "../Images/Image.h"
#include "../Images/Color.h"
#include "Glyph.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Font
    {
        _JATTA_FT_FACE face;
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

        _JATTA_EXPORT UInt64 getCharacterIndex(Jatta::UInt64 characterCode);
        _JATTA_EXPORT Glyph getGlyph(UInt64 index);
    };
}

#include "../External/Undefines.h"