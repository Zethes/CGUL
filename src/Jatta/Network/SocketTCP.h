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
    namespace Network
    {
        /** @class SocketTCP SocketTCP.h <Base/Network/SocketTCP.h>
         *  @brief A class to connect to or listen on a TCP network.
         */
        class SocketTCP
        {
            #if defined(MSVC)
            unsigned int __w64 sock;
            #elif defined(WINDOWS)
            unsigned int sock;
            #else
            int sock;
            #endif

            void MakeNonBlocking();
            void MakeNoDelay();
        public:
            SocketTCP();
            ~SocketTCP();

            void Connect(const Jatta::String& ip, unsigned short port);
            void Listen(unsigned short port, bool ipv4 = true, int backlog = 10);
            bool Accept(SocketTCP* socket);
            void Close();

            bool IsConnected();

            Jatta::String GetIP();

            int Send(const void* data, unsigned int size);
            int Receive(void* data, unsigned int size);
            int Peek(void* data, unsigned int size);

            template <typename T> int Send(const T& data);
#           ifdef CPP_HAS_DOUBLE_REFERENCE
            template <typename T> int Send(const T&& data);
#           endif

            template <typename T> int Receive(T* data);

            template <typename T> int Peek(T* data);
        };
    }
}

template <typename T> int Jatta::Network::SocketTCP::Send(const T& data)
{
    return Send(&data, sizeof(T));
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template <typename T> int Jatta::Network::SocketTCP::Send(const T&& data)
{
    return Send(&data, sizeof(T));
}
#endif

template <typename T> int Jatta::Network::SocketTCP::Receive(T* data)
{
    return Receive(data, sizeof(T));
}

template <typename T> int Jatta::Network::SocketTCP::Peek(T* data)
{
    return Peek(data, sizeof(T));
}

#include "../External/Undefines.h"