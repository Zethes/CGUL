/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifdef __OBJC__
#ifdef JATTA_INCLUDES

#pragma once
#include <Jatta/Config.h>
#include "../../Windows/WindowStyle.h"
#include "../../Utility/String.h"
#include "../../Math/Float2.h"
#include "../../OpenGL/MacOS/OpenGLView.h"
#include "../../External/Defines.h"

// Define the cocoa application delegate
@interface WindowDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate>
{
    // The main application window
    NSWindow* window;

    // The customized OpenGL view
    OpenGLView* view;

    // The window's default content
    id defaultContent;

    int windowOpen;
}

- (id)init: (Jatta::WindowStyle)style;

- (NSWindow*)Window;
- (int)IsOpen;
- (void)SetContent: (OpenGLView*)content;

- (void) close;

//- (void) updateInput;

- (void) setTitle:(const Jatta::String&)title;
- (Jatta::String) getTitle;

- (void) setBackgroundColor: (const Jatta::Color&)color;
- (Jatta::Color) getBackgroundColor;

- (void) setWidth: (UInt32)width;
- (Jatta::UInt32) getWidth;
- (void) setHeight: (UInt32)width;
- (Jatta::UInt32) getHeight;
- (void) setSize: (const Jatta::Float2&)size; // TODO: use something other than Float2
- (Jatta::Float2) getSize;

- (void) setResizable: (Jatta::Boolean)resizable;
- (Jatta::Boolean) getResizable;
/*
- (Jatta::Float4) getFrameSize;

- (Jatta::Boolean) isOpen2;
- (Jatta::Boolean) isFocused;*/

@end

#include "../../External/Undefines.h"

#endif
#endif
