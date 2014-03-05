// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file NetworkException.cpp
 */

// Header
#include "NetworkException.hpp"

static CGUL::String result;

CGUL::NetworkException::NetworkException(UInt8 code, UInt8 reason, const SystemCode& systemCode) :
    Exception(code, reason, systemCode, ExceptionType::NETWORK)
{
}

CGUL::String CGUL::NetworkException::GetString() const
{
    switch (info.code)
    {
        case NetworkExceptionCode::FAILED_LISTEN:
            return U8("Failed to listen on socket.");
        case NetworkExceptionCode::FAILED_CONNECT:
            return U8("Failed to connect to host.");
        case NetworkExceptionCode::FAILED_ACCEPT:
            return U8("Failed to accept connection.");
        case NetworkExceptionCode::FAILED_SEND:
            return U8("Failed to send message.");
        case NetworkExceptionCode::FAILED_RECEIVE:
            return U8("Failed to receive message.");
        case NetworkExceptionCode::FAILED_PEEK:
            return U8("Failed to peek message.");
        case NetworkExceptionCode::FAILED_CALCULATE_ADDRESS:
            return U8("Failed to calculate IP address.");
        case NetworkExceptionCode::FAILED_DNS_LOOKUP:
            return U8("Failed to lookup a DNS address.");
        case NetworkExceptionCode::FAILED_SSL_SETUP:
            return U8("Failed to setup Secure Socket Layer.");
        case NetworkExceptionCode::FAILED_HTTP_REQUEST:
            return U8("Failed to perform HTTP Request.");
        case NetworkExceptionCode::UNKNOWN:
        default:
            return U8("Unknown error occurred.");
    }
}

CGUL::String CGUL::NetworkException::GetReason() const
{
    switch (info.reason)
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
        case NetworkExceptionReason::ADDRESS_MISMATCH:
            return U8("Addresses are not the same protocol (IPv4/IPv6).");
        case NetworkExceptionReason::FAILED_NONBLOCKING:
            return U8("Failed to set socket to nonblocking.");
        case NetworkExceptionReason::FAILED_NO_DELAY:
            return U8("Failed to set the TCP no delay algorithm.");
        case NetworkExceptionReason::FAILED_NEW_BIO:
            return U8("Failed to create a new BIO connection.");
        case NetworkExceptionReason::FAILED_BIO_CONNECT:
            return U8("Failed to connect to unsecure BIO.");
        case NetworkExceptionReason::FAILED_CTX_NEW:
            return U8("Failed to create a new context.");
        case NetworkExceptionReason::FAILED_SSL_NEW:
            return U8("Failed to create an OpenSSL handle.");
        case NetworkExceptionReason::FAILED_SSL_FD:
            return U8("Failed to link SSL to socket.");
        case NetworkExceptionReason::FAILED_SSL_CONNECT:
            return U8("Failed to connect.");
        case NetworkExceptionReason::FAILED_LOADING_CERTIFICATE:
            return U8("Failed to load a trust certificate.");
        case NetworkExceptionReason::INVALID_CERTIFICATE:
            return U8("Failed to validate a trust certificate.");
        case NetworkExceptionReason::UNKNOWN_TRANSFER_ENCODING:
            return U8("Unknown transfer encoding method.");
        case NetworkExceptionReason::SOCKET_NOT_CONNECTED:
            return U8("The socket is not connected.");
        case NetworkExceptionReason::CONNECTION_ABORTED:
            return U8("The connection was aborted (ECONNABORTED).");
        case NetworkExceptionReason::CONNECTION_RESET:
            return U8("Connection reset by peer (ECONNRESET).");
        case NetworkExceptionReason::TIMEOUT:
            return U8("The request timed out.");
        case NetworkExceptionReason::NODE_SERVICE_UNKNOWN:
            return U8("The node or service is unknown.");
        case NetworkExceptionReason::UNKNOWN:
        default:
            return U8("Unknown.");
    }
}
