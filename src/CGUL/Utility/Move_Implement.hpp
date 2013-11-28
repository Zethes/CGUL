// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Move_Implement.hpp
 */

#if defined(CPP_HAS_STD_MOVE)
template< class T >
typename std::remove_reference<T>::type&& CGUL::Move(T&& t)
{
    return std::move(t);
}
#elif defined(CPP_HAS_DOUBLE_REFERENCE)
template< class T >
T&& CGUL::Move(T&& t)
{
    return t;
}
#else
template< class T >
T& CGUL::Move(T& t)
{
    return t;
}
#endif
