/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "OpenGLView.h"

static OpenGLView* current = nil;

@implementation OpenGLView

    + (NSOpenGLPixelFormat*)defaultPixelFormat
    {
        // Set up the OpenGL view's attributes
        NSOpenGLPixelFormatAttribute attributes[] =
        {
            NSOpenGLPFAWindow,
            NSOpenGLPFADoubleBuffer,
            NSOpenGLPFADepthSize, (NSOpenGLPixelFormatAttribute)24,
            (NSOpenGLPixelFormatAttribute)nil
        };

        // Create our pixel format using the above attributes
        return [[[NSOpenGLPixelFormat alloc] initWithAttributes:attributes] autorelease];
    }

    - (id)init
    {
        if (self = [super init])
        {
            if (current == nil)
            {
                current = self;
            }
        }
        return self;
    }

    - (void)idle: (NSTimer*)pTimer
    {
        static double lastTime = CFAbsoluteTimeGetCurrent();
        double time = CFAbsoluteTimeGetCurrent();
        float dt = float(time - lastTime);
        lastTime = time;
        /*glClearColor(0, 255, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        [[self openGLContext] flushBuffer];*/
        //app->update(dt);
        //glClearColor(255, 0, 0, 0);
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //[[self openGLContext] flushBuffer];

        /*if (!*running)
        {
            [[self window] close];
        }*/
    }

    - (void)prepareOpenGL
    {
        // Set up the idle function call
        pTimer = [NSTimer timerWithTimeInterval:(1.0 / 60.0) target:self selector: @selector(idle:) userInfo:nil repeats:YES];
        [[NSRunLoop currentRunLoop]addTimer: pTimer forMode: NSDefaultRunLoopMode];

        // Initialize the application
        //app->initialize();
    }

    - (void)MakeCurrent
    {
        [[self openGLContext] makeCurrentContext];
        // TODO: make Jatta::Graphics create and contain this interface
    }

    - (void)SwapBuffers
    {
        [[self openGLContext] flushBuffer];
    }

@end

#endif