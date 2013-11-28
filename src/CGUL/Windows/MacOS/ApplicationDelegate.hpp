/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifdef JATTA_INCLUDES

#pragma once
#include <Jatta/Config.h>
#include "../../External/Defines.h"

@class Application;

@interface ApplicationDelegate : NSObject<NSApplicationDelegate>
{
    Application* application;
}

- (id)init: (Application*)application;
- (void)applicationWillFinishLaunching: (NSNotification*)notification;
- (void)applicationDidFinishLaunching: (NSNotification*)notification;

@end

#include "../../External/Undefines.h"

#endif