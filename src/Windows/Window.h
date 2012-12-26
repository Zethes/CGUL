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

        std::shared_ptr<Input> input;
    public:
        Window();
        Window(const Window& copy) = delete;
        Window(Window&& move) = delete;
        ~Window();

#       ifdef WINDOWS
        _JATTA_HWND _getHandle();
#       endif

#       ifdef LINUX
        _JATTA_DISPLAY _getDisplay();
        _JATTA_WINDOW _getHandle();
#       endif

        std::shared_ptr<Input> getInput();

        void create(const WindowStyle& style);
        void close();

        void update();

        bool isOpen() const;

        unsigned int getWidth() const;
        unsigned int getHeight() const;
        Float2 getSize() const;
    };
}

#include "../External/Undefines.h"
