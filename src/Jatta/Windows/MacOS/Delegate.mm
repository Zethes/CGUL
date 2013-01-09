/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "Delegate.h"

 @implementation AppDelegate : NSObject

    - (id)init
    {
        // Initialize the base application and make sure it's not nil
        if (self = [super init])
        {
            // Define the size of the window
            NSRect frame = NSMakeRect(200, 200, 800, 600);

            // Define the style masks to be a titled window with close, max and min
            NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask/* | NSResizableWindowMask*/;

            // Adjust the window's sized based on the style mask
            NSRect rect = [NSWindow contentRectForFrameRect: frame styleMask: styleMask];

            // Create the window based on the above specifications
            window =  [[NSWindow alloc] initWithContentRect: rect styleMask: styleMask backing: NSBackingStoreBuffered defer: false];

            // Set the background color to black
            [window setBackgroundColor: [NSColor colorWithCalibratedRed: 0.0 green: 0.0 blue: 0.0 alpha: 1.0]];

            // Set the title of the window
            [window setTitle: @""];

            // Make this object the delegate for the window
            [window setDelegate: self];

            // Create an OpenGL view for the window
            glView = [[OpenGLView alloc] init];

            // Get the default content of the window
            content = [window contentView];

            // Set the content of the window to the OpenGL view we created
            [window setContentView: glView];

            // (TEMPORARILY) Make the window above all other windows
            [window setLevel: NSFloatingWindowLevel];

            // Set the application's window's data to the Cocoa window
            //appWindow->setData(window);
        }
        return self;
    }

    - (void)applicationWillFinishLaunching: (NSNotification*)notification
    {
        // Set the window front and foremost
        [window makeKeyAndOrderFront: self];
    }

    - (void)windowWillClose: (NSNotification*)aNotification
    {
        if (window != nil)
        {
            // Uninitialize the application
            //app->uninitialize();

            // Release the window
            [window release];
            window = nil;

            // Terminate the application when the window closes
            [NSApp terminate: self];
        }
    }

    - (void)windowDidResize: (NSNotification*)aNotification
    {
        // Set the view back to the original view temporarily
        [window setContentView: content];

        // Display the blank black window
        [window display];

        // Switch back to the OpenGL view once resizing is finished
        [window setContentView: glView];
    }

    - (void)dealloc
    {
        // Release the window and dealloc the super class
        [window release];
        [super dealloc];
    }
@end

#endif