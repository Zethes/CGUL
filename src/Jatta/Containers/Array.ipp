/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

template< typename T > Jatta::Array< T >::Array()
{
    data = NULL;
    size = 0;
}

template< typename T > Jatta::Array< T >::~Array()
{
    Free();
}

template< typename T > T* Jatta::Array< T >::GetData()
{
    return data;
}

template< typename T > void Jatta::Array< T >::SetData(void* data, Size size)
{
    if (this->data != data)
    {
        Free();
        this->data = (T*)data;
        this->size = size;
    }
}

template< typename T > void Jatta::Array< T >::Free()
{
    if (this->size != 0)
    {
        delete[] (unsigned char*)this->data;
        this->data = NULL;
        this->size = 0;
    }
}

template< typename T > Jatta::Size Jatta::Array< T >::GetSize() const
{
    return size;
}

template< typename T > void Jatta::Array< T >::SetSize(Size size)
{
    Free();
    data = (T*)new unsigned char[sizeof(T) * size];
    this->size = size;
}

template< typename T > void Jatta::Array< T >::Set(Size index, const T& value)
{
    data[index] = value;
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template< typename T > void Jatta::Array< T >::Set(Size index, const T& value)
{
    data[index] = value;
}
#endif
