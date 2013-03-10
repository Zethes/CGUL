/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Scene.h"
#include "Camera.h"
#include "Light.h"
#include "Material.h"
#include "Mesh.h"
#include "Node.h"
#include "Texture.h"
#include "Animation.h"
 
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
 _JATTA_EXPORT void Jatta::Assimp::Scene::ImportFromMemory(const char* buffer, Jatta::UInt32 size, Enum flags)
 {
    scene = aiImportFileFromMemory(buffer, size, flags, "");
    if (scene == nullptr)
    {
        throw std::runtime_error(aiGetErrorString());
    }
 }

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasAnimations() const
{
    return scene->HasAnimations();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasCameras() const
{
    return scene->HasCameras();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasLights() const
{
    return scene->HasLights();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasMaterials() const
{
    return scene->HasMaterials();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasMeshes() const
{
    return scene->HasMeshes();
}

_JATTA_EXPORT Jatta::Boolean Jatta::Assimp::Scene::HasTextures() const
{
    return scene->HasTextures();
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetAnimationCount() const
{
    return scene->mNumAnimations;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetCameraCount() const
{
    return scene->mNumCameras;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetLightCount() const
{
    return scene->mNumLights;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetMaterialCount() const
{
    return scene->mNumMaterials;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetMeshCount() const
{
    return scene->mNumMeshes;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Scene::GetTextureCount() const
{
    return scene->mNumTextures;
}

_JATTA_EXPORT Jatta::Matrix Jatta::Assimp::Scene::GetSceneTransformation() const
{
    return Jatta::Matrix(
        *scene->mRootNode->mTransformation[0], *scene->mRootNode->mTransformation[1], *scene->mRootNode->mTransformation[2], *scene->mRootNode->mTransformation[3], 
        *scene->mRootNode->mTransformation[4], *scene->mRootNode->mTransformation[5], *scene->mRootNode->mTransformation[6], *scene->mRootNode->mTransformation[7], 
        *scene->mRootNode->mTransformation[8], *scene->mRootNode->mTransformation[9], *scene->mRootNode->mTransformation[10], *scene->mRootNode->mTransformation[11], 
        *scene->mRootNode->mTransformation[12], *scene->mRootNode->mTransformation[13], *scene->mRootNode->mTransformation[14], *scene->mRootNode->mTransformation[15]);
}

_JATTA_EXPORT Jatta::Assimp::Node Jatta::Assimp::Scene::GetRootNode() const
{
    return Node(scene->mRootNode);
}

_JATTA_EXPORT Jatta::Assimp::Camera Jatta::Assimp::Scene::GetCamera(UInt32 index) const
{
    return Camera(scene->mCameras[index]);
}

_JATTA_EXPORT Jatta::Assimp::Light Jatta::Assimp::Scene::GetLight(UInt32 index) const
{
    return Light(scene->mLights[index]);
}

_JATTA_EXPORT Jatta::Assimp::Material Jatta::Assimp::Scene::GetMaterial(UInt32 index) const
{
    return Material(scene->mMaterials[index]);
}

_JATTA_EXPORT Jatta::Assimp::Mesh Jatta::Assimp::Scene::GetMesh(UInt32 index) const
{
    return Mesh(scene->mMeshes[index]);
}

_JATTA_EXPORT Jatta::Assimp::Texture Jatta::Assimp::Scene::GetTexture(UInt32 index) const
{
    return Texture(scene->mTextures[index]);
}
_JATTA_EXPORT Jatta::Assimp::Animation Jatta::Assimp::Scene::GetAnimation(UInt32 index) const
{
    return Animation(scene->mAnimations[index]);
}
