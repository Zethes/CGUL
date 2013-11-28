// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Mesh.cpp
 */

#include "Mesh.hpp"

_CGUL_EXPORT CGUL::Assimp::Mesh::Mesh(aiMesh* mesh)
{
    this->mesh = mesh;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Mesh::GetName()
{
    return String(mesh->mName.C_Str());
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Mesh::HasBones() const
{
    return mesh->HasBones();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Mesh::HasFaces() const
{
    return mesh->HasFaces();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Mesh::HasNormals() const
{
    return mesh->HasNormals();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Mesh::HasPositions() const
{
    return mesh->HasPositions();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Mesh::HasTangentsAndBitangents() const
{
    return mesh->HasTangentsAndBitangents();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Mesh::HasTextureCoords(UInt32 index) const
{
    return mesh->HasTextureCoords(index);
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Mesh::HasVertexColors(UInt32 index) const
{
    return mesh->HasVertexColors(index);
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetBoneCount() const
{
    return mesh->mNumBones;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetFaceCount() const
{
    return mesh->mNumFaces;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetUVComponentsCount(UInt32 index) const
{
    return mesh->mNumUVComponents[index];
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetVertexCount() const
{
    return mesh->mNumVertices;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetUVChannelsCount() const
{
    return mesh->GetNumUVChannels();
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetColorChannelsCount() const
{
    return mesh->GetNumColorChannels();
}

_CGUL_EXPORT CGUL::Vector3* CGUL::Assimp::Mesh::GetPositions() const
{
    return reinterpret_cast<Vector3*>(mesh->mVertices);
}

_CGUL_EXPORT CGUL::Vector3* CGUL::Assimp::Mesh::GetNormals() const
{
    return reinterpret_cast<Vector3*>(mesh->mNormals);
}

_CGUL_EXPORT CGUL::Vector3* CGUL::Assimp::Mesh::GetTangents() const
{
    return reinterpret_cast<Vector3*>(mesh->mTangents);
}

_CGUL_EXPORT CGUL::Vector3* CGUL::Assimp::Mesh::GetBitangents() const
{
    return reinterpret_cast<Vector3*>(mesh->mBitangents);
}

_CGUL_EXPORT CGUL::Color* CGUL::Assimp::Mesh::GetColors(UInt32 index) const
{
    return reinterpret_cast<Color*>(mesh->mColors[index]);
}

_CGUL_EXPORT CGUL::Assimp::Bone* CGUL::Assimp::Mesh::GetBones() const
{
    return reinterpret_cast<Bone*>(mesh->mBones);
}

_CGUL_EXPORT CGUL::Assimp::Face* CGUL::Assimp::Mesh::GetFaces() const
{
    Face* faces = new Face[mesh->mNumFaces];
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        faces[i] = Face(&mesh->mFaces[i]);
    }

    return faces;
}

_CGUL_EXPORT CGUL::Vector3* CGUL::Assimp::Mesh::GetTextureCoords(UInt32 index) const
{
    return reinterpret_cast<Vector3*>(mesh->mTextureCoords[index]);
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetMaterialIndex() const
{
    return mesh->mMaterialIndex;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Mesh::GetPrimitiveTypes() const
{
    if (mesh->mPrimitiveTypes == 0x1)
    {
        return 0x0;
    }
    else if (mesh->mPrimitiveTypes == 0x2)
    {
        return 0x1;
    }
    else if (mesh->mPrimitiveTypes == 0x4)
    {
        return 0x4;
    }
    else if (mesh->mPrimitiveTypes == 0x8)
    {
        return 0x9;
    }
    return 0;
}
