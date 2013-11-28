// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Font.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../Images/Image.hpp"
#include "../Images/Color.hpp"
#include "Glyph.hpp"
#include "FontStyles.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{

    class Font
    {
        std::vector<_CGUL_FT_FACE> faces;
        unsigned int size;
        Color color;
        std::map<UInt32, Glyph*> glyphCache;
    public:
        _CGUL_EXPORT Font();
        _CGUL_EXPORT UInt32 Load(const std::string& fileName);
        _CGUL_EXPORT UInt32 LoadFromMemory(const unsigned char* data, UInt64 size);
        _CGUL_EXPORT void PreloadGlyphs(UInt32 start, UInt32 end);
        _CGUL_EXPORT void ClearCache();

        _CGUL_EXPORT void SetSize(UInt32 size);
        _CGUL_EXPORT unsigned int GetSize();

        _CGUL_EXPORT void SetStyle(UInt32 style);

        _CGUL_EXPORT Image GenerateText(Color color, const String& text);

        _CGUL_EXPORT UInt64 GetCharacterIndex(UInt32 face, UInt64 characterCode);
        _CGUL_EXPORT Glyph* GetGlyph(UInt32 utf8Character, bool useCache = true);
    };
}

#include "../External/Undefines.hpp"
