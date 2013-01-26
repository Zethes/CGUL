/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_OPENGL
#pragma once
#include "../Utility/String.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    /** @brief Experimental OpenGL wrapper.
     */
    namespace OpenGL
    {
        // TODO: add the rest of the OpenGL constants

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
            namespace Extensions
            {
                namespace AMD
                {
                    static const Enum MULTI_DRAW_INDIRECT = 0x0;
                }
                namespace ARB
                {
                    static const Enum ARRAYS_OF_ARRAYS = 0x1;
                    static const Enum BASE_INSTANCE = 0x2;
                    static const Enum BLEND_FUNC_EXTENDED = 0x3;
                    static const Enum CLEAR_BUFFER_OBJECT = 0x4;
                    static const Enum COLOR_BUFFER_FLOAT = 0x5;
                    static const Enum COMPATIBILITY = 0x6;
                    static const Enum COMPRESSED_TEXTURE_PIXEL_STORAGE = 0x7;
                    static const Enum CONSERVATIVE_DEPTH = 0x8;
                    static const Enum COMPUTE_SHADER = 0x9;
                    static const Enum COPY_BUFFER = 0x10;
                    static const Enum COPY_IMAGE = 0x11;
                    static const Enum DEBUG_OUTPUT = 0x12;
                    static const Enum DEPTH_BUFFER_FLOAT = 0x13;
                    static const Enum DEPTH_CLAMP = 0x14;
                    static const Enum DEPTH_TEXTURE = 0x15;
                    static const Enum DRAW_BUFFERS = 0x16;
                    static const Enum DRAW_BUFFERS_BLEND = 0x17;
                    static const Enum DRAW_INDIRECT = 0x18;
                    static const Enum DRAW_ELEMENTS_BASE_VERTEX = 0x19;
                    static const Enum DRAW_INSTANCED = 0x20;
                    static const Enum ES2_COMPATIBILITY = 0x21;
                    static const Enum ES3_COMPATIBILITY = 0x22;
                    static const Enum EXPLICIT_ATTRIB_LOCATION = 0x23;
                    static const Enum EXPLICIT_UNIFORM_LOCATION = 0x24;
                    static const Enum FRAGMENT_COORD_CONVENTIONS = 0x25;
                    static const Enum FRAGMENT_LAYER_VIEWPORT = 0x26;
                    static const Enum FRAGMENT_PROGRAM = 0x27;
                    static const Enum FRAGMENT_PROGRAM_SHADOW = 0x28;
                    static const Enum FRAGMENT_SHADER = 0x29;
                    static const Enum FRAMEBUFFER_NO_ATTACHMENTS = 0x30;
                    static const Enum FRAMEBUFFER_OBJECT = 0x31;
                    static const Enum FRAMEBUFFER_SRGB = 0x32;
                    static const Enum GEOMETRY_SHADER4 = 0x33;
                    static const Enum GET_PROGRAM_BINARY = 0x34;
                    static const Enum GPU_SHADER5 = 0x35;
                    static const Enum GPU_SHADER_FP64 = 0x36;
                    static const Enum HALF_FLOAT_PIXEL = 0x37;
                    static const Enum HALF_FLOAT_VERTEX = 0x38;
                    static const Enum IMAGING = 0x39;
                    static const Enum INSTANCED_ARRAYS = 0x40;
                    static const Enum INTERNALFORMAT_QUERY = 0x41;
                    static const Enum INTERNALFORMAT_QUERY2 = 0x42;
                    static const Enum INVALIDATE_SUBDATA = 0x43;
                    static const Enum MAP_BUFFER_ALIGNMENT = 0x44;
                    static const Enum MAP_BUFFER_RANGE = 0x45;
                    static const Enum MULTI_DRAW_INDIRECT = 0x46;
                    static const Enum MULTISAMPLE = 0x47;
                    static const Enum MULTITEXTURE = 0x48;
                    static const Enum OCCLUSION_QUERY = 0x49;
                    static const Enum OCCLUSION_QUERY2 = 0x50;
                    static const Enum PIXEL_BUFFER_OBJECT = 0x51;
                    static const Enum POINT_PARAMETERS = 0x52;
                    static const Enum POINT_SPRITE = 0x53;
                    static const Enum PROGRAM_INTERFACE_QUERY = 0x54;
                    static const Enum PROVOKING_VERTEX = 0x55;
                    static const Enum ROBUST_BUFFER_ACCESS_BEHAVIOR = 0x56;
                    static const Enum ROBUSTNESS = 0x57;
                    static const Enum SAMPLE_SHADING = 0x58;
                    static const Enum SAMPLER_OBJECTS = 0x59;
                    static const Enum SEAMLESS_CUBE_MAP = 0x60;
                    static const Enum SEPARATE_SHADER_OBJECTS = 0x61;
                    static const Enum SHADER_ATOMIC_COUNTERS = 0x62;
                    static const Enum SHADER_BIT_ENCODING = 0x63;
                    static const Enum SHADER_IMAGE_LOAD_STORE = 0x64;
                    static const Enum SHADER_IMAGE_SIZE = 0x65;
                    static const Enum SHADER_OBJECTS = 0x66;
                    static const Enum SHADER_PRECISION = 0x67;
                    static const Enum SHADER_STORAGE_BUFFER_OBJECT = 0x68;
                    static const Enum SHADER_SUBROUTINE = 0x69;
                    static const Enum SHADER_TEXTURE_LOD = 0x70;
                    static const Enum SHADING_LANGUAGE_100 = 0x71;
                    static const Enum SHADING_LANGUAGE_420PACK = 0x72;
                    static const Enum SHADING_LANGUAGE_INCLUDE = 0x73;
                    static const Enum SHADING_LANGUAGE_PACKING = 0x74;
                    static const Enum SHADOW = 0x75;
                    static const Enum STENCIL_TEXTURING = 0x76;
                    static const Enum SYNC = 0x77;
                    static const Enum TESSELLATION_SHADER = 0x78;
                    static const Enum TEXTURE_BORDER_CLAMP = 0x79;
                    static const Enum TEXTURE_BUFFER_OBJECT = 0x80;
                    static const Enum TEXTURE_BUFFER_OBJECT_RGB32 = 0x81;
                    static const Enum TEXTURE_BUFFER_RANGE = 0x82;
                    static const Enum TEXTURE_COMPRESSION = 0x83;
                    static const Enum TEXTURE_COMPRESSION_BPTC = 0x84;
                    static const Enum TEXTURE_COMPRESSION_RGTC = 0x85;
                    static const Enum TEXTURE_CUBE_MAP = 0x86;
                    static const Enum TEXTURE_CUBE_MAP_ARRAY = 0x87;
                    static const Enum TEXTURE_ENV_ADD = 0x88;
                    static const Enum TEXTURE_ENV_COMBINE = 0x89;
                    static const Enum TEXTURE_ENV_CROSSBAR = 0x90;
                    static const Enum TEXTURE_ENV_DOT3 = 0x91;
                    static const Enum TEXTURE_FLOAT = 0x92;
                    static const Enum TEXTURE_GATHER = 0x93;
                    static const Enum TEXTURE_MIRRORED_REPEAT = 0x94;
                    static const Enum TEXTURE_MULTISAMPLE = 0x95;
                    static const Enum TEXTURE_NON_POWER_OF_TWO = 0x96;
                    static const Enum TEXTURE_QUERY_LEVELS = 0x97;
                    static const Enum TEXTURE_QUERY_LOD = 0x98;
                    static const Enum TEXTURE_RECTANGLE = 0x99;
                    static const Enum TEXTURE_RG = 0x100;
                    static const Enum TEXTURE_RGB10_A2UI = 0x101;
                    static const Enum TEXTURE_STORAGE = 0x102;
                    static const Enum TEXTURE_STORAGE_MULTISAMPLE = 0x103;
                    static const Enum TEXTURE_SWIZZLE = 0x104;
                    static const Enum TEXTURE_VIEW = 0x105;
                    static const Enum TIMER_QUERY = 0x106;
                    static const Enum TRANSFORM_FEEDBACK2 = 0x107;
                    static const Enum TRANSFORM_FEEDBACK3 = 0x108;
                    static const Enum TRANSFORM_FEEDBACK_INSTANCED = 0x109;
                    static const Enum TRANSPOSE_MATRIX = 0x110;
                    static const Enum UNIFORM_BUFFER_OBJECT = 0x111;
                    static const Enum VERTEX_ARRAY_BGRA = 0x112;
                    static const Enum VERTEX_ARRAY_OBJECT = 0x113;
                    static const Enum VERTEX_ATTRIB_64BIT = 0x114;
                    static const Enum VERTEX_ATTRIB_BINDING = 0x115;
                    static const Enum VERTEX_BUFFER_OBJECT = 0x116;
                    static const Enum VERTEX_PROGRAM = 0x117;
                    static const Enum VERTEX_SHADER = 0x118;
                    static const Enum VERTEX_TYPE_2_10_10_10_REV = 0x119;
                    static const Enum VIEWPORT_ARRAY = 0x120;
                    static const Enum WINDOW_POS = 0x121;
                }
                namespace ATI
                {
                    static const Enum DRAW_BUFFERS = 0x122;
                    static const Enum TEXTURE_FLOAT = 0x123;
                    static const Enum TEXTURE_MIRROR_ONCE = 0x124;
                }
                namespace EXT
                {
                    static const Enum TEXTURE_ENV_ADD = 0x126;
                    static const Enum ABGR = 0x127;
                    static const Enum BGRA = 0x128;
                    static const Enum BINDABLE_UNIFORM = 0x129;
                    static const Enum BLEND_COLOR = 0x130;
                    static const Enum BLEND_EQUATION_SEPARATE = 0x131;
                    static const Enum BLEND_FUNC_SEPARATE = 0x132;
                    static const Enum BLEND_MINMAX = 0x133;
                    static const Enum BLEND_SUBTRACT = 0x134;
                    static const Enum COMPILED_VERTEX_ARRAY = 0x135;
                    static const Enum CG_SHADER = 0x136;
                    static const Enum DEPTH_BOUNDS_TEST = 0x137;
                    static const Enum DIRECT_STATE_ACCESS = 0x138;
                    static const Enum DRAW_BUFFERS2 = 0x139;
                    static const Enum DRAW_INSTANCED = 0x140;
                    static const Enum DRAW_RANGE_ELEMENTS = 0x141;
                    static const Enum FOG_COORD = 0x142;
                    static const Enum FRAMEBUFFER_BLIT = 0x143;
                    static const Enum FRAMEBUFFER_MULTISAMPLE = 0x144;
                    static const Enum FRAMEBUFFER_MIXED_FORMATS = 0x145;
                    static const Enum FRAMEBUFFER_MULTISAMPLE_BLIT_SCALED = 0x146;
                    static const Enum FRAMEBUFFER_OBJECT = 0x147;
                    static const Enum FRAMEBUFFER_SRGB = 0x148;
                    static const Enum GEOMETRY_SHADER4 = 0x149;
                    static const Enum GPU_PROGRAM_PARAMETERS = 0x150;
                    static const Enum GPU_SHADER4 = 0x151;
                    static const Enum MULTI_DRAW_ARRAYS = 0x152;
                    static const Enum PACKED_DEPTH_STENCIL = 0x153;
                    static const Enum PACKED_FLOAT = 0x154;
                    static const Enum PACKED_PIXELS = 0x155;
                    static const Enum PIXEL_BUFFER_OBJECT = 0x156;
                    static const Enum POINT_PARAMETERS = 0x157;
                    static const Enum PROVOKING_VERTEX = 0x158;
                    static const Enum RESCALE_NORMAL = 0x159;
                    static const Enum SECONDARY_COLOR = 0x160;
                    static const Enum SEPARATE_SHADER_OBJECTS = 0x161;
                    static const Enum SEPARATE_SPECULAR_COLOR = 0x162;
                    static const Enum SHADER_IMAGE_LOAD_STORE = 0x163;
                    static const Enum SHADOW_FUNCS = 0x164;
                    static const Enum STENCIL_TWO_SIDE = 0x165;
                    static const Enum STENCIL_WRAP = 0x166;
                    static const Enum TEXTURE3D = 0x167;
                    static const Enum TEXTURE_ARRAY = 0x168;
                    static const Enum TEXTURE_BUFFER_OBJECT = 0x169;
                    static const Enum TEXTURE_COMPRESSION_DXT1 = 0x170;
                    static const Enum TEXTURE_COMPRESSION_LATC = 0x171;
                    static const Enum TEXTURE_COMPRESSION_RGTC = 0x172;
                    static const Enum TEXTURE_COMPRESSION_S3TC = 0x173;
                    static const Enum TEXTURE_CUBE_MAP = 0x174;
                    static const Enum TEXTURE_EDGE_CLAMP = 0x175;
                    static const Enum TEXTURE_ENV_COMBINE = 0x176;
                    static const Enum TEXTURE_ENV_DOT3 = 0x177;
                    static const Enum TEXTURE_FILTER_ANISOTROPIC = 0x178;
                    static const Enum TEXTURE_FORMAT_BGRA8888 = 0x179;
                    static const Enum TEXTURE_INTEGER = 0x180;
                    static const Enum TEXTURE_LOD = 0x181;
                    static const Enum TEXTURE_LOD_BIAS = 0x182;
                    static const Enum TEXTURE_MIRROR_CLAMP = 0x183;
                    static const Enum TEXTURE_OBJECT = 0x184;
                    static const Enum TEXTURE_SHARED_EXPONENT = 0x185;
                    static const Enum TEXTURE_SRGB = 0x186;
                    static const Enum TEXTURE_SRGB_DECODE = 0x187;
                    static const Enum TEXTURE_STORAGE = 0x188;
                    static const Enum TEXTURE_SWIZZLE = 0x189;
                    static const Enum TEXTURE_TYPE_2_10_10_10_REV = 0x190;
                    static const Enum TIMER_QUERY = 0x191;
                    static const Enum TRANSFORM_FEEDBACK2 = 0x192;
                    static const Enum VERTEX_ARRAY = 0x193;
                    static const Enum VERTEX_ARRAY_BGRA = 0x194;
                    static const Enum VERTEX_ATTRIB_64BIT = 0x195;
                    static const Enum IMPORT_SYNC_OBJECT = 0x196;
                }
                namespace GLX
                {

                }
                namespace HP
                {

                }
                namespace IBM
                {
                    static const Enum RASTERPOS_CLIP = 0x197;
                    static const Enum TEXTURE_MIRRORED_REPEAT = 0x198;
                }
                namespace KHR
                {
                    static const Enum DEBUG = 0x199;
                }
                namespace KTX
                {
                    static const Enum BUFFER_REGION = 0x200;
                }
                namespace NVIDIA
                {
                    static const Enum ALPHA_TEST = 0x201;
                    static const Enum BLEND_MINMAX = 0x202;
                    static const Enum BLEND_SQUARE = 0x203;
                    static const Enum COMPLEX_PRIMITIVES = 0x204;
                    static const Enum COMPUTE_PROGRAM5 = 0x205;
                    static const Enum CONDITIONAL_RENDER = 0x206;
                    static const Enum COPY_DEPTH_TO_COLOR = 0x207;
                    static const Enum COPY_IMAGE = 0x208;
                    static const Enum DEPTH_BUFFER_FLOAT = 0x209;
                    static const Enum DEPTH_CLAMP = 0x210;
                    static const Enum DRAW_TEXTURE = 0x211;
                    static const Enum ES1_1_COMPATIBILITY = 0x212;
                    static const Enum EXPLICIT_MULTISAMPLE = 0x213;
                    static const Enum FBO_COLOR_ATTACHMENTS = 0x214;
                    static const Enum FENCE = 0x215;
                    static const Enum FLOAT_BUFFER = 0x216;
                    static const Enum FOG_DISTANCE = 0x217;
                    static const Enum FRAGDEPTH = 0x218;
                    static const Enum FRAGMENT_PROGRAM = 0x219;
                    static const Enum FRAGMENT_PROGRAM_OPTION = 0x220;
                    static const Enum FRAGMENT_PROGRAM2 = 0x221;
                    static const Enum FRAMEBUFFER_MULTISAMPLE_COVERAGE = 0x222;
                    static const Enum GEOMETRY_SHADER4 = 0x223;
                    static const Enum GPU_PROGRAM4 = 0x224;
                    static const Enum GPU_PROGRAM4_1 = 0x225;
                    static const Enum GPU_PROGRAM5 = 0x226;
                    static const Enum GPU_PROGRAM_FP64 = 0x227;
                    static const Enum GPU_SHADER5 = 0x228;
                    static const Enum HALF_FLOAT = 0x229;
                    static const Enum LIGHT_MAX_EXPONENT = 0x230;
                    static const Enum MULTISAMPLE_COVERAGE = 0x231;
                    static const Enum MULTISAMPLE_FILTER_HINT = 0x232;
                    static const Enum OCCLUSION_QUERY = 0x233;
                    static const Enum PACKED_DEPTH_STENCIL = 0x234;
                    static const Enum PARAMETER_BUFFER_OBJECT = 0x235;
                    static const Enum PARAMETER_BUFFER_OBJECT2 = 0x236;
                    static const Enum PATH_RENDERING = 0x237;
                    static const Enum PIXEL_DATA_RANGE = 0x238;
                    static const Enum POINT_SPRITE = 0x239;
                    static const Enum PRIMITIVE_RESTART = 0x240;
                    static const Enum REGISTER_COMBINERS = 0x241;
                    static const Enum REGISTER_COMBINERS2 = 0x242;
                    static const Enum SHADER_ATOMIC_COUNTERS = 0x243;
                    static const Enum SHADER_ATOMIC_FLOAT = 0x244;
                    static const Enum SHADER_BUFFER_LOAD = 0x245;
                    static const Enum SHADER_STORAGE_BUFFER_OBJECT = 0x246;
                    static const Enum TEXGEN_REFLECTION = 0x247;
                    static const Enum TEXTURE_BARRIER = 0x248;
                    static const Enum TEXTURE_COMPRESSION_VTC = 0x249;
                    static const Enum TEXTURE_ENV_COMBINE4 = 0x250;
                    static const Enum TEXTURE_EXPAND_NORMAL = 0x251;
                    static const Enum TEXTURE_LOD_CLAMP = 0x252;
                    static const Enum TEXTURE_MULTISAMPLE = 0x253;
                    static const Enum TEXTURE_RECTANGLE = 0x254;
                    static const Enum TEXTURE_SHADER = 0x255;
                    static const Enum TEXTURE_SHADER2 = 0x256;
                    static const Enum TEXTURE_SHADER3 = 0x257;
                    static const Enum TRANSFORM_FEEDBACK = 0x258;
                    static const Enum TRANSFORM_FEEDBACK2 = 0x259;
                    static const Enum VERTEX_ARRAY_RANGE = 0x260;
                    static const Enum VERTEX_ARRAY_RANGE2 = 0x261;
                    static const Enum VERTEX_ATTRIB_INTEGER_64BIT = 0x262;
                    static const Enum VERTEX_BUFFER_UNIFIED_MEMORY = 0x263;
                    static const Enum VERTEX_PROGRAM = 0x264;
                    static const Enum VERTEX_PROGRAM1_1 = 0x265;
                    static const Enum VERTEX_PROGRAM2 = 0x266;
                    static const Enum VERTEX_PROGRAM2_OPTION = 0x267;
                    static const Enum VERTEX_PROGRAM3 = 0x268;
                }
                namespace NVIDIAX
                {
                    static const Enum CONDITIONAL_RENDER = 0x269;
                    static const Enum GPU_MEMORY_INFO = 0x270;
                }
                namespace OES
                {
                    static const Enum COMPRESSED_PALETTED_TEXTURE = 0x271;
                    static const Enum DEPTH24 = 0x272;
                    static const Enum DEPTH32 = 0x273;
                    static const Enum DEPTH_TEXTURE = 0x274;
                    static const Enum ELEMENT_INDEX_UINT = 0x275;
                    static const Enum FBO_RENDER_MIPMAP = 0x276;
                    static const Enum GET_PROGRAM_BINARY = 0x277;
                    static const Enum MAPBUFFER = 0x278;
                    static const Enum PACKED_DEPTH_STENCIL = 0x279;
                    static const Enum POINT_SIZE_ARRAY = 0x280;
                    static const Enum POINT_SPRITE = 0x281;
                    static const Enum RGB8_RGBA8 = 0x282;
                    static const Enum READ_FORMAT = 0x283;
                    static const Enum STANDARD_DERIVATIVES = 0x284;
                    static const Enum TEXTURE_3D = 0x285;
                    static const Enum TEXTURE_FLOAT = 0x286;
                    static const Enum TEXTURE_FLOAT_LINEAR = 0x287;
                    static const Enum TEXTURE_HALF_FLOAT = 0x288;
                    static const Enum TEXTURE_HALF_FLOAT_LINEAR = 0x289;
                    static const Enum TEXTURE_NPOT = 0x290;
                    static const Enum VERTEX_ARRAY_OBJECT = 0x291;
                    static const Enum VERTEX_HALF_FLOAT = 0x292;
                }
                namespace S3
                {
                    static const Enum S3_S3TC = 0x125;
                }
                namespace SGIS
                {
                    static const Enum GENERATE_MIPMAP = 0x293;
                    static const Enum TEXTURE_LOD = 0x294;
                }
                namespace SGIX
                {
                    static const Enum DEPTH_TEXTURE = 0x295;
                    static const Enum SHADOW = 0x296;
                }
                namespace SUN
                {
                    static const Enum SLICE_ACCUM = 0x297;
                }
                namespace WIN
                {
                    static const Enum SWAP_HINT = 0x298;
                }
                namespace WGL
                {
                    static const Enum EXT_SWAP_CONTROL = 0x299;
                }
            }

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

            static const Enum EXTENSIONS = 0x1f03;
            static const Enum MAJOR_VERSION = 0x821b;
            static const Enum MINOR_VERSION = 0x821c;
            static const Enum VERSION = 0x1f02;
            static const Enum GLSL_VERSION = 0x8b8c;
            static const Enum VENDOR = 0x1f00;
            static const Enum RENDERER = 0x1f01;
        }

        _JATTA_EXPORT void ClearErrors();
        _JATTA_EXPORT void Test();

        _JATTA_EXPORT std::string GetString(Enum name);
        _JATTA_EXPORT std::string GetStringi(Enum name, unsigned int index);
        _JATTA_EXPORT std::vector<Jatta::String> GetSupportedExtensions();
        _JATTA_EXPORT int GetOpenGLVersionMajor();
        _JATTA_EXPORT int GetOpenGLVersionMinor();
        _JATTA_EXPORT std::string GetOpenGLVersion();
        _JATTA_EXPORT std::string GetGLSLVersion();
        _JATTA_EXPORT std::string GetOpenGLVendor();
        _JATTA_EXPORT std::string GetOpenGLRenderer();
    }
}
#include "../External/Undefines.h"
#endif
