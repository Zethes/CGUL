/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Material.h"

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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

_JATTA_EXPORT Jatta::Assimp::Material::Material(aiMaterial* material)
{
    this->material = material;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Material::GetTextureCount(Enum type)
{
    return material->GetTextureCount((aiTextureType)type);
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Material::GetTexturePath(Enum type, UInt32 index)
{
    aiString path;
    material->GetTexture((aiTextureType)type, index, &path);
    return String(path.C_Str());
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Material::GetTextureMapping(Enum type, UInt32 index)
{
    aiTextureMapping value;
    material->GetTexture((aiTextureType)type, index, NULL, &value);
    return (UInt32)value;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Material::GetTextureUVIndex(Enum type, UInt32 index)
{
    UInt32 value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, &value);
    return value;
}
_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::Material::GetTextureBlendFactor(Enum type, UInt32 index)
{
    Float32 value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, NULL, &value);
    return value;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Material::GetTextureOp(Enum type, UInt32 index)
{
    aiTextureOp value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, NULL, NULL, &value);
    return (UInt32)value;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Material::GetTextureMapMode(Enum type, UInt32 index)
{
    aiTextureMapMode value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, NULL, NULL, NULL, &value);
    return (UInt32)value;
}

template <typename Type>
_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Material::Get(const char* key, UInt32 type, UInt32 idx, Type* out, UInt32* max) const
{
    aiReturn ret = material->Get(key, type, idx, out, max);
    return (SInt32)ret;
}

template <typename Type>
_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Material::Get(const char* key, UInt32 type, UInt32 idx, Type& out) const
{
    aiReturn ret = material->Get(key, type, idx, out);
    return (SInt32)ret;
}