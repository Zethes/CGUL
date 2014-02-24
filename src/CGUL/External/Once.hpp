// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Once.hpp
 */

#pragma once

// Operating System Detection
#if !defined(CGUL_WINDOWS) & !defined(CGUL_LINUX) & !defined(CGUL_MACOS)
#   if defined(_WIN32)
#       define CGUL_WINDOWS
#   elif defined(__APPLE__)
#       define CGUL_MACOS
#   elif defined(__GNUC__)
#       define CGUL_LINUX
#   else
#       error Failed to automatically detected operating system.  Must define CGUL_WINDOWS, CGUL_LINUX, or CGUL_MACOS on the command line.
#   endif
#endif

#ifdef CGUL_WINDOWS
namespace CGUL
{
    // We should really use CMake to determine the sizes of these
    struct _CGUL_PIXELFORMATDESCRIPTOR
    {
        char padding[40];
    };
    struct _CGUL_CRITICAL_SECTION
    {
        char padding[24];
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
#if defined(CPP_HEADER_CSTDDEF)
#   include <cstddef>
#elif defined(CPP_HEADER_STDDEF_H)
#   include <stddef.h>
#endif

// CGUL Type Defines
#ifdef CPP_HAS_STATIC_ASSERT
#   define TYPE(oldType, newType, size) typedef oldType newType; static_assert(sizeof(oldType) == size, #oldType " must be a size of " #size ". Please change CGUL.hpp to fix this error.")
#else
#   define TYPE(oldType, newType, size) typedef oldType newType
#endif
/** @brief General utility library.
 */
namespace CGUL
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

    const SInt8 SInt8Min = 127;
    const SInt8 SInt8Max = -(127) - 1;
    const UInt8 UInt8Min = 0;
    const UInt8 UInt8Max = 255;

    const SInt16 SInt16Min = -(32767) - 1;
    const SInt16 SInt16Max = 32767;
    const UInt16 UInt16Min = 0;
    const UInt16 UInt16Max = 65535;

    const SInt32 SInt32Min = -(2147483647) - 1;
    const SInt32 SInt32Max = 2147483647;
    const UInt32 UInt32Min = 0;
    const UInt32 UInt32Max = 4294967295U;

#   ifdef CPP_HAS_LL_SUFFIX
    const SInt64 SInt64Min = (-9223372036854775807LL - 1);
    const SInt64 SInt64Max = 9223372036854775807LL;
    const UInt64 UInt64Min = 0ULL;
    const UInt64 UInt64Max = 18446744073709551615ULL;
#   endif

    /** @brief System dependent signed short integer.
     *  @see SInt
     */
    typedef short SShort;

    /** @brief System dependent unsigned short integer.
     *  @see SInt
     */
    typedef unsigned short UShort;

    /** @brief System dependent signed integer.
     *  @details CGUL redefines some of the standard integers in C and C++ for explicitness.  It is
     *  clear that using "SInt" rather than "SInt32" that the user wants a system-dependent (and
     *  usually "faster") integer rather than a fixed size integer.  Short integers will be less
     *  than or equal in size as "normal" integers (SInt and UInt) and long integers will be
     *  larger than or equal in size as "normal" integers.  Note that, depending on whatever wonky
     *  system/compiler you're using, all three types of integers could be the the same size, all
     *  the way down to 8 bytes small.  On modern systems most short integers will be 16 bits,
     *  "normal" integers will be 32 bits, and long integers will be 32 bits on a 32 bit machine and
     *  64 bits on a 64 bit machine.
     *  @see SShort
     *  @see UShort
     *  @see SInt
     *  @see UInt
     *  @see SLong
     *  @see ULong
     */
    typedef int SInt;

    /** @brief System dependent unsigned integer.
     *  @see SInt
     */
    typedef unsigned int UInt;

    /** @brief System dependent signed long integer.
     *  @see SInt
     */
    typedef long SLong;

    /** @brief System dependent unsigned long integer.
     *  @see SInt
     */
    typedef unsigned long ULong;

    /** @brief A type capable of holding an enumeration.
     *  @details Enumerations are iffy in C++.  Older compilers hate typed enumerations.  It's
     *  best, for portability, to reference all enumerations as system-specific sized integer.
     *  (and hope that you never need more than 65535 enumerations)
     */
    typedef SInt Enum;

    /** @brief A type capable of holding the difference between two pointers.
     */
#if defined(CPP_HEADER_CSTDDEF)
    typedef std::ptrdiff_t PtrDiff;
#elif defined(CPP_HEADER_STDDEF_H)
    typedef ptrdiff_t PtrDiff;
#else
    typedef SignedSize PtrDiff;
#endif
}
#undef TYPE

// DLL Exports
#ifdef MSVC
#   ifdef CGUL_BUILD
#       define _CGUL_EXPORT __declspec(dllexport)
#   else
#       define _CGUL_EXPORT __declspec(dllimport)
#   endif
#else
#   define _CGUL_EXPORT
#endif

#if defined(CGUL_INCLUDES)
#   ifdef CGUL_WINDOWS
#       define UNICODE
#       define _UNICODE
#       ifdef CGUL_USE_NETWORK
#           define _WIN32_WINNT 0x501
#           include <winsock2.h>
#           include <ws2tcpip.h>
#       endif
#       include <windows.h>
#       ifdef CGUL_USE_OPENGL
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef CGUL_LINUX
#       include <setjmp.h>
#       include <X11/Xlib.h>
#       include <X11/Xatom.h>
#       include <X11/Xutil.h>
#       ifdef CGUL_USE_OPENGL
#           include <GL/glxew.h>
#           include <GL/glew.h>
#       endif
#   endif
#   ifdef CGUL_MACOS
#       ifdef CGUL_USE_OPENGL
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
#   ifdef OpenSSL_FOUND
#       include <openssl/rand.h>
#       include <openssl/ssl.h>
#       include <openssl/err.h>
#   endif
#   if defined(CGUL_LINUX) | defined(CGUL_MACOS)
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

#if defined(CGUL_WINDOWS) && !defined(_WIN32_WINNT)
#   define _WIN32_WINNT 0x0501
#endif

// Regex support
#if defined(PCRE_FOUND) || defined(CPP_HAS_STD_REGEX)
#   define CGUL_USE_REGEX
#endif

// Deprecated code tag
#if defined(CPP_DEPRECATED_GCC_MESSAGE)
#   define DEPRECATED(func, str) func __attribute__ ((deprecated(str)))
#elif defined(CPP_DEPRECATED_GCC)
#   define DEPRECATED(func, str) func __attribute__ ((deprecated))
#elif defined(CPP_DEPRECATED_MSVC)
#   define DEPRECATED(func, str) __declspec(deprecated) func
#else
#   define DEPRECATED(func, src) func
#endif
