/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Scene.h"
#include "Mesh.h"
#include <iostream> // TODO: remove iostream

/** @brief Just a test.
 */
_JATTA_EXPORT Jatta::Assimp::Scene::Scene()
{
    scene = nullptr;
}

_JATTA_EXPORT void Jatta::Assimp::Scene::Import(const String& fileName, UInt32 flags)
{
    scene = aiImportFile(fileName.GetData().c_str(), flags);
    if (scene == nullptr)
    {
        throw std::runtime_error(aiGetErrorString());
    }
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasAnimations()
{
    return scene->HasAnimations();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasCameras()
{
    return scene->HasCameras();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasLights()
{
    return scene->HasLights();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasMaterials()
{
    return scene->HasMaterials();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasMeshes()
{
    return scene->HasMeshes();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasTextures()
{
    return scene->HasTextures();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetAnimationCount()
{
    return scene->mNumAnimations;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetCameraCount()
{
    return scene->mNumCameras;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetLightCount()
{
    return scene->mNumLights;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetMaterialCount()
{
    return scene->mNumMaterials;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetMeshCount()
{
    return scene->mNumMeshes;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetTextureCount()
{
    return scene->mNumTextures;
}

_JATTA_EXPORT Jatta::Assimp::Mesh Jatta::Assimp::Scene::GetMesh(UInt32 index)
{
    return Mesh(scene->mMeshes[index]);
}