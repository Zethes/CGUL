//        JATTA        //
// by Joshua Brookover //

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
        unsigned int width;
        unsigned int height;
        bool resizable;

        WindowStyle();
        WindowStyle(const WindowStyle& style);
        WindowStyle(const std::string& title, Color backgroundColor, unsigned int width, unsigned int height, bool resizable);
    };
}

#include "../External/Undefines.h"
