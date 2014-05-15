// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SHA.hpp
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
    /** @brief SHA Hash function
     */
    class SHA
    {
        _CGUL_SHA_CTX ctx;
        Byte digest[20];
    public:
        _CGUL_EXPORT SHA();
        _CGUL_EXPORT ~SHA();

        _CGUL_EXPORT void UpdateBigNumbers(BigNumber * bn0, ...);
        _CGUL_EXPORT void UpdateData(const Byte* data, int len);
        _CGUL_EXPORT void UpdateData(const String& str);

        _CGUL_EXPORT void Initialize();
        _CGUL_EXPORT void Finalize();

        _CGUL_EXPORT Byte * GetDigest();
        _CGUL_EXPORT UInt32 GetLength();
    };
}

// Undefines
#include "../External/Undefines.hpp"
