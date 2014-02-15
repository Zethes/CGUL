// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file NetworkException.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Exceptions/Exception.hpp"

// Defines
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
            FAILED_HTTP_REQUEST
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
            SOCKET_NOT_CONNECTED,
            UNKNOWN_TRANSFER_ENCODING,
            CONNECTION_ABORTED,
            CONNECTION_RESET,
            TIMEOUT
        };
    }
    struct NetworkException : public Exception
    {
        NetworkException(UInt8 code, UInt8 reason, SInt networkCode = 99999);

        SInt networkCode;

        String GetString() const;
        String GetReason() const;

        virtual const char* what() const throw();
    };
}

// Undefines
#include "../External/Undefines.hpp"
