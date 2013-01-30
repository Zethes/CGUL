/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    namespace Locales
    {
        namespace NumberFormats
        {
            const NumberFormat enUS(".","$");
            const NumberFormat enEU(",","€")
            const NumberFormat enUK(".","£");
            const NumberFormat enJP(".","円",false,false);
        }

        namespace DateTimeFormats
        {
            const DateTimeFormat enUS(DateTimeFormat::MONTH, DateTimeFormat::DAY, DateTimeFormat::YEAR, DateTimeFormat::HOUR, DateTimeFormat::MINUTE, DateTimeFormat::SECOND, false);
            const DateTimeFormat enEU(DateTimeFormat::DAY, DateTimeFormat::MONTH, DateTimeFormat::YEAR, DateTimeFormat::HOUR, DateTimeFormat::MINUTE, DateTimeFormat::SECOND, true);
            const DateTimeFormat enUK(DateTimeFormat::DAY, DateTimeFormat::MONTH, DateTimeFormat::YEAR, DateTimeFormat::HOUR, DateTimeFormat::MINUTE, DateTimeFormat::SECOND, true);
            const DateTimeFormat enJP(DateTimeFormat::YEAR, DateTimeFormat::MONTH, DateTimeFormat::DAY, DateTimeFormat::HOUR, DateTimeFormat::MINUTE, DateTimeFormat::SECOND, true, "-", ":");
        }
    }
}
