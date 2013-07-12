/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

// TODO: find an open-licensed regex lib, relying on c++11 is a bad idea right now

#pragma once
#include <Jatta/Config.h>
#include "String.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief Regular expressions.
     *  @todo Grab a library for this class, the C++11 one is largely unsupported.
     */
    class Regex
    {
        String expression;
    public:
        Regex();
        Regex(String expression);

        void SetExpression(String expression);
        String GetExpression();
    };
}

#include "../External/Undefines.h"
