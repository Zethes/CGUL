/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Mesh.h"

_JATTA_EXPORT Jatta::Assimp::Mesh::Mesh(aiMesh* mesh)
{
    this->mesh = mesh;
}