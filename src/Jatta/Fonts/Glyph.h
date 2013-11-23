/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Vector2.hpp"
#include "../Images/Image.h"
#include "../Images/Color.h"
#include "FontStyles.h"
#include "../External/Defines.h"

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

namespace Jatta
{
    class Glyph
    {
    private:
        UInt32 character;
        UInt32 width;
        UInt32 height;
        Vector2 offset;
        Vector2 advance;
        Byte* data;
    public:
        _JATTA_EXPORT Glyph(_JATTA_FT_FACE face, UInt32 utf8Character);
        _JATTA_EXPORT ~Glyph();

        _JATTA_EXPORT UInt32 GetWidth();
        _JATTA_EXPORT UInt32 GetHeight();
        _JATTA_EXPORT Vector2 GetAdvance();
        _JATTA_EXPORT Vector2 GetOffset();

        _JATTA_EXPORT Byte* GetData();

        _JATTA_EXPORT Image GetImage(Color color, UInt32 styleFlags); //Generates RGBA8888 image.
    };
}

#include "../External/Undefines.h"
