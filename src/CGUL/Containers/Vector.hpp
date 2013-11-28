// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Vector.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "List.hpp"
#include "FixedList.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A vector functionally equivalent to an std::vector but capable of acting as a
     *  FixedList.
     */
    template< typename T, typename Allocator = std::allocator< T > >
    class Vector : public std::vector< T, Allocator >, public List< T >
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

#include "../External/Undefines.hpp"
#include "Vector_Implement.hpp"
