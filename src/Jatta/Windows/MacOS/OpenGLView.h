/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifdef __OBJC__
#ifdef JATTA_INCLUDES

#pragma once
#include "../External/Defines.h"

@interface OpenGLView : NSOpenGLView
{
    // Create the timer capable of keeping up with delta time
    NSTimer* pTimer;
}
@end

#include "../External/Undefines.h"

#endif
#endif