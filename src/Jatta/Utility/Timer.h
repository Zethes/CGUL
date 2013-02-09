/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Timer
    {
    private:
        Float32 pcFreq;
        long startTime;
        long mSeconds;
        bool running;
    public:
        // TODO: make this class work on all three platforms

        _JATTA_EXPORT static void Sleep(UInt32 milliseconds);

        _JATTA_EXPORT Timer();
        _JATTA_EXPORT void Start();
        _JATTA_EXPORT void Stop();
        _JATTA_EXPORT void Reset();

        _JATTA_EXPORT UInt32 GetSeconds();
        _JATTA_EXPORT UInt32 GetMiliseconds();

        _JATTA_EXPORT UInt32 GetElapsedSeconds();
        _JATTA_EXPORT UInt32 GetElapsedMiliseconds();
    };
}

#include "../External/Undefines.h"
