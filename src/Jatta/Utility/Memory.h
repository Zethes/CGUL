/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    /** @brief A simple memory utility.
     */
    namespace Memory
    {
        template< typename T >
        T* AllocateBulk(Size count);
        template< typename T >
        void FreeBulk(T* data);

        _JATTA_INLINE_DEFINE void ZeroData(void* data, Size count);
        template< typename T >
        void ZeroArray(T* data, Size count);
    }
}

#include "../External/Undefines.h"

#include "Memory.ipp"
