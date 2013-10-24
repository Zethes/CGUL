/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "WindowStyle.h"
#include "../Math/Vector2.h"
#include "../Math/Vector4.h"
#if defined(JATTA_BUILD) && defined(JATTA_MACOS)
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

#       ifdef JATTA_WINDOWS
        _JATTA_HWND handle;

        char className[20];

        _JATTA_HGDIOBJ backgroundBrush;

        static long __stdcall WindowProcedure(_JATTA_HWND handle, unsigned int message, unsigned int wParam, long int lParam);
#       endif

#       ifdef JATTA_LINUX
        static std::map<_JATTA_WINDOW, Window*> windowMap;
        static _JATTA_DISPLAY display;
        _JATTA_WINDOW handle;
        Color backgroundColor;

        static Boolean initialized;
#       endif

#       if defined(JATTA_BUILD) && defined(JATTA_MACOS)
        WindowDelegate* handle;
#       elif defined(JATTA_MACOS)
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
        // @brief Updates all windows in the current application.
        _JATTA_EXPORT static void Update();

        // @brief Default constructor.
        _JATTA_EXPORT Window();
        // @brief Deconstructor.
        _JATTA_EXPORT ~Window();

#       ifdef JATTA_WINDOWS
        _JATTA_EXPORT _JATTA_HWND _GetHandle() const;
#       endif

#       ifdef JATTA_LINUX
        _JATTA_EXPORT _JATTA_DISPLAY _GetDisplay() const;
        _JATTA_EXPORT _JATTA_WINDOW _GetHandle() const;
#       endif

#       if defined(JATTA_BUILD) && defined(JATTA_MACOS)
        WindowDelegate* _GetHandle() const;
#       endif

        // @brief Creates a window based on the given style.
        _JATTA_EXPORT void Create(const WindowStyle& style);
        // @brief Destroys the window.
        _JATTA_EXPORT void Close();

        // @brief Handles system messages and updates input.
        _JATTA_EXPORT void HandleMessages();

        // @brief Updates a window's style.
        _JATTA_EXPORT void SetStyle(const WindowStyle& style);
        // @brief Gets some information about the window.
        _JATTA_EXPORT WindowStyle GetStyle() const;

        // @brief Sets the title of the window.
        _JATTA_EXPORT void SetTitle(const String& title);
        // @brief Gets the title of the window.
        _JATTA_EXPORT String GetTitle() const;

        // @brief Sets the background color of the window.
        _JATTA_EXPORT void SetBackgroundColor(const Color& color);
        // @brief Gets the background color of the window.
        _JATTA_EXPORT Color GetBackgroundColor() const;

        // @brief Sets the width of the window, excluding the border.
        _JATTA_EXPORT void SetWidth(UInt32 width);
        // @brief Gets the width of the window, excluding the border.
        _JATTA_EXPORT UInt32 GetWidth() const;
        // @brief Sets the height of the window, excluding the border.
        _JATTA_EXPORT void SetHeight(UInt32 height);
        // @brief Gets the height of the window, excluding the border.
        _JATTA_EXPORT UInt32 GetHeight() const;
        // @brief Sets the size of the window, excluding the border.
        _JATTA_EXPORT void SetSize(const Vector2& size) const; // TODO: use something other than Vector2
        // @brief Gets the size of the window, excluding the border.
        _JATTA_EXPORT Vector2 GetSize() const;

        // @brief Sets whether the window is resizable or not.
        _JATTA_EXPORT void SetResizable(Boolean resizable);
        // @brief Gets whether the window is resizable or not.
        _JATTA_EXPORT Boolean GetResizable() const;

        // @brief Gets the window's border extents (the frame around the window).
        _JATTA_EXPORT Vector4 GetFrameSize() const;

        // @brief Checks if the window is still open.
        _JATTA_EXPORT Boolean IsOpen() const;
        // @brief Checks if the window currently has focus.
        _JATTA_EXPORT Boolean IsFocused() const;

        _JATTA_EXPORT virtual void OnKeyPress(UInt32 key);
        _JATTA_EXPORT virtual void OnKeyRelease(UInt32 key);

        _JATTA_EXPORT virtual void OnMousePress(Byte button);
        _JATTA_EXPORT virtual void OnMouseRelease(Byte button);

        _JATTA_EXPORT virtual void OnMouseMove(UInt32 mouseX, UInt32 mouseY);
    };
}

#include "../External/Undefines.h"
