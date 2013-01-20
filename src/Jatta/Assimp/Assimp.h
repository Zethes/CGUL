    /* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#pragma once
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    /** @brief Experimental Assimp wrapper.
     */
    namespace Assimp
    {
        class Test
        {
        public:
            _JATTA_EXPORT static void DoStuff();
        };
        typedef UInt32 Enum;

        static Enum PROCESS_CALC_TANGENT_SPACE = 0x1;
        static Enum PROCESS_JOIN_IDENTICAL_VERTICES = 0x2;
        static Enum PROCESS_MAKE_LEFT_HANDED = 0x4;
        static Enum PROCESS_TRIANGULATE = 0x8;
        static Enum PROCESS_REMOVE_COMPONENT = 0x10;
        static Enum PROCESS_GEN_NORMALS = 0x20;
        static Enum PROCESS_GEN_SMOOTH_NORMALS = 0x40;
        static Enum PROCESS_SPLIT_LARGE_MESH = 0x80;
        static Enum PROCESS_PRE_TRANSFORM_VERTICES = 0x100;
        static Enum PROCESS_LIMIT_BONE_WEIGHTS = 0x200;
        static Enum PROCESS_VALIDATE_DATA_STRUCTURE = 0x400;
        static Enum PROCESS_IMPROVE_CACHE_LOCALITY = 0x800;
        static Enum PROCESS_REMOVE_REDUNDANT_MATERIALS = 0x1000;
        static Enum PROCESS_FIX_INFACING_NORMALS = 0x2000;
        static Enum PROCESS_SORT_BY_PTYPE = 0x8000;
        static Enum PROCESS_FIND_DEGENERATES = 0x10000;
        static Enum PROCESS_FIND_INVALID_DATA = 0x20000;
        static Enum PROCESS_GEN_UV_COORDS = 0x40000;
        static Enum PROCESS_TRANSFORM_UV_COORDS = 0x80000;
        static Enum PROCESS_FIND_INSTANCES = 0x100000;
        static Enum PROCESS_OPTIMIZE_MESHES = 0x200000;
        static Enum PROCESS_OPTIMIZE_GRAPH = 0x400000;
        static Enum PROCESS_FLIP_UVS = 0x800000;
        static Enum PROCESS_FLIP_WINDING_ORDER = 0x1000000;
        static Enum PROCESS_SPLIT_BY_BONE_COUNT = 0x2000000;
        static Enum PROCESS_DEBONE = 0x4000000;

        static Enum TEXTURE_TYPE_NONE = 0x0;
        static Enum TEXTURE_TYPE_DIFFUSE = 0x1;
        static Enum TEXTURE_TYPE_SPECULAR = 0x2;
        static Enum TEXTURE_TYPE_AMBIENT = 0x3;
        static Enum TEXTURE_TYPE_EMISSIVE = 0x4;
        static Enum TEXTURE_TYPE_HEIGHT = 0x5;
        static Enum TEXTURE_TYPE_NORMALS = 0x6;
        static Enum TEXTURE_TYPE_SHININESS = 0x7;
        static Enum TEXTURE_TYPE_OPACITY = 0x8;
        static Enum TEXTURE_TYPE_DISPLACEMENT = 0x9;
        static Enum TEXTURE_TYPE_LIGHTMAP = 0xa;
        static Enum TEXTURE_TYPE_REFLECTION = 0xb;
        static Enum TEXTURE_TYPE_UNKNOWN = 0xc;
    }
}

#include "../External/Undefines.h"
#endif
