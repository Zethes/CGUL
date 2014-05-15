// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HMAC.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"
#include "BigNumber.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace HMACMethods
    {
        enum
        {
            SHA         = 0,
            RIPEMD      = 1,        
        };
    }

    /** @brief HMAC Hash function
     */
    class HMAC
    {
        _CGUL_HMAC_CTX ctx;
        Byte * digest;
        UInt32 length;
        UInt32 md;
    public:
        _CGUL_EXPORT HMAC(Byte* seed, UInt32 len, UInt32 method);
        _CGUL_EXPORT ~HMAC();

        _CGUL_EXPORT void UpdateBigNumbers(BigNumber * bn0, ...);
        _CGUL_EXPORT void UpdateData(const Byte* data, int len);
        _CGUL_EXPORT void UpdateData(const String& str);

        _CGUL_EXPORT void Initialize(Byte* seed, UInt32 len, UInt32 method);
        _CGUL_EXPORT void Finalize();

        _CGUL_EXPORT Byte * GetDigest();
        _CGUL_EXPORT UInt32 GetLength();
    };
}

// Undefines
#include "../External/Undefines.hpp"
