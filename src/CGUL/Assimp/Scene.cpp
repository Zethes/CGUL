// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Scene.cpp
 */

#include "Scene.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Material.hpp"
#include "Mesh.hpp"
#include "Node.hpp"
#include "Texture.hpp"
#include "Animation.hpp"

/** @brief Just a test.
 */
_CGUL_EXPORT CGUL::Assimp::Scene::Scene()
{
    scene = NULL;
}

_CGUL_EXPORT CGUL::Assimp::Scene::Scene(::aiScene* scene)
{
    this->scene = scene;
}

_CGUL_EXPORT CGUL::Assimp::Scene::Scene(const ::aiScene* scene)
{
    this->scene = scene;
}

_CGUL_EXPORT void CGUL::Assimp::Scene::Import(const String& fileName, UInt32 flags)
{
    scene = aiImportFile(fileName.GetData().c_str(), flags);
    if (scene == NULL)
    {
        throw std::runtime_error(aiGetErrorString());
    }
}

_CGUL_EXPORT void CGUL::Assimp::Scene::ImportFromMemory(const char* buffer, CGUL::UInt32 size, Enum flags)
{
    scene = aiImportFileFromMemory(buffer, size, flags, "");
    if (scene == NULL)
    {
        throw std::runtime_error(aiGetErrorString());
    }
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Scene::HasAnimations() const
{
    return scene->HasAnimations();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Scene::HasCameras() const
{
    return scene->HasCameras();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Scene::HasLights() const
{
    return scene->HasLights();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Scene::HasMaterials() const
{
    return scene->HasMaterials();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Scene::HasMeshes() const
{
    return scene->HasMeshes();
}

_CGUL_EXPORT CGUL::Boolean CGUL::Assimp::Scene::HasTextures() const
{
    return scene->HasTextures();
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Scene::GetAnimationCount() const
{
    return scene->mNumAnimations;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Scene::GetCameraCount() const
{
    return scene->mNumCameras;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Scene::GetLightCount() const
{
    return scene->mNumLights;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Scene::GetMaterialCount() const
{
    return scene->mNumMaterials;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Scene::GetMeshCount() const
{
    return scene->mNumMeshes;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Scene::GetTextureCount() const
{
    return scene->mNumTextures;
}

_CGUL_EXPORT CGUL::Matrix CGUL::Assimp::Scene::GetSceneTransformation() const
{
    // TODO: make sure this order is correct, the matrix constructor is changing in the mathfix branch
    return CGUL::Matrix(*scene->mRootNode->mTransformation[ 0], *scene->mRootNode->mTransformation[ 1], *scene->mRootNode->mTransformation[ 2], *scene->mRootNode->mTransformation[ 3],
                        *scene->mRootNode->mTransformation[ 4], *scene->mRootNode->mTransformation[ 5], *scene->mRootNode->mTransformation[ 6], *scene->mRootNode->mTransformation[ 7],
                        *scene->mRootNode->mTransformation[ 8], *scene->mRootNode->mTransformation[ 9], *scene->mRootNode->mTransformation[10], *scene->mRootNode->mTransformation[11],
                        *scene->mRootNode->mTransformation[12], *scene->mRootNode->mTransformation[13], *scene->mRootNode->mTransformation[14], *scene->mRootNode->mTransformation[15]);
}

_CGUL_EXPORT CGUL::Assimp::Node CGUL::Assimp::Scene::GetRootNode() const
{
    return Node(scene->mRootNode);
}

_CGUL_EXPORT CGUL::Assimp::Camera CGUL::Assimp::Scene::GetCamera(UInt32 index) const
{
    return Camera(scene->mCameras[index]);
}

_CGUL_EXPORT CGUL::Assimp::Light CGUL::Assimp::Scene::GetLight(UInt32 index) const
{
    return Light(scene->mLights[index]);
}

_CGUL_EXPORT CGUL::Assimp::Material CGUL::Assimp::Scene::GetMaterial(UInt32 index) const
{
    return Material(scene->mMaterials[index]);
}

_CGUL_EXPORT CGUL::Assimp::Mesh CGUL::Assimp::Scene::GetMesh(UInt32 index) const
{
    return Mesh(scene->mMeshes[index]);
}

_CGUL_EXPORT CGUL::Assimp::Texture CGUL::Assimp::Scene::GetTexture(UInt32 index) const
{
    return Texture(scene->mTextures[index]);
}

_CGUL_EXPORT CGUL::Assimp::Animation CGUL::Assimp::Scene::GetAnimation(UInt32 index) const
{
    return Animation(scene->mAnimations[index]);
}
