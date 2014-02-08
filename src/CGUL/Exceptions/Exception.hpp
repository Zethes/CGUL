// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Exception.hpp
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
    namespace ExceptionType
    {
        enum
        {
            USER,
            FATAL,
            IMAGE,
            NETWORK,
            FILE,
            OPENGL
        };
    }
    struct Exception : public std::exception
    {
        union
        {
            struct
            {
                UInt16 reason;
                UInt16 code;
                UInt32 type;
            } info;
            UInt64 unique;
        };

        ~Exception() throw();

        virtual String GetString() const = 0;
        virtual String GetReason() const = 0;

        virtual const char* what() const throw();
    protected:
        Exception(UInt16 code, UInt16 reason, UInt32 type = ExceptionType::USER);
    };
}

// Undefines
#include "../External/Undefines.hpp"
