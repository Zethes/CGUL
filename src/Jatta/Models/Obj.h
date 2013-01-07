#if 0
/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "Model.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Obj : public Model
    {
        _JATTA_EXPORT static void CleanLine(std::string* line);
        _JATTA_EXPORT static bool GetParameters(const std::string& parameters, float* data, unsigned int* size);
        _JATTA_EXPORT static bool GetParameters(const std::string& parameters);//, std::vector<std::pair<float*, unsigned int>>* data);
    public:
        _JATTA_EXPORT Obj();

        _JATTA_EXPORT bool Load(const std::string& fileName);
    };
}

#include "../External/Undefines.h"
#endif
