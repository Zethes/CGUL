/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    /** @brief Experimental OpenGL wrapper.
     */
    namespace OpenGL
    {
        static const UInt32 POSITION1 =  0;
        static const UInt32 POSITION2 =  1;
        static const UInt32 POSITION3 =  2;
        static const UInt32 POSITION4 =  3;
        static const UInt32 COLOR1    =  4;
        static const UInt32 COLOR2    =  5;
        static const UInt32 COLOR3    =  6;
        static const UInt32 COLOR4    =  7;
        static const UInt32 TEXCOORD1 =  8;
        static const UInt32 TEXCOORD2 =  9;
        static const UInt32 TEXCOORD3 = 10;
        static const UInt32 TEXCOORD4 = 11;
        static const UInt32 NORMAL1   = 12;
        static const UInt32 NORMAL2   = 13;
        static const UInt32 NORMAL3   = 14;
        static const UInt32 NORMAL4   = 15;

        typedef UInt32 Enum;

        namespace GL
        {
            static const Enum POINTS = 0x0;
            static const Enum LINES = 0x1;
            static const Enum LINE_LOOP = 0x2;
            static const Enum LINE_STRIP = 0x3;
            static const Enum TRIANGLES = 0x4;
            static const Enum TRIANGLE_STRIP = 0x5;
            static const Enum TRIANGLE_FAN = 0x6;
            static const Enum QUADS = 0x7;
            static const Enum QUAD_STRIP = 0x8;
            static const Enum POLYGON = 0x9;
            static const Enum LINES_ADJACENCY = 0xa;
            static const Enum LINE_STRIP_ADJACENCY = 0xb;
            static const Enum TRIANGLES_ADJACENCY = 0xc;
            static const Enum TRIANGLE_STRIP_ADJACENCY = 0xd;
            static const Enum PATCHES = 0xe;

            static const Enum COLOR_BUFFER_BIT = 0x4000;
            static const Enum DEPTH_BUFFER_BIT = 0x100;
            static const Enum STENCIL_BUFFER_BIT = 0x400;

            static const Enum VERTEX_SHADER = 0x8b31;
            static const Enum TESS_CONTROL_SHADER = 0x8e88;
            static const Enum TESS_EVALUATION_SHADER = 0x8e87;
            static const Enum GEOMETRY_SHADER = 0x8dd9;
            static const Enum FRAGMENT_SHADER = 0x8b30;

            static const Enum ARRAY_BUFFER = 0x8892;
            static const Enum ATOMIC_COUNTER_BUFFER = 0x92c0;
            static const Enum COPY_READ_BUFFER = 0x8f36;
            static const Enum COPY_WRITE_BUFFER = 0x8f37;
            static const Enum DRAW_INDIRECT_BUFFER = 0x8f3f;
            static const Enum ELEMENT_ARRAY_BUFFER = 0x8893;
            static const Enum PIXEL_PACK_BUFFER = 0x88eb;
            static const Enum PIXEL_UNPACK_BUFFER = 0x88ec;
            static const Enum SHADER_STORAGE_BUFFER = 0x90d2;
            static const Enum TEXTURE_BUFFER = 0x8c2a;
            static const Enum TRANSFORM_FEEDBACK_BUFFER = 0x8c8e;
            static const Enum UNIFORM_BUFFER = 0x8a11;

            static const Enum STREAM_DRAW = 0x88e0;
            static const Enum STREAM_READ = 0x88e1;
            static const Enum STREAM_COPY = 0x88e2;
            static const Enum STATIC_DRAW = 0x88e4;
            static const Enum STATIC_READ = 0x88e5;
            static const Enum STATIC_COPY = 0x88e6;
            static const Enum DYNAMIC_DRAW = 0x88e8;
            static const Enum DYNAMIC_READ = 0x88e9;
            static const Enum DYNAMIC_COPY = 0x88ea;

            static const Enum CLAMP_TO_EDGE = 0x812f;
            static const Enum CLAMP_TO_BORDER = 0x812d;
            static const Enum MIRRORED_REPEAT = 0x8370;
            static const Enum REPEAT = 0x2901;

            static const Enum NEAREST = 0x2600;
            static const Enum LINEAR = 0x2601;

            static const Enum RED = 0x1903;
            static const Enum RG = 0x8227;
            static const Enum RGB = 0x1907;
            static const Enum BGR = 0x80e0;
            static const Enum RGBA = 0x1908;
            static const Enum BGRA = 0x80e1;

            static const Enum BYTE = 0x1400;
            static const Enum UNSIGNED_BYTE = 0x1401;
            static const Enum SHORT = 0x1402;
            static const Enum UNSIGNED_SHORT = 0x1403;
            static const Enum INT = 0x1404;
            static const Enum UNSIGNED_INT = 0x1405;
            static const Enum FLOAT = 0x1406;
            static const Enum DOUBLE = 0x140a;
            static const Enum HALF_FLOAT = 0x140b;
            static const Enum FIXED = 0x140c;
            static const Enum UNSIGNED_BYTE_3_3_2 = 0x8032;
            static const Enum UNSIGNED_SHORT_4_4_4_4 = 0x8033;
            static const Enum UNSIGNED_SHORT_5_5_5_1 = 0x8034;
            static const Enum UNSIGNED_INT_8_8_8_8 = 0x8035;
            static const Enum UNSIGNED_INT_10_10_10_2 = 0x8036;
            static const Enum UNSIGNED_BYTE_2_3_3_REV = 0x8362;
            static const Enum UNSIGNED_SHORT_5_6_5 = 0x8363;
            static const Enum UNSIGNED_SHORT_5_6_5_REV = 0x8364;
            static const Enum UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
            static const Enum UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
            static const Enum UNSIGNED_INT_8_8_8_8_REV = 0x8367;
            static const Enum UNSIGNED_INT_2_10_10_10_REV = 0x8368;
            static const Enum INT_2_10_10_10_REV = 0x8d9f;

            static const Enum TEXTURE_2D = 0xde1;
            static const Enum PROXY_TEXTURE_2D = 0x8064;
            static const Enum TEXTURE_1D_ARRAY = 0x8c18;
            static const Enum PROXY_TEXTURE_1D_ARRAY = 0x8c19;
            static const Enum TEXTURE_RECTANGLE = 0x84f5;
            static const Enum PROXY_TEXTURE_RECTANGLE = 0x84f7;
            static const Enum TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
            static const Enum TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
            static const Enum TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
            static const Enum TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
            static const Enum TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
            static const Enum TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851a;
            static const Enum PROXY_TEXTURE_CUBE_MAP = 0x851b;
        }

        _JATTA_EXPORT void ClearErrors();
        _JATTA_EXPORT void Test();
    }
}
#include "../External/Undefines.h"