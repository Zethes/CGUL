/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

template< typename T, typename Allocator >
void Jatta::Vector< T, Allocator >::Push(const T& value)
{
    std::vector<T, Allocator>::push_back(value);
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template< typename T, typename Allocator >
void Jatta::Vector< T, Allocator >::Push(const T&& value)
{
    std::vector<T, Allocator>::push_back(value);
}
#endif

template< typename T, typename Allocator >
void Jatta::Vector< T, Allocator >::SetSize(Size size)
{
    std::vector<T, Allocator>::resize(size);
}

template< typename T, typename Allocator >
void Jatta::Vector< T, Allocator >::Set(Size index, const T& value)
{
    std::vector<T, Allocator>::at(index) = value;
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template< typename T, typename Allocator >
void Jatta::Vector< T, Allocator >::Set(Size index, const T&& value)
{
    std::vector<T, Allocator>::at(index) = value;
}
#endif
