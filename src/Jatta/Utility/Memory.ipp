/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

template< typename T > T* Jatta::Memory::AllocateBulk(Size count)
{
    return (T*)new unsigned char[count * sizeof(T)];
}

template< typename T > void Jatta::Memory::FreeBulk(T* data)
{
    delete[] data; // TODO: check this function on windows, it might need to delete one at a time (to avoid stack overflow)
}

_JATTA_INLINE_IMPLEMENT void Jatta::Memory::ZeroData(void* data, Size count)
{
    //memset(data, 0, count);
}

template< typename T > void Jatta::Memory::ZeroArray(T* data, Size count)
{
    //memset(data, 0, sizeof(T) * count);
}
