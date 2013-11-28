// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ApplicationDelegate.hpp
 */

#ifdef CGUL_INCLUDES

#pragma once
#include <CGUL/Config.hpp>
#include "../../External/Defines.hpp"

@class Application;

@interface ApplicationDelegate : NSObject<NSApplicationDelegate>
{
    Application* application;
}

- (id)init: (Application*)application;
- (void)applicationWillFinishLaunching: (NSNotification*)notification;
- (void)applicationDidFinishLaunching: (NSNotification*)notification;

@end

#include "../../External/Undefines.hpp"

#endif
