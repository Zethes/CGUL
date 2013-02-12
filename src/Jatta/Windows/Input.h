/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Float2.h"
#include "InputState.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Window;

    class Input
    {
        friend class Window;

        Window* window;
        InputState keyData[256];
        Float2 mousePos;
        InputState mouseData[3];

        _JATTA_EXPORT Input(Window* window);

        _JATTA_EXPORT InputState* GetKeyData();
        _JATTA_EXPORT InputState* GetMouseData();
        _JATTA_EXPORT void AnalyzeKeyData();
        _JATTA_EXPORT void AnalyzeMouseData();
        _JATTA_EXPORT unsigned char GetKeyFromLayout(unsigned char key);
    public:
        _JATTA_EXPORT InputState GetKeyState(unsigned char key);

        _JATTA_EXPORT InputState GetButtonState(unsigned char button);

        _JATTA_EXPORT Float2 GetMousePosition();
        _JATTA_EXPORT void SetMousePosition(Float2 pos);
    };
}

#include "../External/Undefines.h"
