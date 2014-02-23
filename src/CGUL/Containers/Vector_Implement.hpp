// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Vector_Implement.hpp
 */

template< typename T, typename Allocator >
CGUL::Vector< T, Allocator >::~Vector()
{
}

template< typename T, typename Allocator >
void CGUL::Vector< T, Allocator >::Push(const T& value)
{
    std::vector< T, Allocator >::push_back(value);
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template< typename T, typename Allocator >
void CGUL::Vector< T, Allocator >::Push(const T&& value)
{
    std::vector< T, Allocator >::push_back(value);
}
#endif

template< typename T, typename Allocator >
void CGUL::Vector< T, Allocator >::SetSize(Size size)
{
    std::vector< T, Allocator >::resize(size);
}

template< typename T, typename Allocator >
void CGUL::Vector< T, Allocator >::Set(Size index, const T& value)
{
    std::vector< T, Allocator >::at(index) = value;
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template< typename T, typename Allocator >
void CGUL::Vector< T, Allocator >::Set(Size index, const T&& value)
{
    std::vector< T, Allocator >::at(index) = value;
}
#endif

template< typename T, typename Allocator >
CGUL::Size CGUL::Vector< T, Allocator >::GetSize() const
{
    return std::vector< T, Allocator >::size();
}

template< typename T, typename Allocator >
T& CGUL::Vector< T, Allocator >::Get(Size index)
{
    return std::vector< T, Allocator >::at(index);
}

template< typename T, typename Allocator >
const T& CGUL::Vector< T, Allocator >::Get(Size index) const
{
    return std::vector< T, Allocator >::at(index);
}
