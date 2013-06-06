/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

// TODO: find an open-licensed regex lib, relying on c++11 is a bad idea right now

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    template<typename T> class Hook
    {
    public:
        typedef void(*Type)(T);
    private:
        std::vector<Type> functions;
    public:
        Type Attach(Type func);
        bool Remove(Type func);
        void Call(T parameter);
    };
}

#include "../External/Undefines.h"

#include "Hook.ipp"