/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "StreamData.h"
#include "Device.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace PortAudio
    {
        class Stream
        {
            _JATTA_PASTREAM stream;
        protected:
            UInt32 sampleRate;
            UInt32 framesPerBuffer;
            UInt32 channelCount;
            StreamData data;
            _JATTA_EXPORT virtual SInt32 OpenStream(Device device);
        public:
            _JATTA_EXPORT Stream();
            _JATTA_EXPORT ~Stream();

            _JATTA_EXPORT virtual bool Update(StreamData* data) = 0;

            _JATTA_EXPORT SInt32 Start();
            _JATTA_EXPORT SInt32 Stop();
            _JATTA_EXPORT SInt32 Close();
        };
    }
}
#include "../External/Undefines.h"