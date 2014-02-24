// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Thread.cpp
 */

// Header
#include "Thread.hpp"

#if defined(CPP_HAS_WINTHREAD) || defined(CPP_HAS_STD_THREAD) || defined(CPP_HAS_PTHREAD)

#if defined(CPP_HAS_WINTHREAD)
DWORD WINAPI MyThread(LPVOID ptr)
{
    ((CGUL::Thread*)ptr)->Main();
    return 0;
}
#else
static void runThread(CGUL::Thread* ptr)
{
    ptr->Main();
}
#endif

_CGUL_EXPORT CGUL::Thread::Thread()
{
}
_CGUL_EXPORT CGUL::Thread::~Thread()
{
#   if defined(CPP_HAS_WINTHREAD)
    TerminateThread(thread, 0);
#   elif defined(CPP_HAS_STD_THREAD)
    delete thread;
#   elif defined(CPP_HAS_PTHREAD)
    pthread_cancel(thread);
#   endif
}

_CGUL_EXPORT void CGUL::Thread::Run()
{
#   if defined(CPP_HAS_WINTHREAD)
    thread = CreateThread(0, 0, MyThread, this, 0, NULL);
#   elif defined(CPP_HAS_STD_THREAD)
    thread = new std::thread(runThread, this);
#   elif defined(CPP_HAS_PTHREAD)
    pthread_create(&thread, NULL, mythread, this);
#   endif
}

_CGUL_EXPORT void CGUL::Thread::Join()
{
#   if defined(CPP_HAS_WINTHREAD)
    WaitForSingleObject(thread, INFINITE);
#   elif defined(CPP_HAS_STD_THREAD)
    thread->join();
#   elif defined(CPP_HAS_PTHREAD)
    pthread_join(thread);
#   endif
}

_CGUL_EXPORT void CGUL::Thread::Detach()
{
#   if defined(CPP_HAS_WINTHREAD)
    // TODO Thread::Detach for WinThreads
#   elif defined(CPP_HAS_STD_THREAD)
    thread->detach();
#   elif defined(CPP_HAS_PTHREAD)
    pthread_detach(thread);
#   endif
}

#endif
