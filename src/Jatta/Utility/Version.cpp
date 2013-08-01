/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Version.h"

_JATTA_EXPORT Jatta::String Jatta::GetJattaVersion()
{
    return U8("") + GetJattaVersionMajor() + U8(".") + GetJattaVersionMinor() + U8(".") + GetJattaVersionPatch();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::GetJattaVersionMajor()
{
    return _JATTA_MAJOR;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::GetJattaVersionMinor()
{
    return _JATTA_MINOR;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::GetJattaVersionPatch()
{
    return _JATTA_PATCH;
}

_JATTA_EXPORT Jatta::String Jatta::GetJattaCompilerName()
{
    return _COMPILER_NAME;
}
