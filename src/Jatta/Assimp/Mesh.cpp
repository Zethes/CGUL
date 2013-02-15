/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Mesh.h"

_JATTA_EXPORT Jatta::Assimp::Mesh::Mesh(aiMesh* mesh)
{
    this->mesh = mesh;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Mesh::GetName()
{
    return String(mesh->mName.C_Str());
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Mesh::HasBones() const
{
    return mesh->HasBones();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Mesh::HasFaces() const
{
    return mesh->HasFaces();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Mesh::HasNormals() const
{
    return mesh->HasNormals();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Mesh::HasPositions() const
{
    return mesh->HasPositions();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Mesh::HasTangentsAndBitangents() const
{
    return mesh->HasTangentsAndBitangents();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Mesh::HasTextureCoords(UInt32 index) const
{
    return mesh->HasTextureCoords(index);
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Mesh::HasVertexColors(UInt32 index) const
{
    return mesh->HasVertexColors(index);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetBoneCount() const
{
    return mesh->mNumBones;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetFaceCount() const
{
    return mesh->mNumFaces;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetUVComponentsCount() const
{
    return mesh->mNumUVComponents[0]; // TODO: input this index
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetVertexCount() const
{
    return mesh->mNumVertices;
}

_JATTA_EXPORT Jatta::Float3* Jatta::Assimp::Mesh::GetPositions() const
{
    return (Float3*)mesh->mVertices;
}
_JATTA_EXPORT Jatta::Assimp::Bone* Jatta::Assimp::Mesh::GetBones() const
{
	return (Bone*)mesh->mBones;
}

_JATTA_EXPORT Jatta::Float3* Jatta::Assimp::Mesh::GetTextureCoords() const
{
    return (Float3*)mesh->mTextureCoords[0];
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetMaterialIndex() const
{
    return mesh->mMaterialIndex;
}
