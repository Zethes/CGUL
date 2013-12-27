// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Regex.cpp
 */

#include "Regex.hpp"
#include "../Utility/Move.hpp"

#include <string.h>

#ifdef CGUL_USE_REGEX
_CGUL_EXPORT CGUL::Regex::Regex()
{
#   ifdef PCRE_FOUND
    pcre = NULL;
    pcreExtra = NULL;
#   endif
}

_CGUL_EXPORT CGUL::Regex::Regex(String expression)
{
    SetExpression(expression);
}

_CGUL_EXPORT CGUL::Regex::Regex(const Regex& copy)
{
#   ifdef PCRE_FOUND
    this->pcre = copy.pcre;
    this->pcreExtra = copy.pcreExtra;
    if (this->pcre)
    {
        pcre_refcount(this->pcre, 1);
    }
#   endif
}

#ifdef CPP_HAS_MOVE_CONSTRUCTOR
_CGUL_EXPORT CGUL::Regex::Regex(Regex&& move)
{
#   ifdef PCRE_FOUND
    this->pcre = move.pcre;
    this->pcreExtra = move.pcreExtra;
    move.pcre = NULL;
    move.pcreExtra = NULL;
#   endif
}
#endif

_CGUL_EXPORT CGUL::Regex::~Regex()
{
    SetExpression("");
}

CGUL::Regex& CGUL::Regex::operator=(const Regex& operand)
{
#   ifdef PCRE_FOUND
    this->pcre = operand.pcre;
    this->pcreExtra = operand.pcreExtra;
    if (this->pcre)
    {
        pcre_refcount(this->pcre, 1);
    }
#   endif
    return *this;
}

_CGUL_EXPORT void CGUL::Regex::SetExpression(const String& expression)
{
    this->expression = expression;

#   ifdef PCRE_FOUND
    if (expression == "")
    {
        if (pcre)
        {
            if (pcre_refcount(pcre, -1) == 0)
            {
                if (pcreExtra)
                {
#                   ifdef PCRE_HAS_FREE_STUDY
                    pcre_free_study(pcreExtra);
#                   else
                    pcre_free(pcreExtra);
#                   endif
                    pcreExtra = NULL;
                }
                pcre_free(pcre);
            }
            pcre = NULL;
        }
    }
    else
    {
        const char* error;
        int erroffset;
        pcre = pcre_compile(expression.GetCString(), 0, &error, &erroffset, NULL);
        if (pcre == NULL)
        {
            throw std::runtime_error(error);
        }
        pcre_refcount(pcre, 1);
        pcreExtra = pcre_study(pcre, 0, &error);
    }
#   endif
}

_CGUL_EXPORT CGUL::String CGUL::Regex::GetExpression() const
{
    return this->expression;
}

_CGUL_EXPORT CGUL::Boolean CGUL::Regex::Match(const String& test) const
{
#   ifdef PCRE_FOUND
    if (!pcre)
    {
        throw std::runtime_error("Invalid regular expression.");
    }
    static int ovec[30];
    int res = pcre_exec(pcre, pcreExtra, test.GetCString(), test.GetSize(), 0, 0, ovec, 30);
    return (res > 0);
#   endif
}

_CGUL_EXPORT CGUL::Boolean CGUL::Regex::Find(const String& test, Size offset, Size* start, Size* count) const
{
#   ifdef PCRE_FOUND
    if (!pcre)
    {
        throw std::runtime_error("Invalid regular expression.");
    }
    static int ovec[30];
    int res = pcre_exec(pcre, pcreExtra, test.GetCString(), test.GetSize(), offset, 0, ovec, 30);
    if (res > 0 && (Size)ovec[0] != test.GetSize())
    {
        if (start != NULL)
        {
            *start = ovec[0];
        }
        if (count != NULL)
        {
            *count = ovec[1] - 1;
        }
        return true;
    }
    return false;
#   endif
}
#endif
