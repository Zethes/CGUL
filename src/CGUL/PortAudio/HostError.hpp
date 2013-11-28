// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HostError.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class HostError
        {
            const _CGUL_PAHOSTERROR_INFO info;
        public:
            _CGUL_EXPORT HostError(const _CGUL_PAHOSTERROR_INFO info);

            _CGUL_EXPORT SInt32 GetType();
            _CGUL_EXPORT SInt64 GetErrorCode();
            _CGUL_EXPORT String GetErrorText();
        };
    }
}
#include "../External/Undefines.hpp"
