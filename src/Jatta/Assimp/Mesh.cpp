/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#include "Mesh.h"

_JATTA_EXPORT Jatta::Assimp::Mesh::Mesh(aiMesh* mesh)
{
    this->mesh = mesh;
}

#endif