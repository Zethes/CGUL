// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Face.cpp
 */

#include "Face.hpp"

_CGUL_EXPORT CGUL::Assimp::Face::Face()
{
    this->face = NULL;
}

_CGUL_EXPORT CGUL::Assimp::Face::Face(aiFace* face)
{
    this->face = face;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Face::GetIndicesCount()
{
    return face->mNumIndices;
}

_CGUL_EXPORT CGUL::UInt32* CGUL::Assimp::Face::GetIndices()
{
    return (CGUL::UInt32*)face->mIndices;
}
