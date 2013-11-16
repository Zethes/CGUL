/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Assimp.h"

_JATTA_EXPORT Jatta::String Jatta::Assimp::GetLegalString()
{
    return String(aiGetLegalString());
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::GetVersionMinor()
{
    return aiGetVersionMinor();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::GetVersionMajor()
{
    return aiGetVersionMajor();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::GetVersionRevision()
{
    return aiGetVersionMajor();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::GetCompileFlags()
{
    return aiGetCompileFlags();
}
