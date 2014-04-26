// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file DateTime.cpp
 */

// Header
#include "DateTime.hpp"
#include "Timer.hpp"
#include "../Math/Math.hpp"

CGUL::UInt64 CGUL::DateTime::MonthLength(UInt32 m, UInt32 year)
{
    UInt32 dc = 30;
    if (m == Months::FEBURARY)
    {
        dc = 28;
        if (IsLeapYear(year))
            dc++;
    }
    else if (m % 2 == 1) 
        dc++;
    return dc;
}

CGUL::UInt64 CGUL::DateTime::YearLength(UInt32 year)
{
    return (IsLeapYear(year) ? 366 : 365);
}

bool CGUL::DateTime::IsLeapYear(UInt32 year)
{
    return (!(year % 4) && ((year % 100) || !(year % 400)));
}

CGUL::DateTime CGUL::DateTime::Now()
{
    return UnixTime::UnixToDateTime(CGUL::Timer::GetSeconds());
}

CGUL::String CGUL::DateTime::GetWeekdayString(UInt32 weekday, bool abbreviate)
{
    String table[][2] = {
        { "Sunday", "Sun" },
        { "Monday", "Mon" },
        { "Tuesday", "Tue" },
        { "Wednesday", "Wed" },
        { "Thurday", "Thu" },
        { "Friday", "Fri" },
        { "Saturday", "Sat" },
    };

    if (weekday < 0 || weekday > 6)
    {
        return "Err";
    }

    return table[weekday][abbreviate ? 1 : 0];
}
CGUL::String CGUL::DateTime::GetMonthString(UInt32 month, bool abbreviate)
{
    String table[][2] = {
        { "January", "Jan" },
        { "Febuary", "Feb" },
        { "March", "Mar" },
        { "April", "Apr" },
        { "May", "May" },
        { "June", "Jun" },
        { "July", "Jul" },
        { "August", "Aug" },
        { "September", "Sep" },
        { "November", "Nov" },
        { "December", "Dec" },
    };

    month -= 1;
    if (month < 0 || month > 11)
    {
        return "Err";
    }

    return table[month][abbreviate ? 1 : 0];
}

CGUL::DateTime::DateTime()
{
    DateTime(1970, 1, 1, 0, 0, 0, Timezones::GMT);
}
CGUL::DateTime::DateTime(UInt32 y, UInt32 mo, UInt32 d, UInt32 h, UInt32 m, UInt32 s)
{
    DateTime(y, mo, d, h, m, s, Timezones::GMT);
}

CGUL::DateTime::DateTime(UInt32 y, UInt32 mo, UInt32 d, UInt32 h, UInt32 m, UInt32 s, Timezone tz)
{
    year = y;
    month = mo;
    day = d;
    hour = h;
    minute = m;
    second = s;

    weekday = (d + 1) % 7;

    ChangeTimezone(tz);
}

CGUL::DateTime::~DateTime()
{
}

void CGUL::DateTime::ChangeTimezone(Timezone tz)
{
    this->tz = tz;
}

CGUL::UInt32 CGUL::DateTime::GetYear()
{
    return year;
}
CGUL::UInt32 CGUL::DateTime::GetMonth()
{
    return month;
}
CGUL::UInt32 CGUL::DateTime::GetDay()
{
    return day;
}
CGUL::UInt32 CGUL::DateTime::GetHour()
{
    return hour;
}
CGUL::UInt32 CGUL::DateTime::GetMinute()
{
    return minute;
}
CGUL::UInt32 CGUL::DateTime::GetSecond()
{
    return second;
}

CGUL::Timezone CGUL::DateTime::GetTimezone()
{
    return tz;
}

CGUL::String CGUL::DateTime::ToString(String format)
{
    UInt32 y = year;
    UInt32 m = month;
    UInt32 d = day;
    UInt32 h = hour - tz.zoneOffset + tz.daylight;

    while (h >= 24)
    {
        h -= 24;
        d++;
        while (d > MonthLength(month, year))
        {
            d -= MonthLength(month, year);
            m++;
            while (m > 12) 
            {
                m -= 12;
                y++;
            }
        }
    }

    UInt32 wday = (d + 1) % 7;
    UInt32 week_year = d / 7;
    UInt32 week_year2 = (d+1) / 7;

    String ret = "";

    for (UInt32 i = 0; i < format.GetLength(); ++i)
    {
        if (format[i] == '%' && i+1 < format.GetLength())
        {
            switch (format[i+1])
            {
                case 'a':
                    ret += GetWeekdayString(wday, true);
                    break;
                case 'A':
                    ret += GetWeekdayString(wday, false);
                    break;
                case 'h':
                case 'b':
                    ret += GetMonthString(m, true);
                    break;
                case 'B':
                    ret += GetMonthString(m, false);
                    break;
                case 'c':
                {
                    DateTime dt = UnixTime::UnixToDateTime(CGUL::Timer::GetSeconds());
                    ret += dt.ToString("%a %b %d %k:%M:%S %Y");
                }
                break;
                case 'C':
                    ret += String::From<UInt32>(y).SubString(0,2);
                    break;
                case 'd':
                    ret += String::From<UInt32>(d);
                    break;
                case 'D':
                {
                    ret += String::From<UInt32>(m);
                    ret += "/";
                    ret += String::From<UInt32>(d);
                    ret += "/";
                    ret += String::From<UInt32>(y).SubString(2);
                }
                break;
                case 'e':
                    ret += String(" ") + String::From<UInt32>(d) + String(" ");
                    break;
                case 'F':
                {
                    ret += String::From<UInt32>(y);
                    ret += "-";
                    ret += String::From<UInt32>(m);
                    ret += "-";
                    ret += String::From<UInt32>(d);
                }
                break;
                case 'g':
                    ret += GetMonthString(wday, false); //?
                    break;
                case 'G':
                    ret += GetMonthString(wday, false); //?
                    break;
                case 'H':
                    if (h < 10)
                        ret += "0";
                    ret += String::From<UInt32>(h);
                    break;
                case 'I':
                    if (h < 10 || h-12 < 10)
                        ret += "0";
                    if (h > 12)
                        ret += String::From<UInt32>(h-12);
                    else
                        ret += String::From<UInt32>(h);
                    break;
                case 'j':
                    if (d < 10)
                        ret += "0";
                    if (d < 100)
                        ret += "0";
                    ret += String::From<UInt32>(d);
                    break;
                case 'k':
                    if (h < 10)
                        ret += "0";
                    ret += String::From<UInt32>(h);
                    break;
                case 'l':
                    if (h > 12)
                        ret += String::From<UInt32>(h-12);
                    else
                        ret += String::From<UInt32>(h);
                    break;
                case 'm':
                    if (m < 10)
                        ret += "0";
                    ret += String::From<UInt32>(m);
                    break;
                case 'M':
                    if (minute < 10)
                        ret += "0";
                    ret += String::From<UInt32>(minute);
                    break;
                case 'n':
                    ret += "\n";
                    break;
                case 'N':
                    ret += "000000000"; //Nanoseconds
                    break;
                case 'p':
                    if (h > 12)
                        ret += "PM";
                    else
                        ret += "AM";
                    break;
                case 'P':
                    if (h > 12)
                        ret += "pm";
                    else
                        ret += "am";
                    break;
                case 'r':
                    {
                        if (h > 12)
                            ret += String::From<UInt32>(h-12);
                        else
                            ret += String::From<UInt32>(h);
                        ret += ":";
                        ret += String::From<UInt32>(minute);
                        if (h > 12)
                            ret += " PM";
                        else
                            ret += " AM";
                    }
                    break;
                case 'R':
                    if (h < 10)
                        ret += "0";
                    ret += String::From<UInt32>(hour);
                    ret += ":";
                    ret += String::From<UInt32>(minute);
                    break;
                case 's':
                    ret += String::From<UInt32>(UnixTime::DateTimeToUnix(DateTime(year,month,day,hour,minute,second)));
                    break;
                case 'S':
                    if (second < 10)
                        ret += "0";
                    ret += String::From<UInt32>(second);
                    break;
                case 't':
                    ret += "\t";
                    break;
                case 'T':
                    if (h < 10)
                        ret += "0";
                    ret += String::From<UInt32>(h);
                    ret += ":";
                    if (minute < 10)
                        ret += "0";
                    ret += String::From<UInt32>(minute);
                    ret += ":";
                    if (second < 10)
                        ret += "0";
                    ret += String::From<UInt32>(second);
                    break;
                case 'u':
                    ret += String::From<UInt32>(wday+1);
                    break;
                case 'U':
                    if (week_year < 10)
                        ret += "0";
                    ret += String::From<UInt32>(week_year);
                    break;
                case 'V':
                    if (week_year+1 < 10)
                        ret += "0";
                    ret += String::From<UInt32>(week_year+1);
                    break;
                case 'w':
                    ret += String::From<UInt32>(wday);
                    break;
                case 'W':
                    if (week_year2 < 10)
                        ret += "0";
                    ret += String::From<UInt32>(week_year2);
                    break;
                case 'x':
                    ret += String::From<UInt32>(m);
                    ret += "/";
                    ret += String::From<UInt32>(d);
                    ret += "/";
                    ret += String::From<UInt32>(y).SubString(2);
                    break;
                case 'X':
                    if (h < 10)
                        ret += "0";
                    ret += String::From<UInt32>(h);
                    ret += ":";
                    if (minute < 10)
                        ret += "0";
                    ret += String::From<UInt32>(minute);
                    ret += ":";
                    if (second < 10)
                        ret += "0";
                    ret += String::From<UInt32>(second);
                    break;
                case 'y':
                    ret += String::From<UInt32>(y).SubString(2);
                    break;
                case 'Y':
                    ret += String::From<UInt32>(y);
                    break;
                case 'z':
                    if (tz.zoneOffset < 0)
                        ret += "-";
                    else
                        ret += "+";
                    if (CGUL::Math::Abs(tz.zoneOffset) < 10)
                        ret += "0";
                    ret += String::From<UInt32>(CGUL::Math::Abs(tz.zoneOffset)*100);
                    break;
                case 'Z':
                    ret += tz.name;
                    break;
                case '%':
                default:
                    ret += "%";
            }
            i++;
        }
        else
            ret += format[i];
    }

    return ret;
}


CGUL::DateTime CGUL::UnixTime::UnixToDateTime(UInt64 unix_time)
{
    UnixTime u(unix_time);
    return u.ToDateTime();
}

CGUL::UInt64 CGUL::UnixTime::DateTimeToUnix(DateTime dt)
{
    UnixTime u(dt);
    return u.GetTime();
}

CGUL::UInt64 CGUL::UnixTime::Now()
{
    return CGUL::Timer::GetSeconds();
}

CGUL::UnixTime::UnixTime()
{
    unix_time = 0;
}
CGUL::UnixTime::UnixTime(UInt64 unix_time)
{
    this->unix_time = unix_time;
}
CGUL::UnixTime::UnixTime(DateTime dt)
{
    FromDateTime(dt);
}
CGUL::UnixTime::~UnixTime()
{
}

CGUL::UInt64 CGUL::UnixTime::GetTime()
{   
    return unix_time;
}

CGUL::DateTime CGUL::UnixTime::ToDateTime()
{
    UInt32 y, mo, d, h, m, s;

    UInt64 dayclock = unix_time % DateTime::SECONDS_PER_DAY;
    UInt64 dayno = unix_time / DateTime::SECONDS_PER_DAY;

    y = EPOCH_YEAR;

    s = dayclock % DateTime::SECONDS_PER_MINUTE;
    m = (dayclock % DateTime::SECONDS_PER_HOUR) / 60;
    h = dayclock / DateTime::SECONDS_PER_HOUR;
    while (dayno >= DateTime::YearLength(y)) 
    {
        dayno -= DateTime::YearLength(y);
        y++;
    }

    mo = 1;
    while (dayno >= DateTime::MonthLength(mo, y)) 
    {
        dayno -= DateTime::MonthLength(mo, y);
        mo++;
    }

    d = dayno+1;

    return DateTime(y, mo, d, h, m, s, Timezones::GMT);
}

void CGUL::UnixTime::FromDateTime(DateTime dt)
{
    unix_time = 0;
    for (UInt32 i = EPOCH_YEAR; i < dt.GetYear(); ++i)
        unix_time += DateTime::YearLength(i);
    for (UInt32 i = Months::JANUARY; i < dt.GetMonth(); ++i)
        unix_time += DateTime::MonthLength(i, dt.GetYear());

    unix_time += DateTime::SECONDS_PER_DAY * (dt.GetDay()-1);
    unix_time += DateTime::SECONDS_PER_HOUR * (dt.GetHour()-1);
    unix_time += DateTime::SECONDS_PER_MINUTE * (dt.GetMinute()-1);
    unix_time += dt.GetSecond();
}