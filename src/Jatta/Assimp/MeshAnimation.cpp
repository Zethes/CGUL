/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "MeshAnimation.h"

_JATTA_EXPORT Jatta::Assimp::MeshAnimation::MeshAnimation(aiMeshAnim* meshAnim)
{
    this->meshAnim = meshAnim;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::MeshAnimation::GetName()
{
    return String(meshAnim->mName.C_Str());
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::MeshAnimation::GetKeyCount()
{
    return meshAnim->mNumKeys;
}

_JATTA_EXPORT Jatta::Assimp::MeshKey* Jatta::Assimp::MeshAnimation::GetKeys()
{
    return reinterpret_cast<MeshKey*>(meshAnim->mKeys);
}
