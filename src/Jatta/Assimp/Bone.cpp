/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Bone.h"

_JATTA_EXPORT Jatta::Assimp::Bone::Bone(aiBone* bone)
{
    this->bone = bone;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Bone::GetName()
{
	return String(bone->mName.C_Str());
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Bone::GetWeightCount()
{
	return bone->mNumWeights;
}
_JATTA_EXPORT Jatta::Assimp::VertexWeight Jatta::Assimp::Bone::GetWeight(Jatta::UInt32 id)
{
	return VertexWeight(&bone->mWeights[id]);
}

_JATTA_EXPORT Jatta::Matrix Jatta::Assimp::Bone::GetOffsetMatrix()
{
	return Jatta::Matrix(*bone->mOffsetMatrix[0], *bone->mOffsetMatrix[1], *bone->mOffsetMatrix[2], *bone->mOffsetMatrix[3], 
		*bone->mOffsetMatrix[4], *bone->mOffsetMatrix[5], *bone->mOffsetMatrix[6], *bone->mOffsetMatrix[7], 
		*bone->mOffsetMatrix[8], *bone->mOffsetMatrix[9], *bone->mOffsetMatrix[10], *bone->mOffsetMatrix[11], 
		*bone->mOffsetMatrix[12], *bone->mOffsetMatrix[13], *bone->mOffsetMatrix[14], *bone->mOffsetMatrix[15]);
}
