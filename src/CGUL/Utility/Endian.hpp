// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Endian.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace System
    {
        _CGUL_INLINE_DEFINE bool IsBigEndian();

        template< typename Type >
        _CGUL_INLINE_DEFINE void SwapBytes(Type* value);

        _CGUL_INLINE_DEFINE void SwapBytes(void* value, Size size);
    }
}

// Undefines
#include "../External/Undefines.hpp"

// Implementation
#include "Endian_Implement.hpp"
