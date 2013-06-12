/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "MacWindow.h"
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

    - (void) keyUp: (NSEvent *)event
    {
    }

    - (void) keyDown: (NSEvent *)event
    {
    }

@end

#endif
