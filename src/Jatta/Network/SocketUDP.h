/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Network/IPAddress.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Network
    {
        /** @class SocketUDP SocketUDP.h <Base/Network/SocketUDP.h>
         *  @brief A class to communicate on a UDP network.
         */
        class SocketUDP
        {
            #if defined(MSVC)
            unsigned int __w64 sock;
            #elif defined(WINDOWS)
            unsigned int sock;
            #else
            int sock;
            #endif

            //! @brief Makes the socket a non-blocking socket.
            void MakeNonBlocking();
        public:
            //! @brief Default constructor.
            SocketUDP();
            //! @brief Destructor.
            ~SocketUDP();

            //! @brief Binds the socket to a specified port.
            void Bind(unsigned short port, bool ipv4 = true);
            //! @brief Binds the socket to a specified port, and restricts communication to one IP
            //! address.
            void Connect(const IPAddress& ip, unsigned short port);
            //! @brief Gracefully closes the connection.
            void Close();

            //! @brief Checks if the socket is currently bound to a port.
            bool IsBound();
            //! @brief Checks if the socket is connected to a host.
            bool IsConnected();

            //! @brief Sends data over the network.
            int Send(const void* data, unsigned int size);
            //! @brief Receives data over the network and gets information about the remote host.
            int SendTo(const IPAddress& ip, unsigned short port, const void* data, unsigned int size);
            //! @brief Receives data over the network.
            int Receive(void* data, unsigned int size);
            int ReceiveFrom(IPAddress* ip, unsigned short* port, void* data, unsigned int size);
            int Peek(void* data, unsigned int size);
            int PeekFrom(void* data, unsigned int size);
            int PeekFrom(IPAddress* ip, unsigned short* port, void* data, unsigned int size);

            template <typename T> int Send(const T& data);
#           ifdef CPP_HAS_DOUBLE_REFERENCE
            template <typename T> int Send(const T&& data);
#           endif

            template <typename T> int SendTo(const IPAddress& ip, unsigned short port, const T& data);
#           ifdef CPP_HAS_DOUBLE_REFERENCE
            template <typename T> int SendTo(const IPAddress& ip, unsigned short port, const T&& data);
#           endif

            template <typename T> int Receive(T* data);

            template <typename T> int ReceiveFrom(IPAddress* ip, unsigned short* port, T* data);

            template <typename T> int Peek(T* data);

            template <typename T> int PeekFrom(IPAddress* ip, unsigned short* port, T* data);
        };
    }
}

template <typename T> int Jatta::Network::SocketUDP::Send(const T& data)
{
    return Send(&data, sizeof(T));
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template <typename T> int Jatta::Network::SocketUDP::Send(const T&& data)
{
    return Send(&data, sizeof(T));
}
#endif

template <typename T> int Jatta::Network::SocketUDP::SendTo(const IPAddress& ip, unsigned short port, const T& data)
{
    return Send(ip, port, &data, sizeof(T));
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template <typename T> int Jatta::Network::SocketUDP::SendTo(const IPAddress& ip, unsigned short port, const T&& data)
{
    return SendTo(ip, port, &data, sizeof(T));
}
#endif

template <typename T> int Jatta::Network::SocketUDP::Receive(T* data)
{
    return Receive(data, sizeof(T));
}

template <typename T> int Jatta::Network::SocketUDP::ReceiveFrom(IPAddress* ip, unsigned short* port, T* data)
{
    return ReceiveFrom(ip, port, data, sizeof(T));
}

template <typename T> int Jatta::Network::SocketUDP::Peek(T* data)
{
    return Peek(data, sizeof(T));
}

template <typename T> int Jatta::Network::SocketUDP::PeekFrom(IPAddress* ip, unsigned short* port, T* data)
{
    return PeekFrom(ip, port, data, sizeof(T));
}

#include "../External/Undefines.h"
