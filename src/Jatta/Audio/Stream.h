/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_AUDIO
#pragma once
#include "PortAudio.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Audio
    {
        class Stream
        {
        private:
            _JATTA_PASTREAM stream;
            bool playing;
            Device* outDevice;

            float pitch, pan, volume;
        public:
            _JATTA_EXPORT Stream();
            _JATTA_EXPORT Stream(Device* device);
            _JATTA_EXPORT virtual ~Stream();

            _JATTA_EXPORT AudioError CreateSineWave();
            _JATTA_EXPORT AudioError LoadRaw(String filename);
            _JATTA_EXPORT AudioError Start();
            _JATTA_EXPORT AudioError Stop();
            _JATTA_EXPORT AudioError Close();

            _JATTA_EXPORT float GetPitch();
            _JATTA_EXPORT float GetVolume();
            _JATTA_EXPORT float GetPan();

            _JATTA_EXPORT void SetPitch(float p);
            _JATTA_EXPORT void SetVolume(float v);
            _JATTA_EXPORT void SetPan(float p);
        };
    }
}
#include "../External/Undefines.h"
#endif
