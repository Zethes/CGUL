//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "Model.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Obj : public Model
    {
        _JATTA_EXPORT static void cleanLine(std::string* line);
        _JATTA_EXPORT static bool getParameters(const std::string& parameters, float* data, unsigned int* size);
        _JATTA_EXPORT static bool getParameters(const std::string& parameters);//, std::vector<std::pair<float*, unsigned int>>* data);
    public:
        _JATTA_EXPORT Obj();

        _JATTA_EXPORT bool load(const std::string& fileName);
    };
}

#include "../External/Undefines.h"