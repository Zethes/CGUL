// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file HostApi.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
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
            const _CGUL_PAHOSTAPI_INFO host;
        public:
            _CGUL_EXPORT HostApi(const _CGUL_PAHOSTAPI_INFO host);

            _CGUL_EXPORT String GetName();
            _CGUL_EXPORT SInt32 GetType();
            _CGUL_EXPORT SInt32 GetDeviceCount();
            _CGUL_EXPORT Device GetDefaultInputDevice();
            _CGUL_EXPORT Device GetDefaultOutputDevice();
        };
    }
}
#include "../External/Undefines.hpp"
