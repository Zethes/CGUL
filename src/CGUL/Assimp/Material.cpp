// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Material.cpp
 */

#include "Material.hpp"
#include "MaterialProperty.hpp"
#include "UVTransform.hpp"

_CGUL_EXPORT CGUL::Assimp::Material::Material(aiMaterial* material)
{
    this->material = material;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Material::GetTextureCount(Enum type)
{
    return material->GetTextureCount((aiTextureType)type);
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Material::GetTexturePath(Enum type, UInt32 index)
{
    aiString path;
    material->GetTexture((aiTextureType)type, index, &path);
    return String(path.C_Str());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Material::GetTextureMapping(Enum type, UInt32 index)
{
    aiTextureMapping value;
    material->GetTexture((aiTextureType)type, index, NULL, &value);
    return (UInt32)value;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Material::GetTextureUVIndex(Enum type, UInt32 index)
{
    UInt32 value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, &value);
    return value;
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::Material::GetTextureBlendFactor(Enum type, UInt32 index)
{
    Float32 value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, NULL, &value);
    return value;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Material::GetTextureOp(Enum type, UInt32 index)
{
    aiTextureOp value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, NULL, NULL, &value);
    return (UInt32)value;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Material::GetTextureMapMode(Enum type, UInt32 index)
{
    aiTextureMapMode value;
    material->GetTexture((aiTextureType)type, index, NULL, NULL, NULL, NULL, NULL, &value);
    return (UInt32)value;
}

template <typename Type>
_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Material::Get(const char* key, UInt32 type, UInt32 idx, Type* out, UInt32* max) const
{
    aiReturn ret = material->Get(key, type, idx, out, max);
    return (SInt32)ret;
}

template <typename Type>
_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Material::Get(const char* key, UInt32 type, UInt32 idx, Type& out) const
{
    aiReturn ret = material->Get(key, type, idx, out);
    return (SInt32)ret;
}
