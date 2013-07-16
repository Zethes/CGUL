/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

/** @file SocketUDP.cpp
 *  @brief Implements Network::SocketUDP
 */

#include "SocketUDP.h"

#ifndef DOXYGEN
namespace Jatta
{
    namespace Network
    {
        void __jatta_network_initiate();
        void __jatta_network_clean();
    }
}
#endif

/** @brief Makes the socket a non-blocking socket.
 *  @details This happens to all sockets created.  This class does not supported blocking sockets.
 */
 void Jatta::Network::SocketUDP::MakeNonBlocking()
{
    // TODO: error checking?

    #ifdef WINDOWS
    u_long uNonBlocking = 1;
    ioctlsocket(sock, FIONBIO, &uNonBlocking);
    #else
    fcntl(sock, F_SETFL, fcntl(sock, F_GETFL) | O_NONBLOCK);
    #endif
}

Jatta::Network::SocketUDP::SocketUDP()
{
    sock = INVALID_SOCKET;
    __jatta_network_initiate();
}

Jatta::Network::SocketUDP::~SocketUDP()
{
}

/** @details Since UDP is connectionless, all that is required for a connection is a port.  To send
 *  to a specific host use SendTo.  When receiving, use ReceiveFrom.
 *  @param port The port to receive packets on.
 *  @param ipv4 True for IPv4, false for IPv6.
 */
void Jatta::Network::SocketUDP::Bind(unsigned short port, bool ipv4)
{
    // For error checking.
    int status;

    // Create a hints variable used to determine the connection configuration.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(addrinfo));

    // Check if the IP is an IPv4 or IPv6.
    hints.ai_family = (ipv4 ? AF_INET : AF_INET6);

    // We're setting up a UDP connection, which is a DGRAM socket.
    hints.ai_socktype = SOCK_DGRAM;

    // Pick the address for us (we'll use a local address)
    hints.ai_flags = AI_PASSIVE;

    // Convert the port into a string.
    char portString[6];
    #ifdef MSVC
    sprintf_s(portString, "%d", port);
    #else
    sprintf(portString, "%d", port);
    #endif

    // Get the address info using the hints.
    addrinfo* result;
    if ((status = getaddrinfo(NULL, portString, &hints, &result)) != 0)
    {
        throw std::runtime_error("bind failed");
    }

    // Create the socket.  Because our hints are so strict, we don't have to worry about looping
    // through the linked list.  We should be able to trust that the first result is what we want.
    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == INVALID_SOCKET)
    {
        freeaddrinfo(result);
        throw std::runtime_error("bind failed");
    }

    // Bind the socket to the port.
    if (bind(sock, result->ai_addr, result->ai_addrlen) == SOCKET_ERROR)
    {
        freeaddrinfo(result);
        sock = INVALID_SOCKET;
        throw std::runtime_error("Failed to bind socket.");
    }

    // Make a non-blocking socket.
    MakeNonBlocking();

    // Free up the address info linked list.
    freeaddrinfo(result);
}

/** @details Although UDP is a connectionless protocol, it is still possible to "connect" to a
 *  single host.  After connecting, use Send and Receive methods instead of SendTo and ReceiveFrom.
 *  @param ip The host to send all packets to.
 *  @param port The remote port.
 *  @todo Isnt it necessary to have a local and remote port?
 */
void Jatta::Network::SocketUDP::Connect(const IPAddress& ip, unsigned short port)
{
    // For error checking.
    int status;

    // Create a hints variable used to determine the connection configuration.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(addrinfo));

    // Check if the IP is an IPv4 or IPv6.
    hints.ai_family = (ip.GetType() == IPAddressType::IPV4 ? AF_INET : AF_INET6);

    // We're setting up a UDP connection, which is a DGRAM socket.
    hints.ai_socktype = SOCK_DGRAM;

    // Convert the port into a string.
    char portString[6];
    #ifdef MSVC
    sprintf_s(portString, "%d", port);
    #else
    sprintf(portString, "%d", port);
    #endif

    // Get the address info using the hints.
    addrinfo* result;
    if ((status = getaddrinfo(ip.ToString().GetCString(), portString, &hints, &result)) != 0)
    {
        throw std::runtime_error("Failed to get address info.");
    }

    // Create the socket.
    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == INVALID_SOCKET)
    {
        freeaddrinfo(result);
        throw std::runtime_error("Failed to create socket.");
    }

    // Make the connection.
    if (::connect(sock, result->ai_addr, result->ai_addrlen) == SOCKET_ERROR)
    {
        freeaddrinfo(result);
        sock = INVALID_SOCKET;
        throw std::runtime_error("connect failed");
    }

    // Make a non-blocking socket.
    MakeNonBlocking();

    // Free up the address info linked list.
    freeaddrinfo(result);
}

/** @note Because UDP sockets are connectionless, no remote hosts will be notified when this socket
 *  is closed.
 */
void Jatta::Network::SocketUDP::Close()
{
    #ifdef WINDOWS
    closesocket(sock);
    #else
    ::close(sock);
    #endif
    sock = INVALID_SOCKET;
}

/** @returns True if the socket is bound, false otherwise.
 */
bool Jatta::Network::SocketUDP::IsBound()
{
    return sock != INVALID_SOCKET;
}

/** @param data An array of bytes to send over the network.
 *  @param size The size of the array.
 *  @returns The number of bytes that were sent.
 */
int Jatta::Network::SocketUDP::Send(const void* data, unsigned int size)
{
    // Check if the socket is valid before we continue.
    if (sock == INVALID_SOCKET)
    {
        throw std::runtime_error("send failed");
    }

    // Pizza delivery!
    int amount;
    if ((amount = ::send(sock, (const char*)data, size, 0)) == SOCKET_ERROR)
    {
        throw std::runtime_error("send failed");
    }
    return amount;
}

/** @param data The buffer the data will be written into.
 *  @param size The size of the data array.
 *  @returns The number of bytes that were received, or 0 if there was nothing to be received.
 */
int Jatta::Network::SocketUDP::Receive(void* data, unsigned int size)
{
    // Check if the socket is valid before we continue.
    if (sock == INVALID_SOCKET)
    {
        throw std::runtime_error("receive failed");
    }

    // Pizza delivery!
    int amount;
    if ((amount = ::recv(sock, (char*)data, size, 0)) == SOCKET_ERROR)
    {
        // Check if recv failed because of a WOULDBLOCK error.  This basically means that there was
        // nothing to be received.  In that case, just return 0.  Otherwise, there was an error.
        #ifdef WINDOWS
        if (WSAGetLastError() == WSAEWOULDBLOCK)
        #else
        if (errno == EWOULDBLOCK)
        #endif
        {
            return 0;
        }
        else
        {
            throw std::runtime_error("receive failed");
        }
    }

    // Check if recv returned 0, if so, the remove socket disconnected gracefully.
    if (amount == 0)
    {
        Close();
        return 0;
    }
    else
    {
        return amount;
    }
}

/** @param ip A pointer to an IP address to be filled with the remote host's address.
 *  @param port A pointer to a port, used to communicate back with the host.
 *  @param data A void pointer, to be filled with the data sent from the remote host.
 *  @param size The size of the buffer put into the data parameter.
 *  @returns The number of bytes that were received, or 0 if there was nothing to be received.
 */
int Jatta::Network::SocketUDP::ReceiveFrom(IPAddress* ip, unsigned short* port, void* data, unsigned int size)
{
    // Check if the socket is valid before we continue.
    if (sock == INVALID_SOCKET)
    {
        throw std::runtime_error("receive failed");
    }

    // Setup an address storage class to get information about the remote socket.
    sockaddr_storage theirAddress;
    socklen_t addressLength = sizeof(sockaddr_storage);

    // Receive messages and get information about the remote host.
    int amount;
    if ((amount = ::recvfrom(sock, (char*)data, size, 0, (struct sockaddr *)&theirAddress, &addressLength)) == SOCKET_ERROR)
    {
        // Check if recv failed because of a WOULDBLOCK error.  This basically means that there was
        // nothing to be received.  In that case, just return 0.  Otherwise, there was an error.
        #ifdef WINDOWS
        if (WSAGetLastError() == WSAEWOULDBLOCK)
        #else
        if (errno == EWOULDBLOCK)
        #endif
        {
            return 0;
        }
        else
        {
            throw std::runtime_error("receive failed");
        }
    }

    // Get the IP address and port of whoever sent us data.
    if (theirAddress.ss_family == AF_INET) // ipv4
    {
        *ip = IPAddress((UInt32)((struct sockaddr_in*)&theirAddress)->sin_addr.s_addr);
    }
    else // ipv6
    {
        UInt64 address[2];
        memcpy(&address, &((struct sockaddr_in6*)&theirAddress)->sin6_addr, sizeof(address));
        *ip = IPAddress(address);
    }

    // Check if recvfrom returned 0, if so, the remove socket disconnected gracefully.
    if (amount == 0)
    {
        Close();
        return 0;
    }
    else
    {
        return amount;
    }
}

int Jatta::Network::SocketUDP::Peek(void* data, unsigned int size)
{
    // Check if the socket is valid before we continue.
    if (sock == INVALID_SOCKET)
    {
        throw std::runtime_error("peek failed");
    }

    // Pizza delivery!
    int amount;
    if ((amount = ::recv(sock, (char*)data, size, MSG_PEEK)) == SOCKET_ERROR)
    {
        // Check if recv failed because of a WOULDBLOCK error.  This basically means that there was
        // nothing to be received.  In that case, just return 0.  Otherwise, there was an error.
        #ifdef WINDOWS
        if (WSAGetLastError() == WSAEWOULDBLOCK)
        #else
        if (errno == EWOULDBLOCK)
        #endif
        {
            return 0;
        }
        else
        {
            throw std::runtime_error("peek failed");
        }
    }

    // Check if recv returned 0, if so, the remove socket disconnected gracefully.
    if (amount == 0)
    {
        Close();
        return 0;
    }
    else
    {
        return amount;
    }
}
