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
        T* AllocateBulk(Size count);
        template< typename T >
        void FreeBulk(T* data);

        _CGUL_INLINE_DEFINE void ZeroData(void* data, Size count);
        template< typename T >
        void ZeroArray(T* data, Size count);
    }
}

#include "../External/Undefines.hpp"
#include "Memory_Implement.hpp"
