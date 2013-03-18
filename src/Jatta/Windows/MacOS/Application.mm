/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef DOXYGEN

#import "Application.h"

@implementation Application

- (id)init
{
    if ((self = [super init]))
    {
        delegate = [[ApplicationDelegate alloc] init: self];
        [self setDelegate:delegate];
    }
    return self;
}

- (void)createMenu
{
    NSMenu *appleMenu = [[NSMenu alloc] initWithTitle: @"Apple Menu"];
    [appleMenu addItemWithTitle:@"Quit" action:@selector(terminate:) keyEquivalent:@"q"];
    NSMenuItem * menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:nil keyEquivalent:@""];
    NSMenu *mainMenu = [[NSMenu alloc] initWithTitle: @"" ];
    [menuItem setSubmenu:appleMenu];
    [mainMenu addItem:menuItem];
    [self setMainMenu:mainMenu];
    [self setAppleMenu:appleMenu];
    [menuItem release];
    [mainMenu release];
    [appleMenu release];
}

- (void)run
{
    [self finishLaunching];
 
    shouldKeepRunning = YES;
}

- (bool)update
{
    // IDK??
    NSEvent *event =
        [self
            nextEventMatchingMask:NSAnyEventMask
            untilDate:nil
            inMode:NSDefaultRunLoopMode
            dequeue:YES];
    
    // Cocoa is some sort of black magic
    [self sendEvent:event];
    [self updateWindows];

    // Ehem...
    return shouldKeepRunning;
}

- (void)terminate: (id)sender
{
    shouldKeepRunning = NO;
}

- (bool)keepRunning
{
    return shouldKeepRunning == YES;
}

@end

#endif
