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
        class Device;

        enum HostApiTypes
        {
            IN_DEVELOPMENT = 0,
            DIRECT_SOUND = 1,
            MME = 2,
            ASIO = 3,
            SOUND_MANAGER = 4,
            CORE_AUDIO = 5,
            OSS = 7,
            ALSA = 8,
            AL = 9,
            BE_OS = 10,
            WDMKS = 11,
            JACK = 12,
            WASAPI = 13,
            AUDIO_SCIENCE_HPI = 14
        };

        class HostApi
        {
            const _JATTA_PAHOSTAPI_INFO host;
        public:
            _JATTA_EXPORT HostApi(const _JATTA_PAHOSTAPI_INFO host);

            _JATTA_EXPORT String GetName();
            _JATTA_EXPORT SInt32 GetType();
            _JATTA_EXPORT SInt32 GetDeviceCount();
            _JATTA_EXPORT Device GetDefaultInputDevice();
            _JATTA_EXPORT Device GetDefaultOutputDevice();
        };
    }
}
#include "../External/Undefines.h"