/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "ApplicationDelegate.h"

@implementation ApplicationDelegate

- (id)init: (Application*)application;
{
    self->application = application;
    if ((self = [super init]))
    {
    }
    return self;
}

- (void)applicationWillFinishLaunching: (NSNotification*)notification
{
}

- (void)applicationDidFinishLaunching: (NSNotification*)notification
{
    NSApplication *app = [notification object];

    [app createMenu];

    //[window makeKeyAndOrderFront:self];
}

@end

#endif
