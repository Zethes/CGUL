/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../Utility/String.h"
#include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    struct WindowStyle
    {
        String title;
        Color backgroundColor;
        UInt32 width;
        UInt32 height;
        Boolean resizable;

        _JATTA_EXPORT WindowStyle();
        _JATTA_EXPORT WindowStyle(const WindowStyle& style);
        _JATTA_EXPORT WindowStyle(const std::string& title, Color backgroundColor, UInt32 width, UInt32 height, Boolean resizable);
    };
}

#include "../External/Undefines.h"
