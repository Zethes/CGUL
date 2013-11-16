/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Node.h"

_JATTA_EXPORT Jatta::Assimp::Node::Node(aiNode* node)
{
    this->node = node;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Node::GetName() const
{
    return String(node->mName.C_Str());
}

_JATTA_EXPORT Jatta::Matrix Jatta::Assimp::Node::GetTransformation() const
{
    // TODO: make sure this order is correct, the matrix constructor is changing in the mathfix branch
    return Jatta::Matrix(*node->mTransformation[ 0], *node->mTransformation[ 1], *node->mTransformation[ 2], *node->mTransformation[ 3],
                         *node->mTransformation[ 4], *node->mTransformation[ 5], *node->mTransformation[ 6], *node->mTransformation[ 7],
                         *node->mTransformation[ 8], *node->mTransformation[ 9], *node->mTransformation[10], *node->mTransformation[11],
                         *node->mTransformation[12], *node->mTransformation[13], *node->mTransformation[14], *node->mTransformation[15]);
}

_JATTA_EXPORT Jatta::Assimp::Node Jatta::Assimp::Node::GetParent() const
{
    return Node(node->mParent);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Node::GetChildrenCount() const
{
    return node->mNumChildren;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Node::GetMeshesCount() const
{
    return node->mNumMeshes;
}

_JATTA_EXPORT Jatta::Assimp::Node Jatta::Assimp::Node::GetChild(UInt32 index) const
{
    return Node(node->mChildren[index]);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Node::GetMesh(UInt32 index) const
{
    return node->mMeshes[index];
}

_JATTA_EXPORT Jatta::Assimp::Node Jatta::Assimp::Node::FindNode(String name)
{
    return Node(node->FindNode(name.GetCString()));
}
