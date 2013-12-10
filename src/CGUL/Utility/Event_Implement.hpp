// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Event_Implement.hpp
 */

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Event< Type >::Event()
{
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Event< Type >::~Event()
{
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Event< Type >& CGUL::Event< Type >::operator+=(EventFunction function)
{
    bool found = false;
    for (typename Vector< EventFunction >::iterator itr = hooks.begin(), itrEnd = hooks.end(); itr != itrEnd; ++itr)
    {
        if (*itr == function)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        hooks.push_back(function);
        return *this;
    }
    else
    {
#       ifdef CGUL_SANITY_CHECK
        throw std::runtime_error("Event function already added.");
#       endif
    }
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Event< Type >& CGUL::Event< Type >::operator-=(EventFunction function)
{
    for (typename Vector< EventFunction >::iterator itr = hooks.begin(), itrEnd = hooks.end(); itr != itrEnd; ++itr)
    {
        if (*itr == function)
        {
            hooks.erase(itr);
            return *this;
        }
    }
#   ifdef CGUL_SANITY_CHECK
    throw std::runtime_error("Event function doesn't exist and therefore cannot be removed.");
#   endif
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Event< Type >::Trigger(const Type& event)
{
    for (typename Vector< EventFunction >::iterator itr = hooks.begin(), itrEnd = hooks.end(); itr != itrEnd; ++itr)
    {
        (*itr)(event);
    }
}
