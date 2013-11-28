/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Face.h"

_JATTA_EXPORT Jatta::Assimp::Face::Face()
{
    this->face = NULL;
}

_JATTA_EXPORT Jatta::Assimp::Face::Face(aiFace* face)
{
    this->face = face;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Face::GetIndicesCount()
{
    return face->mNumIndices;
}

_JATTA_EXPORT Jatta::UInt32* Jatta::Assimp::Face::GetIndices()
{
    return (Jatta::UInt32*)face->mIndices;
}
