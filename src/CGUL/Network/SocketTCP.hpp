// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SocketTCP.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Network/IPAddress.hpp"
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Network
    {
        /** @class SocketTCP SocketTCP.hpp <CGUL/Network/SocketTCP.hpp>
         *  @brief A class to connect to or listen on a TCP network.
         */
        class SocketTCP
        {
#           if defined(MSVC)
            unsigned int __w64 sock;
#           elif defined(CGUL_WINDOWS)
            unsigned int sock;
#           else
            int sock;
#           endif

#           ifdef OpenSSL_FOUND
            bool connectionSecure;
            _CGUL_SSL sslHandle;
            _CGUL_SSL_CTX sslContext;
#           endif

            bool MakeNonBlocking();
            bool MakeNoDelay();
        public:
            SocketTCP();
            ~SocketTCP();

            void Connect(const IPAddress& ip, unsigned short port);
            void Listen(unsigned short port, bool ipv4 = true, int backlog = 10);
            bool Accept(SocketTCP* socket);
            void Close();

#           ifdef OpenSSL_FOUND
            void ConnectSSL(const IPAddress& ip, unsigned short port);
            void ListenSSL(unsigned short port, bool ipv4 = true, int backlog = 10);
#           endif

            bool IsConnected();

            IPAddress GetIP();

            int Send(const void* data, unsigned int size);
            int Receive(void* data, unsigned int size);
            int Peek(void* data, unsigned int size);

            template <typename T>
            int Send(const T& data);
#           ifdef CPP_HAS_DOUBLE_REFERENCE
            template <typename T>
            int Send(const T&& data);
#           endif

            template <typename T>
            int Receive(T* data);

            template <typename T>
            int Peek(T* data);
        };
    }
}

// Undefines
#include "../External/Undefines.hpp"

// Implementation
#include "SocketTCP_Implement.hpp"
