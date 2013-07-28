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
    namespace ExceptionType
    {
        enum
        {
            USER,
            FATAL,
            NETWORK
        };
    }
    struct Exception : public std::exception
    {
        union
        {
            struct
            {
                UInt8 code;
                UInt8 reason;
                UInt16 type;
            };
            UInt32 unique;
        };

        ~Exception() throw();

        virtual Jatta::String GetString() const = 0;
        virtual Jatta::String GetReason() const = 0;

        virtual const char* what() const throw();
    protected:
        Exception(UInt8 code, UInt8 reason, UInt16 type = ExceptionType::USER);
    };
}

#include "../External/Undefines.h"
