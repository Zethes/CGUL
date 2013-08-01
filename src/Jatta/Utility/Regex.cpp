/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Regex.h"
#include "../Utility/Move.h"

#include <iostream>
#include <string.h>

#ifdef Jatta_USE_REGEX
_JATTA_EXPORT Jatta::Regex::Regex()
{
#   ifdef PCRE_FOUND
    pcre = NULL;
    pcreExtra = NULL;
#   endif
}

_JATTA_EXPORT Jatta::Regex::Regex(String expression)
{
    SetExpression(expression);
}

_JATTA_EXPORT Jatta::Regex::Regex(const Regex& copy)
{
#   ifdef PCRE_FOUND
    const char* error;
    this->pcre = copy.pcre;
    this->pcreExtra = copy.pcreExtra;
    if (this->pcre)
    {
        pcre_refcount(this->pcre, 1);
    }
#   endif
}

#ifdef CPP_HAS_MOVE_CONSTRUCTOR
_JATTA_EXPORT Jatta::Regex::Regex(Regex&& move)
{
#   ifdef PCRE_FOUND
    this->pcre = move.pcre;
    this->pcreExtra = move.pcreExtra;
    move.pcre = NULL;
    move.pcreExtra = NULL;
#   endif
}
#endif

_JATTA_EXPORT Jatta::Regex::~Regex()
{
    SetExpression("");
}

Jatta::Regex& Jatta::Regex::operator=(const Regex& operand)
{
#   ifdef PCRE_FOUND
    const char* error;
    this->pcre = operand.pcre;
    this->pcreExtra = operand.pcreExtra;
    if (this->pcre)
    {
        pcre_refcount(this->pcre, 1);
    }
#   endif
}

_JATTA_EXPORT void Jatta::Regex::SetExpression(const String& expression)
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

_JATTA_EXPORT Jatta::String Jatta::Regex::GetExpression() const
{
    return this->expression;
}

_JATTA_EXPORT Jatta::Boolean Jatta::Regex::Match(const String& test) const
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

_JATTA_EXPORT Jatta::Boolean Jatta::Regex::Find(const String& test, Size offset, Size* start, Size* count) const
{
#   ifdef PCRE_FOUND
    if (!pcre)
    {
        throw std::runtime_error("Invalid regular expression.");
    }
    static int ovec[30];
    int res = pcre_exec(pcre, pcreExtra, test.GetCString(), test.GetSize(), offset, 0, ovec, 30);
    if (res > 0 && ovec[0] != test.GetSize())
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
