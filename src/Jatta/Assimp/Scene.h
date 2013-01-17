/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#pragma once
#include "Assimp.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        class Mesh;

        class Scene
        {
            const _JATTA_AISCENE scene;
        public:
            _JATTA_EXPORT Scene();

            _JATTA_EXPORT void Import(const String& fileName, Enum flags);

            _JATTA_EXPORT Boolean HasAnimations();
            _JATTA_EXPORT Boolean HasCameras();
            _JATTA_EXPORT Boolean HasLights();
            _JATTA_EXPORT Boolean HasMaterials();
            _JATTA_EXPORT Boolean HasMeshes();
            _JATTA_EXPORT Boolean HasTextures();

            _JATTA_EXPORT UInt32 GetAnimationCount();
            _JATTA_EXPORT UInt32 GetCameraCount();
            _JATTA_EXPORT UInt32 GetLightCount();
            _JATTA_EXPORT UInt32 GetMaterialCount();
            _JATTA_EXPORT UInt32 GetMeshCount();
            _JATTA_EXPORT UInt32 GetTextureCount();

            _JATTA_EXPORT Mesh GetMesh(UInt32 index);
        };
    }
}

#include "../External/Undefines.h"
#endif