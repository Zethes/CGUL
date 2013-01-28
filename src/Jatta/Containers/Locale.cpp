#include "Locale.h"

_JATTA_EXPORT Jatta::NumberFormat::NumberFormat()
{
    NumberFormat(".","$");
}
_JATTA_EXPORT Jatta::NumberFormat::NumberFormat(String dec, String curr)
{
    NumberFormat(dec, curr, false);
}
_JATTA_EXPORT Jatta::NumberFormat::NumberFormat(String dec, String curr, bool curAfter)
{
    NumberFormat(dec, curr, curAfter, true);
}
_JATTA_EXPORT Jatta::NumberFormat::NumberFormat(String dec, String curr, bool curAfter, bool allowCent)
{
    SetDecimal(dec);
    SetCurrency(curr);
    ShowCurrencyAfterNumber(false);
    SetPercentSign("%");
    currencyAfterNumber = curAfter;
    allowCents = allowCent;
}
_JATTA_EXPORT void Jatta::NumberFormat::SetDecimal(String dec)
{
    decimal = dec;
}
_JATTA_EXPORT void Jatta::NumberFormat::SetCurrency(String curr)
{
    currency = curr;
}
_JATTA_EXPORT void Jatta::NumberFormat::ShowCurrencyAfterNumber(bool yes)
{
    currencyAfterNumber = yes;
}
_JATTA_EXPORT void Jatta::NumberFormat::SetPercentSign(String percent)
{
    percentSign = percent;
}

_JATTA_EXPORT Jatta::String Jatta::NumberFormat::Format(long number)
{
    String ret = "";
    ret += number;
    return ret;
}
_JATTA_EXPORT Jatta::String Jatta::NumberFormat::Format(double number)
{
    String ret = "";
    ret += long(number);
    ret += decimal;
    ret += (number-long(number))*100;
    return ret;
}
_JATTA_EXPORT Jatta::String Jatta::NumberFormat::FormatCurrency(long number)
{
    String ret = Format(number);
    if (currencyAfterNumber)
        ret += currency;
    else
        ret = currency+ret;
    return ret;
}
_JATTA_EXPORT Jatta::String Jatta::NumberFormat::FormatCurrency(double number)
{
    String ret = Format(number);
    if (!allowCents)
        ret = Format(long(number));

    if (currencyAfterNumber)
        ret += currency;
    else
        ret = currency+ret;
    return ret;
}
_JATTA_EXPORT Jatta::String Jatta::NumberFormat::FormatPercent(long number)
{
    String ret = Format(number);
    ret += percentSign;
    return ret;
}
_JATTA_EXPORT Jatta::String Jatta::NumberFormat::FormatPercent(double number)
{
    String ret = Format(number);
    ret += percentSign;
    return ret;
}



_JATTA_EXPORT Jatta::DateTimeFormat::DateTimeFormat()
{
    DateTimeFormat(MONTH, DAY, YEAR, HOUR, MINUTE, SECOND, true);
}
_JATTA_EXPORT Jatta::DateTimeFormat::DateTimeFormat(int date1, int date2, int date3, int time1, int time2, int time3, bool twentyFourHour)
{
    DateTimeFormat(date1, date2, date3, time1, time2, time3, twentyFourHour, "/", ":");
}
_JATTA_EXPORT Jatta::DateTimeFormat::DateTimeFormat(int date1, int date2, int date3, int time1, int time2, int time3, bool twentyFourHour, String dateSep, String timeSep)
{
    SetDateFormat(date1, date2, date3, dateSep);
    SetTimeFormat(time1, time2, time3, timeSep, twentyFourHour);
}
_JATTA_EXPORT void Jatta::DateTimeFormat::SetDateFormat(int date1, int date2, int date3, String sep)
{
    dateFormat[0] = date1;
    dateFormat[1] = date2;
    dateFormat[2] = date3;

    dateSeperator = sep;
}
_JATTA_EXPORT void Jatta::DateTimeFormat::SetTimeFormat(int time1, int time2, int time3, String sep, bool twentyFourHour)
{
    timeFormat[0] = time1;
    timeFormat[1] = time2;
    timeFormat[2] = time3;

    timeSeperator = sep;

    TwentyFourHourClock(twentyFourHour);
}
_JATTA_EXPORT void Jatta::DateTimeFormat::TwentyFourHourClock(bool yes)
{
    twentyFourHourClock = yes;
}

_JATTA_EXPORT Jatta::String Jatta::DateTimeFormat::FormatDate(int m, int d, int y)
{
    String ret = "";
    for (unsigned int i = 0; i < 3; i++)
    {
        if (dateFormat[i] == YEAR)
            ret += y;
        if (dateFormat[i] == MONTH)
            ret += m;
        if (dateFormat[i] == DAY)
            ret += d;

        if (i != 2)
            ret += dateSeperator;
    }

    return ret;
}
_JATTA_EXPORT Jatta::String Jatta::DateTimeFormat::FormatTime(int h, int m, int s)
{
    String ret = "";
    String _ampm = "AM";
    if (!twentyFourHourClock && h > 12)
    {
        h -= 12;
        _ampm = "PM";
    }

    for (unsigned int i = 0; i < 3; i++)
    {
        if (timeFormat[i] == HOUR)
            ret += h;
        if (timeFormat[i] == MINUTE)
            ret += m;
        if (timeFormat[i] == SECOND)
            ret += s;

        if (i != 2)
            ret += timeSeperator;
    }

    if (!twentyFourHourClock)
        ret += _ampm;

    return ret;
}



_JATTA_EXPORT Jatta::Locale::Locale(NumberFormat nf, DateTimeFormat dtf)
{
    numberFormat = nf;
    dateTimeFormat = dtf;
}

_JATTA_EXPORT Jatta::NumberFormat Jatta::Locale::GetNumberFormat()
{
    return numberFormat;
}
_JATTA_EXPORT Jatta::DateTimeFormat Jatta::Locale::GetDateTimeFormat()
{
    return dateTimeFormat;
}

_JATTA_EXPORT void Jatta::Locale::AddWord(String id, String word)
{
    words.insert(std::make_pair(id, word));
}
_JATTA_EXPORT Jatta::String Jatta::Locale::GetWord(String id)
{
    return words[id];
}
_JATTA_EXPORT Jatta::String Jatta::Locale::Translation(String word)
{
    for (auto i = words.begin(); i != words.end(); i++)
    {
        if (i->second == word)
            return i->first;
    }
    return "";
}
