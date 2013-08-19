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

// Standard Template Library Includes
#ifdef CPP_HEADER_ALGORITHM
#   include <algorithm>
#endif
#ifdef CPP_HEADER_CCTYPE
#   include <cctype>
#endif
#ifdef CPP_HEADER_FSTREAM
#   include <fstream>
#endif
#ifdef CPP_HEADER_LIST
#   include <list>
#endif
#ifdef CPP_HEADER_MAP
#   include <map>
#endif
#ifdef CPP_HEADER_MEMORY
#   include <memory>
#endif
#ifdef CPP_HEADER_SSTREAM
#   include <sstream>
#endif
#ifdef CPP_HEADER_STDEXCEPT
#   include <stdexcept>
#endif
#ifdef CPP_HEADER_STRING
#   include <string>
#endif
#ifdef CPP_HEADER_THREAD
#   include <thread>
#endif
#ifdef CPP_HEADER_UTILITY
#   include <utility>
#endif
#ifdef CPP_HEADER_VECTOR
#   include <vector>
#endif
#if defined(CPP_HEADER_CSTDINT)
#   include <cstdint>
#elif defined(CPP_HEADER_STDINT_H)
#   include <stdint.h>
#endif

// Jatta Type Defines
#ifdef CPP_HAS_STATIC_ASSERT
#   define TYPE(oldType, newType, size) typedef oldType newType; static_assert(sizeof(oldType) == size, #oldType " must be a size of " #size ". Please change Jatta.h to fix this error.")
#else
#   define TYPE(oldType, newType, size) typedef oldType newType
#endif
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
#   ifdef _STDINT_H
    TYPE(int8_t, SInt8, 1);
#   else
    TYPE(char, SInt8, 1);
#   endif

    /** @brief An 8 bit (1 byte) unsigned integer number.
     */
#   ifdef _STDINT_H
    TYPE(uint8_t, UInt8, 1);
#   else
    TYPE(unsigned char, UInt8, 1);
#   endif

    /** @brief A 16 bit (2 bytes) signed integer number.
     */
#   ifdef _STDINT_H
    TYPE(int16_t, SInt16, 2);
#   else
    TYPE(short, SInt16, 2);
#   endif

    /** @brief A 16 bit (2 bytes) unsigned integer number.
     */
#   ifdef _STDINT_H
    TYPE(uint16_t, UInt16, 2);
#   else
    TYPE(unsigned short, UInt16, 2);
#   endif

    /** @brief A 32 bit (4 bytes) signed integer number.
     */
#   ifdef _STDINT_H
    TYPE(int32_t, SInt32, 4);
#   else
    TYPE(int, SInt32, 4);
#   endif

    /** @brief A 32 bit (4 bytes) unsigned integer number.
     */
#   ifdef _STDINT_H
    TYPE(uint32_t, UInt32, 4);
#   else
    TYPE(unsigned int, UInt32, 4);
#   endif

    /** @brief A 64 bit (8 bytes) signed integer number.
     */
#   ifdef _STDINT_H
    TYPE(int64_t, SInt64, 8);
#   else
    TYPE(long long, SInt64, 8);
#   endif

    /** @brief A 64 bit (8 bytes) unsigned integer number.
     */
#   ifdef _STDINT_H
    TYPE(uint64_t, UInt64, 8);
#   else
    TYPE(unsigned long long, UInt64, 8);
#   endif

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
#   ifdef _STDINT_H
    TYPE(uintptr_t, Size, sizeof(void*));
#   else
    TYPE(unsigned long, Size, sizeof(void*));
#   endif

    /** @brief A system-dependent sized signed integer capable of holding addresses in memory.
     */
#   ifdef _STDINT_H
    TYPE(intptr_t, SignedSize, sizeof(void*));
#   else
    TYPE(unsigned long, SignedSize, sizeof(void*));
#   endif

    /** @brief An value capable of holding an enumeration.
     *  @details Enumerations are iffy in C++.  Older compilers hate typed enumerations.  It's
     *  best, for portability, to reference all enumerations as an unsigned 32 bit integer.
     */
    typedef UInt32 Enum;

    const SInt8 SInt8Min = 127;
    const SInt8 SInt8Max = -(127) - 1;
    const UInt8 UInt8Min = 0;
    const UInt8 UInt8Max = 255U;

    const SInt16 SInt16Min = -(32767) - 1;
    const SInt16 SInt16Max = 32767;
    const UInt16 UInt16Min = 0;
    const UInt16 UInt16Max = 65535U;

    const SInt32 SInt32Min = -(2147483647) - 1;
    const SInt32 SInt32Max = 2147483647;
    const UInt32 UInt32Min = 0;
    const UInt32 UInt32Max = 4294967295U;

    const SInt64 SInt64Min = -(9223372036854775807LL) - 1;
    const SInt64 SInt64Max = 9223372036854775807LL;
    const UInt64 UInt64Min = 0ULL;
    const UInt64 UInt64Max = 18446744073709551615ULL;
}
#undef TYPE

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
#       ifdef Jatta_USE_NETWORK
#           define _WIN32_WINNT 0x501
#           include <winsock2.h>
#           include <ws2tcpip.h>
#       endif
#       include <windows.h>
#       ifdef Jatta_USE_OPENGL
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef LINUX
#       include <setjmp.h>
#       include <X11/Xlib.h>
#       include <X11/Xatom.h>
#       include <X11/Xutil.h>
#       ifdef Jatta_USE_OPENGL
#           include <GL/glxew.h>
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef MACOS
#       ifdef Jatta_USE_OPENGL
#           include <GL/glew.h>
#       endif
#       import <Cocoa/Cocoa.h>
#   endif
#   ifdef FreeType_FOUND
#       include <ft2build.h>
#       include <freetype/freetype.h>
#       include <freetype/ftxf86.h>
#       include <freetype/ftglyph.h>
#   endif
#   ifdef Assimp_FOUND
#       include <assimp/cimport.h>
#       include <assimp/scene.h>
#       include <assimp/postprocess.h>
#       include <assimp/version.h>
#       include <assimp/importerdesc.h>
#       include <assimp/Importer.hpp>
#       include <assimp/Exporter.hpp>
#   endif
#   ifdef PortAudio_FOUND
#       include <portaudio.h>
#   endif
#   ifdef PCRE_FOUND
#       include <pcre.h>
#   endif
/*#   ifdef OpenSSL_FOUND
#       include <openssl/rand.h>
#       include <openssl/ssl.h>
#       include <openssl/err.h>
#   endif*/
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

// Regex support
#if defined(PCRE_FOUND) || defined(CPP_HAS_STD_REGEX)
#   define Jatta_USE_REGEX
#endif
