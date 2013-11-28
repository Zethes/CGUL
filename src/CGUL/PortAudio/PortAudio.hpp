// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file PortAudio.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"
#undef NO_ERROR

namespace CGUL
{
    namespace PortAudio
    {
        class Device;
        class HostApi;
        class HostError;

        namespace Errors
        {
            enum
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
        }

        _CGUL_EXPORT SInt32 Initialize();
        _CGUL_EXPORT SInt32 Terminate();

        _CGUL_EXPORT SInt32 GetVersion();
        _CGUL_EXPORT String GetVersionText();
        _CGUL_EXPORT String GetErrorText(SInt32 error);

        _CGUL_EXPORT SInt32 GetDeviceCount();
        _CGUL_EXPORT SInt32 GetDefaultInputDeviceIndex();
        _CGUL_EXPORT SInt32 GetDefaultOutputDeviceIndex();
        _CGUL_EXPORT Device GetDefaultInputDevice();
        _CGUL_EXPORT Device GetDefaultOutputDevice();
        _CGUL_EXPORT Device GetDevice(SInt32 index);

        _CGUL_EXPORT SInt32 GetHostApiCount();
        _CGUL_EXPORT SInt32 GetDefaultHostApiIndex();
        _CGUL_EXPORT HostApi GetDefaultHostApi();
        _CGUL_EXPORT HostApi GetHostApi(SInt32 index);
        _CGUL_EXPORT HostError GetLastHostError();

        _CGUL_EXPORT void Sleep(UInt32 miliseconds);
    }
}
#include "../External/Undefines.hpp"
