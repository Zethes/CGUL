/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Version.h"

/** @returns A version in the format "1.2.3"
 */
_JATTA_EXPORT Jatta::String Jatta::GetJattaVersion()
{
    return U8("") + GetJattaVersionMajor() + U8(".") + GetJattaVersionMinor() + U8(".") + GetJattaVersionPatch();
}

/** @returns The major version number (first digit in "1.2.3").
 */
_JATTA_EXPORT Jatta::UInt32 Jatta::GetJattaVersionMajor()
{
    return _JATTA_MAJOR;
}

/** @returns The minor version number (second digit in "1.2.3").
 */
_JATTA_EXPORT Jatta::UInt32 Jatta::GetJattaVersionMinor()
{
    return _JATTA_MINOR;
}

/** @returns The patch version number (third digit in "1.2.3").
 */
_JATTA_EXPORT Jatta::UInt32 Jatta::GetJattaVersionPatch()
{
    return _JATTA_PATCH;
}

/** @details The string returned is in no specific parseable format and is only useful for
 *  debugging.  The compiler used to build Jatta is determined by the CMake build system and any
 *  unknown compiler will result in an "Unknown" compiler.
 *  @returns A string containing information about the compiler.
 */
_JATTA_EXPORT Jatta::String Jatta::GetJattaCompilerName()
{
    return _COMPILER_NAME;
}
