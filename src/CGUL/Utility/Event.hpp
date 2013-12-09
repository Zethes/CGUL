// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Event.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Containers/Vector.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A simple file utility.
     */
    template< typename Type >
    class Event
    {
        typedef void(*EventFunction)(const Type& event);

        std::vector< EventFunction > hooks;
    public:
        _CGUL_INLINE_DEFINE Event();
        _CGUL_INLINE_DEFINE ~Event();

        _CGUL_INLINE_DEFINE Event& operator+=(EventFunction function);
        _CGUL_INLINE_DEFINE Event& operator-=(EventFunction function);

        _CGUL_INLINE_DEFINE void Trigger(const Type& event);
    };
}

// Undefines
#include "../External/Undefines.hpp"

// Implementation
#include "Event_Implement.hpp"
