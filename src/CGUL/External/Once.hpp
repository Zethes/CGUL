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

namespace CGUL
{
    // TODO: absolute TERRIBLE solution here, need to automate these values with CMake ASAP!
    struct _CGUL_PIXELFORMATDESCRIPTOR
    {
        char padding[40];
    };
#   ifdef CGUL_SIZEOF_CRITICAL_SECTION
    struct _CGUL_CRITICAL_SECTION
    {
        char padding[CGUL_SIZEOF_CRITICAL_SECTION];
    };
#   endif
    struct _CGUL_PTHREAD_MUTEX_T
    {
        char padding[40];
    };
    struct _CGUL_PTHREAD_COND_T
    {
        char padding[48];
    };
}

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
#ifdef CPP_HEADER_LIMITS
#   include <limits>
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
#else
#    error CGUL requires stdint.h or cstdint
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
    typedef int8_t SInt8;

    /** @brief An 8 bit (1 byte) unsigned integer number.
     */
    typedef uint8_t UInt8;

    /** @brief A 16 bit (2 bytes) signed integer number.
     */
    typedef int16_t SInt16;

    /** @brief A 16 bit (2 bytes) unsigned integer number.
     */
    typedef uint16_t UInt16;

    /** @brief A 32 bit (4 bytes) signed integer number.
     */
    typedef int32_t SInt32;

    /** @brief A 32 bit (4 bytes) unsigned integer number.
     */
    typedef uint32_t UInt32;

    /** @brief A 64 bit (8 bytes) signed integer number.
     */
    typedef int64_t SInt64;

    /** @brief A 64 bit (8 bytes) unsigned integer number.
     */
    typedef uint64_t UInt64;

    /** @brief A boolean value (true or false).
     */
    typedef bool Boolean;

    /** @brief Alias for UInt8, an unsigned byte.
     */
    typedef UInt8 Byte;

    /** @brief Alias for SInt8, a signed byte.
     */
    typedef SInt8 SignedByte;

    /** @brief A system-dependent sized integer capable of holding addresses in memory.
     */
    typedef uintptr_t Size;

    /** @brief A system-dependent sized signed integer capable of holding addresses in memory.
     */
    typedef intptr_t SignedSize;

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

    typedef int_fast8_t SIntF8;
    typedef uint_fast8_t UIntF8;
    typedef int_fast16_t SIntF16;
    typedef uint_fast16_t UIntF16;
    typedef int_fast32_t SIntF32;
    typedef uint_fast32_t UIntF32;
    typedef int_fast64_t SIntF64;
    typedef uint_fast64_t UIntF64;

    /** @brief System dependent signed short integer.
     *  @see SInt
     */
    typedef short SShortN;

    /** @brief System dependent unsigned short integer.
     *  @see SInt
     */
    typedef unsigned short UShortN;

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
    typedef int SIntN;

    /** @brief System dependent unsigned integer.
     *  @see SInt
     */
    typedef unsigned int UIntN;

    /** @brief System dependent signed long integer.
     *  @see SInt
     */
    typedef long SLongN;

    /** @brief System dependent unsigned long integer.
     *  @see SInt
     */
    typedef unsigned long ULongN;

    /** @brief A type capable of holding an enumeration.
     *  @details Enumerations are iffy in C++.  Older compilers hate typed enumerations.  It's
     *  best, for portability, to reference all enumerations as system-specific sized integer.
     *  (and hope that you never need more than 65535 enumerations)
     */
    typedef SIntN Enum;

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

#if 0
#   if defined(CGUL_WINDOWS) && !defined(_WIN32_WINNT)
#       define _WIN32_WINNT 0x0600
#   endif
#   if defined(CGUL_WINDOWS) && !defined(WINVER)
#       define WINVER 0x0600
#   endif
#else // UTTER BOLLOCKS
#   if defined(_WIN32_WINNT)
#       undef _WIN32_WINNT
#   endif
#   if defined(WINVER)
#       undef WINVER
#   endif
#   define _WIN32_WINNT 0x0600
#   define WINVER 0x0600
#endif

#if defined(CGUL_INCLUDES)
#   ifdef CGUL_WINDOWS
#       define UNICODE
#       define _UNICODE
#       ifdef CGUL_USE_NETWORK
#           include <winsock2.h>
#           include <ws2tcpip.h>
#       endif
#       include <windows.h>
#       ifdef CGUL_USE_OPENGL
#           include <GL/glew.h>
#           include <GL/wglew.h>
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
#   ifdef Crypto_FOUND
#       include <openssl/bn.h>
#       include <openssl/sha.h>
#       include <openssl/crypto.h>
#       include <openssl/hmac.h>
#       include <openssl/md2.h>
#       include <openssl/md4.h>
#       include <openssl/md5.h>
#       include <openssl/ripemd.h>
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
