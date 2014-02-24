// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Mutex.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

#if defined(CPP_HAS_WINTHREAD)// || defined(CPP_HAS_STD_THREAD) || defined(CPP_HAS_PTHREAD)

namespace CGUL
{
    class Mutex
    {
    private:
#       if defined(CPP_HAS_WINTHREAD)
        _CGUL_CRITICAL_SECTION* criticalSection;
#       elif defined(CPP_HAS_STD_THREAD)
        //
#       elif defined(CPP_HAS_PTHREAD)
        //
#       endif
    public:
        _CGUL_EXPORT Mutex();
        _CGUL_EXPORT ~Mutex();

        _CGUL_EXPORT void Lock();
        _CGUL_EXPORT void Unlock();

        _CGUL_EXPORT bool Check();
    };
}

#endif

// Undefines
#include "../External/Undefines.hpp"
