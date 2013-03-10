/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Float2.h"
#include "../Utility/String.h"
#include "../Assimp/Assimp.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        enum TextureOp
        {
            MULTIPLY = 0x0,
            ADD = 0x1,
            SUBTRACT = 0x2,
            DIVIDE = 0x3,
            SMOOTH_ADD = 0x4,
            SIGNED_ADD = 0x5
        };

        enum TextureMapMode
        {
            WRAP = 0x0,
            CLAMP = 0x1,
            DECAL = 0x3,
            MIRROR = 0x2
        };

        enum TextureMapping
        {
            UV = 0x0,
            SPHERE = 0x1,
            CYLINDER = 0x2,
            BOX = 0x3,
            PLANE = 0x4,
            OTHER = 0x5
        };

        enum TextureType
        {
            NONE = 0x0,
            DIFFUSE = 0x1,
            SPECULAR = 0x2,
            AMBIENT = 0x3,
            EMISSIVE = 0x4,
            HEIGHT = 0x5,
            NORMALS = 0x6,
            SHININESS = 0x7,
            OPACITY = 0x8,
            DISPLACEMENT = 0x9,
            LIGHTMAP = 0xA,
            REFLECTION = 0xB,
            UNKNOWN = 0xC
        };

        enum ShadingMode
        {
            FLAT = 0x1,
            GOURAUD = 0x2,
            PHONG = 0x3,
            BLINN = 0x4,
            TOON = 0x5,
            OREN_NAYAR = 0x6,
            MINNAERT = 0x7,
            COOK_TORRANCE = 0x8,
            NO_SHADING = 0x9,
            FRESNEL = 0xA
        };

        enum BlendMode
        {
            DEFUALT = 0x0,
            ADDITIVE = 0x1
        };

        enum PropertyTypeInfo
        {
            FLOAT = 0x1,
            STRING = 0x3,
            INTEGER = 0x4,
            BUFFER = 0x5
        };

        enum TextureFlags
        {
            INVERT = 0x1,
            USE_ALPHA = 0x2,
            IGNORE_ALPHA = 0x4
        };

        class UVTransform
        {   
            _JATTA_AIUVTRANSFORM uvTransform;
        public:
            _JATTA_EXPORT UVTransform(_JATTA_AIUVTRANSFORM uvTransform);

            _JATTA_EXPORT Float2 GetTranslation();
            _JATTA_EXPORT Float2 GetScaling();
            _JATTA_EXPORT Float32 GetRotation();
        };

        class MaterialProperty
        {
            _JATTA_AIMATERIALPROPERTY matProp;
        public:
            _JATTA_EXPORT MaterialProperty(_JATTA_AIMATERIALPROPERTY matProp);

            _JATTA_EXPORT String GetKey();
            _JATTA_EXPORT UInt32 GetSemantic();
            _JATTA_EXPORT UInt32 GetIndex();

            _JATTA_EXPORT UInt32 GetDataLength();
            _JATTA_EXPORT UInt32 GetType();
            _JATTA_EXPORT char* GetData();
        };

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