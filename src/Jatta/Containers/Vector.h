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
    template< typename T, typename Allocator = std::allocator< T > > class Vector : public std::vector< T, Allocator >, public List< T >, public FixedList< T >
    {
    public:
        // List
        void Push(T value);

        // FixedList
        void SetSize(Size size);
        void Set(Size index, T value);
    };
}

#include "../External/Undefines.h"
#include "Vector.ipp"
