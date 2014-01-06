// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Timer.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A timer to keep track of time, similar to a stop watch.
     */
    class Timer
    {
    private:
        UInt64 startTime;
        UInt64 storedTime;
        bool running;

        static Float64 GetFrequency();
        static UInt64 GetTime();

        // TODO: make Get functions templated to support 64 or 32 bit precision
    public:
        //! @brief Causes the current thread to idle for the given amount of time (in millseconds).
        _CGUL_EXPORT static void Sleep(UInt32 milliseconds);

        //! @brief Get a system time in seconds.
        _CGUL_EXPORT static Float64 GetSeconds();
        //! @brief Get a system time in milliseconds.
        _CGUL_EXPORT static Float64 GetMilliseconds();

        //! @brief Gets a high precision timestamp.
        _CGUL_EXPORT static UInt64 GetRawTime();

        //! @brief Default constructor.
        _CGUL_EXPORT Timer();

        //! @brief Copies data from one timer into another.
        _CGUL_EXPORT Timer& operator=(const Timer& operand);

        //! @brief Starts the timer causing time to elapse.
        _CGUL_EXPORT void Start();
        //! @brief Stops the timer, freezing it at the current time.
        _CGUL_EXPORT void Stop();
        //! @brief Resets the timer to zero without stopping or starting it.
        _CGUL_EXPORT void Reset();

        // @brief Sets the elapsed time (in seconds) for the timer.
        _CGUL_EXPORT void SetElapsedSeconds(Float64 seconds);
        // @brief Sets the elapsed time (in milliseconds) for the timer.
        _CGUL_EXPORT void SetElapsedMilliseconds(Float64 milliseconds);

        //! @brief Get the elapsed time (in seconds) from when the timer was started.
        _CGUL_EXPORT Float64 GetElapsedSeconds() const;
        //! @brief Get the elapsed time (in milliseconds) from when the timer was started.
        _CGUL_EXPORT Float64 GetElapsedMilliseconds() const;

        //! @brief A quick utility function for calculating delta time.
        _CGUL_EXPORT Float64 GetDeltaTime();
    };
}

// Undefines
#include "../External/Undefines.hpp"
