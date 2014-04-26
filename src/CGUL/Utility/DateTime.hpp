// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file DateTime.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"
#include "Timezones.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{   
    namespace Days
    {
        enum
        {
            SUNDAY,
            MONDAY,
            TUESDAY,
            WEDNESDAY,
            THURSDAY,
            FRIDAY,
            SATURDAY
        };
    }

    namespace Months
    {
        enum
        {
            JANUARY = 1,
            FEBURARY,
            MARCH,
            APRIL,
            MAY,
            JUNE,
            JULY,
            AUGUST,
            SEPTEMBER,
            NOVEMBER,
            DECEMBER
        };
    }

    class DateTime
    {
        UInt32 year, month, day, hour, minute, second;
        UInt32 weekday;
        Timezone tz;
    public:
        static const UInt64 SECONDS_PER_MINUTE = 60;
        static const UInt64 SECONDS_PER_HOUR = 3600;
        static const UInt64 SECONDS_PER_DAY = 86400;

        static UInt64 MonthLength(UInt32 m, UInt32 year);
        static UInt64 YearLength(UInt32 year);
        static bool IsLeapYear(UInt32 year);

        static DateTime Now();

        static String GetWeekdayString(UInt32 weekday, bool abbreviate = false);
        static String GetMonthString(UInt32 month, bool abbreviate = false);

        DateTime();
        DateTime(UInt32 y, UInt32 mo, UInt32 d, UInt32 h, UInt32 m, UInt32 s);
        DateTime(UInt32 y, UInt32 mo, UInt32 d, UInt32 h, UInt32 m, UInt32 s, Timezone tz);
        ~DateTime();

        void ChangeTimezone(Timezone tz);

        UInt32 GetYear();
        UInt32 GetMonth();
        UInt32 GetDay();
        UInt32 GetHour();
        UInt32 GetMinute();
        UInt32 GetSecond();
        Timezone GetTimezone();

        String ToString(String format);
    };

    class UnixTime
    {
        UInt64 unix_time;
    public:
        static const UInt32 YEAR0 = 1900;
        static const UInt32 EPOCH_YEAR = 1970;
        static const UInt32 EPOCH_MONTH = 1;
        static const UInt32 EPOCH_DAY = 1;

        static DateTime UnixToDateTime(UInt64 unix_time);
        static UInt64 DateTimeToUnix(DateTime dt);
        static UInt64 Now();

        UnixTime();
        UnixTime(UInt64 unix_time);
        UnixTime(DateTime dt);
        ~UnixTime();

        UInt64 GetTime();

        DateTime ToDateTime();
        void FromDateTime(DateTime dt);
    };
}

// Undefines
#include "../External/Undefines.hpp"
