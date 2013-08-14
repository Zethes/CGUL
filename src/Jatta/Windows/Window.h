/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "WindowStyle.h"
#include "../Math/Vector2.h"
#include "../Math/Vector4.h"
#if defined(JATTA_BUILD) && defined(MACOS)
#   include "MacOS/WindowDelegate.h"
#endif
#include "../External/Defines.h"

namespace Jatta
{
#   ifdef Jatta_USE_OPENGL
    namespace OpenGL
    {
        class Context;
    }
#   endif

    /** @brief A class capable of creating windows and manipulating them.
     *  @details Internally this class can work very differently depending on the operating system.
     *  Direct calls are made to WinAPI on Microsoft Windows, Cocoa on Mac OS X, and X11 on linux
     *  and other unix platforms.  Each window api is different, and windows behave differently
     *  depending on the desktop environment.  Note also that certain X11 environments may
     *  wrongfully ignore essential messages resulting in some features not working -- this is not
     *  an issue with Jatta, but instead with the environment itself.
     */
    class Window
    {
#       ifdef Jatta_USE_OPENGL
        friend class OpenGL::Context;
#       endif

#       ifdef WINDOWS
        _JATTA_HWND handle;

        char className[20];

        _JATTA_HGDIOBJ backgroundBrush;

        static long __stdcall WindowProcedure(_JATTA_HWND handle, unsigned int message, unsigned int wParam, long int lParam);
#       endif

#       ifdef LINUX
        static std::map<_JATTA_WINDOW, Window*> windowMap;
        static _JATTA_DISPLAY display;
        _JATTA_WINDOW handle;
        Color backgroundColor;

        static Boolean initialized;
#       endif

#       if defined(JATTA_BUILD) && defined(MACOS)
        WindowDelegate* handle;
#       elif defined(MACOS)
        void* handle;
#       endif

#       ifdef Jatta_USE_OPENGL
        OpenGL::Context* context;
#       endif

        _JATTA_EXPORT static UInt32 TranslateKey(UInt64 key);

        _JATTA_EXPORT Window(const Window& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        _JATTA_EXPORT Window(Window&& move);
#       endif
    public:
        _JATTA_EXPORT static void Update();

        _JATTA_EXPORT Window();
        _JATTA_EXPORT ~Window();

#       ifdef WINDOWS
        _JATTA_EXPORT _JATTA_HWND _GetHandle() const;
#       endif

#       ifdef LINUX
        _JATTA_EXPORT _JATTA_DISPLAY _GetDisplay() const;
        _JATTA_EXPORT _JATTA_WINDOW _GetHandle() const;
#       endif

#       if defined(JATTA_BUILD) && defined(MACOS)
        WindowDelegate* _GetHandle() const;
#       endif

        _JATTA_EXPORT void Create(const WindowStyle& style);
        _JATTA_EXPORT void Close();

        _JATTA_EXPORT void HandleMessages();

        _JATTA_EXPORT void SetStyle(const WindowStyle& style);
        _JATTA_EXPORT WindowStyle GetStyle() const;

        _JATTA_EXPORT void SetTitle(const String& title);
        _JATTA_EXPORT String GetTitle() const;

        _JATTA_EXPORT void SetBackgroundColor(const Color& color);
        _JATTA_EXPORT Color GetBackgroundColor() const;

        _JATTA_EXPORT void SetWidth(UInt32 width);
        _JATTA_EXPORT UInt32 GetWidth() const;
        _JATTA_EXPORT void SetHeight(UInt32 height);
        _JATTA_EXPORT UInt32 GetHeight() const;
        _JATTA_EXPORT void SetSize(const Vector2& size) const; // TODO: use something other than Vector2
        _JATTA_EXPORT Vector2 GetSize() const;

        _JATTA_EXPORT void SetResizable(Boolean resizable);
        _JATTA_EXPORT Boolean GetResizable() const;

        _JATTA_EXPORT Vector4 GetFrameSize() const;

        _JATTA_EXPORT Boolean IsOpen() const;
        _JATTA_EXPORT Boolean IsFocused() const;

        _JATTA_EXPORT virtual void OnKeyPress(UInt32 key);
        _JATTA_EXPORT virtual void OnKeyRelease(UInt32 key);

        _JATTA_EXPORT virtual void OnMousePress(Byte key);
        _JATTA_EXPORT virtual void OnMouseRelease(Byte key);
    };
}

#include "../External/Undefines.h"
