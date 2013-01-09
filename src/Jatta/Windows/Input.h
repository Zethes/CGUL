/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class Window;

    class Input
    {
        friend class Window;

        Window* window;
        bool keyData[256];

        _JATTA_EXPORT Input(Window* window);

        _JATTA_EXPORT bool* GetKeyData();
        _JATTA_EXPORT unsigned char GetKeyFromLayout(unsigned char key);
    public:
        _JATTA_EXPORT bool IsKeyDown(unsigned char key);
        _JATTA_EXPORT bool IsKeyPressed(unsigned char key);
        _JATTA_EXPORT bool IsKeyReleased(unsigned char key);
    };
}

#include "../External/Undefines.h"
