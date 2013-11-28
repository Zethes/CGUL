// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Animation.cpp
 */

#include "MeshAnimation.hpp"

_CGUL_EXPORT CGUL::Assimp::MeshAnimation::MeshAnimation(aiMeshAnim* meshAnim)
{
    this->meshAnim = meshAnim;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::MeshAnimation::GetName()
{
    return String(meshAnim->mName.C_Str());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::MeshAnimation::GetKeyCount()
{
    return meshAnim->mNumKeys;
}

_CGUL_EXPORT CGUL::Assimp::MeshKey* CGUL::Assimp::MeshAnimation::GetKeys()
{
    return reinterpret_cast<MeshKey*>(meshAnim->mKeys);
}
