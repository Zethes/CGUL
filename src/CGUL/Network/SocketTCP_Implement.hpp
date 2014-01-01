// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file SocketTCP_Implement.hpp
 */

template <typename T>
int CGUL::Network::SocketTCP::Send(const T& data)
{
    return Send(&data, sizeof(T));
}

#ifdef CPP_HAS_DOUBLE_REFERENCE
template <typename T>
int CGUL::Network::SocketTCP::Send(const T&& data)
{
    return Send(&data, sizeof(T));
}
#endif

template <typename T>
int CGUL::Network::SocketTCP::Receive(T* data)
{
    return Receive(data, sizeof(T));
}

template <typename T>
int CGUL::Network::SocketTCP::Peek(T* data)
{
    return Peek(data, sizeof(T));
}
