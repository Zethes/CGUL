/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "NetworkException.h"

Jatta::NetworkException::NetworkException(UInt8 code, UInt8 reason) : Exception(code, reason, ExceptionType::NETWORK)
{
}

Jatta::String Jatta::NetworkException::GetString() const
{
    switch (code)
    {
        case NetworkExceptionCode::FAILED_LISTEN:
        return U8("Failed to listen on socket.");
        case NetworkExceptionCode::FAILED_CONNECT:
        return U8("Failed to connect to host.");
        case NetworkExceptionCode::FAILED_ACCEPT:
        return U8("Failed to accept connection.");
        case NetworkExceptionCode::FAILED_SEND:
        return U8("Failed to send connection.");
        case NetworkExceptionCode::FAILED_RECEIVE:
        return U8("Failed to receive connection.");
        case NetworkExceptionCode::FAILED_PEEK:
        return U8("Failed to peek message.");
        case NetworkExceptionCode::UNKNOWN:
        default:
        return U8("Unknown error occurred.");
    }
}

Jatta::String Jatta::NetworkException::GetReason() const
{
    switch (reason)
    {
        case NetworkExceptionReason::NO_NETWORK_INTERFACE:
        return U8("Unable to find a valid network interface.");
        case NetworkExceptionReason::FAILED_CREATE_SOCKET:
        return U8("Failed to create a network socket.");
        case NetworkExceptionReason::FAILED_BIND_PORT:
        return U8("Failed to bind socket to port.");
        case NetworkExceptionReason::FAILED_LISTEN_CALL:
        return U8("The listen call failed.");
        case NetworkExceptionReason::FAILED_CONNECT_CALL:
        return U8("The connect call failed.");
        case NetworkExceptionReason::SOCKET_INVALID:
        return U8("The socket is invalid.");
        case NetworkExceptionReason::ADDRESS_INVALID:
        return U8("The IP address is invalid.");
        case NetworkExceptionReason::UNKNOWN:
        default:
        return U8("Unknown error occurred.");
    }
}
