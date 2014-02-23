// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Logger.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    class Logger
    {
    public:
        typedef void (*Callback)(const String& result);

        _CGUL_EXPORT Logger();
        _CGUL_EXPORT Logger(Callback callback);
        _CGUL_EXPORT ~Logger();

        _CGUL_EXPORT void SetCallback(Callback callback);
        _CGUL_EXPORT void CopyFormat(const std::ostream& stream);
        _CGUL_EXPORT void CopyFormat(const Logger& logger);
        _CGUL_EXPORT void Manipulate(std::ios_base& (*manipulator)(std::ios_base&));

        template< typename Type >
        _CGUL_INLINE_DEFINE Logger operator<<(const Type& operand);

        _CGUL_EXPORT Logger operator<<(std::ostream& (*manipulator)(std::ostream&));
    private:
        std::ostringstream* stream;
        int counter;
        Callback callback;

        _CGUL_EXPORT Logger(std::ostringstream* stream, int counter, Callback callback);
    };
}

// Undefines
#include "../External/Undefines.hpp"

// Implementation
#include "Logger_Implement.hpp"
