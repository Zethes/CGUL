/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "UVTransform.h"

_JATTA_EXPORT Jatta::Assimp::UVTransform::UVTransform(::aiUVTransform* uvTransform)
{
    this->uvTransform = uvTransform;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Assimp::UVTransform::GetTranslation()
{
    return Float2(uvTransform->mTranslation.x, uvTransform->mTranslation.y);
}
_JATTA_EXPORT Jatta::Float2 Jatta::Assimp::UVTransform::GetScaling()
{
    return Float2(uvTransform->mScaling.x, uvTransform->mScaling.y);
}
_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::UVTransform::GetRotation()
{
    return uvTransform->mRotation;
}
