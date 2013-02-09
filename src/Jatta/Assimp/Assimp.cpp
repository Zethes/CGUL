/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#include "Assimp.h"
#include <iostream>

#define OUTPUT(x) std::cout << #x << ": " << std::hex << x << std::endl;

/** @brief Just a test.
 */
_JATTA_EXPORT void Jatta::Assimp::Test::DoStuff()
{
    /*OUTPUT(aiProcess_CalcTangentSpace);
    OUTPUT(aiProcess_JoinIdenticalVertices);
    OUTPUT(aiProcess_MakeLeftHanded);
    OUTPUT(aiProcess_Triangulate);
    OUTPUT(aiProcess_RemoveComponent);
    OUTPUT(aiProcess_GenNormals);
    OUTPUT(aiProcess_GenSmoothNormals);
    OUTPUT(aiProcess_SplitLargeMeshes);
    OUTPUT(aiProcess_PreTransformVertices);
    OUTPUT(aiProcess_LimitBoneWeights);
    OUTPUT(aiProcess_ValidateDataStructure);
    OUTPUT(aiProcess_ImproveCacheLocality);
    OUTPUT(aiProcess_RemoveRedundantMaterials);
    OUTPUT(aiProcess_FixInfacingNormals);
    OUTPUT(aiProcess_SortByPType);
    OUTPUT(aiProcess_FindDegenerates);
    OUTPUT(aiProcess_FindInvalidData);
    OUTPUT(aiProcess_GenUVCoords);
    OUTPUT(aiProcess_TransformUVCoords);
    OUTPUT(aiProcess_FindInstances);
    OUTPUT(aiProcess_OptimizeMeshes);
    OUTPUT(aiProcess_OptimizeGraph);
    OUTPUT(aiProcess_FlipUVs);
    OUTPUT(aiProcess_FlipWindingOrder);
    OUTPUT(aiProcess_SplitByBoneCount);
    OUTPUT(aiProcess_Debone);*/

    OUTPUT(aiTextureType_NONE);
    OUTPUT(aiTextureType_DIFFUSE);
    OUTPUT(aiTextureType_SPECULAR);
    OUTPUT(aiTextureType_AMBIENT);
    OUTPUT(aiTextureType_EMISSIVE);
    OUTPUT(aiTextureType_HEIGHT);
    OUTPUT(aiTextureType_NORMALS);
    OUTPUT(aiTextureType_SHININESS);
    OUTPUT(aiTextureType_OPACITY);
    OUTPUT(aiTextureType_DISPLACEMENT);
    OUTPUT(aiTextureType_LIGHTMAP);
    OUTPUT(aiTextureType_REFLECTION);
    OUTPUT(aiTextureType_UNKNOWN);
}

#endif
