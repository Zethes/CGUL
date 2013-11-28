/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "NodeAnimation.h"

_JATTA_EXPORT Jatta::Assimp::NodeAnimation::NodeAnimation(aiNodeAnim* nodeAnim)
{
    this->nodeAnim = nodeAnim;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::NodeAnimation::GetName()
{
    return String(nodeAnim->mNodeName.C_Str());
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::NodeAnimation::GetPositionKeyCount()
{
    return nodeAnim->mNumPositionKeys;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::NodeAnimation::GetRotationKeyCount()
{
    return nodeAnim->mNumRotationKeys;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::NodeAnimation::GetScalingKeyCount()
{
    return nodeAnim->mNumScalingKeys;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::NodeAnimation::GetPreState()
{
    return nodeAnim->mPreState;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::NodeAnimation::GetPostState()
{
    return nodeAnim->mPostState;
}

_JATTA_EXPORT Jatta::Assimp::VectorKey* Jatta::Assimp::NodeAnimation::GetPositionKeys()
{
    return reinterpret_cast<VectorKey*>(nodeAnim->mPositionKeys);
}

_JATTA_EXPORT Jatta::Assimp::QuatKey* Jatta::Assimp::NodeAnimation::GetRotationKeys()
{
    aiQuatKey* keys = nodeAnim->mRotationKeys;

    QuatKey* ret = new QuatKey[nodeAnim->mNumRotationKeys];
    for (unsigned int i = 0; i < nodeAnim->mNumRotationKeys; i++)
    {
        ret[i].time = keys[i].mTime;
        ret[i].value = Jatta::Quaternion(keys[i].mValue.w, keys[i].mValue.x, keys[i].mValue.y, keys[i].mValue.z);
    }

    return ret;
}

_JATTA_EXPORT Jatta::Assimp::VectorKey* Jatta::Assimp::NodeAnimation::GetScalingKeys()
{
    return reinterpret_cast<VectorKey*>(nodeAnim->mScalingKeys);
}
