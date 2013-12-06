// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Memory_Implement.hpp
 */

template< typename T >
_CGUL_INLINE_IMPLEMENT T* CGUL::Memory::AllocateBulk(Size count)
{
    return (T*)new unsigned char[count * sizeof(T)];
}

template< typename T >
_CGUL_INLINE_IMPLEMENT void CGUL::Memory::FreeBulk(T* data)
{
    delete[] data; // TODO: check this function on windows, it might need to delete one at a time (to avoid stack overflow)
}

_CGUL_INLINE_IMPLEMENT void CGUL::Memory::ZeroData(void* data, Size count)
{
    // TODO: Memory::ZeroData - Not the best implementation(?), but will do for now
    for (Size i = 0; i < count; i++)
    {
        *((char*)data + i) = 0;
    }
}

template< typename T >
_CGUL_INLINE_IMPLEMENT void CGUL::Memory::ZeroArray(T* data, Size count)
{
    ZeroData(data, sizeof(T) * count);
}

_CGUL_INLINE_IMPLEMENT void CGUL::Memory::Copy(void* destination, void* source, Size count)
{
    // TODO: Memory::Copy - Not the best implementation(?), but will do for now
    for (Size i = 0; i < count; i++)
    {
        *((char*)destination + i) = *((char*)source + i);
    }
}
