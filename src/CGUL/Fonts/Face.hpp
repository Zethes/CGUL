// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Face.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Images/Image.hpp"
#include "../Images/Color.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Font
    {
        class Glyph;

        class Face
        {
            _CGUL_FT_FACE face;
            UIntN size;
        public:
            _CGUL_EXPORT Face();
            _CGUL_EXPORT ~Face();

            _CGUL_EXPORT void Load(const CGUL::String& fileName);
            _CGUL_EXPORT void Load(const void* data, Size size);
            _CGUL_EXPORT void Free();

            _CGUL_EXPORT void SetSize(UInt32 size);
            _CGUL_EXPORT UInt32 GetSize() const;

            _CGUL_EXPORT UInt32 GetMetricHeight() const;
            _CGUL_EXPORT UInt32 GetNumGlyphs() const;

            _CGUL_EXPORT bool LoadGlyph(UInt32 character, Glyph* glyph);
        private:
            _CGUL_INLINE_DEFINE void* _GetData();
        };
    }
}

#include "../External/Undefines.hpp"
