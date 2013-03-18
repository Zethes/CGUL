/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifdef JATTA_INCLUDES

#pragma once
#include <Jatta/Config.h>
#include "ApplicationDelegate.h"
#include "../../External/Defines.h"

@interface Application : NSApplication
{
    bool shouldKeepRunning;
    bool active;

    ApplicationDelegate* delegate;
}

- (id)init;
- (void)createMenu;
- (void)run;
- (bool)update;
- (void)terminate: (id)sender;
- (bool)keepRunning;

@end

#include "../../External/Undefines.h"

#endif