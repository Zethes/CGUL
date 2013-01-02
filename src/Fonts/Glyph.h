//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct Glyph
    {
        UInt32 width;
        UInt32 height;
        Byte* data;
    };
}

#include "../External/Undefines.h"