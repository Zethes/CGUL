// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Thread.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

#if defined(CPP_HAS_WINTHREAD) || defined(CPP_HAS_STD_THREAD) || defined(CPP_HAS_PTHREAD)

namespace CGUL
{
    class Thread
    {
    private:
#       if defined(CPP_HAS_WINTHREAD)
        _CGUL_HANDLE thread;
#       elif defined(CPP_HAS_STD_THREAD)
        std::thread* thread;
#       elif defined(CPP_HAS_PTHREAD)
        _CGUL_PTHREAD_T thread;
#       endif
    public:
        _CGUL_EXPORT Thread();
        _CGUL_EXPORT virtual ~Thread();

        _CGUL_EXPORT void Run();

        _CGUL_EXPORT void Join();
        _CGUL_EXPORT void Detach();

        _CGUL_EXPORT virtual void Main() = 0;
    };
}

#endif

// Undefines
#include "../External/Undefines.hpp"
