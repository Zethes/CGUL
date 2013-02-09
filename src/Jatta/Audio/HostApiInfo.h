/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_AUDIO
#pragma once
#include "../Utility/String.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Audio
    {
        class Device;

        const String HostApiTypes[] = {
                "Unknown",
                "In Development",
                "Direct Sound",
                "MME",
                "ASIO",
                "Sound Manager",
                "Core Audio",
                "OSS",
                "ALSA",
                "AL",
                "BeOS",
                "WDMKS",
                "JACK",
                "WASAPI",
                "Audio Science HPI"
        };

        class HostApiInfo
        {
        private:
            int index;
            String name;
            int type;
            int deviceCount;
            int defaultInputDevice;
            int defaultOutputDevice;
        public:
            _JATTA_EXPORT HostApiInfo();
            _JATTA_EXPORT HostApiInfo(int apiIndex);
            _JATTA_EXPORT HostApiInfo(int apiIndex, const _JATTA_PAHOSTAPI_INFO apiInfo);
            _JATTA_EXPORT virtual ~HostApiInfo();

            _JATTA_EXPORT int Index();
            _JATTA_EXPORT String Name();
            _JATTA_EXPORT String Type();
            _JATTA_EXPORT int DeviceCount();
            _JATTA_EXPORT Device* DefaultDevice();
        };
    }
}
#include "../External/Undefines.h"
#endif
