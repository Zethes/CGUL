/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    struct InputState
    {
        friend class Input;
        friend class Window;

    private:
        bool down;
        bool hasPressed;
        bool justPressed;
        bool justReleased;

        _JATTA_EXPORT void Analyze();
    public:
        _JATTA_EXPORT InputState();
        _JATTA_EXPORT bool IsDown();
        _JATTA_EXPORT bool IsReleased();
        _JATTA_EXPORT bool IsPressed();
    };
}

#include "../External/Undefines.h"