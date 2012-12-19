//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Ttf
    {
        _JATTA_FT_FACE face;
    public:
        Ttf(const std::string& fileName);
        void load();
    };
}

#include "../External/Undefines.h"