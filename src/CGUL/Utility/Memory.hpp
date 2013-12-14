// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Memory.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A simple memory utility.
     */
    namespace Memory
    {
        template< typename T >
        _CGUL_INLINE_DEFINE T* AllocateBulk(Size count);
        template< typename T >
        _CGUL_INLINE_DEFINE void FreeBulk(T* data);

        _CGUL_INLINE_DEFINE void ZeroData(void* data, Size count);
        template< typename T >
        _CGUL_INLINE_DEFINE void ZeroArray(T* data, Size count);

        _CGUL_INLINE_DEFINE void Copy(void* destination, const void* source, Size count);
    }
}

#include "../External/Undefines.hpp"
#include "Memory_Implement.hpp"
