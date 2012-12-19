#pragma once

#include "../JattaDefines.h"

#include "WindowStyle.h"
#include "Input.h"
#include <memory>

namespace Jatta
{
    class Window
    {
        _JATTA_HWND(handle);
        _JATTA_DWORD(style);

        char className[20];

        std::shared_ptr<Input> input;

        static long __stdcall windowProcedure(_JATTA_HWND(handle), unsigned int message, unsigned int wParam, long int lParam);
    public:
        Window();
        Window(const Window& copy) = delete;
        Window(Window&& move) = delete;
        ~Window();

        _JATTA_HWND(getHandle());

        std::shared_ptr<Input> getInput();

        void create(const WindowStyle& style);
        void close();

        void update();

        bool isOpen();

        unsigned int getWidth();
        unsigned int getHeight();
    };
}

#include "../JattaUndefines.h"