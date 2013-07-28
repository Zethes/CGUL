/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#if defined(CPP_HAS_STD_MOVE)
template< class T > typename std::remove_reference<T>::type&& Jatta::Move(T&& t)
{
    return std::move(t);
}
#elif defined(CPP_HAS_DOUBLE_REFERENCE)
template< class T > T&& Jatta::Move(T&& t)
{
    return t;
}
#else
template< class T > T& Jatta::Move(T& t)
{
    return t;
}
#endif
