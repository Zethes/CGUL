// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file FatalException.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Exception.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    struct FatalException : public Exception
    {
        String error;

        FatalException(const String& error, UInt16 code = 0);
        ~FatalException() throw();

        String GetString() const;
        String GetReason() const;

        virtual const char* what() const throw();
    };
}

#include "../External/Undefines.hpp"
