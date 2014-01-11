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
_CGUL_INLINE_IMPLEMENT CGUL::Event< Type >& CGUL::Event< Type >::AddEvent(EventFunction function, void* userData)
{
    bool found = false;
    for (typename Vector< std::pair< EventFunction, void* > >::iterator itr = hooks.begin(), itrEnd = hooks.end(); itr != itrEnd; ++itr)
    {
        if (itr->first == function)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        hooks.push_back(std::make_pair(function, userData));
        return *this;
    }
    else
    {
#       ifdef CGUL_SANITY_CHECK
        throw std::runtime_error("Event function already added.");
#       endif
    }
    return *this;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Event< Type >& CGUL::Event< Type >::RemoveEvent(EventFunction function, void* userData)
{
    for (typename Vector< std::pair< EventFunction, void* > >::iterator itr = hooks.begin(), itrEnd = hooks.end(); itr != itrEnd; ++itr)
    {
        if (itr->second == function)
        {
            hooks.erase(itr);
            return *this;
        }
    }
#   ifdef CGUL_SANITY_CHECK
    throw std::runtime_error("Event function doesn't exist and therefore cannot be removed.");
#   endif
    return *this;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Event< Type >::HasEvents() const
{
    return !hooks.empty();
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Event< Type >::Trigger(const Type& event)
{
    for (typename Vector< std::pair< EventFunction, void* > >::iterator itr = hooks.begin(), itrEnd = hooks.end(); itr != itrEnd; ++itr)
    {
        (*itr->first)(event, itr->second);
    }
}
