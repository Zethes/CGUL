//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    struct WindowStyle
    {
        std::string title; // 8
        Color backgroundColor; // 4
        unsigned int width; // 4
        unsigned int height; // 4

        WindowStyle();
        WindowStyle(const WindowStyle& style);
        WindowStyle(const std::string& title, Color backgroundColor, unsigned int width, unsigned int height);
    };
}

#include "../External/Undefines.h"
