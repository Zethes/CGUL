// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MD5.hpp
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
    /** @brief MD5 Hash function
     */
    class MD5
    {
        _CGUL_MD5_CTX ctx;
        Byte * digest;
    public:
        static String Hash(String in);

        _CGUL_EXPORT MD5();
        _CGUL_EXPORT ~MD5();

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
