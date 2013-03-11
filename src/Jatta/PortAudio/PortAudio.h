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
        class HostApi;

        enum Errors
        {
            NO_ERROR = 0,

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
            STREAM_IS_PLAYING,
            INPUT_OVERFLOWED,
            OUTPUT_UNDERFLOWED,
            HOST_API_NOT_FOUND,
            INVALID_HOST_API,
            CANNOT_READ_FROM_A_CALLBACK_STREAM,
            CANNOT_WRITE_TO_A_CALLBACK_STREAM,
            CANNOT_READ_FROM_AN_OUTPUT_ONLY_STREAM,
            CANNOT_WRITE_TO_AN_INPUT_ONLY_STREAM,
            INCOMPATIBLE_STREAM_HOST_API,
            BAD_BUFFER_PTR
        };

        _JATTA_EXPORT SInt32 Initialize();
        _JATTA_EXPORT SInt32 Terminate();

        _JATTA_EXPORT SInt32 GetVersion();
        _JATTA_EXPORT String GetVersionText();

        _JATTA_EXPORT SInt32 GetDeviceCount();
        _JATTA_EXPORT SInt32 GetDefaultInputDeviceIndex();
        _JATTA_EXPORT SInt32 GetDefaultOutputDeviceIndex();
        _JATTA_EXPORT Device GetDefaultInputDevice();
        _JATTA_EXPORT Device GetDefaultOutputDevice();
        _JATTA_EXPORT Device GetDevice(SInt32 index);

        _JATTA_EXPORT SInt32 GetHostApiCount();
        _JATTA_EXPORT SInt32 GetDefaultHostApiIndex();
        _JATTA_EXPORT HostApi GetDefaultHostApi();
        _JATTA_EXPORT HostApi GetHostApi(SInt32 index);
    }
}
#include "../External/Undefines.h"