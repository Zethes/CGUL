// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Stream.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "StreamData.hpp"
#include "Device.hpp"
#include "StreamInfo.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace PortAudio
    {
        class Stream
        {
        protected:
            Float32 volume;
            Float32 pitch;
            bool loop;

            _CGUL_PASTREAM stream;
            UInt32 sampleRate;
            UInt32 framesPerBuffer;
            StreamData streamData;
            _CGUL_EXPORT virtual SInt32 OpenStream(Device device) = 0;
        public:
            _CGUL_EXPORT Stream();
            _CGUL_EXPORT ~Stream();

            _CGUL_EXPORT SInt32 Start();
            _CGUL_EXPORT SInt32 Stop();
            _CGUL_EXPORT SInt32 Close();

            _CGUL_EXPORT void SetVolume(Float32 volume);
            _CGUL_EXPORT Float32 GetVolume();
            _CGUL_EXPORT void SetPitch(Float32 pitch);
            _CGUL_EXPORT Float32 GetPitch();
            _CGUL_EXPORT bool GetLooping();
            _CGUL_EXPORT void SetLooping(bool loop);

            _CGUL_EXPORT bool IsStopped();
            _CGUL_EXPORT bool IsActive();
            _CGUL_EXPORT StreamInfo GetInfo();
            _CGUL_EXPORT double GetTime();
            _CGUL_EXPORT double GetCpuLoad();

            _CGUL_EXPORT StreamData* GetData();

            _CGUL_EXPORT SInt32 Read(void* buffer, UInt64 frames);
            _CGUL_EXPORT SInt32 Write(Float32* buffer, UInt64 frames);
            _CGUL_EXPORT SInt64 ReadAvailable();
            _CGUL_EXPORT SInt64 WriteAvailable();
        };
    }
}
#include "../External/Undefines.hpp"
