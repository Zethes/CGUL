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

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetUVComponentsCount(UInt32 index) const
{
    return mesh->mNumUVComponents[index];
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetVertexCount() const
{
    return mesh->mNumVertices;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetUVChannelsCount() const
{
    return mesh->GetNumUVChannels();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetColorChannelsCount() const
{
    return mesh->GetNumColorChannels();
}

_JATTA_EXPORT Jatta::Vector3* Jatta::Assimp::Mesh::GetPositions() const
{
    return (Vector3*)mesh->mVertices;
}
_JATTA_EXPORT Jatta::Vector3* Jatta::Assimp::Mesh::GetNormals() const
{
    return (Vector3*)mesh->mNormals;
}
_JATTA_EXPORT Jatta::Vector3* Jatta::Assimp::Mesh::GetTangents() const
{
    return (Vector3*)mesh->mTangents;
}
_JATTA_EXPORT Jatta::Vector3* Jatta::Assimp::Mesh::GetBitangents() const
{
    return (Vector3*)mesh->mBitangents;
}
_JATTA_EXPORT Jatta::Color* Jatta::Assimp::Mesh::GetColors(UInt32 index) const
{
    return (Color*)mesh->mColors[index];
}
_JATTA_EXPORT Jatta::Assimp::Bone* Jatta::Assimp::Mesh::GetBones() const
{
	return (Bone*)mesh->mBones;
}
_JATTA_EXPORT Jatta::Assimp::Face* Jatta::Assimp::Mesh::GetFaces() const
{
    Face* faces = new Face[mesh->mNumFaces];
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        faces[i] = Face(&mesh->mFaces[i]);

    return faces;
}

_JATTA_EXPORT Jatta::Vector3* Jatta::Assimp::Mesh::GetTextureCoords(UInt32 index) const
{
    return (Vector3*)mesh->mTextureCoords[index];
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetMaterialIndex() const
{
    return mesh->mMaterialIndex;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Mesh::GetPrimitiveTypes() const
{
    if (mesh->mPrimitiveTypes == 0x1)
        return 0x0;
    else if (mesh->mPrimitiveTypes == 0x2)
        return 0x1;
    else if (mesh->mPrimitiveTypes == 0x4)
        return 0x4;
    else if (mesh->mPrimitiveTypes == 0x8)
        return 0x9;
    return 0;
}
