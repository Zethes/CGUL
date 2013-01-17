/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_FONTS
#pragma once
#include "../Utility/String.h"
#include "../Images/Image.h"
#include "../Images/Color.h"
//#include "Glyph.h"
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
        _JATTA_EXPORT void Load(const std::string& fileName);

        _JATTA_EXPORT void SetSize(UInt32 size);
        _JATTA_EXPORT unsigned int GetSize();

        _JATTA_EXPORT void SetColor(const Color& color);
        _JATTA_EXPORT Color GetColor();

        _JATTA_EXPORT Image GenerateText(const Jatta::String& text, Boolean beginningSpacer = false);

        _JATTA_EXPORT UInt64 GetCharacterIndex(UInt64 characterCode);
        //_JATTA_EXPORT Glyph getGlyph(UInt64 index);
    };
}

#include "../External/Undefines.h"
#endif