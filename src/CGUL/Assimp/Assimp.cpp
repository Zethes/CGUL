// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Assimp.cpp
 */

#include "Assimp.hpp"

_CGUL_EXPORT CGUL::String CGUL::Assimp::GetLegalString()
{
    return String(aiGetLegalString());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::GetVersionMinor()
{
    return aiGetVersionMinor();
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::GetVersionMajor()
{
    return aiGetVersionMajor();
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::GetVersionRevision()
{
    return aiGetVersionMajor();
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::GetCompileFlags()
{
    return aiGetCompileFlags();
}
