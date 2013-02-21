/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once

// Operating System Detection
#if !defined(WINDOWS) & !defined(LINUX) & !defined(MACOS)
#   if defined(_WIN32)
#       define WINDOWS
#   elif defined(__APPLE__)
#       define MACOS
#   elif defined(__GNUC__)
#       define LINUX
#   else
#       error Failed to automatically detected operating system.  Must define WINDOWS, LINUX, or MACOS on the command line.
#   endif
#endif

#ifdef WINDOWS
namespace Jatta
{
    struct _JATTA_PIXELFORMATDESCRIPTOR
    {
        char padding[40];
    };
}
#endif

// TODO: clean this up (make a more logical way of determining if std::move exists)
// Clang doesn't support this...
#ifdef MACOS
namespace std
{
    template <typename T> const T& move(const T& value)
    {
        return value;
    }
    template <typename T> T& move(T& value)
    {
        return value;
    }
}
#endif

// TODO: fix static assert on clang builds
// Jatta Type Defines
#define TYPE(oldType, newType, size) typedef oldType newType; static_assert(sizeof(oldType) == size, #oldType " must be a size of " #size ". Please change Jatta.h to fix this error.");
/** @brief General utility library.
 */
namespace Jatta
{
    /** @brief A 32 bit (4 bytes) floating point number.
     */
    TYPE(float, Float32, 4);

    /** @brief A 64 bit (8 bytes) floating point number.
     */
    TYPE(double, Float64, 8);

    /** @brief An 8 bit (1 byte) signed integer number.
     */
    TYPE(char, SInt8, 1);

    /** @brief An 8 bit (1 byte) unsigned integer number.
     */
    TYPE(unsigned char, UInt8, 1);

    /** @brief A 16 bit (2 bytes) signed integer number.
     */
    TYPE(short, SInt16, 2);

    /** @brief A 16 bit (2 bytes) unsigned integer number.
     */
    TYPE(unsigned short, UInt16, 2);

    /** @brief A 32 bit (4 bytes) signed integer number.
     */
    TYPE(int, SInt32, 4);

    /** @brief A 32 bit (4 bytes) unsigned integer number.
     */
    TYPE(unsigned int, UInt32, 4);

    /** @brief A 64 bit (8 bytes) signed integer number.
     */
    TYPE(long long, SInt64, 8);

    /** @brief A 64 bit (8 bytes) unsigned integer number.
     */
    TYPE(unsigned long long, UInt64, 8);

    /** @brief A 8 bit (1 byte) boolean value (true or false).
     */
    TYPE(bool, Boolean, 1);

    /** @brief Alias for UInt8, an unsigned byte.
     */
    TYPE(UInt8, Byte, 1);

    /** @brief Alias for SInt8, a signed byte.
     */
    TYPE(SInt8, SignedByte, 1);

    /** @brief A system-dependent sized integer capable of holding addresses in memory.
     */
    TYPE(unsigned long, Size, sizeof(void*));
}
#undef TYPE

// TODO: clean up the standard template library list
// Standard Template Library Includes
#ifdef _CPP_HEADER_ALGORITHM
#include <algorithm>
#endif
#ifdef _CPP_HEADER_CCTYPE
#include <cctype>
#endif
#ifdef _CPP_HEADER_FSTREAM
#include <fstream>
#endif
#ifdef _CPP_HEADER_LIST
#include <list>
#endif
#ifdef _CPP_HEADER_MAP
#include <map>
#endif
#ifdef _CPP_HEADER_MEMORY
#include <memory>
#endif
#ifdef _CPP_HEADER_SSTREAM
#include <sstream>
#endif
#ifdef _CPP_HEADER_STDEXCEPT
#include <stdexcept>
#endif
#ifdef _CPP_HEADER_STRING
#include <string>
#endif
#ifdef _CPP_HEADER_THREAD
#include <thread>
#endif
#ifdef _CPP_HEADER_UTILITY
#include <utility>
#endif
#ifdef _CPP_HEADER_VECTOR
#include <vector>
#endif

// DLL Exports
#ifdef MSVC
#   ifdef JATTA_BUILD
#       define _JATTA_EXPORT __declspec(dllexport) 
#   else
#       define _JATTA_EXPORT __declspec(dllimport)
#   endif
#else
#   define _JATTA_EXPORT
#endif

#if defined(JATTA_INCLUDES)
#   ifdef WINDOWS
#       define UNICODE
#       define _UNICODE
#       ifdef JATTA_USE_NETWORK
#           include <winsock2.h>
#           include <ws2tcpip.h>
#       endif
#       include <windows.h>
#       ifdef JATTA_USE_OPENGL
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef LINUX
#       include <X11/Xlib.h>
#       include <X11/Xlib.h>
#       include <X11/Xatom.h>
#       ifdef JATTA_USE_OPENGL
#           include <GL/glxew.h>
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef MACOS
#       ifdef JATTA_USE_OPENGL
#           include <GL/glew.h>
#       endif
#       import <Cocoa/Cocoa.h>
#   endif
#   ifdef JATTA_USE_FREETYPE
#       include <ft2build.h>
#       include <freetype/freetype.h>
#       include <freetype/ftxf86.h>
#   endif
#   ifdef JATTA_USE_ASSIMP
#       include <assimp/cimport.h>
#       include <assimp/scene.h>
#       include <assimp/postprocess.h>
#   endif
#   ifdef JATTA_USE_AUDIO
#       include <portaudio.h>
#   endif
#   if defined(LINUX) | defined(MACOS)
#       include <arpa/inet.h>
#       include <errno.h>
#       include <fcntl.h>
#       include <netdb.h>
#       include <netinet/in.h>
#       include <netinet/tcp.h>
#       include <signal.h>
#       include <stdio.h>
#       include <stdlib.h>
#       include <string.h>
#       include <sys/socket.h>
#       include <sys/types.h>
#       include <sys/wait.h>
#       include <unistd.h>
#       define INVALID_SOCKET ~0
#       define SOCKET_ERROR -1
#   endif
#endif

#if defined(WINDOWS) && !defined(_WIN32_WINNT)
#   define _WIN32_WINNT 0x0501
#endif