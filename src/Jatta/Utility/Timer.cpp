/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Timer.h"
#ifdef LINUX
#  include <sys/time.h>
#  include <unistd.h>
#endif

_JATTA_EXPORT Jatta::Timer::Timer()
{
    running = false;
    mSeconds = 0;

#   ifdef WINDOWS
    LARGE_INTEGER li;
    QueryPerformanceFrequency(&li);
    pcFreq = Float32(li.QuadPart) / 1000.0f;
#   endif
}

_JATTA_EXPORT void Jatta::Timer::Start()
{
    startTime = GetMiliseconds();
    running = true;
}

_JATTA_EXPORT void Jatta::Timer::Stop()
{
    long end = GetMiliseconds();
    mSeconds = end-  startTime;
    running = false;
}

_JATTA_EXPORT void Jatta::Timer::Reset()
{
    Stop();
    mSeconds = 0;
    Start();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Timer::GetSeconds()
{
    return (UInt32)(GetMiliseconds() / 1000);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Timer::GetMiliseconds()
{
#   ifdef WINDOWS
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return (UInt32)(li.QuadPart / (UInt32)pcFreq);
#   endif

#   ifdef LINUX
    struct timeval t;
    gettimeofday(&t, NULL);
    return ((t.tv_sec) * 1000 + t.tv_usec / 1000.0) + 0.5f;
#   endif
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Timer::GetElapsedSeconds()
{
    return GetElapsedMiliseconds() / 1000;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Timer::GetElapsedMiliseconds()
{
    if (running)
    {
        long end = GetMiliseconds();
        return end-startTime;
    }
    else
    {
        return mSeconds;
    }
}

_JATTA_EXPORT void Jatta::Timer::Sleep(UInt32 milliseconds)
{
#   ifdef WINDOWS
    ::Sleep(milliseconds);
#   endif

#   ifdef LINUX
    usleep(milliseconds * 1000);
#   endif
}
