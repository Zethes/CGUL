/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Bone.h"
#include "../Math/Float3.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        // TODO: finish importing methods from aiMesh
        class Mesh
        {
        private:
            _JATTA_AIMESH mesh;
        public:
            _JATTA_EXPORT Mesh(_JATTA_AIMESH mesh);

            _JATTA_EXPORT String GetName();

            _JATTA_EXPORT Boolean HasBones() const;
            _JATTA_EXPORT Boolean HasFaces() const;
            _JATTA_EXPORT Boolean HasNormals() const;
            _JATTA_EXPORT Boolean HasPositions() const;
            _JATTA_EXPORT Boolean HasTangentsAndBitangents() const;
            _JATTA_EXPORT Boolean HasTextureCoords(UInt32 index) const;
            _JATTA_EXPORT Boolean HasVertexColors(UInt32 index) const;

            _JATTA_EXPORT UInt32 GetBoneCount() const;
            _JATTA_EXPORT UInt32 GetFaceCount() const;
            _JATTA_EXPORT UInt32 GetUVComponentsCount() const;
            _JATTA_EXPORT UInt32 GetVertexCount() const;

            _JATTA_EXPORT Float3* GetPositions() const;
            _JATTA_EXPORT Float3* GetTextureCoords() const;
            _JATTA_EXPORT Bone* GetBones() const;

            _JATTA_EXPORT UInt32 GetMaterialIndex() const;

            // GetPrimitiveTypes
        };
    }
}

#include "../External/Undefines.h"
