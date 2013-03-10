/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Float2.h"
#include "../Utility/String.h"
#include "../Assimp/Assimp.h"
#include "MaterialEnums.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class UVTransform;
        class MaterialProperty;

        class Material
        {
            _JATTA_AIMATERIAL material;
        public:
            _JATTA_EXPORT Material(_JATTA_AIMATERIAL material);

            _JATTA_EXPORT UInt32 GetPropertiesCount();
            _JATTA_EXPORT MaterialProperty** GetProperties();

            _JATTA_EXPORT UInt32 GetTextureCount(Enum type);
            _JATTA_EXPORT Jatta::String GetTexturePath(Enum type, UInt32 index);
            _JATTA_EXPORT UInt32 GetTextureMapping(Enum type, UInt32 index);
            _JATTA_EXPORT UInt32 GetTextureUVIndex(Enum type, UInt32 index);
            _JATTA_EXPORT Float32 GetTextureBlendFactor(Enum type, UInt32 index);
            _JATTA_EXPORT UInt32 GetTextureOp(Enum type, UInt32 index);
            _JATTA_EXPORT UInt32 GetTextureMapMode(Enum type, UInt32 index);

            template <typename Type>
            _JATTA_EXPORT SInt32 Get(const char* key, UInt32 type, UInt32 idx, Type* out, UInt32* max) const;

            template <typename Type>
            _JATTA_EXPORT SInt32 Get(const char* key, UInt32 type, UInt32 idx, Type& out) const;  
        };
    }
}

#include "../External/Undefines.h"