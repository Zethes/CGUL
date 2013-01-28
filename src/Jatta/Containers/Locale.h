/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../Utility/String.h"
#include "../External/Defines.h"

#ifdef GetNumberFormat
#undef GetNumberFormat
#endif

namespace Jatta
{
    struct NumberFormat
    {
    private:
        String decimal;
        String percentSign;
        String currency;
        bool currencyAfterNumber;
        bool allowCents;
    public:
        _JATTA_EXPORT NumberFormat();
        _JATTA_EXPORT NumberFormat(String dec, String curr);
        _JATTA_EXPORT NumberFormat(String dec, String curr, bool curAfter);
        _JATTA_EXPORT NumberFormat(String dec, String curr, bool curAfter, bool allowCents);
        _JATTA_EXPORT void SetDecimal(String dec);
        _JATTA_EXPORT void SetCurrency(String curr);
        _JATTA_EXPORT void ShowCurrencyAfterNumber(bool yes);
        _JATTA_EXPORT void SetPercentSign(String percent);

        _JATTA_EXPORT String Format(long number);
        _JATTA_EXPORT String Format(double number);
        _JATTA_EXPORT String FormatCurrency(long number);
        _JATTA_EXPORT String FormatCurrency(double number);
        _JATTA_EXPORT String FormatPercent(long number);
        _JATTA_EXPORT String FormatPercent(double number);
    };

    struct DateTimeFormat
    {
    private:
        int timeFormat[3];
        int dateFormat[3];
        String timeSeperator;
        String dateSeperator;
        bool twentyFourHourClock;
    public:
        enum { BLANK, MONTH, DAY, YEAR, HOUR, MINUTE, SECOND };

        _JATTA_EXPORT DateTimeFormat();
        _JATTA_EXPORT DateTimeFormat(int date1, int date2, int date3, int time1, int time2, int time3, bool twentyFourHour);
        _JATTA_EXPORT DateTimeFormat(int date1, int date2, int date3, int time1, int time2, int time3, bool twentyFourHour, String dateSep, String timeSep);
        _JATTA_EXPORT void SetDateFormat(int date1, int date2, int date3, String sep);
        _JATTA_EXPORT void SetTimeFormat(int time1, int time2, int time3, String sep, bool twentyFourHour);
        _JATTA_EXPORT void TwentyFourHourClock(bool yes);

        _JATTA_EXPORT String FormatDate(int m, int d, int y);
        _JATTA_EXPORT String FormatTime(int h, int m, int s);
    };

    class Locale
    {
    private:
        NumberFormat numberFormat;
        DateTimeFormat dateTimeFormat;
        std::map<String,String> words;
    public:
        _JATTA_EXPORT Locale(NumberFormat nf, DateTimeFormat dtf);

        _JATTA_EXPORT NumberFormat GetNumberFormat();
        _JATTA_EXPORT DateTimeFormat GetDateTimeFormat();

        _JATTA_EXPORT void AddWord(String id, String word);
        _JATTA_EXPORT String GetWord(String id);
        _JATTA_EXPORT String Translation(String word);
    };
}

#include "../External/Undefines.h"
#include "LocaleFormats.h"
