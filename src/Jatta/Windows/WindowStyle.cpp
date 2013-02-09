/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "WindowStyle.h"

/** @brief Default constructor.  Loads the window style with presets.
 *  @details Sets up the window style with the following presets:
 *  @code
 *  title = "Jatta Window";
 *  backgroundColor = Color(255, 255, 255);
 *  width = 640;
 *  height = 480;
 *  resizable = true;
 *  @endcode
 */
_JATTA_EXPORT Jatta::WindowStyle::WindowStyle()
{
    this->title = "Jatta Window";
    this->backgroundColor = Color(255, 255, 255);
    this->width = 640;
    this->height = 480;
    this->resizable = true;
}

/** @brief Copy constructor.
 *  @param style The style to copy.
 */
_JATTA_EXPORT Jatta::WindowStyle::WindowStyle(const WindowStyle& style)
{
    this->title = style.title;
    this->backgroundColor = style.backgroundColor;
    this->width = style.width;
    this->height = style.height;
    this->resizable = style.resizable;
}

/** @brief Parameterized constructor.
 *  @param title The title of the window.
 *  @param backgroundColor The background color of the window.
 *  @param width The width of the window.
 *  @param height The height of the window.
 *  @param resizable Whether the window is resizable or not.
 */
_JATTA_EXPORT Jatta::WindowStyle::WindowStyle(const std::string& title, Color backgroundColor, UInt32 width, UInt32 height, Boolean resizable)
{
    this->title = title;
    this->backgroundColor = backgroundColor;
    this->width = width;
    this->height = height;
    this->resizable = resizable;
}
