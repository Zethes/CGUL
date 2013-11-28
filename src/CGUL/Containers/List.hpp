// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file List.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "FixedList.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    template< typename T >
    class List : public FixedList< T >
    {
    public:
        virtual void Push(const T& value) = 0;
#       ifdef CPP_HAS_DOUBLE_REFERENCE
        virtual void Push(const T&& value) = 0;
#       endif
    };
}

#include "../External/Undefines.hpp"
