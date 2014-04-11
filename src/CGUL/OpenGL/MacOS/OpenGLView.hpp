// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGLView.hpp
 */

#ifdef __OBJC__
#ifdef CGUL_INCLUDES

#pragma once
#include <CGUL/Config.hpp>
#include "../../External/Defines.hpp"

@interface OpenGLView : NSOpenGLView
{
    // Create the timer capable of keeping up with delta time
    NSTimer* pTimer;
}

- (void)MakeCurrent;
- (void)SwapBuffers;

@end

#include "../../External/Undefines.hpp"

#endif
#endif
