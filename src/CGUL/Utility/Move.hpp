// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Move.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../External/Defines.hpp"

namespace CGUL
{
#   if defined(CPP_HAS_STD_MOVE)
    template< class T >
    typename std::remove_reference<T>::type&& Move(T&& t);
#   elif defined(CPP_HAS_DOUBLE_REFERENCE)
    template< class T >
    T&& Move(T&& t);
#   else
    template< class T >
    T& Move(T& t);
#   endif
}

#include "../External/Undefines.hpp"
#include "Move_Implement.hpp"
