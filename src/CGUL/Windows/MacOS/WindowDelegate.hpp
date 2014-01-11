// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file WindowDelegate.hpp
 */

#ifdef CGUL_INCLUDES

#pragma once
#include <CGUL/Config.hpp>
#include "MacWindow.hpp"
#include "../../Windows/WindowStyle.hpp"
#include "../../Utility/String.hpp"
#include "../../Math/Vector2.hpp"
#include "../../OpenGL/MacOS/OpenGLView.hpp"
#include "../../External/Defines.hpp"

namespace CGUL
{
    class Window;
}

// Define the cocoa application delegate
@interface WindowDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate>
{
    // The main application window
    MacWindow* window;

    // The customized OpenGL view
    OpenGLView* view;

    // The window's default content
    id defaultContent;

    int windowOpen;

    CGUL::SCoord32 lastMousePos;
}

- (id) init: (CGUL::WindowStyle) style;

- (void) internalUpdate: (CGUL::Window*) cgulWindow;

- (MacWindow*) Window;
- (int) isOpen;
- (void) setContent: (OpenGLView*) content;

- (void) close;

- (void) setTitle: (const CGUL::String&) title;
- (CGUL::String) getTitle;

- (void) setBackgroundColor: (const CGUL::Color&) color;
- (CGUL::Color) getBackgroundColor;

- (void) setWidth: (UInt32) width;
- (CGUL::UInt32) getWidth;
- (void) setHeight: (UInt32) height;
- (CGUL::UInt32) getHeight;
- (void) setSize: (const CGUL::UCoord32&) size;
- (CGUL::UCoord32) getSize;
- (void) setPosition: (const CGUL::SCoord32&) position;
- (CGUL::SCoord32) getPosition;

- (void) setResizable: (CGUL::Boolean) resizable;
- (CGUL::Boolean) getResizable;

- (void) setAlwaysOnTop: (CGUL::Boolean) alwaysOnTop;
- (CGUL::Boolean) getAlwaysOnTop;

- (CGUL::Vector4) getFrameSize;
- (CGUL::Boolean) isFocused;

@end

#include "../../External/Undefines.hpp"

#endif
