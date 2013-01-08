/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Regex.h"

Jatta::Regex::Regex()
{
}

Jatta::Regex::Regex(String expression)
{
    this->expression = expression;
}

void Jatta::Regex::SetExpression(String expression)
{
    this->expression = expression;
}

Jatta::String Jatta::Regex::GetExpression()
{
    return this->expression;
}