/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Assimp.h"
#include "SceneFlags.h"
#include "../Math/Matrix.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class Camera;
        class Light;
        class Material;
        class Mesh;
        class Node;
        class Texture;
        class Animation;

        class Scene
        {
            friend class Importer;
            friend class Exporter;
            const _JATTA_AISCENE scene;
        public:
            _JATTA_EXPORT Scene();
            _JATTA_EXPORT Scene(_JATTA_AISCENE scene);
            _JATTA_EXPORT Scene(const _JATTA_AISCENE scene);

            _JATTA_EXPORT UInt32 GetFlags() const;

            _JATTA_EXPORT void Import(const String& fileName, Enum flags);
            _JATTA_EXPORT void ImportFromMemory(const char* buffer, Jatta::UInt32 size, Enum flags);

            _JATTA_EXPORT Boolean HasAnimations() const;
            _JATTA_EXPORT Boolean HasCameras() const;
            _JATTA_EXPORT Boolean HasLights() const;
            _JATTA_EXPORT Boolean HasMaterials() const;
            _JATTA_EXPORT Boolean HasMeshes() const;
            _JATTA_EXPORT Boolean HasTextures() const;

            _JATTA_EXPORT UInt32 GetAnimationCount() const;
            _JATTA_EXPORT UInt32 GetCameraCount() const;
            _JATTA_EXPORT UInt32 GetLightCount() const;
            _JATTA_EXPORT UInt32 GetMaterialCount() const;
            _JATTA_EXPORT UInt32 GetMeshCount() const;
            _JATTA_EXPORT UInt32 GetTextureCount() const;
            
            _JATTA_EXPORT Jatta::Matrix GetSceneTransformation() const;
 
            _JATTA_EXPORT Node GetRootNode() const;

            _JATTA_EXPORT Animation GetAnimation(UInt32 index) const;
            _JATTA_EXPORT Camera GetCamera(UInt32 index) const;
            _JATTA_EXPORT Light GetLight(UInt32 index) const;
            _JATTA_EXPORT Material GetMaterial(UInt32 index) const;
            _JATTA_EXPORT Mesh GetMesh(UInt32 index) const;
            _JATTA_EXPORT Texture GetTexture(UInt32 index) const;
        };
    }
}

#include "../External/Undefines.h"
