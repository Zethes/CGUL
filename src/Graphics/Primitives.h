//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../Math/Float2.h"
#include "../Math/Float3.h"
#include "../Images/Color.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Primitives
    {
        _JATTA_EXPORT void drawLine(Jatta::Float2 position1, Jatta::Color color1, Jatta::Float2 position2, Jatta::Color color2);
        _JATTA_EXPORT void drawLine(Jatta::Float3 position1, Jatta::Color color1, Jatta::Float3 position2, Jatta::Color color2);
        _JATTA_EXPORT void drawTriangle(Jatta::Float2 position1, Jatta::Color color1, Jatta::Float2 position2, Jatta::Color color2, Jatta::Float2 position3, Jatta::Color color3);
    };
}

#include "../External/Undefines.h"