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
        class HostApi;

        class Device
        {
            const _JATTA_PADEVICE_INFO device;
        public:
            _JATTA_EXPORT Device(const _JATTA_PADEVICE_INFO device);

            _JATTA_EXPORT String GetName();
            _JATTA_EXPORT HostApi GetHostApi();
            _JATTA_EXPORT SInt32 GetMaxInputChannels();
            _JATTA_EXPORT SInt32 GetMaxOutputChannels();

            _JATTA_EXPORT double GetDefaultLowInputLatency();
            _JATTA_EXPORT double GetDefaultLowOutputLatency();
            _JATTA_EXPORT double GetDefaultHightInputLatency();
            _JATTA_EXPORT double GetDefaultHighOutputLatency();

            _JATTA_EXPORT double GetDefaultSampleRate();
        };
    }
}
#include "../External/Undefines.h"