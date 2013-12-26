// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Timer.cpp
 */

#include "Timer.hpp"
#if defined(CGUL_LINUX) || defined(CGUL_MACOS)
#   include <sys/time.h>
#   include <unistd.h>
#endif

CGUL::Float64 CGUL::Timer::GetFrequency()
{
#   ifdef CGUL_WINDOWS
    static UInt64 cachedFrequency = 0;
    if (cachedFrequency == 0)
    {
        LARGE_INTEGER frequency;
        QueryPerformanceFrequency(&frequency);
        cachedFrequency = frequency.QuadPart;
    }
    return (Float64)cachedFrequency;
#   else
    return 1000000.0;
#   endif
}

CGUL::UInt64 CGUL::Timer::GetTime()
{
#   ifdef CGUL_WINDOWS
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    return counter.QuadPart;
#   else
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000000 + time.tv_usec;
#   endif
}

/** @details A program that never sleeps can cause CPU thrashing so its a good idea to call sleep
 *  and let the CPU take care of other things for a short while.  Sleeping will cause the currently
 *  active thread to halt for the given amount of time.  As little as 1 millisecond is enough to
 *  take a huge load off of the CPU and its recommended that applications in a constant loop makes
 *  a call each tick to the @ref Sleep method.  It is not guaranteed (and in fact very unlikely)
 *  that this method will halt the program for @em exactly the amount of milliseconds specified.
 *  @param milliseconds The amount of time to sleep in milliseconds.
 */
_CGUL_EXPORT void CGUL::Timer::Sleep(UInt32 milliseconds)
{
#   ifdef CGUL_WINDOWS
    ::Sleep(milliseconds);
#   else
    usleep(milliseconds * 1000);
#   endif
}

/** @details Same as the @ref GetMilliseconds method but in seconds.
 *  @see GetMilliseconds
 *  @returns An undefined time in seconds.
 */
_CGUL_EXPORT CGUL::Float64 CGUL::Timer::GetSeconds()
{
    return (GetMilliseconds() / 1000.0);
}

/** @details Gets a time from the operating system in milliseconds.  The time acquired is not
 *  guaranteed to represent any significance aside from being incremental from a previous
 *  @ref GetMilliseconds or @ref GetSeconds call.  In other words, this time does not represent the
 *  current time of day, the time the operating system has been up, or any other such data.  The
 *  only purpose of this method is to compare two time stamps to find a delta in time.
 *  @returns An undefined time in milliseconds.
 */
_CGUL_EXPORT CGUL::Float64 CGUL::Timer::GetMilliseconds()
{
    return (GetTime() / (GetFrequency() / 1000.0));
}

/** @details The value here is practically guaranteed to be different everytime it's called.  The
 *  value is primarily useful for seeding random numbers.
 *  @returns A high precision timestamp of little value to anyone.
 */
_CGUL_EXPORT CGUL::UInt64 CGUL::Timer::GetRawTime()
{
    return GetTime();
}

/**
 */
_CGUL_EXPORT CGUL::Timer::Timer()
{
    running = false;
    startTime = GetTime();
    storedTime = 0;
}

/** @details Acts just as the start would on a stop watch.  If the clock is currently stopped it
 *  will resume the last time recorded.  If the clock is already started, it will do nothing.
 *  @see Stop
 *  @see Reset
 */
_CGUL_EXPORT void CGUL::Timer::Start()
{
    startTime = GetTime() - storedTime;
    running = true;
}

/** @details Acts just as the stop would on a stop watch.  The current time will be recorded and
 *  the clock will stop progressing forward.  This method will not reset the clock to zero, for
 *  that the @ref Reset method must be called separately.  If the clock is already stopped then this
 *  method does nothing.
 *  @see Start
 *  @see Reset
 */
_CGUL_EXPORT void CGUL::Timer::Stop()
{
    if (running)
    {
        UInt64 end = GetTime();
        storedTime = end - startTime;
        running = false;
    }
}

/** @details Acts just as the reset would on a stop watch.  The current time is set to zero but the
 *  state of the clock is not changed.  If the clock was running when this method was called then
 *  it will continue to run starting from zero.  In order to both stop and reset the clock, the
 *  methods @ref Stop and @ref Reset must be called in that order.  Calling the @ref Start method
 *  after calling @ref Reset will cause the clock to pick up the time where it left off.
 *  @see Start
 *  @see Stop
 */
_CGUL_EXPORT void CGUL::Timer::Reset()
{
    startTime = GetTime();
    storedTime = 0;
}

/** @details Same as @ref GetElapsedMilliseconds method but in seconds.
 *  @see GetElapsedMilliseconds
 *  @returns Elapsed time in seconds.
 */
_CGUL_EXPORT CGUL::Float64 CGUL::Timer::GetElapsedSeconds()
{
    return GetElapsedMilliseconds() / 1000.0;
}

/** @details Represents the time currently recorded by this clock some time after a call to the
 *  Start method.  If a clock has not been started this method will simply return zero.
 *  @returns Elapsed time in milliseconds.
 */
_CGUL_EXPORT CGUL::Float64 CGUL::Timer::GetElapsedMilliseconds()
{
    if (running)
    {
        UInt64 end = GetTime();
        return (end - startTime) / GetFrequency();
    }
    else
    {
        return storedTime / GetFrequency();
    }
}

/** @details Determines time in between calls and returns a floating point (decimal) time in
 *  seconds.  It is recommended that this method be used instead of @ref Start, @ref Stop, and
 *  @ref Reset for delta time calculations because it is better optimized for that purpose and will
 *  yield more accurate results.  Additionally, this method will reset the timer every time it is
 *  called so the @ref GetElapsedSeconds and @ref GetElapsedMilliseconds methods will not give
 *  accurate results.
 *  @note The first time this method is called it will return the time between the creation of the
 *  @ref Timer object and the time the method was called.  For best use create the @ref Timer
 *  immediately before it is to be used.
 *  @returns A floating pointer decimal number representing the time in seconds since the last call
 *  to this method.
 */
_CGUL_EXPORT CGUL::Float64 CGUL::Timer::GetDeltaTime()
{
    UInt64 time = GetTime();
    Float64 deltaTime = (time - startTime) / GetFrequency();
    startTime = time;
    return deltaTime;
}
