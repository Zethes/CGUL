/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "WindowDelegate.h"
#import "Application.h"

 // leaving this here for future reference:
 // http://stackoverflow.com/questions/4312338/how-to-use-the-object-property-of-nsnotificationcenter   

 @implementation WindowDelegate : NSObject

    - (id)init: (Jatta::WindowStyle)style
    {
        // Initialize the base application and make sure it's not nil
        if ((self = [super init]))
        {
            windowOpen = 1;

            // Define the size of the window
            NSRect frame = NSMakeRect(200, 200, style.width, style.height);

            // Define the style masks to be a titled window with close, max and min
            NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;

            // Adjust the window's sized based on the style mask
            //NSRect rect = [NSWindow contentRectForFrameRect: frame styleMask: styleMask];
            //NSRect rect = [NSWindow frameRectForContentRect: frame styleMask: styleMask];
            NSRect rect = frame;

            // Create the window based on the above specifications
            window = [[NSWindow alloc] initWithContentRect: rect styleMask: styleMask backing: NSBackingStoreBuffered defer: false];

            // Set the background color to black
            //[window setBackgroundColor: [NSColor colorWithCalibratedRed: style.backgroundColor.r / 255.0 green: style.backgroundColor.g / 255.0 blue: style.backgroundColor.b / 255.0 alpha: 1.0]];

            // Set the title of the window
            //NSString* str = [NSString stringWithCString:style.title.GetData().c_str() encoding:[NSString defaultCStringEncoding]];
            //[window setTitle:str];
            //[str release];

            // Make this object the delegate for the window
            [window setDelegate: self];

            // Create an OpenGL view for the window
            //view = [[OpenGLView alloc] init];

            // Get the default content of the window
            // defaultContent = [window contentView];

            // Set the content of the window to the OpenGL view we created
            //[window setContentView: view];

            // (TEMPORARILY) Make the window above all other windows
            //[window setLevel: NSFloatingWindowLevel];

            view = nil;

            [window makeKeyAndOrderFront: self];
        }

        return self;
    }

    - (void)windowWillClose: (NSNotification*)aNotification
    {
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
        [view update];
    }

    - (void)dealloc
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        // Release the window and dealloc the super class
        //[window release
        if (windowOpen == 1)
        {
            [self close];
        }
        [super dealloc];
        [pool drain];
    }

    - (NSWindow*)Window
    {
        return window;
    }

    - (int)IsOpen
    {
        return windowOpen;
    }

    - (void)SetContent: (OpenGLView*)content
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        [window setContentView: content];
        view = content;
        [pool drain];
    }

    - (void) close
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        [window close];
        //[window release]; // TODO: don't we need to release the window? the segfault says otherwise
        [pool drain];
    }

    /*- (void) UpdateInput
    {
    }*/

    - (void) setTitle:(const Jatta::String&)title
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        NSString* str = [NSString stringWithCString:title.GetData().c_str() encoding:NSUTF8StringEncoding];
        [window setTitle:str];
        [pool drain];
    }

    - (Jatta::String) getTitle
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        Jatta::String ret([[window title] UTF8String]);
        [pool drain];
        return ret;
    }

    - (void) setBackgroundColor: (const Jatta::Color&)color
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        [window setBackgroundColor: [NSColor colorWithCalibratedRed: color.r / 255.0 green: color.g / 255.0 blue: color.b / 255.0 alpha: 1.0]];
        [pool drain];
    }

    - (Jatta::Color) getBackgroundColor
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        NSColor* color = [window backgroundColor];
        Jatta::Color ret([color redComponent] * 255, [color greenComponent] * 255, [color blueComponent] * 255, 255);
        [pool drain];
        return ret;
    }

    - (void) setWidth: (Jatta::UInt32)width
    {
        // TODO: mac setWidth
    }

    - (Jatta::UInt32) getWidth
    {
        //NSRect rect = [NSWindow contentRectForFrameRect: [[window contentView] frame] styleMask: [window styleMask]];
        NSRect rect = [[window contentView] frame];
        return rect.size.width;
    }

    - (void) setHeight: (Jatta::UInt32)width
    {
        // TODO: mac setHeight
    }

    - (Jatta::UInt32) getHeight
    {
        //NSRect rect = [NSWindow contentRectForFrameRect: [[window contentView] frame] styleMask: [window styleMask]];
        NSRect rect = [[window contentView] frame];
        return rect.size.height;
    }

    - (void) setSize: (const Jatta::Float2&)size // TODO: use something other than Float2
    {
    }

    - (Jatta::Float2) getSize
    {
        //NSRect rect = [NSWindow contentRectForFrameRect: [[window contentView] frame] styleMask: [window styleMask]];
        NSRect rect = [[window contentView] frame];
        return Jatta::Float2(rect.size.width, rect.size.height);
    }

    - (void) setResizable: (Jatta::Boolean)resizable
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        NSUInteger styleMask = [window styleMask];
        if (resizable)
        {
            styleMask |= NSResizableWindowMask;
        }
        else
        {
            styleMask &= ~NSResizableWindowMask;
        }
        [window setStyleMask: styleMask];
        [pool drain];
    }

    - (Jatta::Boolean) getResizable
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        NSUInteger styleMask = [window styleMask];
        [pool drain];
        return (styleMask & NSResizableWindowMask) > 0;
    }
/*
    - (Jatta::Float4) GetFrameSize
    {
    }

    - (Jatta::Boolean) IsOpen2
    {
    }*/

    - (Jatta::Boolean) isFocused
    {
        return [window isKeyWindow];
    }
@end

#endif