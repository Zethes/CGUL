/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "List.h"
#include "FixedList.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief A vector functionally equivalent to an std::vector but capable of acting as a
     *  FixedList.
     */
    template< typename T, typename Allocator = std::allocator< T > > class Vector : public std::vector< T, Allocator >, public FixedList< T >
    {
    public:
        // List
        void Push(const T& value);
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        void Push(const T&& value);
#       endif

        // FixedList
        void SetSize(Size size);
        void Set(Size index, const T& value);
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        void Set(Size index, const T&& value);
#       endif
    };
}

#include "../External/Undefines.h"
#include "Vector.ipp"
