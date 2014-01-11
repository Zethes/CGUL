// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file WindowStyle.cpp
 */

#include "WindowStyle.hpp"

/** @brief Default constructor.  Loads the window style with presets.
 *  @details Sets up the window style with the following presets:
 *  @code
 *  title = "CGUL Window";
 *  backgroundColor = Color(255, 255, 255);
 *  size = SCoord32(640, 480);
 *  resizable = true;
 *  centerWindow = true;
 *  position = SCoord32(0, 0);
 *  alwaysOnTop = false
 *  @endcode
 */
_CGUL_EXPORT CGUL::WindowStyle::WindowStyle() :
    title("CGUL Window"),
    backgroundColor(Color(255, 255, 255)),
    size(640, 480),
    resizable(true),
    centerWindow(true),
    position(0, 0),
    alwaysOnTop(false)
{
}

/** @brief Copy constructor.
 *  @param style The style to copy.
 */
_CGUL_EXPORT CGUL::WindowStyle::WindowStyle(const WindowStyle& style) :
    title(style.title),
    backgroundColor(style.backgroundColor),
    size(style.size),
    resizable(style.resizable),
    centerWindow(style.centerWindow),
    position(style.position),
    alwaysOnTop(style.alwaysOnTop)
{
}

/** @brief Parameterized constructor.
 *  @param title The title of the window.
 *  @param backgroundColor The background color of the window.
 *  @param size The size of the window.
 *  @param resizable Whether the window is resizable or not.
 *  @param minimizable Whether the minimize button is enabled or not.
 *  @param maximizable Whether the maximize button is enabled or not.
 *  @param closeable Whether the close button is enabled or not.
 *  @param centerWindow Whether the window should be in the center of the screen or not.
 *  @param position The position of the window on screen.  If centerWindow is set to true this
 *  @param alwaysOnTop Whether the windows is above all others even when not focused.
 */
_CGUL_EXPORT CGUL::WindowStyle::WindowStyle(const std::string& title,
                                            Color backgroundColor,
                                            UCoord32 size,
                                            Boolean resizable,
                                            Boolean centerWindow,
                                            SCoord32 position,
                                            Boolean alwaysOnTop) :
    title(title),
    backgroundColor(backgroundColor),
    size(size),
    resizable(resizable),
    centerWindow(centerWindow),
    position(position),
    alwaysOnTop(alwaysOnTop)
{
}
