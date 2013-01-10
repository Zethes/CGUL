/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "WindowDelegate.h"
#include "../WindowStyle.h"

 // leaving this here for future reference:
 // http://stackoverflow.com/questions/4312338/how-to-use-the-object-property-of-nsnotificationcenter   

 @implementation WindowDelegate : NSObject

    - (id)init: (Jatta::WindowStyle)style
    {
        // Initialize the base application and make sure it's not nil
        if (self = [super init])
        {
            windowOpen = 1;

            // Define the size of the window
            NSRect frame = NSMakeRect(200, 200, 800, 600);

            // Define the style masks to be a titled window with close, max and min
            NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask/* | NSResizableWindowMask*/;

            // Adjust the window's sized based on the style mask
            NSRect rect = [NSWindow contentRectForFrameRect: frame styleMask: styleMask];

            // Create the window based on the above specifications
            window =  [[NSWindow alloc] initWithContentRect: rect styleMask: styleMask backing: NSBackingStoreBuffered defer: false];

            // Set the background color to black
            [window setBackgroundColor: [NSColor colorWithCalibratedRed: style.backgroundColor.r / 255.0 green: style.backgroundColor.g / 255.0 blue: style.backgroundColor.b / 255.0 alpha: 1.0]];

            // Set the title of the window
            NSString* str = [NSString stringWithCString:style.title.GetData().c_str() encoding:[NSString defaultCStringEncoding]];
            [window setTitle:str];
            [str release];

            // Make this object the delegate for the window
            [window setDelegate: self];

            // Create an OpenGL view for the window
            //view = [[OpenGLView alloc] init];

            // Get the default content of the window
            //id content = [window contentView];

            // Set the content of the window to the OpenGL view we created
            //[window setContentView: view];

            // (TEMPORARILY) Make the window above all other windows
            [window setLevel: NSFloatingWindowLevel];

            [window makeKeyAndOrderFront: self];
        }

        return self;
    }

    - (void)windowWillClose: (NSNotification*)aNotification
    {
        NSLog(@"Sup");
        windowOpen = 0;
        /*if (window != nil)
        {
            // Uninitialize the application
            //app->uninitialize();

            // Release the window
            //[window release];
            //window = nil;

            // Terminate the application when the window closes
            //[NSApp terminate: self];
        }*/
    }

    - (void)windowDidResize: (NSNotification*)aNotification
    {
        // Set the view back to the original view temporarily
        //[window setContentView: content];

        // Display the blank black window
        //[window display];

        // Switch back to the OpenGL view once resizing is finished
        //[window setContentView: glView];
    }

    - (void)dealloc
    {
        // Release the window and dealloc the super class
        [window release];
        [super dealloc];
    }

    - (NSWindow*) Window
    {
        return window;
    }

    - (int)IsOpen
    {
        return windowOpen;
    }

    - (void)SetContent: (OpenGLView*)content
    {
        [window setContentView: content];
    }
@end

#endif