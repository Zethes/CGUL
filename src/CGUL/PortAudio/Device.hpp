// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Device.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class HostApi;

        class Device
        {
            const _CGUL_PADEVICE_INFO device;
            UInt32 index;
        public:
            _CGUL_EXPORT Device(UInt32 index, const _CGUL_PADEVICE_INFO device);

            _CGUL_EXPORT String GetName();
            _CGUL_EXPORT UInt32 GetIndex();
            _CGUL_EXPORT HostApi GetHostApi();
            _CGUL_EXPORT SInt32 GetMaxInputChannels();
            _CGUL_EXPORT SInt32 GetMaxOutputChannels();

            _CGUL_EXPORT double GetDefaultLowInputLatency();
            _CGUL_EXPORT double GetDefaultLowOutputLatency();
            _CGUL_EXPORT double GetDefaultHightInputLatency();
            _CGUL_EXPORT double GetDefaultHighOutputLatency();

            _CGUL_EXPORT double GetDefaultSampleRate();
        };
    }
}
#include "../External/Undefines.hpp"
