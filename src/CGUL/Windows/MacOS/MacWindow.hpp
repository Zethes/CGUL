// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MacWindow.hpp
 */

#ifdef CGUL_INCLUDES

#pragma once
#include <CGUL/Config.hpp>
#include "../../External/Defines.hpp"

// Define the cocoa application delegate
@interface MacWindow : NSWindow
{
}

- (id)init;

- (void) keyUp: (NSEvent *)event;
- (void) keyDown: (NSEvent *)event;

@end

#include "../../External/Undefines.hpp"

#endif
