// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file MaterialProperty.cpp
 */

#include "MaterialProperty.hpp"

_CGUL_EXPORT CGUL::Assimp::MaterialProperty::MaterialProperty(::aiMaterialProperty* matProp)
{
    this->matProp = matProp;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::MaterialProperty::GetKey()
{
    return String(matProp->mKey.data);
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::MaterialProperty::GetSemantic()
{
    return matProp->mSemantic;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::MaterialProperty::GetIndex()
{
    return matProp->mIndex;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::MaterialProperty::GetDataLength()
{
    return matProp->mDataLength;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::MaterialProperty::GetType()
{
    return matProp->mType;
}

_CGUL_EXPORT char* CGUL::Assimp::MaterialProperty::GetData()
{
    return matProp->mData;
}
