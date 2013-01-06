/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once

// Operating System Detection
#if !defined(WINDOWS) & !defined(LINUX) & !defined(MACOS)
#  if defined(_WIN32)
#    define WINDOWS
#  elif defined(__APPLE__)
#    define MACOS
#  elif defined(__GNUC__)
#    define LINUX
#  else
#    error Failed to automatically detected operating system.  Must define WINDOWS, LINUX, or MACOS on the command line.
#  endif
#endif

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

// Standard Template Library Includes
#include <array>
#include <cctype>
#include <forward_list>
#include <fstream>
#include <list>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// Debugging Outputs
#ifdef JATTA_INCLUDES
#  ifdef JATTA_DEBUG
#    include <iostream>
#    define _JATTA_DEBUG_LN(x) std::cout << "JATTA_DEBUG (" __FILE__ ":" << __LINE__ << ")" << std::endl << x << std::endl;
#    define _JATTA_DEBUG(x) std::cout << x;
#  else
#    define _JATTA_DEBUG_LN(x)
#    define _JATTA_DEBUG(x)
#  endif
#endif

// DLL Exports
#ifdef MSVC
#  ifdef JATTA_BUILD
#    define _JATTA_EXPORT __declspec(dllexport) 
#  else
#    define _JATTA_EXPORT __declspec(dllimport)
#  endif
#else
#  define _JATTA_EXPORT
#endif
