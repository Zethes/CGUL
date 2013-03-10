/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "MaterialProperty.h"

_JATTA_EXPORT Jatta::Assimp::MaterialProperty::MaterialProperty(::aiMaterialProperty* matProp)
{
    this->matProp = matProp;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::MaterialProperty::GetKey()
{
    return String(matProp->mKey.data);
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::MaterialProperty::GetSemantic()
{
    return matProp->mSemantic;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::MaterialProperty::GetIndex()
{
    return matProp->mIndex;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::MaterialProperty::GetDataLength()
{
    return matProp->mDataLength;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::MaterialProperty::GetType()
{
    return matProp->mType;
}
_JATTA_EXPORT char* Jatta::Assimp::MaterialProperty::GetData()
{
    return matProp->mData;
}