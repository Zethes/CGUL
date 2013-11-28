// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Mesh.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Bone.hpp"
#include "Face.hpp"
#include "../Math/Vector3.hpp"
#include "../Images/Color.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class Mesh
        {
            _CGUL_AIMESH mesh;
        public:
            _CGUL_EXPORT Mesh(_CGUL_AIMESH mesh);

            _CGUL_EXPORT String GetName();

            _CGUL_EXPORT Boolean HasBones() const;
            _CGUL_EXPORT Boolean HasFaces() const;
            _CGUL_EXPORT Boolean HasNormals() const;
            _CGUL_EXPORT Boolean HasPositions() const;
            _CGUL_EXPORT Boolean HasTangentsAndBitangents() const;
            _CGUL_EXPORT Boolean HasTextureCoords(UInt32 index) const;
            _CGUL_EXPORT Boolean HasVertexColors(UInt32 index) const;

            _CGUL_EXPORT UInt32 GetBoneCount() const;
            _CGUL_EXPORT UInt32 GetFaceCount() const;
            _CGUL_EXPORT UInt32 GetUVComponentsCount(UInt32 index) const;
            _CGUL_EXPORT UInt32 GetVertexCount() const;
            _CGUL_EXPORT UInt32 GetUVChannelsCount() const;
            _CGUL_EXPORT UInt32 GetColorChannelsCount() const;

            _CGUL_EXPORT Vector3* GetPositions() const;
            _CGUL_EXPORT Vector3* GetNormals() const;
            _CGUL_EXPORT Vector3* GetTangents() const;
            _CGUL_EXPORT Vector3* GetBitangents() const;
            _CGUL_EXPORT Vector3* GetTextureCoords(UInt32 index) const;
            _CGUL_EXPORT Color* GetColors(UInt32 index) const;
            _CGUL_EXPORT Bone* GetBones() const;
            _CGUL_EXPORT Face* GetFaces() const;

            _CGUL_EXPORT UInt32 GetMaterialIndex() const;
            _CGUL_EXPORT UInt32 GetPrimitiveTypes() const;
        };
    }
}

#include "../External/Undefines.hpp"
