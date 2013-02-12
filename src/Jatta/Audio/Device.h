/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "HostApiInfo.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Audio
    {
        class Device
        {
        private:
            String deviceName;
            int maxInputChannels;
            int maxOutputChannels;
            double defaultSampleRate;
            int index;
            HostApiInfo hostApiInfo;
        public:
            _JATTA_EXPORT Device();
            _JATTA_EXPORT Device(int deviceIndex);
            _JATTA_EXPORT Device(int deviceIndex, const _JATTA_PADEVICE_INFO deviceInfo);
            _JATTA_EXPORT virtual ~Device();

            _JATTA_EXPORT String GetName();
            _JATTA_EXPORT int GetIndex();
            _JATTA_EXPORT int GetMaxInputChannels();
            _JATTA_EXPORT int GetMaxOutputChannels();
            _JATTA_EXPORT double GetSampleRate();
            _JATTA_EXPORT HostApiInfo* GetHostApiInfo();
        };
    }
}
#include "../External/Undefines.h"