// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file NodeAnimation.cpp
 */

#include "NodeAnimation.hpp"

_CGUL_EXPORT CGUL::Assimp::NodeAnimation::NodeAnimation(aiNodeAnim* nodeAnim)
{
    this->nodeAnim = nodeAnim;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::NodeAnimation::GetName()
{
    return String(nodeAnim->mNodeName.C_Str());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::NodeAnimation::GetPositionKeyCount()
{
    return nodeAnim->mNumPositionKeys;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::NodeAnimation::GetRotationKeyCount()
{
    return nodeAnim->mNumRotationKeys;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::NodeAnimation::GetScalingKeyCount()
{
    return nodeAnim->mNumScalingKeys;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::NodeAnimation::GetPreState()
{
    return nodeAnim->mPreState;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::NodeAnimation::GetPostState()
{
    return nodeAnim->mPostState;
}

_CGUL_EXPORT CGUL::Assimp::VectorKey* CGUL::Assimp::NodeAnimation::GetPositionKeys()
{
    return reinterpret_cast<VectorKey*>(nodeAnim->mPositionKeys);
}

_CGUL_EXPORT CGUL::Assimp::QuatKey* CGUL::Assimp::NodeAnimation::GetRotationKeys()
{
    aiQuatKey* keys = nodeAnim->mRotationKeys;

    QuatKey* ret = new QuatKey[nodeAnim->mNumRotationKeys];
    for (unsigned int i = 0; i < nodeAnim->mNumRotationKeys; i++)
    {
        ret[i].time = keys[i].mTime;
        ret[i].value = CGUL::Quaternion(keys[i].mValue.w, keys[i].mValue.x, keys[i].mValue.y, keys[i].mValue.z);
    }

    return ret;
}

_CGUL_EXPORT CGUL::Assimp::VectorKey* CGUL::Assimp::NodeAnimation::GetScalingKeys()
{
    return reinterpret_cast<VectorKey*>(nodeAnim->mScalingKeys);
}
