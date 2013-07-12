/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Container.h"
#include "../External/Defines.h"

namespace Jatta
{
    template< typename T > class FixedList : public Container< T >
    {
    public:
        virtual void SetSize(Size size) = 0;
        virtual void Set(Size index, T value) = 0; // TODO: do not pass by value
    };
}

#include "../External/Undefines.h"
