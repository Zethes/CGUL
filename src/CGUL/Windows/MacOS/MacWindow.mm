// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MacWindow.mm
 */

#ifndef DOXYGEN

#import "MacWindow.hpp"
#include <fstream>

@implementation MacWindow : NSWindow

- (id)init
{
    // Initialize the base application and make sure it's not nil
    if ((self = [super init]))
    {
        //
    }

    return self;
}

- (void)keyUp: (NSEvent *)event
{
}

- (void)keyDown: (NSEvent *)event
{
}

@end

#endif
