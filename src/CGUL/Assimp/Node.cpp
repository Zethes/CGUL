// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Node.cpp
 */

#include "Node.hpp"

_CGUL_EXPORT CGUL::Assimp::Node::Node(aiNode* node)
{
    this->node = node;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Node::GetName() const
{
    return String(node->mName.C_Str());
}

_CGUL_EXPORT CGUL::Matrix CGUL::Assimp::Node::GetTransformation() const
{
    // TODO: make sure this order is correct, the matrix constructor is changing in the mathfix branch
    return CGUL::Matrix(*node->mTransformation[ 0], *node->mTransformation[ 1], *node->mTransformation[ 2], *node->mTransformation[ 3],
                         *node->mTransformation[ 4], *node->mTransformation[ 5], *node->mTransformation[ 6], *node->mTransformation[ 7],
                         *node->mTransformation[ 8], *node->mTransformation[ 9], *node->mTransformation[10], *node->mTransformation[11],
                         *node->mTransformation[12], *node->mTransformation[13], *node->mTransformation[14], *node->mTransformation[15]);
}

_CGUL_EXPORT CGUL::Assimp::Node CGUL::Assimp::Node::GetParent() const
{
    return Node(node->mParent);
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Node::GetChildrenCount() const
{
    return node->mNumChildren;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Node::GetMeshesCount() const
{
    return node->mNumMeshes;
}

_CGUL_EXPORT CGUL::Assimp::Node CGUL::Assimp::Node::GetChild(UInt32 index) const
{
    return Node(node->mChildren[index]);
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Node::GetMesh(UInt32 index) const
{
    return node->mMeshes[index];
}

_CGUL_EXPORT CGUL::Assimp::Node CGUL::Assimp::Node::FindNode(String name)
{
    return Node(node->FindNode(name.GetCString()));
}
