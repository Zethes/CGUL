/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Exception.h"
#include "../External/Defines.h"

namespace Jatta
{
    struct FatalException : public Exception
    {
        Jatta::String error;

        FatalException(const Jatta::String& error, UInt16 code = 0);

        Jatta::String GetString() const;
    };
}

#include "../External/Undefines.h"
