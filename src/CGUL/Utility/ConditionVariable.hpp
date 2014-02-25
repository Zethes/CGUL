// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ConditionVariable.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

#if defined(CPP_HAS_WINTHREAD) || defined(CPP_HAS_STD_THREAD) || defined(CPP_HAS_PTHREAD)

namespace CGUL
{
    class Mutex;

    class ConditionVariable
    {
    private:
#       if defined(CPP_HAS_WINTHREAD)
        _CGUL_CONDITION_VARIABLE conditionVariable;
#       elif defined(CPP_HAS_STD_THREAD)
        //
#       elif defined(CPP_HAS_PTHREAD)
        _CGUL_PTHREAD_COND_T conditionVariable;
#       endif
    public:
        _CGUL_EXPORT ConditionVariable();
        _CGUL_EXPORT ~ConditionVariable();

        _CGUL_EXPORT void Wait(CGUL::Mutex* mutex);
        _CGUL_EXPORT void Signal();
    };
}

#endif

// Undefines
#include "../External/Undefines.hpp"
