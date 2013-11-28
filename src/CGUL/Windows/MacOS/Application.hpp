// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Application.hpp
 */

#ifdef CGUL_INCLUDES

#pragma once
#include <CGUL/Config.hpp>
#include "ApplicationDelegate.hpp"
#include "../../External/Defines.hpp"

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

#include "../../External/Undefines.hpp"

#endif
