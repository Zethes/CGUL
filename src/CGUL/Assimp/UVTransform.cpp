// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file UVTransform.cpp
 */

#include "UVTransform.hpp"

_CGUL_EXPORT CGUL::Assimp::UVTransform::UVTransform(::aiUVTransform* uvTransform)
{
    this->uvTransform = uvTransform;
}

_CGUL_EXPORT CGUL::Vector2 CGUL::Assimp::UVTransform::GetTranslation()
{
    return Vector2(uvTransform->mTranslation.x, uvTransform->mTranslation.y);
}

_CGUL_EXPORT CGUL::Vector2 CGUL::Assimp::UVTransform::GetScaling()
{
    return Vector2(uvTransform->mScaling.x, uvTransform->mScaling.y);
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::UVTransform::GetRotation()
{
    return uvTransform->mRotation;
}
