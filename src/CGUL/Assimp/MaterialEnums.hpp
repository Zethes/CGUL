/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Math/Vector2.h"
#include "../External/Defines.h"

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
    }
}

#include "../External/Undefines.h"
