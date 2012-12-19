#pragma once

#include "../JattaDefines.h"
#include <string>

namespace Jatta
{
    class Ttf
    {
        _JATTA_FT_FACE(face);
    public:
        Ttf(const std::string& fileName);
        void load();
    };
}

#include "../JattaUndefines.h"