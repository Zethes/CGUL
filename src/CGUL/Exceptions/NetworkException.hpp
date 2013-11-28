// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file NetworkException.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Exception.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace NetworkExceptionCode
    {
        enum
        {
            UNKNOWN,
            FAILED_STARTUP,
            FAILED_LISTEN,
            FAILED_CONNECT,
            FAILED_ACCEPT,
            FAILED_SEND,
            FAILED_RECEIVE,
            FAILED_PEEK,
            FAILED_CALCULATE_ADDRESS,
            FAILED_DNS_LOOKUP,
            FAILED_SSL_SETUP,
            FAILED_HTTP_REQUEST,
        };
    }
    namespace NetworkExceptionReason
    {
        enum
        {
            UNKNOWN,
            FAILED_WINSOCK_INITIALIZE,
            NO_NETWORK_INTERFACE,
            FAILED_CREATE_SOCKET,
            FAILED_BIND_PORT,
            FAILED_LISTEN_CALL,
            FAILED_CONNECT_CALL,
            SOCKET_INVALID,
            ADDRESS_INVALID,
            ADDRESS_MISMATCH,
            FAILED_NONBLOCKING,
            FAILED_NO_DELAY,
            FAILED_NEW_BIO,
            FAILED_BIO_CONNECT,
            FAILED_CTX_NEW,
            FAILED_SSL_NEW,
            FAILED_SSL_FD,
            FAILED_SSL_CONNECT,
            FAILED_LOADING_CERTIFICATE,
            INVALID_CERTIFICATE,
            UNKNOWN_TRANSFER_ENCODING,
            TIMEOUT,
        };
    }
    struct NetworkException : public Exception
    {
        NetworkException(UInt8 code, UInt8 reason);

        String GetString() const;
        String GetReason() const;
    };
}

#include "../External/Undefines.hpp"
