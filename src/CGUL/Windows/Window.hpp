// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Window.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Containers/Vector.hpp"
#include "../Math/Vector2.hpp"
#include "../Math/Vector4.hpp"
#include "../Utility/Event.hpp"
#include "../Windows/WindowStyle.hpp"
#if defined(CGUL_BUILD) && defined(CGUL_MACOS)
#   include "MacOS/WindowDelegate.hpp"
#endif

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
#   ifdef CGUL_USE_OPENGL
    namespace OpenGL
    {
        class Context;
    }
#   endif

    struct WindowKeyButtonEvent
    {
        Boolean pressed;
        UInt32 key;
    };

    struct WindowMouseButtonEvent
    {
        Boolean pressed;
        Byte button;
    };

    struct WindowMouseMoveEvent
    {
        SCoord32 location;
    };

    /** @brief A class capable of creating windows and manipulating them.
     *  @details Internally this class can work very differently depending on the operating system.
     *  Direct calls are made to WinAPI on Microsoft Windows, Cocoa on Mac OS X, and X11 on linux
     *  and other unix platforms.  Each window api is different, and windows behave differently
     *  depending on the desktop environment.  Note also that certain X11 environments may
     *  wrongfully ignore essential messages resulting in some features not working -- this is not
     *  an issue with CGUL, but instead with the environment itself.
     */
    class Window
    {
#       ifdef CGUL_USE_OPENGL
        friend class OpenGL::Context;
#       endif

        static Vector< Window* > windows;

#       ifdef CGUL_WINDOWS
        _CGUL_HWND handle;

        char className[20];

        _CGUL_HGDIOBJ backgroundBrush;

        static long __stdcall WindowProcedure(_CGUL_HWND handle, unsigned int message, unsigned int wParam, long int lParam);
#       endif

#       ifdef CGUL_LINUX
        static std::map<_CGUL_WINDOW, Window*> windowMap;
        static _CGUL_DISPLAY display;
        _CGUL_WINDOW handle;
        Color backgroundColor;

        static Boolean initialized;
#       endif

#       if defined(CGUL_BUILD) && defined(CGUL_MACOS)
        WindowDelegate* handle;
#       elif defined(CGUL_MACOS)
        void* handle;
#       endif

#       ifdef CGUL_USE_OPENGL
        OpenGL::Context* context;
#       endif

        _CGUL_EXPORT static UInt32 TranslateKey(UInt64 key);

        _CGUL_EXPORT Window(const Window& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        _CGUL_EXPORT Window(Window&& move);
#       endif

        //! @brief Internal update logic for each window when Update() is called.
        _CGUL_EXPORT void InternalUpdate();
    public:
        //! @brief Updates all windows in the current application.
        _CGUL_EXPORT static void Update();

        Event< WindowKeyButtonEvent > onKeyButton;
        Event< WindowMouseButtonEvent > onMouseButton;
        Event< WindowMouseMoveEvent > onMouseMove;

        //! @brief Default constructor.
        _CGUL_EXPORT Window();
        //! @brief Deconstructor.
        _CGUL_EXPORT ~Window();

#       ifdef CGUL_WINDOWS
        _CGUL_EXPORT _CGUL_HWND _GetHandle() const;
#       endif

#       ifdef CGUL_LINUX
        _CGUL_EXPORT _CGUL_DISPLAY _GetDisplay() const;
        _CGUL_EXPORT _CGUL_WINDOW _GetHandle() const;
#       endif

#       if defined(CGUL_BUILD) && defined(CGUL_MACOS)
        WindowDelegate* _GetHandle() const;
#       endif

        //! @brief Creates a window based on the given style.
        _CGUL_EXPORT void Create(const WindowStyle& style);
        //! @brief Destroys the window.
        _CGUL_EXPORT void Close();

        //! @brief Handles system messages and updates input.
        _CGUL_EXPORT void HandleMessages();

        //! @brief Updates a window's style.
        _CGUL_EXPORT void SetStyle(const WindowStyle& style);
        //! @brief Gets some information about the window.
        _CGUL_EXPORT WindowStyle GetStyle() const;

        //! @brief Sets the title of the window.
        _CGUL_EXPORT void SetTitle(const String& title);
        //! @brief Gets the title of the window.
        _CGUL_EXPORT String GetTitle() const;

        //! @brief Sets the background color of the window.
        _CGUL_EXPORT void SetBackgroundColor(const Color& color);
        //! @brief Gets the background color of the window.
        _CGUL_EXPORT Color GetBackgroundColor() const;

        //! @brief Sets the width of the window, excluding the border.
        _CGUL_EXPORT void SetWidth(UInt32 width);
        //! @brief Gets the width of the window, excluding the border.
        _CGUL_EXPORT UInt32 GetWidth() const;
        //! @brief Sets the height of the window, excluding the border.
        _CGUL_EXPORT void SetHeight(UInt32 height);
        //! @brief Gets the height of the window, excluding the border.
        _CGUL_EXPORT UInt32 GetHeight() const;
        //! @brief Sets the size of the window, excluding the border.
        _CGUL_EXPORT void SetSize(const UCoord32& size) const;
        //! @brief Gets the size of the window, excluding the border.
        _CGUL_EXPORT UCoord32 GetSize() const;
        //! @brief Sets the position of the window on the screen.
        _CGUL_EXPORT void SetPosition(const SCoord32& position);
        //! @brief Gets the position of the window on the screen.
        _CGUL_EXPORT SCoord32 GetPosition() const;

        //! @brief Sets whether the window is resizable or not.
        _CGUL_EXPORT void SetResizable(Boolean resizable);
        //! @brief Gets whether the window is resizable or not.
        _CGUL_EXPORT Boolean GetResizable() const;

        //! @brief Gets the window's border extents (the frame around the window).
        _CGUL_EXPORT URect32 GetFrameSize() const;

        //! @brief Checks if the window is still open.
        _CGUL_EXPORT Boolean IsOpen() const;
        //! @brief Checks if the window currently has focus.
        _CGUL_EXPORT Boolean IsFocused() const;

        //! @brief Sets the mouse position relative to the window.
        _CGUL_EXPORT void SetMousePosition(SCoord32 mousePosition);
        //! @brief Sets if the mouse is visible in the window or not.
        _CGUL_EXPORT void SetCursorShow(bool show);
    };
}

// Undefines
#include "../External/Undefines.hpp"
