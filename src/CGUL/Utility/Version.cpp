// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Version.cpp
 */

#include "Version.hpp"

/** @returns A version in the format "1.2.3"
 */
_CGUL_EXPORT CGUL::String CGUL::GetCGULVersion()
{
    return U8("") + GetCGULVersionMajor() + U8(".") + GetCGULVersionMinor() + U8(".") + GetCGULVersionPatch();
}

/** @returns The major version number (first digit in "1.2.3").
 */
_CGUL_EXPORT CGUL::UInt32 CGUL::GetCGULVersionMajor()
{
    return _CGUL_MAJOR;
}

/** @returns The minor version number (second digit in "1.2.3").
 */
_CGUL_EXPORT CGUL::UInt32 CGUL::GetCGULVersionMinor()
{
    return _CGUL_MINOR;
}

/** @returns The patch version number (third digit in "1.2.3").
 */
_CGUL_EXPORT CGUL::UInt32 CGUL::GetCGULVersionPatch()
{
    return _CGUL_PATCH;
}

/** @details The string returned is in no specific parseable format and is only useful for
 *  debugging.  The compiler used to build CGUL is determined by the CMake build system and any
 *  unknown compiler will result in an "Unknown" compiler.
 *  @returns A string containing information about the compiler.
 */
_CGUL_EXPORT CGUL::String CGUL::GetCGULCompilerName()
{
    return _COMPILER_NAME;
}
