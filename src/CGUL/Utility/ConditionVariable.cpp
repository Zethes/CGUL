// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ConditionVariable.cpp
 */

// Header
#include "ConditionVariable.hpp"

// CGUL Includes
#include "../Utility/Mutex.hpp"

#if defined(CPP_HAS_WINTHREAD) || defined(CPP_HAS_STD_THREAD) || defined(CPP_HAS_PTHREAD)

CGUL::ConditionVariable::ConditionVariable()
{
#   if defined(CPP_HAS_WINTHREAD)
    criticalSection = new CRITICAL_SECTION;
    InitializeCriticalSection(criticalSection);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::Mutex() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_init(&conditionVariable, NULL);
#   endif
}

CGUL::ConditionVariable::~ConditionVariable()
{
#   if defined(CPP_HAS_WINTHREAD)
    DeleteCriticalSection(criticalSection);
    delete criticalSection;
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::~Mutex() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_destroy(&conditionVariable);
#   endif
}

_CGUL_EXPORT void CGUL::ConditionVariable::Wait(CGUL::Mutex* mutex)
{
#   if defined(CPP_HAS_WINTHREAD)
    EnterCriticalSection(criticalSection);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::Lock() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_wait(&conditionVariable, &mutex->mutex);
#   endif
}

_CGUL_EXPORT void CGUL::ConditionVariable::Signal()
{
#   if defined(CPP_HAS_WINTHREAD)
    LeaveCriticalSection(criticalSection);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::Unlock() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_signal(&conditionVariable);
#   endif
}

#endif
