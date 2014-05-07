// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Glyph.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../Images/Image.hpp"
#include "../Images/Color.hpp"
#include "../External/Defines.hpp"

/*
 * Glyph metrics:
 * --------------
 *
 *                       xmin                     xmax
 *                        |                         |
 *                        |<-------- width -------->|
 *                        |                         |
 *              |         +-------------------------+----------------- ymax
 *              |         |    ggggggggg   ggggg    |     ^        ^
 *              |         |   g:::::::::ggg::::g    |     |        |
 *              |         |  g:::::::::::::::::g    |     |        |
 *              |         | g::::::ggggg::::::gg    |     |        |
 *              |         | g:::::g     g:::::g     |     |        |
 *    offset_x -|-------->| g:::::g     g:::::g     |  offset_y    |
 *              |         | g:::::g     g:::::g     |     |        |
 *              |         | g::::::g    g:::::g     |     |        |
 *              |         | g:::::::ggggg:::::g     |     |        |
 *              |         |  g::::::::::::::::g     |     |      height
 *              |         |   gg::::::::::::::g     |     |        |
 *  baseline ---*---------|---- gggggggg::::::g-----*--------      |
 *            / |         |             g:::::g     |              |
 *     origin   |         | gggggg      g:::::g     |              |
 *              |         | g:::::gg   gg:::::g     |              |
 *              |         |  g::::::ggg:::::::g     |              |
 *              |         |   gg:::::::::::::g      |              |
 *              |         |     ggg::::::ggg        |              |
 *              |         |         gggggg          |              v
 *              |         +-------------------------+----------------- ymin
 *              |                                   |
 *              |------------- advance_x ---------->|
 */

// TODO: should probably update the graphic above with the CGUL equivalents

namespace CGUL
{
    namespace Font
    {
        class Glyph
        {
            friend class Face;

            _CGUL_FT_GLYPH glyph;
            UCoord32 size;
            SCoord32 origin;
            SCoord32 advance;

            _CGUL_EXPORT bool Setup(_CGUL_FT_GLYPH glyph, void* glyphSlot);
        public:
            _CGUL_EXPORT Glyph();
            _CGUL_EXPORT ~Glyph();

            _CGUL_EXPORT void Free();

            _CGUL_EXPORT UInt32 GetWidth() const;
            _CGUL_EXPORT UInt32 GetHeight() const;
            _CGUL_EXPORT UCoord32 GetSize() const;
            _CGUL_EXPORT SCoord32 GetOrigin() const;
            _CGUL_EXPORT SCoord32 GetAdvance() const;

            _CGUL_EXPORT Byte Get(UInt32 x, UInt32 y) const;
        };
    }
}

#include "../External/Undefines.hpp"
