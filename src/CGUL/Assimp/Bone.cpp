// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Bone.cpp
 */

#include "Bone.hpp"

_CGUL_EXPORT CGUL::Assimp::Bone::Bone(aiBone* bone)
{
    this->bone = bone;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Bone::GetName()
{
    return String(bone->mName.C_Str());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Bone::GetWeightCount()
{
    return bone->mNumWeights;
}

_CGUL_EXPORT CGUL::Assimp::VertexWeight CGUL::Assimp::Bone::GetWeight(CGUL::UInt32 id)
{
    return VertexWeight(&bone->mWeights[id]);
}

_CGUL_EXPORT CGUL::Matrix CGUL::Assimp::Bone::GetOffsetMatrix()
{
    // TODO: make sure this order is correct, the matrix constructor is changing in the mathfix branch
    return CGUL::Matrix(*bone->mOffsetMatrix[ 0], *bone->mOffsetMatrix[ 1], *bone->mOffsetMatrix[ 2], *bone->mOffsetMatrix[ 3],
                        *bone->mOffsetMatrix[ 4], *bone->mOffsetMatrix[ 5], *bone->mOffsetMatrix[ 6], *bone->mOffsetMatrix[ 7],
                        *bone->mOffsetMatrix[ 8], *bone->mOffsetMatrix[ 9], *bone->mOffsetMatrix[10], *bone->mOffsetMatrix[11],
                        *bone->mOffsetMatrix[12], *bone->mOffsetMatrix[13], *bone->mOffsetMatrix[14], *bone->mOffsetMatrix[15]);
}
