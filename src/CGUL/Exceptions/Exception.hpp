// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Exception.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
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
            OPENGL,
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
            };
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

#include "../External/Undefines.hpp"
