// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Array_Implement.hpp
 */

template< typename T >
CGUL::Array< T >::Array()
{
    data = NULL;
    size = 0;
}

template< typename T >
CGUL::Array< T >::~Array()
{
    Free();
}

template< typename T >
T* CGUL::Array< T >::GetData()
{
    return data;
}

template< typename T >
void CGUL::Array< T >::SetData(void* data, Size size)
{
    if (this->data != data)
    {
        Free();
        this->data = (T*)data;
        this->size = size;
    }
}

template< typename T >
void CGUL::Array< T >::Free()
{
    delete[] (unsigned char*)this->data;
    this->data = NULL;
    this->size = 0;
}

template< typename T >
CGUL::Size CGUL::Array< T >::GetSize() const
{
    return size;
}

template< typename T >
void CGUL::Array< T >::SetSize(Size size)
{
    Free();
    data = (T*)new unsigned char[sizeof(T) * size];
    this->size = size;
}

template< typename T >
void CGUL::Array< T >::Set(Size index, const T& value)
{
    data[index] = value;
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template< typename T >
void CGUL::Array< T >::Set(Size index, const T&& value)
{
    data[index] = value;
}
#endif
