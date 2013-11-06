/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
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

#include "../External/Undefines.h"

#include "Move.ipp"
