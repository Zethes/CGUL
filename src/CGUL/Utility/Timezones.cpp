// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Timezones.cpp
 */

// Header
#include "Timezones.hpp"

CGUL::Timezone::Timezone()
{
    Timezone("NULL", 0, 0.0f);
}

CGUL::Timezone::Timezone(const String& n, const UInt32 dl, Float32 zo)
{
    name = n;
    daylight = dl;
    zoneOffset = zo;
}

CGUL::Timezone& CGUL::Timezone::operator=(const Timezone& tz)
{
    name = tz.name;
    daylight = tz.daylight;
    zoneOffset = tz.zoneOffset;
}