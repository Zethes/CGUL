// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Scene.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Assimp.hpp"
#include "SceneFlags.hpp"
#include "../Math/Matrix.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
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
            const _CGUL_AISCENE scene;
        public:
            _CGUL_EXPORT Scene();
            _CGUL_EXPORT Scene(_CGUL_AISCENE scene);
            _CGUL_EXPORT Scene(const _CGUL_AISCENE scene);

            _CGUL_EXPORT UInt32 GetFlags() const;

            _CGUL_EXPORT void Import(const String& fileName, Enum flags);
            _CGUL_EXPORT void ImportFromMemory(const char* buffer, CGUL::UInt32 size, Enum flags);

            _CGUL_EXPORT Boolean HasAnimations() const;
            _CGUL_EXPORT Boolean HasCameras() const;
            _CGUL_EXPORT Boolean HasLights() const;
            _CGUL_EXPORT Boolean HasMaterials() const;
            _CGUL_EXPORT Boolean HasMeshes() const;
            _CGUL_EXPORT Boolean HasTextures() const;

            _CGUL_EXPORT UInt32 GetAnimationCount() const;
            _CGUL_EXPORT UInt32 GetCameraCount() const;
            _CGUL_EXPORT UInt32 GetLightCount() const;
            _CGUL_EXPORT UInt32 GetMaterialCount() const;
            _CGUL_EXPORT UInt32 GetMeshCount() const;
            _CGUL_EXPORT UInt32 GetTextureCount() const;

            _CGUL_EXPORT CGUL::Matrix GetSceneTransformation() const;

            _CGUL_EXPORT Node GetRootNode() const;

            _CGUL_EXPORT Animation GetAnimation(UInt32 index) const;
            _CGUL_EXPORT Camera GetCamera(UInt32 index) const;
            _CGUL_EXPORT Light GetLight(UInt32 index) const;
            _CGUL_EXPORT Material GetMaterial(UInt32 index) const;
            _CGUL_EXPORT Mesh GetMesh(UInt32 index) const;
            _CGUL_EXPORT Texture GetTexture(UInt32 index) const;
        };
    }
}

#include "../External/Undefines.hpp"
