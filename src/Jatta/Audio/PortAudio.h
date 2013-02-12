/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Device.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Audio
    {
        typedef int AudioError;
        namespace Errors
        {
            enum
            {
                SUCCESS = 0,
                NOT_INITIALIZED = -10000,
                UNANTICIPATED_HOST_ERROR,
                INVALID_CHANNEL_COUNT,
                INVALID_SAMPLE_RATE,
                INVALID_DEVICE,
                INVALID_FLAG,
                SAMPLE_FORMAT_NOT_SUPPORTED,
                BAD_IO_DEVICE_COMBINATION,
                INSUFFICIENT_MEMORY,
                BUFFER_TOO_BIG,
                BUFFER_TOO_SMALL,
                NULL_CALLBACK,
                BAD_STREAM_PTR,
                TIMED_OUT,
                INTERNAL_ERROR,
                DEVICE_UNAVAILABLE,
                INCOMPATIBLE_HOST_API_SPECIFIC_STREAM_INFO,
                STREAM_IS_STOPPED,
                STREAM_IS_NOT_STOPPED,
                INPUT_OVERFLOWED,
                OUTPUT_UNDERFLOWED,
                HOST_API_NOT_FOUND,
                INVALID_HOST_API,
                CAN_NOT_READ_FROM_A_CALLBACK_STREAM,
                CAN_NOT_WRITE_TO_A_CALLBACK_STREAM,
                CAN_NOT_READ_FROM_AN_OUTPUT_ONLY_STREAM,
                CAN_NOT_WRITE_TO_AN_INPUT_ONLY_STREAM,
                INCOMPATIBLE_STREAM_HOST_API,
                BAD_BUFFER_PTR,

                FAILED_TO_LOAD_RAW = 100
            };

            const String ErrorMessages[] = {
                    "Failed to load raw."
            };
        }
#       ifdef JATTA_BUILD
        static AudioError lastError;
#       endif
        static std::vector<Device*> outputDevices;

        _JATTA_EXPORT AudioError Initilize();
        _JATTA_EXPORT AudioError Terminate();

        _JATTA_EXPORT int NumberOfDevices();
        _JATTA_EXPORT Device* GetDefaultDevice();
        _JATTA_EXPORT Device* GetDevice(int index);

        _JATTA_EXPORT void Sleep(unsigned int ms);

        _JATTA_EXPORT int GetPAVersion();

        _JATTA_EXPORT AudioError GetLastError();
        _JATTA_EXPORT String GetErrorText(AudioError errorCode);
    }
}
#include "../External/Undefines.h"