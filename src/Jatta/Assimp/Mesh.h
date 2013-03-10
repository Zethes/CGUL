/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Bone.h"
#include "Face.h"
#include "../Math/Float3.h"
#include "../Images/Color.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
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
            _JATTA_EXPORT UInt32 GetUVComponentsCount(UInt32 index) const;
            _JATTA_EXPORT UInt32 GetVertexCount() const;
            _JATTA_EXPORT UInt32 GetUVChannelsCount() const;
            _JATTA_EXPORT UInt32 GetColorChannelsCount() const;

            _JATTA_EXPORT Float3* GetPositions() const;
            _JATTA_EXPORT Float3* GetNormals() const;
            _JATTA_EXPORT Float3* GetTangents() const;
            _JATTA_EXPORT Float3* GetBitangents() const;
            _JATTA_EXPORT Float3* GetTextureCoords(UInt32 index) const;
            _JATTA_EXPORT Color* GetColors(UInt32 index) const;
            _JATTA_EXPORT Bone* GetBones() const;
            _JATTA_EXPORT Face* GetFaces() const;

            _JATTA_EXPORT UInt32 GetMaterialIndex() const;
            _JATTA_EXPORT UInt32 GetPrimitiveTypes() const;
        };
    }
}

#include "../External/Undefines.h"
