/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifdef JATTA_INCLUDES

#pragma once
#include <Jatta/Config.h>
#include "../../External/Defines.h"

// Define the cocoa application delegate
@interface MacWindow : NSWindow
{
}

- (id)init;

- (void) keyUp: (NSEvent *)event;
- (void) keyDown: (NSEvent *)event;

@end

#include "../../External/Undefines.h"

#endif
