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

        Logger();
        Logger(Callback callback);
        ~Logger();

        void SetCallback(Callback callback);
        void CopyFormat(const std::ostream& stream);
        void CopyFormat(const Logger& logger);
        void Manipulate(std::ios_base& (*manipulator)(std::ios_base&));

        template< typename Type >
        Logger operator<<(const Type& operand);

        Logger operator<<(std::ostream& (*manipulator)(std::ostream&));
    private:
        std::ostringstream* stream;
        int counter;
        Callback callback;

        Logger(std::ostringstream* stream, int counter, Callback callback);
    };
};

// Undefines
#include "../External/Undefines.hpp"

// Implementation
#include "Logger_Implement.hpp"
