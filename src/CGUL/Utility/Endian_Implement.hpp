// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Endian_Implement.hpp
 */

// Header
#include "Endian.hpp"

_CGUL_INLINE_IMPLEMENT bool CGUL::System::IsBigEndian()
{
    // Thanks David Cournapeau
    // http://stackoverflow.com/questions/1001307/detecting-endianness-programmatically-in-a-c-program
    union
    {
        uint32_t i;
        char c[4];
    } check = {0x01020304};

    return check.c[0] == 1;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::System::SwapBytes(Type* value)
{
    Size s = sizeof(Type);
    Size y;
    unsigned char* data = (unsigned char*)value;
    for (Size x = 0; x < s / 2; x++)
    {
        y = s - (x + 1);
        data[x] = data[x] ^ data[y];
        data[y] = data[x] ^ data[y];
        data[x] = data[x] ^ data[y];
    }
}

// There's probably a different way to do this...
namespace CGUL
{
    namespace System
    {
        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::UInt8 >(CGUL::UInt8* value)
        {
            // do nothing, 1 byte cannot be swapped
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::SInt8 >(CGUL::SInt8* value)
        {
            // do nothing, 1 byte cannot be swapped
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::UInt16 >(CGUL::UInt16* value)
        {
            *value = (*value >> 8) | (*value << 8);
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::SInt16 >(CGUL::SInt16* value)
        {
            SwapBytes((CGUL::UInt16*)value);
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::UInt32 >(CGUL::UInt32* value)
        {
            *value = (*value & 0x0000FFFF) << 16 | (*value & 0xFFFF0000) >> 16;
            *value = (*value & 0x00FF00FF) << 8 | (*value & 0xFF00FF00) >> 8;
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::SInt32 >(CGUL::SInt32* value)
        {
            SwapBytes((CGUL::UInt32*)value);
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::UInt64 >(CGUL::UInt64* value)
        {
            *value = (*value & 0x00000000FFFFFFFF) << 32 | (*value & 0xFFFFFFFF00000000) >> 32;
            *value = (*value & 0x0000FFFF0000FFFF) << 16 | (*value & 0xFFFF0000FFFF0000) >> 16;
            *value = (*value & 0x00FF00FF00FF00FF) << 8 | (*value & 0xFF00FF00FF00FF00) >> 8;
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::SInt64 >(CGUL::SInt64* value)
        {
            SwapBytes((CGUL::UInt64*)value);
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::Float32 >(CGUL::Float32* value)
        {
            SwapBytes((CGUL::UInt32*)value);
        }

        template< >
        _CGUL_INLINE_IMPLEMENT void SwapBytes< CGUL::Float64 >(CGUL::Float64* value)
        {
            SwapBytes((CGUL::UInt64*)value);
        }
    }
}
