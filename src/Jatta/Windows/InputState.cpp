/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "InputState.h"

_JATTA_EXPORT void Jatta::InputState::Analyze()
{
    if (justReleased)
        justReleased = false;

    if (down && hasPressed == false && justReleased == false)
    {
        down = false;
        justPressed = true;
    }
    else if (justPressed && hasPressed == false && justReleased == false)
    {
        justPressed = false;
        hasPressed = true;
        down = true;
    }
    else if (down == false && hasPressed == true)
    {
        hasPressed = false;
        justReleased = true;
    }
}

_JATTA_EXPORT Jatta::InputState::InputState()
{
    down = justReleased = justPressed = hasPressed = false;
}

_JATTA_EXPORT bool Jatta::InputState::IsDown()
{
    return down;
}

_JATTA_EXPORT bool Jatta::InputState::IsReleased()
{
    return justReleased;
}

_JATTA_EXPORT bool Jatta::InputState::IsPressed()
{
    return justPressed;
}
