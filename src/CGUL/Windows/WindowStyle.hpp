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
        UInt32 width;
        UInt32 height;
        Boolean resizable;

        _CGUL_EXPORT WindowStyle();
        _CGUL_EXPORT WindowStyle(const WindowStyle& style);
        _CGUL_EXPORT WindowStyle(const std::string& title, Color backgroundColor, UInt32 width, UInt32 height, Boolean resizable);

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

#include "../External/Undefines.hpp"
