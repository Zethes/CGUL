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
#   ifdef _CPP_QUALIFIED_ENUM
    enum FontStyles
    {
        OBLIQUE         = 0x0001,
        OVERLINED       = 0x0002,
        UNDERLINED      = 0x0004,
        STRIKED         = 0x0008
    };
#   else
    namespace FontStyles
    {
        enum
        {
            OBLIQUE         = 0x0001,
            OVERLINED       = 0x0002,
            UNDERLINED      = 0x0004,
            STRIKED         = 0x0008
        };
    }
#   endif
}

#include "../External/Undefines.h"
