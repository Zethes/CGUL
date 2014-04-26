// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Timezones.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    struct Timezone 
    {
    public:
        String name;
        UInt32 daylight;
        Float32 zoneOffset;

        Timezone();     
        Timezone(const String& n, const UInt32 dl, Float32 zo);

        Timezone& operator=(const Timezone& tz);
    };

    namespace Timezones
    {
        const Timezone GMT("GMT", 0, 0.0f);      /* Greenwich Mean */
        const Timezone BST("BST", 1,   0.0f );      /* British Summer */
        const Timezone WAT("WAT", 0,       1.0f );      /* West Africa */
        const Timezone AT ("AT",  0,       2.0f );      /* Azores */
        const Timezone BZST("BST", 0,       3.0f );      /* Brazil Standard */
        const Timezone NFT("NFT", 0,       3.5f );      /* Newfoundland */
        const Timezone NDT("NDT", 1,   3.5f );      /* Newfoundland Daylight */
        const Timezone AST("AST", 0,       4.0f );      /* Atlantic Standard */
        const Timezone ADT("ADT", 1,   4.0f );      /* Atlantic Daylight */
        const Timezone EST("EST", 0,       5.0f );      /* Eastern Standard */
        const Timezone EDT("EDT", 1,   5.0f );      /* Eastern Daylight */
        const Timezone CST("CST", 0,       6.0f );      /* Central Standard */
        const Timezone CDT("CDT", 1,   6.0f );      /* Central Daylight */
        const Timezone MST("MST", 0,       7.0f );      /* Mountain Standard */
        const Timezone MDT("MDT", 1,   7.0f );      /* Mountain Daylight */
        const Timezone PST("PST", 0,       8.0f );      /* Pacific Standard */
        const Timezone PDT("PDT", 1,   8.0f );      /* Pacific Daylight */
        const Timezone YST("YST", 0,       9.0f );      /* Yukon Standard */
        const Timezone YDT("YDT", 1,   9.0f );      /* Yukon Daylight */
        const Timezone HST("HST", 0,      10.0f );      /* Hawaii Standard */
        const Timezone HDT("HDT", 1,  10.0f );      /* Hawaii Daylight */
        const Timezone NT ("NT",  0,      11.0f );      /* Nome */
        const Timezone IDLW("IDLW",0,      12.0f );      /* International Date Line West */
        const Timezone MET("MET", 0,      -1.0f );      /* Middle European */
        const Timezone MEDT("MDT", 1,  -1.0f );      /* Middle European Summer */
        const Timezone EET("EET", 0,      -2.0f );      /* Eastern Europe, USSR Zone 1 */
        const Timezone BT ("BT",  0,      -3.0f );      /* Baghdad, USSR Zone 2 */
        const Timezone IT ("IT",  0,      -3.5f );      /* Iran */
        const Timezone ZP4("ZP4", 0,      -4.0f );      /* USSR Zone 3 */
        const Timezone ZP5("ZP5", 0,      -5.0f );      /* USSR Zone 4 */
        const Timezone IST("IST", 0,      -5.5f );      /* Indian Standard */
        const Timezone ZP6("ZP6", 0,      -6.0f );      /* USSR Zone 5 */
        const Timezone NST("NST", 0,      -6.5f );      /* North Sumatra */
        const Timezone SST("SST", 0,      -7.0f );      /* South Sumatra, USSR Zone 6 */
        const Timezone WAST("WAST",0,      -7.0f );      /* West Australian Standard */
        const Timezone WADT("WADT",1,  -7.0f );      /* West Australian Daylight */
        const Timezone JT ("JT",  0,      -7.5f );      /* Java 3pm in Cronusland! */
        const Timezone CCT("CCT", 0,      -8.0f );      /* China Coast, USSR Zone 7 */
        const Timezone JST("JST", 0,      -9.0f );      /* Japan Standard, USSR Zone 8 */
        const Timezone CAST("CAST",0,      -9.5f );      /* Central Australian Standard */
        const Timezone CADT("CADT",1,  -9.5f );      /* Central Australian Daylight */
        const Timezone EAST("EAST",0,      -10.0f );     /* Eastern Australian Standard */
        const Timezone EADT("EADT",1,  -10.0f );     /* Eastern Australian Daylight */
        const Timezone NZT("NZT", 0,      -12.0f );     /* New Zealand */
        const Timezone NZDT("NZDT",1,  -12.0f );     /* New Zealand Daylight */
    }
}

// Undefines
#include "../External/Undefines.hpp"