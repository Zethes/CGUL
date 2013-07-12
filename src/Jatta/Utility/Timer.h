/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief A timer to keep track of time, similar to a stop watch.
     */
    class Timer
    {
    private:
        Float32 pcFreq;
        long startTime;
        long mSeconds;
        bool running;
    public:
        //! @brief Causes the current thread to idle for the given amount of time (in millseconds).
        _JATTA_EXPORT static void Sleep(UInt32 milliseconds);

        //! @brief Default constructor.
        _JATTA_EXPORT Timer();
        //! @brief Starts the timer causing time to elapse.
        _JATTA_EXPORT void Start();
        //! @brief Stops the timer, freezing it at the current time.
        _JATTA_EXPORT void Stop();
        //! @brief Resets the timer to zero without stopping or starting it.
        _JATTA_EXPORT void Reset();

        //! @brief Get a system time in seconds.
        _JATTA_EXPORT UInt32 GetSeconds();
        //! @brief Get a system time in milliseconds.
        _JATTA_EXPORT UInt32 GetMilliseconds();

        //! @brief Get the elapsed time (in seconds) from when the timer was started.
        _JATTA_EXPORT UInt32 GetElapsedSeconds();
        //! @brief Get the elapsed time (in milliseconds) from when the timer was started.
        _JATTA_EXPORT UInt32 GetElapsedMilliseconds();

        //! @brief A quick utility function for calculating delta time.
        _JATTA_EXPORT Float32 GetDeltaTime();
    };
}

#include "../External/Undefines.h"
