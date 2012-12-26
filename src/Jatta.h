#pragma once

// Operating System Detection
#if !defined(WINDOWS) and !defined(LINUX) and !defined(MACOS)
#  if defined(_WIN32)
#    define WINDOWS
#  elif defined(__APPLE__)
#    define MACOS
#  elif defined(unix)
#    define LINUX
#  else
#    error Failed to automatically detected operating system.  Must define WINDOWS, LINUX, or MACOS on the command line.
#  endif
#endif

// Jatta Type Defines
#define TYPE(oldType, newType, size) typedef oldType newType; static_assert(sizeof(oldType) == size, #oldType " must be a size of " #size ". Please change Jatta.h to fix this error.");
namespace Jatta
{
    TYPE(float, Float32, 4);
    TYPE(double, Float64, 8);

    TYPE(char, SInt8, 1);
    TYPE(unsigned char, UInt8, 1);
    TYPE(short, SInt16, 2);
    TYPE(unsigned short, UInt16, 2);
    TYPE(int, SInt32, 4);
    TYPE(unsigned int, UInt32, 4);
    TYPE(long long, SInt64, 8);
    TYPE(unsigned long long, UInt64, 8);

    TYPE(bool, Boolean, 1);

    TYPE(SInt8, UTF8Char, 1);
    TYPE(SInt16, UTF16Char, 2);
    TYPE(SInt32, UTF32Char, 4);

    TYPE(UInt8, Byte, 1);
    TYPE(SInt8, SignedByte, 1);

    TYPE(long, Size, sizeof(void*));
}
#undef TYPE

// Standard Template Library Includes
#include <array>
#include <forward_list>
#include <fstream>
#include <list>
#include <memory>
#include <sstream>
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