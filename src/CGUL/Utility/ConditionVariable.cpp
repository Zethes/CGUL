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
    InitializeConditionVariable(&conditionVariable);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: ConditionVariable::ConditionVariable() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_init(&conditionVariable, NULL);
#   endif
}

CGUL::ConditionVariable::~ConditionVariable()
{
#   if defined(CPP_HAS_WINTHREAD)
    // do nothing
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: ConditionVariable::~ConditionVariable() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_destroy(&conditionVariable);
#   endif
}

_CGUL_EXPORT void CGUL::ConditionVariable::Wait(CGUL::Mutex* mutex)
{
#   if defined(CPP_HAS_WINTHREAD)
    SleepConditionVariableCS(&conditionVariable, mutex->criticalSection, INFINITE);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: ConditionVariable::Wait() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_wait(&conditionVariable, &mutex->mutex);
#   endif
}

// timeout is in milliseconds
// returns true if a signal was received, false if an error occurred (such as timeout)
_CGUL_EXPORT bool CGUL::ConditionVariable::WaitFor(CGUL::Mutex* mutex, UInt32 timeout)
{
#   if defined(CPP_HAS_WINTHREAD)
    return SleepConditionVariableCS(&conditionVariable, mutex->criticalSection, timeout) != 0;
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: ConditionVariable::WaitFor() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    timeval currentTime;
    timespec waitTime;

    gettimeofday(&currentTime, NULL);

    waitTime.tv_sec = currentTime.tv_sec;
    waitTime.tv_nsec = currentTime.tv_usec * 1000;

    waitTime.tv_sec += timeout / 1000;
    waitTime.tv_nsec += (timeout % 1000) * 1000000;

    if (waitTime.tv_nsec > 1000000000)
    {
        waitTime.tv_sec++;
        waitTime.tv_nsec -= 1000000000;
    }

    return pthread_cond_timedwait(&conditionVariable, &mutex->mutex, &waitTime) == 0;
#   endif
}

_CGUL_EXPORT void CGUL::ConditionVariable::Signal()
{
#   if defined(CPP_HAS_WINTHREAD)
    WakeConditionVariable(&conditionVariable);
#   elif defined(CPP_HAS_STD_THREAD)
    // TODO: ConditionVariable::Signal() for std::thread
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cond_signal(&conditionVariable);
#   endif
}

#endif
