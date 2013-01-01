//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "Input.h"
#include "WindowStyle.h"
#include "../Math/Float2.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Window
    {
#       ifdef WINDOWS
        _JATTA_HWND handle;
        _JATTA_DWORD style;

        char className[20];

        static long __stdcall windowProcedure(_JATTA_HWND handle, unsigned int message, unsigned int wParam, long int lParam);
#       endif

#       ifdef LINUX
        _JATTA_DISPLAY display;
        _JATTA_WINDOW handle;

        static bool initialized;
#       endif

        Input input;

        _JATTA_EXPORT Window(const Window& copy);
        _JATTA_EXPORT Window(Window&& move);
    public:
        _JATTA_EXPORT  Window();
        _JATTA_EXPORT ~Window();

#       ifdef WINDOWS
        _JATTA_EXPORT _JATTA_HWND _getHandle();
#       endif

#       ifdef LINUX
        _JATTA_EXPORT _JATTA_DISPLAY _getDisplay();
        _JATTA_EXPORT _JATTA_WINDOW _getHandle();
#       endif

        _JATTA_EXPORT Input* getInput();

        _JATTA_EXPORT void create(const WindowStyle& style);
        _JATTA_EXPORT void close();

        _JATTA_EXPORT void update();

        _JATTA_EXPORT bool isOpen() const;

        _JATTA_EXPORT unsigned int getWidth() const;
        _JATTA_EXPORT unsigned int getHeight() const;
        _JATTA_EXPORT Float2 getSize() const;
    };
}

#include "../External/Undefines.h"
