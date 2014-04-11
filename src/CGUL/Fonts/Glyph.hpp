// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Glyph.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Vector2.hpp"
#include "../Images/Image.hpp"
#include "../Images/Color.hpp"
#include "FontStyles.hpp"
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

namespace CGUL
{
    class Glyph
    {
    private:
        UInt32 character;
        UInt32 width;
        UInt32 height;
        Vector2F offset;
        Vector2F advance;
        Byte* data;
    public:
        _CGUL_EXPORT Glyph(_CGUL_FT_FACE face, UInt32 utf8Character);
        _CGUL_EXPORT ~Glyph();

        _CGUL_EXPORT UInt32 GetWidth();
        _CGUL_EXPORT UInt32 GetHeight();
        _CGUL_EXPORT Vector2F GetAdvance();
        _CGUL_EXPORT Vector2F GetOffset();

        _CGUL_EXPORT Byte* GetData();

        _CGUL_EXPORT Image GetImage(Color color, UInt32 styleFlags); //Generates RGBA8888 image.
    };
}

#include "../External/Undefines.hpp"
