// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file WindowStyle.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../Images/Color.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief Contains customizable attributes for window creation.
     */
    struct WindowStyle
    {
        String title;
        Color backgroundColor;
        UCoord32 size;
        Boolean resizable;
        Boolean centerWindow;
        SCoord32 position;
        Boolean alwaysOnTop;

        _CGUL_EXPORT WindowStyle();
        _CGUL_EXPORT WindowStyle(const WindowStyle& style);
        _CGUL_EXPORT WindowStyle(const std::string& title,
                                 Color backgroundColor,
                                 UCoord32 size,
                                 Boolean resizable,
                                 Boolean centerWindow,
                                 SCoord32 position,
                                 Boolean alwaysOnTop);

        friend std::ostream& operator<<(std::ostream& stream, const WindowStyle& style)
        {
            stream << "Title:            " << style.title << std::endl;
            stream << "Background Color: " << style.backgroundColor << std::endl;
            stream << "Size:             " << style.size << std::endl;
            stream << "Resizable:        " << (style.resizable ? "true" : "false") << std::endl;;
            stream << "Window Centered:  " << (style.centerWindow ? "true" : "false") << std::endl;
            if (style.centerWindow)
            {
                stream << "Offset:           " << style.position << std::endl;
            }
            else
            {
                stream << "Position:         " << style.position << std::endl;
            }
            stream << "Always On Top:    " << (style.alwaysOnTop ? "true" : "false");
            return stream;
        }
    };
}

#include "../External/Undefines.hpp"
