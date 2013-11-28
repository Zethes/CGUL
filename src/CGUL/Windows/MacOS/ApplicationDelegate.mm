// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ApplicationDelegate.mm
 */

#ifndef DOXYGEN

#import "ApplicationDelegate.hpp"

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
