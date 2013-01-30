/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

/** @file SocketTCP.cpp
 *  @brief Implements Network::SocketTCP
 */

#include "SocketTCP.h"

// TODO: clean this up
void __jatta_network_initiate();
void __jatta_network_clean();

// TODO: come up with a more permanent place for this
#if defined(WINDOWS) && !defined(MSVC)
static const char* inet_ntop(int af, const void *src, char *dst, socklen_t cnt)
{
  if (af == AF_INET) {
    struct sockaddr_in in;
    memset(&in, 0, sizeof(in));
    in.sin_family = AF_INET;
    memcpy(&in.sin_addr, src, sizeof(struct in_addr));
    getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in), dst, cnt,
                NULL, 0, NI_NUMERICHOST);
    return dst;
  }
  else if (af == AF_INET6) {
    struct sockaddr_in6 in;
    memset(&in, 0, sizeof(in));
    in.sin6_family = AF_INET6;
    memcpy(&in.sin6_addr, src, sizeof(struct in_addr6));
    getnameinfo((struct sockaddr *)&in, sizeof(struct sockaddr_in6), dst, cnt,
                NULL, 0, NI_NUMERICHOST);
    return dst;
  }
  return NULL;
}
#endif



/** @brief Makes the socket a non-blocking socket.
 *  @details This happens to all sockets created.  This class does not supported blocking sockets.
 */
 void Jatta::Network::SocketTCP::MakeNonBlocking()
{
    // TODO: error checking?

    #ifdef WINDOWS
    u_long uNonBlocking = 1;
    ioctlsocket(sock, FIONBIO, &uNonBlocking);
    #else
    fcntl(sock, F_SETFL, fcntl(sock, F_GETFL) | O_NONBLOCK);
    #endif
}

/** @brief Turns off the Nagle Algorithm which removes a small delay in sending and receiving.
 */
void Jatta::Network::SocketTCP::MakeNoDelay()
{
    // Turn off the Nagle Algorithm which will increase the socket's send and receive speed.
    int flag = 1;
    int result = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

    // Check if there was a problem in doing so.
    if (result != 0)
    {
        // TODO: this exception will almost NEVER happen... maybe make the methods that call this
        // one return some other well known exception?
        throw std::runtime_error("makeNoDelay failed");
    }
}

Jatta::Network::SocketTCP::SocketTCP()
{
    sock = INVALID_SOCKET;
    __jatta_network_initiate();
}

Jatta::Network::SocketTCP::~SocketTCP()
{
}

/** @brief Connects to a server on a given ip and port.
 *  @param ip The IP address to connect to.
 *  @param port The port number.
 */
void Jatta::Network::SocketTCP::Connect(const Jatta::String& ip, unsigned short port)
{
    // For error checking.
    int status;

    // Create a hints variable used to determine the connection configuration.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(addrinfo));

    // Check if the IP is an IPv4 or IPv6.
    bool ipv4 = true;
    if (ipv4)
    {
        // Use IPv4.
        hints.ai_family = AF_INET;
    }
    else
    {
        // Use IPv6.
        hints.ai_family = AF_INET6;
    }

    // We're setting up a TCP/IP connection, which is a STREAM socket.
    hints.ai_socktype = SOCK_STREAM;

    // Convert the port into a string.
    char portString[6];
    #ifdef MSVC
    sprintf_s(portString, "%d", port);
    #else
    sprintf(portString, "%d", port);
    #endif

    // Get the address info using the hints.
    addrinfo* result;
    if ((status = getaddrinfo(ip.GetData().c_str(), portString, &hints, &result)) != 0)
    {
        throw std::runtime_error("connect failed");
    }

    // Create the socket.  Because our hints are so strict, we don't have to worry about looping
    // through the linked list.  We should be able to trust that the first result is what we want.
    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == INVALID_SOCKET)
    {
        freeaddrinfo(result);
        throw std::runtime_error("connect failed");
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

    // Turn off the Nagle Algorithm to increase speed.
    MakeNoDelay();

    // Free up the address info linked list.
    freeaddrinfo(result);
}

/** @brief Starts listening for clients on a specified port.
 *  @param port The port number.
 *  @param ipv4 Whether to use the local ipv4 address or not.  Will use an ipv6 address otherwise.
 *  @param backlog How many clients can wait to be accepted.  Defaults to 10.
 */
void Jatta::Network::SocketTCP::Listen(unsigned short port, bool ipv4, int backlog)
{
    // For error checking.
    int status;

    // Convert the port into a string.
    char portString[6];
    #ifdef MSVC
    sprintf_s(portString, "%d", port);
    #else
    sprintf(portString, "%d", port);
    #endif

    // Create a hints variable used to determine the connection configuration.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(addrinfo));

    // Check if IPv4 or IPv6.
    if (ipv4)
    {
        // Use IPv4.
        hints.ai_family = AF_INET;
    }
    else
    {
        // Use IPv6.
        hints.ai_family = AF_INET6;
    }

    // We're setting up a TCP/IP connection, which is a STREAM socket.
    hints.ai_socktype = SOCK_STREAM;

    // Pick the address for us (we'll use a local address)
    hints.ai_flags = AI_PASSIVE;

    // Get the address info using the hints.
    addrinfo* result;
    if ((status = getaddrinfo(nullptr, portString, &hints, &result)) != 0)
    {
        throw std::runtime_error("listen failed");
    }

    // Create the socket.
    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == INVALID_SOCKET)
    {
        freeaddrinfo(result);
        throw std::runtime_error("listen failed");
    }

    // Bind the socket to the port.
    if (bind(sock, result->ai_addr, result->ai_addrlen) == SOCKET_ERROR)
    {
        freeaddrinfo(result);
        sock = INVALID_SOCKET;
        throw std::runtime_error("listen failed");
    }

    // Start listening like the champ that we are.
    if (::listen(sock, backlog) == SOCKET_ERROR)
    {
        freeaddrinfo(result);
        sock = INVALID_SOCKET;
        throw std::runtime_error("listen failed");
    }

    // Make a non-blocking socket.
    MakeNonBlocking();

    // Turn off the Nagle Algorithm to increase speed.
    MakeNoDelay();

    // Free up the address info linked list.
    freeaddrinfo(result);
}

bool Jatta::Network::SocketTCP::Accept(SocketTCP* socket)
{
    // Check if the socket is valid before we continue.
    if (sock == INVALID_SOCKET)
    {
        throw std::runtime_error("accept failed");
    }

    // Try to accept an incoming client.
    if ((socket->sock = ::accept(sock, nullptr, nullptr)) == INVALID_SOCKET)
    {
        #ifdef WINDOWS
        if (WSAGetLastError() == WSAEWOULDBLOCK)
        #else
        if (errno == EWOULDBLOCK)
        #endif
        {
            return false;
        }
        else
        {
            throw std::runtime_error("accept failed");
        }
    }

    // Make a non-blocking socket.
    socket->MakeNonBlocking();

    // Turn off the Nagle Algorithm to increase speed.
    socket->MakeNoDelay();

    return true;
}

void Jatta::Network::SocketTCP::Close()
{
    #ifdef WINDOWS
    closesocket(sock);
    #else
    ::close(sock);
    #endif
    sock = INVALID_SOCKET;
}

/** @brief Checks if the socket is still connected to the remote host.
 *  @returns True if the connection is still active, false otherwise.
 */
bool Jatta::Network::SocketTCP::IsConnected()
{
    // Check if we've already determined the connection is dead.  If so, we can go ahead and return.
    if (sock == INVALID_SOCKET)
    {
        return false;
    }

    // Check if recv is returning 0.  In that case, the remote host has disconnected gracefully.
    // TODO: receive could return non-zero and still fail, certain winsock errors indicate this
    // add a check for those for a more accurate isConnected() method
    char data;
    if (recv(sock, &data, 1, MSG_PEEK) == 0)
    {
        sock = INVALID_SOCKET;
        return false;
    }
    return true;
}

Jatta::String Jatta::Network::SocketTCP::GetIP()
{
    if (true) // ipv4
    {
        char _IP[INET_ADDRSTRLEN];
        memset(_IP, 0, INET_ADDRSTRLEN);
        struct sockaddr_storage _Addr;
        socklen_t _Length = sizeof(_Addr);
        getpeername(sock, (struct sockaddr*)&_Addr, &_Length);
        inet_ntop(AF_INET, &((struct sockaddr_in*)&_Addr)->sin_addr, _IP, INET_ADDRSTRLEN);
        return String(_IP);
    }
    else // TODO: ipv6
    {
        char _IP[INET6_ADDRSTRLEN];
        memset(_IP, 0, INET6_ADDRSTRLEN);
        struct sockaddr_storage _Addr;
        socklen_t _Length = sizeof(_Addr);
        getpeername(sock, (struct sockaddr*)&_Addr, &_Length);
        inet_ntop(AF_INET6, &((struct sockaddr_in6*)&_Addr)->sin6_addr, _IP, INET6_ADDRSTRLEN);
        return String(_IP);
    }
}

/** @brief Sends data over the network.
 *  @param data An array of bytes to send over the network.
 *  @param size The size of the array.
 *  @returns The number of bytes that were sent.
 */
int Jatta::Network::SocketTCP::Send(const void* data, unsigned int size)
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

/** @brief Receives data over the network.
 *  @param data The buffer the data will be written into.
 *  @param size The size of the data array.
 *  @returns The number of bytes that were received, or 0 if there was nothing to be received.
 */
int Jatta::Network::SocketTCP::Receive(void* data, unsigned int size)
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
        throw std::runtime_error("receive failed");
    }
    else
    {
        return amount;
    }
}
