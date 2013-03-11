/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Stream.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace PortAudio
    {
        class InputStream : public Stream
        {
        protected:
            _JATTA_EXPORT SInt32 OpenStream(Device device);
            std::vector<Float32>* inputs;
        public:
            _JATTA_EXPORT InputStream(Device device);

            _JATTA_EXPORT virtual bool Update(StreamData* data);

            _JATTA_EXPORT Float32 GetLastInput(int channel);
            _JATTA_EXPORT std::vector<Float32> GetInput(int channel);
            _JATTA_EXPORT void ClearInput();

            _JATTA_EXPORT void WriteToRaw(const char* filename);
        };
    }
}
#include "../External/Undefines.h"