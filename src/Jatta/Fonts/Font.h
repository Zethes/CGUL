/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../Images/Image.h"
#include "../Images/Color.h"
#include "Glyph.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Font
    {
        std::vector<_JATTA_FT_FACE> faces;
        unsigned int size;
        Color color;
        std::map<UInt32, Glyph*> glyphCache;
    public:
        _JATTA_EXPORT Font();
        _JATTA_EXPORT UInt32 Load(const std::string& fileName);
        _JATTA_EXPORT UInt32 LoadFromMemory(const unsigned char* data, UInt64 size);
        _JATTA_EXPORT void PreloadGlyphs(UInt32 start, UInt32 end);
        _JATTA_EXPORT void ClearCache();

        _JATTA_EXPORT void SetSize(UInt32 size);
        _JATTA_EXPORT unsigned int GetSize();

        _JATTA_EXPORT Image GenerateText(Jatta::Color color, const Jatta::String& text);

        _JATTA_EXPORT UInt64 GetCharacterIndex(UInt32 face, UInt64 characterCode);
        _JATTA_EXPORT Glyph* GetGlyph(UInt32 utf8Character, bool useCache = true);
    };
}

#include "../External/Undefines.h"