// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Material.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Math/Vector2.hpp"
#include "../Utility/String.hpp"
#include "../Assimp/Assimp.hpp"
#include "MaterialEnums.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class UVTransform;
        class MaterialProperty;

        class Material
        {
            _CGUL_AIMATERIAL material;
        public:
            _CGUL_EXPORT Material(_CGUL_AIMATERIAL material);

            _CGUL_EXPORT UInt32 GetPropertiesCount();
            _CGUL_EXPORT MaterialProperty** GetProperties();

            _CGUL_EXPORT UInt32 GetTextureCount(Enum type);
            _CGUL_EXPORT CGUL::String GetTexturePath(Enum type, UInt32 index);
            _CGUL_EXPORT UInt32 GetTextureMapping(Enum type, UInt32 index);
            _CGUL_EXPORT UInt32 GetTextureUVIndex(Enum type, UInt32 index);
            _CGUL_EXPORT Float32 GetTextureBlendFactor(Enum type, UInt32 index);
            _CGUL_EXPORT UInt32 GetTextureOp(Enum type, UInt32 index);
            _CGUL_EXPORT UInt32 GetTextureMapMode(Enum type, UInt32 index);

            template <typename Type>
            _CGUL_EXPORT SInt32 Get(const char* key, UInt32 type, UInt32 idx, Type* out, UInt32* max) const;

            template <typename Type>
            _CGUL_EXPORT SInt32 Get(const char* key, UInt32 type, UInt32 idx, Type& out) const;
        };
    }
}

#include "../External/Undefines.hpp"
