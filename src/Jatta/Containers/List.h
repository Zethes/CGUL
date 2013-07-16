/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "FixedList.h"
#include "../External/Defines.h"

namespace Jatta
{
    template< typename T > class List : public FixedList< T >
    {
    public:
        virtual void Push(const T& value) = 0;
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        virtual void Push(const T&& value) = 0;
#       endif
    };
}

#include "../External/Undefines.h"
