/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Animation.h"

_JATTA_EXPORT Jatta::Assimp::Animation::Animation(aiAnimation* animation)
{
	this->animation = animation;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Animation::GetName()
{
	return String(animation->mName.C_Str());
}
_JATTA_EXPORT double Jatta::Assimp::Animation::GetDuration()
{
	return animation->mDuration;
}
_JATTA_EXPORT double Jatta::Assimp::Animation::GetTicksPerSecond()
{
	return animation->mTicksPerSecond;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Animation::GetChannelCount()
{
	return animation->mNumChannels;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Animation::GetMeshChannelCount()
{
	return animation->mNumMeshChannels;
}	

_JATTA_EXPORT Jatta::Assimp::NodeAnimation* Jatta::Assimp::Animation::GetChannels()
{
	return (NodeAnimation*)animation->mChannels;
}
_JATTA_EXPORT Jatta::Assimp::MeshAnimation* Jatta::Assimp::Animation::GetMeshChannels()
{
	return (MeshAnimation*)animation->mMeshChannels;
}