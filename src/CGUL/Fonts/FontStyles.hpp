// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FontStyles.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../Images/Image.hpp"
#include "../Images/Color.hpp"
#include "Glyph.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
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
}

#include "../External/Undefines.hpp"
