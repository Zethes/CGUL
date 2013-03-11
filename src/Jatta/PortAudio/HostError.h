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
    namespace PortAudio
    {
        class HostError
        {
            const _JATTA_PAHOSTERROR_INFO info;
        public:
            _JATTA_EXPORT HostError(const _JATTA_PAHOSTERROR_INFO info);

            _JATTA_EXPORT SInt32 GetType();
            _JATTA_EXPORT SInt64 GetErrorCode();
            _JATTA_EXPORT String GetErrorText();
        };
    }
}
#include "../External/Undefines.h"