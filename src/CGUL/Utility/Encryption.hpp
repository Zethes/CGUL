// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Encryption.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Encryption
    {
        namespace MD5
        {
            _CGUL_EXPORT String Data(const char* data, unsigned int length);
            _CGUL_EXPORT String String(String in);
        }

        namespace CRC32
        {
            _CGUL_EXPORT unsigned long Data( const void* data, unsigned int length, unsigned long seed=0);
            _CGUL_EXPORT unsigned long String(String in, unsigned long seed=0);

            _CGUL_EXPORT unsigned long Start(unsigned long seed=0);
            _CGUL_EXPORT void Add(unsigned long& crc, const void* data, unsigned int length);
            _CGUL_EXPORT void End(unsigned long& crc);
        }
    }
}

#include "../External/Undefines.hpp"
