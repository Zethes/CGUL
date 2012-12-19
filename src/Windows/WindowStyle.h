//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    struct WindowStyle
    {
        std::string title;
        Color backgroundColor;
        unsigned int width;
        unsigned int height;
    };
}

#include "../External/Undefines.h"