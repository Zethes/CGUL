/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifdef __OBJC__
#ifdef JATTA_INCLUDES

#pragma once
#include "../../Graphics/MacOS/OpenGLView.h"
#include "../../External/Defines.h"

// Define the cocoa application delegate
@interface WindowDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate>
{
    // The main application window
    NSWindow* window;

    // The customized OpenGL view
    OpenGLView* view;

    // The window's default content
    id content;

    int windowOpen;
}

- (NSWindow*) Window;
- (int)IsOpen;
- (void)SetContent: (OpenGLView*)content;

@end

#include "../../External/Undefines.h"

#endif
#endif
