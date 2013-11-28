// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Animation.cpp
 */

#include "Animation.hpp"

_CGUL_EXPORT CGUL::Assimp::Animation::Animation(aiAnimation* animation)
{
    this->animation = animation;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Animation::GetName()
{
    return String(animation->mName.C_Str());
}

_CGUL_EXPORT double CGUL::Assimp::Animation::GetDuration()
{
    return animation->mDuration;
}

_CGUL_EXPORT double CGUL::Assimp::Animation::GetTicksPerSecond()
{
    return animation->mTicksPerSecond;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Animation::GetChannelCount()
{
    return animation->mNumChannels;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Animation::GetMeshChannelCount()
{
    return animation->mNumMeshChannels;
}

_CGUL_EXPORT CGUL::Assimp::NodeAnimation* CGUL::Assimp::Animation::GetChannels()
{
    return reinterpret_cast<NodeAnimation*>(animation->mChannels);
}

_CGUL_EXPORT CGUL::Assimp::MeshAnimation* CGUL::Assimp::Animation::GetMeshChannels()
{
    return reinterpret_cast<MeshAnimation*>(animation->mMeshChannels);
}
