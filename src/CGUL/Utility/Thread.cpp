// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Thread.cpp
 */

#include "Thread.hpp"

// TODO: add some alternatives to std::thread (pthread and winapi thread)
#ifdef CPP_HAS_STD_THREAD

static void runThread(CGUL::Thread* ptr)
{
    ptr->Main();
}

_CGUL_EXPORT CGUL::Thread::Thread()
{

}
_CGUL_EXPORT CGUL::Thread::~Thread()
{
    delete thread;
}

_CGUL_EXPORT void CGUL::Thread::Run()
{
    thread = new std::thread(runThread, this);
}

_CGUL_EXPORT void CGUL::Thread::Join()
{
    thread->join();
}

_CGUL_EXPORT void CGUL::Thread::Detach()
{
    thread->detach();
}

#endif
