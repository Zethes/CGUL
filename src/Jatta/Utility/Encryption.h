/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Encryption
    {
        namespace MD5
        {
            _JATTA_EXPORT String Data(const char* data, unsigned int length);
            _JATTA_EXPORT String String(String in);
        }

        namespace CRC32
        {
            _JATTA_EXPORT unsigned long Data( const void* data, unsigned int length, unsigned long seed=0);
            _JATTA_EXPORT unsigned long String(String in, unsigned long seed=0);

            _JATTA_EXPORT unsigned long Start(unsigned long seed=0);
            _JATTA_EXPORT void Add(unsigned long& crc, const void* data, unsigned int length);
            _JATTA_EXPORT void End(unsigned long& crc);
        }
    }
}

#include "../External/Undefines.h"
