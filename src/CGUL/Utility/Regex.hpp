/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "String.h"
#include "../External/Defines.h"

#ifdef Jatta_USE_REGEX
namespace Jatta
{
    /** @brief Regular expressions.
     *  @todo Grab a library for this class, the C++11 one is largely unsupported.
     */
    class Regex
    {
#       ifdef PCRE_FOUND
        _JATTA_PCRE pcre;
        _JATTA_PCRE_EXTRA pcreExtra;
#       endif

        String expression;
    public:
        _JATTA_EXPORT Regex();
        _JATTA_EXPORT Regex(String expression);
        _JATTA_EXPORT Regex(const Regex& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        _JATTA_EXPORT Regex(Regex&& move);
#       endif
        _JATTA_EXPORT ~Regex();

        Regex& operator=(const Regex& operand);
        friend std::ostream& operator<<(std::ostream& stream, const Regex& string)
        {
            stream << string.expression;
            return stream;
        }

        _JATTA_EXPORT void SetExpression(const String& expression);
        _JATTA_EXPORT String GetExpression() const;

        _JATTA_EXPORT Boolean Match(const String& test) const;
        _JATTA_EXPORT Boolean Find(const String& test, Size offset, Size* start, Size* end = NULL) const;
    };
}
#endif

#include "../External/Undefines.h"
