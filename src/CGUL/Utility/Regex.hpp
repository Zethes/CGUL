// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Regex.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "String.hpp"
#include "../External/Defines.hpp"

#ifdef CGUL_USE_REGEX
namespace CGUL
{
    /** @brief Regular expressions.
     *  @todo Grab a library for this class, the C++11 one is largely unsupported.
     */
    class Regex
    {
#       ifdef PCRE_FOUND
        _CGUL_PCRE pcre;
        _CGUL_PCRE_EXTRA pcreExtra;
#       endif

        String expression;
    public:
        _CGUL_EXPORT Regex();
        _CGUL_EXPORT Regex(String expression);
        _CGUL_EXPORT Regex(const Regex& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        _CGUL_EXPORT Regex(Regex&& move);
#       endif
        _CGUL_EXPORT ~Regex();

        Regex& operator=(const Regex& operand);
        friend std::ostream& operator<<(std::ostream& stream, const Regex& string)
        {
            stream << string.expression;
            return stream;
        }

        _CGUL_EXPORT void SetExpression(const String& expression);
        _CGUL_EXPORT String GetExpression() const;

        _CGUL_EXPORT Boolean Match(const String& test) const;
        _CGUL_EXPORT Boolean Find(const String& test, Size offset, Size* start, Size* end = NULL) const;
    };
}
#endif

#include "../External/Undefines.hpp"
