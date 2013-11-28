/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief Contains customizable attributes for window creation.
     */
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

        friend std::ostream& operator<<(std::ostream& stream, const WindowStyle& style)
        {
            stream << "Title:            " << style.title << std::endl;
            stream << "Background Color: " << style.backgroundColor << std::endl;
            stream << "Width:            " << style.width << std::endl;
            stream << "Height:           " << style.height << std::endl;
            stream << "Resizable:        " << style.resizable;
            return stream;
        }
    };
}

#include "../External/Undefines.h"
