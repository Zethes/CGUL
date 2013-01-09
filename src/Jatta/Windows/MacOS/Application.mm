/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "Application.h"

@implementation MyApplication

- (void)run
{
    // I'm not sure what this does
//  [self finishLaunching];

    // Or this
    [[NSNotificationCenter defaultCenter]
        postNotificationName:NSApplicationWillFinishLaunchingNotification
        object:NSApp];

    // Or this
    [[NSNotificationCenter defaultCenter]
        postNotificationName:NSApplicationDidFinishLaunchingNotification
        object:NSApp];
    
    // OK, I got this one down
    shouldKeepRunning = YES;
}

- (bool)update
{
    // IDK??
    NSEvent *event =
        [self
            nextEventMatchingMask:NSAnyEventMask
            untilDate:nil
            inMode:NSDefaultRunLoopMode
            dequeue:YES];
    
    // Cocoa is some sort of black magic
    [self sendEvent:event];
    [self updateWindows];

    // Ehem...
    return shouldKeepRunning;
}

- (void)terminate: (id)sender
{
    shouldKeepRunning = NO;
}

@end

#endif