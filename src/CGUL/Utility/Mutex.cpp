// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Mutex.cpp
 */

// Header
#include "Mutex.hpp"

#if defined(CPP_HAS_WINTHREAD) || defined(CPP_HAS_STD_THREAD) || defined(CPP_HAS_PTHREAD)

CGUL::Mutex::Mutex()
{
#   if defined(CPP_HAS_WINTHREAD)
    criticalSection = new CRITICAL_SECTION;
    InitializeCriticalSection(criticalSection);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::Mutex() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_mutex_init(&mutex, NULL);
#   endif
}

CGUL::Mutex::~Mutex()
{
#   if defined(CPP_HAS_WINTHREAD)
    DeleteCriticalSection(criticalSection);
    delete criticalSection;
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::~Mutex() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_mutex_destroy(&mutex);
#   endif
}

_CGUL_EXPORT void CGUL::Mutex::Lock()
{
#   if defined(CPP_HAS_WINTHREAD)
    EnterCriticalSection(criticalSection);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::Lock() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_mutex_lock(&mutex);
#   endif
}

_CGUL_EXPORT void CGUL::Mutex::Unlock()
{
#   if defined(CPP_HAS_WINTHREAD)
    LeaveCriticalSection(criticalSection);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: Mutex::Unlock() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_mutex_unlock(&mutex);
#   endif
}

#endif
