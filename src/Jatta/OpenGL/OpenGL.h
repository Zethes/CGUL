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
        typedef UInt32 Enum;

        static const Enum POINTS = 0x0;
        static const Enum LINE_STRIP = 0x3;
        static const Enum LINE_LOOP = 0x2;
        static const Enum LINES = 0x1;
        static const Enum LINE_STRIP_ADJACENCY = 0xb;
        static const Enum LINES_ADJACENCY = 0xa;
        static const Enum TRIANGLE_STRIP = 0x5;
        static const Enum TRIANGLE_FAN = 0x6;
        static const Enum TRIANGLES = 0x4;
        static const Enum TRIANGLE_STRIP_ADJACENCY = 0xd;
        static const Enum TRIANGLES_ADJACENCY = 0xc;
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
        static const Enum INT_2_10_10_10_REV = 0x8d9f;
        static const Enum UNSIGNED_INT_2_10_10_10_REV = 0x8368;

        _JATTA_EXPORT void ClearErrors();
        _JATTA_EXPORT void Test();
    }
}
#include "../External/Undefines.h"