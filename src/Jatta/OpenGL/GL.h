/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        typedef UInt32 Enum;
    }

    /** @brief Contains all of the OpenGL defines.
     */
    namespace GL
    {
        // TODO: add the rest of the OpenGL constants

        /** @brief OpenGL numerical representation of position 1.
         *  @details Older OpenGL versions used numbers 0-15 to represent different types of data,
         *  most commonly 0-3 are used for positions, 4-7 are used for colors, 8-11 are used for
         *  texture coordinates, and 12-15 are used for normals.  In reality, these indices can be
         *  used for @b whatever data you wish to pass into a shader.
         */
        static const UInt32 POSITION1 =  0;
        /** @brief OpenGL numerical representation of position 2. (see @ref POSITION1)
         */
        static const UInt32 POSITION2 =  1;
        /** @brief OpenGL numerical representation of position 3. (see @ref POSITION1)
         */
        static const UInt32 POSITION3 =  2;
        /** @brief OpenGL numerical representation of position 4. (see @ref POSITION1)
         */
        static const UInt32 POSITION4 =  3;
        /** @brief OpenGL numerical representation of color 1. (see @ref POSITION1)
         */
        static const UInt32 COLOR1    =  4;
        /** @brief OpenGL numerical representation of color 2. (see @ref POSITION1)
         */
        static const UInt32 COLOR2    =  5;
        /** @brief OpenGL numerical representation of color 3. (see @ref POSITION1)
         */
        static const UInt32 COLOR3    =  6;
        /** @brief OpenGL numerical representation of color 4. (see @ref POSITION1)
         */
        static const UInt32 COLOR4    =  7;
        /** @brief OpenGL numerical representation of texcoord 1. (see @ref POSITION1)
         */
        static const UInt32 TEXCOORD1 =  8;
        /** @brief OpenGL numerical representation of texcoord 2. (see @ref POSITION1)
         */
        static const UInt32 TEXCOORD2 =  9;
        /** @brief OpenGL numerical representation of texcoord 3. (see @ref POSITION1)
         */
        static const UInt32 TEXCOORD3 = 10;
        /** @brief OpenGL numerical representation of texcoord 4. (see @ref POSITION1)
         */
        static const UInt32 TEXCOORD4 = 11;
        /** @brief OpenGL numerical representation of normal 1. (see @ref POSITION1)
         */
        static const UInt32 NORMAL1   = 12;
        /** @brief OpenGL numerical representation of normal 2. (see @ref POSITION1)
         */
        static const UInt32 NORMAL2   = 13;
        /** @brief OpenGL numerical representation of normal 3. (see @ref POSITION1)
         */
        static const UInt32 NORMAL3   = 14;
        /** @brief OpenGL numerical representation of normal 4. (see @ref POSITION1)
         */
        static const UInt32 NORMAL4   = 15;

        namespace Extensions
        {
            namespace AMD
            {
                static const OpenGL::Enum MULTI_DRAW_INDIRECT = 0x0;
            }
            namespace ARB
            {
                static const OpenGL::Enum ARRAYS_OF_ARRAYS = 0x1;
                static const OpenGL::Enum BASE_INSTANCE = 0x2;
                static const OpenGL::Enum BLEND_FUNC_EXTENDED = 0x3;
                static const OpenGL::Enum CLEAR_BUFFER_OBJECT = 0x4;
                static const OpenGL::Enum COLOR_BUFFER_FLOAT = 0x5;
                static const OpenGL::Enum COMPATIBILITY = 0x6;
                static const OpenGL::Enum COMPRESSED_TEXTURE_PIXEL_STORAGE = 0x7;
                static const OpenGL::Enum CONSERVATIVE_DEPTH = 0x8;
                static const OpenGL::Enum COMPUTE_SHADER = 0x9;
                static const OpenGL::Enum COPY_BUFFER = 0x10;
                static const OpenGL::Enum COPY_IMAGE = 0x11;
                static const OpenGL::Enum DEBUG_OUTPUT = 0x12;
                static const OpenGL::Enum DEPTH_BUFFER_FLOAT = 0x13;
                static const OpenGL::Enum DEPTH_CLAMP = 0x14;
                static const OpenGL::Enum DEPTH_TEXTURE = 0x15;
                static const OpenGL::Enum DRAW_BUFFERS = 0x16;
                static const OpenGL::Enum DRAW_BUFFERS_BLEND = 0x17;
                static const OpenGL::Enum DRAW_INDIRECT = 0x18;
                static const OpenGL::Enum DRAW_ELEMENTS_BASE_VERTEX = 0x19;
                static const OpenGL::Enum DRAW_INSTANCED = 0x20;
                static const OpenGL::Enum ES2_COMPATIBILITY = 0x21;
                static const OpenGL::Enum ES3_COMPATIBILITY = 0x22;
                static const OpenGL::Enum EXPLICIT_ATTRIB_LOCATION = 0x23;
                static const OpenGL::Enum EXPLICIT_UNIFORM_LOCATION = 0x24;
                static const OpenGL::Enum FRAGMENT_COORD_CONVENTIONS = 0x25;
                static const OpenGL::Enum FRAGMENT_LAYER_VIEWPORT = 0x26;
                static const OpenGL::Enum FRAGMENT_PROGRAM = 0x27;
                static const OpenGL::Enum FRAGMENT_PROGRAM_SHADOW = 0x28;
                static const OpenGL::Enum FRAGMENT_SHADER = 0x29;
                static const OpenGL::Enum FRAMEBUFFER_NO_ATTACHMENTS = 0x30;
                static const OpenGL::Enum FRAMEBUFFER_OBJECT = 0x31;
                static const OpenGL::Enum FRAMEBUFFER_SRGB = 0x32;
                static const OpenGL::Enum GEOMETRY_SHADER4 = 0x33;
                static const OpenGL::Enum GET_PROGRAM_BINARY = 0x34;
                static const OpenGL::Enum GPU_SHADER5 = 0x35;
                static const OpenGL::Enum GPU_SHADER_FP64 = 0x36;
                static const OpenGL::Enum HALF_FLOAT_PIXEL = 0x37;
                static const OpenGL::Enum HALF_FLOAT_VERTEX = 0x38;
                static const OpenGL::Enum IMAGING = 0x39;
                static const OpenGL::Enum INSTANCED_ARRAYS = 0x40;
                static const OpenGL::Enum INTERNALFORMAT_QUERY = 0x41;
                static const OpenGL::Enum INTERNALFORMAT_QUERY2 = 0x42;
                static const OpenGL::Enum INVALIDATE_SUBDATA = 0x43;
                static const OpenGL::Enum MAP_BUFFER_ALIGNMENT = 0x44;
                static const OpenGL::Enum MAP_BUFFER_RANGE = 0x45;
                static const OpenGL::Enum MULTI_DRAW_INDIRECT = 0x46;
                static const OpenGL::Enum MULTISAMPLE = 0x47;
                static const OpenGL::Enum MULTITEXTURE = 0x48;
                static const OpenGL::Enum OCCLUSION_QUERY = 0x49;
                static const OpenGL::Enum OCCLUSION_QUERY2 = 0x50;
                static const OpenGL::Enum PIXEL_BUFFER_OBJECT = 0x51;
                static const OpenGL::Enum POINT_PARAMETERS = 0x52;
                static const OpenGL::Enum POINT_SPRITE = 0x53;
                static const OpenGL::Enum PROGRAM_INTERFACE_QUERY = 0x54;
                static const OpenGL::Enum PROVOKING_VERTEX = 0x55;
                static const OpenGL::Enum ROBUST_BUFFER_ACCESS_BEHAVIOR = 0x56;
                static const OpenGL::Enum ROBUSTNESS = 0x57;
                static const OpenGL::Enum SAMPLE_SHADING = 0x58;
                static const OpenGL::Enum SAMPLER_OBJECTS = 0x59;
                static const OpenGL::Enum SEAMLESS_CUBE_MAP = 0x60;
                static const OpenGL::Enum SEPARATE_SHADER_OBJECTS = 0x61;
                static const OpenGL::Enum SHADER_ATOMIC_COUNTERS = 0x62;
                static const OpenGL::Enum SHADER_BIT_ENCODING = 0x63;
                static const OpenGL::Enum SHADER_IMAGE_LOAD_STORE = 0x64;
                static const OpenGL::Enum SHADER_IMAGE_SIZE = 0x65;
                static const OpenGL::Enum SHADER_OBJECTS = 0x66;
                static const OpenGL::Enum SHADER_PRECISION = 0x67;
                static const OpenGL::Enum SHADER_STORAGE_BUFFER_OBJECT = 0x68;
                static const OpenGL::Enum SHADER_SUBROUTINE = 0x69;
                static const OpenGL::Enum SHADER_TEXTURE_LOD = 0x70;
                static const OpenGL::Enum SHADING_LANGUAGE_100 = 0x71;
                static const OpenGL::Enum SHADING_LANGUAGE_420PACK = 0x72;
                static const OpenGL::Enum SHADING_LANGUAGE_INCLUDE = 0x73;
                static const OpenGL::Enum SHADING_LANGUAGE_PACKING = 0x74;
                static const OpenGL::Enum SHADOW = 0x75;
                static const OpenGL::Enum STENCIL_TEXTURING = 0x76;
                static const OpenGL::Enum SYNC = 0x77;
                static const OpenGL::Enum TESSELLATION_SHADER = 0x78;
                static const OpenGL::Enum TEXTURE_BORDER_CLAMP = 0x79;
                static const OpenGL::Enum TEXTURE_BUFFER_OBJECT = 0x80;
                static const OpenGL::Enum TEXTURE_BUFFER_OBJECT_RGB32 = 0x81;
                static const OpenGL::Enum TEXTURE_BUFFER_RANGE = 0x82;
                static const OpenGL::Enum TEXTURE_COMPRESSION = 0x83;
                static const OpenGL::Enum TEXTURE_COMPRESSION_BPTC = 0x84;
                static const OpenGL::Enum TEXTURE_COMPRESSION_RGTC = 0x85;
                static const OpenGL::Enum TEXTURE_CUBE_MAP = 0x86;
                static const OpenGL::Enum TEXTURE_CUBE_MAP_ARRAY = 0x87;
                static const OpenGL::Enum TEXTURE_ENV_ADD = 0x88;
                static const OpenGL::Enum TEXTURE_ENV_COMBINE = 0x89;
                static const OpenGL::Enum TEXTURE_ENV_CROSSBAR = 0x90;
                static const OpenGL::Enum TEXTURE_ENV_DOT3 = 0x91;
                static const OpenGL::Enum TEXTURE_FLOAT = 0x92;
                static const OpenGL::Enum TEXTURE_GATHER = 0x93;
                static const OpenGL::Enum TEXTURE_MIRRORED_REPEAT = 0x94;
                static const OpenGL::Enum TEXTURE_MULTISAMPLE = 0x95;
                static const OpenGL::Enum TEXTURE_NON_POWER_OF_TWO = 0x96;
                static const OpenGL::Enum TEXTURE_QUERY_LEVELS = 0x97;
                static const OpenGL::Enum TEXTURE_QUERY_LOD = 0x98;
                static const OpenGL::Enum TEXTURE_RECTANGLE = 0x99;
                static const OpenGL::Enum TEXTURE_RG = 0x100;
                static const OpenGL::Enum TEXTURE_RGB10_A2UI = 0x101;
                static const OpenGL::Enum TEXTURE_STORAGE = 0x102;
                static const OpenGL::Enum TEXTURE_STORAGE_MULTISAMPLE = 0x103;
                static const OpenGL::Enum TEXTURE_SWIZZLE = 0x104;
                static const OpenGL::Enum TEXTURE_VIEW = 0x105;
                static const OpenGL::Enum TIMER_QUERY = 0x106;
                static const OpenGL::Enum TRANSFORM_FEEDBACK2 = 0x107;
                static const OpenGL::Enum TRANSFORM_FEEDBACK3 = 0x108;
                static const OpenGL::Enum TRANSFORM_FEEDBACK_INSTANCED = 0x109;
                static const OpenGL::Enum TRANSPOSE_MATRIX = 0x110;
                static const OpenGL::Enum UNIFORM_BUFFER_OBJECT = 0x111;
                static const OpenGL::Enum VERTEX_ARRAY_BGRA = 0x112;
                static const OpenGL::Enum VERTEX_ARRAY_OBJECT = 0x113;
                static const OpenGL::Enum VERTEX_ATTRIB_64BIT = 0x114;
                static const OpenGL::Enum VERTEX_ATTRIB_BINDING = 0x115;
                static const OpenGL::Enum VERTEX_BUFFER_OBJECT = 0x116;
                static const OpenGL::Enum VERTEX_PROGRAM = 0x117;
                static const OpenGL::Enum VERTEX_SHADER = 0x118;
                static const OpenGL::Enum VERTEX_TYPE_2_10_10_10_REV = 0x119;
                static const OpenGL::Enum VIEWPORT_ARRAY = 0x120;
                static const OpenGL::Enum WINDOW_POS = 0x121;
            }
            namespace ATI
            {
                static const OpenGL::Enum DRAW_BUFFERS = 0x122;
                static const OpenGL::Enum TEXTURE_FLOAT = 0x123;
                static const OpenGL::Enum TEXTURE_MIRROR_ONCE = 0x124;
            }
            namespace EXT
            {
                static const OpenGL::Enum TEXTURE_ENV_ADD = 0x126;
                static const OpenGL::Enum ABGR = 0x127;
                static const OpenGL::Enum BGRA = 0x128;
                static const OpenGL::Enum BINDABLE_UNIFORM = 0x129;
                static const OpenGL::Enum BLEND_COLOR = 0x130;
                static const OpenGL::Enum BLEND_EQUATION_SEPARATE = 0x131;
                static const OpenGL::Enum BLEND_FUNC_SEPARATE = 0x132;
                static const OpenGL::Enum BLEND_MINMAX = 0x133;
                static const OpenGL::Enum BLEND_SUBTRACT = 0x134;
                static const OpenGL::Enum COMPILED_VERTEX_ARRAY = 0x135;
                static const OpenGL::Enum CG_SHADER = 0x136;
                static const OpenGL::Enum DEPTH_BOUNDS_TEST = 0x137;
                static const OpenGL::Enum DIRECT_STATE_ACCESS = 0x138;
                static const OpenGL::Enum DRAW_BUFFERS2 = 0x139;
                static const OpenGL::Enum DRAW_INSTANCED = 0x140;
                static const OpenGL::Enum DRAW_RANGE_ELEMENTS = 0x141;
                static const OpenGL::Enum FOG_COORD = 0x142;
                static const OpenGL::Enum FRAMEBUFFER_BLIT = 0x143;
                static const OpenGL::Enum FRAMEBUFFER_MULTISAMPLE = 0x144;
                static const OpenGL::Enum FRAMEBUFFER_MIXED_FORMATS = 0x145;
                static const OpenGL::Enum FRAMEBUFFER_MULTISAMPLE_BLIT_SCALED = 0x146;
                static const OpenGL::Enum FRAMEBUFFER_OBJECT = 0x147;
                static const OpenGL::Enum FRAMEBUFFER_SRGB = 0x148;
                static const OpenGL::Enum GEOMETRY_SHADER4 = 0x149;
                static const OpenGL::Enum GPU_PROGRAM_PARAMETERS = 0x150;
                static const OpenGL::Enum GPU_SHADER4 = 0x151;
                static const OpenGL::Enum MULTI_DRAW_ARRAYS = 0x152;
                static const OpenGL::Enum PACKED_DEPTH_STENCIL = 0x153;
                static const OpenGL::Enum PACKED_FLOAT = 0x154;
                static const OpenGL::Enum PACKED_PIXELS = 0x155;
                static const OpenGL::Enum PIXEL_BUFFER_OBJECT = 0x156;
                static const OpenGL::Enum POINT_PARAMETERS = 0x157;
                static const OpenGL::Enum PROVOKING_VERTEX = 0x158;
                static const OpenGL::Enum RESCALE_NORMAL = 0x159;
                static const OpenGL::Enum SECONDARY_COLOR = 0x160;
                static const OpenGL::Enum SEPARATE_SHADER_OBJECTS = 0x161;
                static const OpenGL::Enum SEPARATE_SPECULAR_COLOR = 0x162;
                static const OpenGL::Enum SHADER_IMAGE_LOAD_STORE = 0x163;
                static const OpenGL::Enum SHADOW_FUNCS = 0x164;
                static const OpenGL::Enum STENCIL_TWO_SIDE = 0x165;
                static const OpenGL::Enum STENCIL_WRAP = 0x166;
                static const OpenGL::Enum TEXTURE3D = 0x167;
                static const OpenGL::Enum TEXTURE_ARRAY = 0x168;
                static const OpenGL::Enum TEXTURE_BUFFER_OBJECT = 0x169;
                static const OpenGL::Enum TEXTURE_COMPRESSION_DXT1 = 0x170;
                static const OpenGL::Enum TEXTURE_COMPRESSION_LATC = 0x171;
                static const OpenGL::Enum TEXTURE_COMPRESSION_RGTC = 0x172;
                static const OpenGL::Enum TEXTURE_COMPRESSION_S3TC = 0x173;
                static const OpenGL::Enum TEXTURE_CUBE_MAP = 0x174;
                static const OpenGL::Enum TEXTURE_EDGE_CLAMP = 0x175;
                static const OpenGL::Enum TEXTURE_ENV_COMBINE = 0x176;
                static const OpenGL::Enum TEXTURE_ENV_DOT3 = 0x177;
                static const OpenGL::Enum TEXTURE_FILTER_ANISOTROPIC = 0x178;
                static const OpenGL::Enum TEXTURE_FORMAT_BGRA8888 = 0x179;
                static const OpenGL::Enum TEXTURE_INTEGER = 0x180;
                static const OpenGL::Enum TEXTURE_LOD = 0x181;
                static const OpenGL::Enum TEXTURE_LOD_BIAS = 0x182;
                static const OpenGL::Enum TEXTURE_MIRROR_CLAMP = 0x183;
                static const OpenGL::Enum TEXTURE_OBJECT = 0x184;
                static const OpenGL::Enum TEXTURE_SHARED_EXPONENT = 0x185;
                static const OpenGL::Enum TEXTURE_SRGB = 0x186;
                static const OpenGL::Enum TEXTURE_SRGB_DECODE = 0x187;
                static const OpenGL::Enum TEXTURE_STORAGE = 0x188;
                static const OpenGL::Enum TEXTURE_SWIZZLE = 0x189;
                static const OpenGL::Enum TEXTURE_TYPE_2_10_10_10_REV = 0x190;
                static const OpenGL::Enum TIMER_QUERY = 0x191;
                static const OpenGL::Enum TRANSFORM_FEEDBACK2 = 0x192;
                static const OpenGL::Enum VERTEX_ARRAY = 0x193;
                static const OpenGL::Enum VERTEX_ARRAY_BGRA = 0x194;
                static const OpenGL::Enum VERTEX_ATTRIB_64BIT = 0x195;
                static const OpenGL::Enum IMPORT_SYNC_OBJECT = 0x196;
            }
            namespace GLX
            {

            }
            namespace HP
            {

            }
            namespace IBM
            {
                static const OpenGL::Enum RASTERPOS_CLIP = 0x197;
                static const OpenGL::Enum TEXTURE_MIRRORED_REPEAT = 0x198;
            }
            namespace KHR
            {
                static const OpenGL::Enum DEBUG = 0x199;
            }
            namespace KTX
            {
                static const OpenGL::Enum BUFFER_REGION = 0x200;
            }
            namespace NVIDIA
            {
                static const OpenGL::Enum ALPHA_TEST = 0x201;
                static const OpenGL::Enum BLEND_MINMAX = 0x202;
                static const OpenGL::Enum BLEND_SQUARE = 0x203;
                static const OpenGL::Enum COMPLEX_PRIMITIVES = 0x204;
                static const OpenGL::Enum COMPUTE_PROGRAM5 = 0x205;
                static const OpenGL::Enum CONDITIONAL_RENDER = 0x206;
                static const OpenGL::Enum COPY_DEPTH_TO_COLOR = 0x207;
                static const OpenGL::Enum COPY_IMAGE = 0x208;
                static const OpenGL::Enum DEPTH_BUFFER_FLOAT = 0x209;
                static const OpenGL::Enum DEPTH_CLAMP = 0x210;
                static const OpenGL::Enum DRAW_TEXTURE = 0x211;
                static const OpenGL::Enum ES1_1_COMPATIBILITY = 0x212;
                static const OpenGL::Enum EXPLICIT_MULTISAMPLE = 0x213;
                static const OpenGL::Enum FBO_COLOR_ATTACHMENTS = 0x214;
                static const OpenGL::Enum FENCE = 0x215;
                static const OpenGL::Enum FLOAT_BUFFER = 0x216;
                static const OpenGL::Enum FOG_DISTANCE = 0x217;
                static const OpenGL::Enum FRAGDEPTH = 0x218;
                static const OpenGL::Enum FRAGMENT_PROGRAM = 0x219;
                static const OpenGL::Enum FRAGMENT_PROGRAM_OPTION = 0x220;
                static const OpenGL::Enum FRAGMENT_PROGRAM2 = 0x221;
                static const OpenGL::Enum FRAMEBUFFER_MULTISAMPLE_COVERAGE = 0x222;
                static const OpenGL::Enum GEOMETRY_SHADER4 = 0x223;
                static const OpenGL::Enum GPU_PROGRAM4 = 0x224;
                static const OpenGL::Enum GPU_PROGRAM4_1 = 0x225;
                static const OpenGL::Enum GPU_PROGRAM5 = 0x226;
                static const OpenGL::Enum GPU_PROGRAM_FP64 = 0x227;
                static const OpenGL::Enum GPU_SHADER5 = 0x228;
                static const OpenGL::Enum HALF_FLOAT = 0x229;
                static const OpenGL::Enum LIGHT_MAX_EXPONENT = 0x230;
                static const OpenGL::Enum MULTISAMPLE_COVERAGE = 0x231;
                static const OpenGL::Enum MULTISAMPLE_FILTER_HINT = 0x232;
                static const OpenGL::Enum OCCLUSION_QUERY = 0x233;
                static const OpenGL::Enum PACKED_DEPTH_STENCIL = 0x234;
                static const OpenGL::Enum PARAMETER_BUFFER_OBJECT = 0x235;
                static const OpenGL::Enum PARAMETER_BUFFER_OBJECT2 = 0x236;
                static const OpenGL::Enum PATH_RENDERING = 0x237;
                static const OpenGL::Enum PIXEL_DATA_RANGE = 0x238;
                static const OpenGL::Enum POINT_SPRITE = 0x239;
                static const OpenGL::Enum PRIMITIVE_RESTART = 0x240;
                static const OpenGL::Enum REGISTER_COMBINERS = 0x241;
                static const OpenGL::Enum REGISTER_COMBINERS2 = 0x242;
                static const OpenGL::Enum SHADER_ATOMIC_COUNTERS = 0x243;
                static const OpenGL::Enum SHADER_ATOMIC_FLOAT = 0x244;
                static const OpenGL::Enum SHADER_BUFFER_LOAD = 0x245;
                static const OpenGL::Enum SHADER_STORAGE_BUFFER_OBJECT = 0x246;
                static const OpenGL::Enum TEXGEN_REFLECTION = 0x247;
                static const OpenGL::Enum TEXTURE_BARRIER = 0x248;
                static const OpenGL::Enum TEXTURE_COMPRESSION_VTC = 0x249;
                static const OpenGL::Enum TEXTURE_ENV_COMBINE4 = 0x250;
                static const OpenGL::Enum TEXTURE_EXPAND_NORMAL = 0x251;
                static const OpenGL::Enum TEXTURE_LOD_CLAMP = 0x252;
                static const OpenGL::Enum TEXTURE_MULTISAMPLE = 0x253;
                static const OpenGL::Enum TEXTURE_RECTANGLE = 0x254;
                static const OpenGL::Enum TEXTURE_SHADER = 0x255;
                static const OpenGL::Enum TEXTURE_SHADER2 = 0x256;
                static const OpenGL::Enum TEXTURE_SHADER3 = 0x257;
                static const OpenGL::Enum TRANSFORM_FEEDBACK = 0x258;
                static const OpenGL::Enum TRANSFORM_FEEDBACK2 = 0x259;
                static const OpenGL::Enum VERTEX_ARRAY_RANGE = 0x260;
                static const OpenGL::Enum VERTEX_ARRAY_RANGE2 = 0x261;
                static const OpenGL::Enum VERTEX_ATTRIB_INTEGER_64BIT = 0x262;
                static const OpenGL::Enum VERTEX_BUFFER_UNIFIED_MEMORY = 0x263;
                static const OpenGL::Enum VERTEX_PROGRAM = 0x264;
                static const OpenGL::Enum VERTEX_PROGRAM1_1 = 0x265;
                static const OpenGL::Enum VERTEX_PROGRAM2 = 0x266;
                static const OpenGL::Enum VERTEX_PROGRAM2_OPTION = 0x267;
                static const OpenGL::Enum VERTEX_PROGRAM3 = 0x268;
            }
            namespace NVIDIAX
            {
                static const OpenGL::Enum CONDITIONAL_RENDER = 0x269;
                static const OpenGL::Enum GPU_MEMORY_INFO = 0x270;
            }
            namespace OES
            {
                static const OpenGL::Enum COMPRESSED_PALETTED_TEXTURE = 0x271;
                static const OpenGL::Enum DEPTH24 = 0x272;
                static const OpenGL::Enum DEPTH32 = 0x273;
                static const OpenGL::Enum DEPTH_TEXTURE = 0x274;
                static const OpenGL::Enum ELEMENT_INDEX_UINT = 0x275;
                static const OpenGL::Enum FBO_RENDER_MIPMAP = 0x276;
                static const OpenGL::Enum GET_PROGRAM_BINARY = 0x277;
                static const OpenGL::Enum MAPBUFFER = 0x278;
                static const OpenGL::Enum PACKED_DEPTH_STENCIL = 0x279;
                static const OpenGL::Enum POINT_SIZE_ARRAY = 0x280;
                static const OpenGL::Enum POINT_SPRITE = 0x281;
                static const OpenGL::Enum RGB8_RGBA8 = 0x282;
                static const OpenGL::Enum READ_FORMAT = 0x283;
                static const OpenGL::Enum STANDARD_DERIVATIVES = 0x284;
                static const OpenGL::Enum TEXTURE_3D = 0x285;
                static const OpenGL::Enum TEXTURE_FLOAT = 0x286;
                static const OpenGL::Enum TEXTURE_FLOAT_LINEAR = 0x287;
                static const OpenGL::Enum TEXTURE_HALF_FLOAT = 0x288;
                static const OpenGL::Enum TEXTURE_HALF_FLOAT_LINEAR = 0x289;
                static const OpenGL::Enum TEXTURE_NPOT = 0x290;
                static const OpenGL::Enum VERTEX_ARRAY_OBJECT = 0x291;
                static const OpenGL::Enum VERTEX_HALF_FLOAT = 0x292;
            }
            namespace S3
            {
                static const OpenGL::Enum S3_S3TC = 0x125;
            }
            namespace SGIS
            {
                static const OpenGL::Enum GENERATE_MIPMAP = 0x293;
                static const OpenGL::Enum TEXTURE_LOD = 0x294;
            }
            namespace SGIX
            {
                static const OpenGL::Enum DEPTH_TEXTURE = 0x295;
                static const OpenGL::Enum SHADOW = 0x296;
            }
            namespace SUN
            {
                static const OpenGL::Enum SLICE_ACCUM = 0x297;
            }
            namespace WIN
            {
                static const OpenGL::Enum SWAP_HINT = 0x298;
            }
            namespace WGL
            {
                static const OpenGL::Enum EXT_SWAP_CONTROL = 0x299;
            }
        }

        /** @brief Equivalent to GL_POINTS.
         *  @details Additional info etc etc.
         */
        static const OpenGL::Enum POINTS                      = 0x0000;
        /** @brief Equivalent to GL_ZERO.
         */
        static const OpenGL::Enum ZERO                        = 0x0000;
        /** @brief Equivalent to GL_LINES.
         */
        static const OpenGL::Enum LINES                       = 0x0001;
        /** @brief Equivalent to GL_ONE.
         */
        static const OpenGL::Enum ONE                         = 0x0001;
        /** @brief Equivalent to GL_LINE_LOOP.
         */
        static const OpenGL::Enum LINE_LOOP                   = 0x0002;
        /** @brief Equivalent to GL_LINE_STRIP.
         */
        static const OpenGL::Enum LINE_STRIP                  = 0x0003;
        /** @brief Equivalent to GL_TRIANGLES.
         */
        static const OpenGL::Enum TRIANGLES                   = 0x0004;
        /** @brief Equivalent to GL_TRIANGLE_STRIP.
         */
        static const OpenGL::Enum TRIANGLE_STRIP              = 0x0005;
        /** @brief Equivalent to GL_TRIANGLE_FAN.
         */
        static const OpenGL::Enum TRIANGLE_FAN                = 0x0006;
        /** @brief Equivalent to GL_QUADS.
         */
        static const OpenGL::Enum QUADS                       = 0x0007;
        /** @brief Equivalent to GL_QUAD_STRIP.
         */
        static const OpenGL::Enum QUAD_STRIP                  = 0x0008;
        /** @brief Equivalent to GL_POLYGON.
         */
        static const OpenGL::Enum POLYGON                     = 0x0009;
        /** @brief Equivalent to GL_LINES_ADJACENCY.
         */
        static const OpenGL::Enum LINES_ADJACENCY             = 0x000a;
        /** @brief Equivalent to GL_LINE_STRIP_ADJACENCY.
         */
        static const OpenGL::Enum LINE_STRIP_ADJACENCY        = 0x000b;
        /** @brief Equivalent to GL_TRIANGLES_ADJACENCY.
         */
        static const OpenGL::Enum TRIANGLES_ADJACENCY         = 0x000c;
        /** @brief Equivalent to GL_TRIANGLE_STRIP_ADJACENCY.
         */
        static const OpenGL::Enum TRIANGLE_STRIP_ADJACENCY    = 0x000d;
        /** @brief Equivalent to GL_PATCHES.
         */
        static const OpenGL::Enum PATCHES                     = 0x000e;
        /** @brief Equivalent to GL_DEPTH_BUFFER_BIT.
         */
        static const OpenGL::Enum DEPTH_BUFFER_BIT            = 0x0100;
        /** @brief Equivalent to GL_NEVER.
         */
        static const OpenGL::Enum NEVER                       = 0x0200;
        /** @brief Equivalent to GL_LESS.
         */
        static const OpenGL::Enum LESS                        = 0x0201;
        /** @brief Equivalent to GL_EQUAL.
         */
        static const OpenGL::Enum EQUAL                       = 0x0202;
        /** @brief Equivalent to GL_LEQUAL.
         */
        static const OpenGL::Enum LEQUAL                      = 0x0203;
        /** @brief Equivalent to GL_GREATER.
         */
        static const OpenGL::Enum GREATER                     = 0x0204;
        /** @brief Equivalent to GL_NOTEQUAL.
         */
        static const OpenGL::Enum NOTEQUAL                    = 0x0205;
        /** @brief Equivalent to GL_GEQUAL.
         */
        static const OpenGL::Enum GEQUAL                      = 0x0206;
        /** @brief Equivalent to GL_ALWAYS.
         */
        static const OpenGL::Enum ALWAYS                      = 0x0207; 
        /** @brief Equivalent to GL_SRC_COLOR.
         */
        static const OpenGL::Enum SRC_COLOR                   = 0x0300;
        /** @brief Equivalent to GL_ONE_MINUS_SRC_COLOR.
         */
        static const OpenGL::Enum ONE_MINUS_SRC_COLOR         = 0x0301;
        /** @brief Equivalent to GL_SRC_ALPHA.
         */
        static const OpenGL::Enum SRC_ALPHA                   = 0x0302;
        /** @brief Equivalent to GL_ONE_MINUS_SRC_ALPHA.
         */
        static const OpenGL::Enum ONE_MINUS_SRC_ALPHA         = 0x0303;
        /** @brief Equivalent to GL_DST_ALPHA.
         */
        static const OpenGL::Enum DST_ALPHA                   = 0x0304;
        /** @brief Equivalent to GL_ONE_MINUS_DST_ALPHA.
         */
        static const OpenGL::Enum ONE_MINUS_DST_ALPHA         = 0x0305;
        /** @brief Equivalent to GL_DST_COLOR.
         */
        static const OpenGL::Enum DST_COLOR                   = 0x0306;
        /** @brief Equivalent to GL_ONE_MINUS_DST_COLOR.
         */
        static const OpenGL::Enum ONE_MINUS_DST_COLOR         = 0x0307;
        /** @brief Equivalent to GL_STENCIL_BUFFER_BIT.
         */
        static const OpenGL::Enum STENCIL_BUFFER_BIT          = 0x0400;
        /** @brief Equivalent to GL_CULL_FACE.
         */
        static const OpenGL::Enum CULL_FACE                   = 0x0b44;
        /** @brief Equivalent to GL_DEPTH_TEST.
         */
        static const OpenGL::Enum DEPTH_TEST                  = 0x0b71;
        /** @brief Equivalent to GL_STENCIL_TEST.
         */
        static const OpenGL::Enum STENCIL_TEST                = 0x0b90;
        /** @brief Equivalent to GL_BLEND.
         */
        static const OpenGL::Enum BLEND                       = 0x0be2;
        /** @brief Equivalent to GL_TEXTURE_2D.
         */
        static const OpenGL::Enum TEXTURE_2D                  = 0x0de1;
        /** @brief Equivalent to GL_BYTE.
         */
        static const OpenGL::Enum BYTE                        = 0x1400;
        /** @brief Equivalent to GL_UNSIGNED_BYTE.
         */
        static const OpenGL::Enum UNSIGNED_BYTE               = 0x1401;
        /** @brief Equivalent to GL_SHORT.
         */
        static const OpenGL::Enum SHORT                       = 0x1402;
        /** @brief Equivalent to GL_UNSIGNED_SHORT.
         */
        static const OpenGL::Enum UNSIGNED_SHORT              = 0x1403;
        /** @brief Equivalent to GL_INT.
         */
        static const OpenGL::Enum INT                         = 0x1404;
        /** @brief Equivalent to GL_UNSIGNED_INT.
         */
        static const OpenGL::Enum UNSIGNED_INT                = 0x1405;
        /** @brief Equivalent to GL_FLOAT.
         */
        static const OpenGL::Enum FLOAT                       = 0x1406;
        /** @brief Equivalent to GL_DOUBLE.
         */
        static const OpenGL::Enum DOUBLE                      = 0x140a;
        /** @brief Equivalent to GL_HALF_FLOAT.
         */
        static const OpenGL::Enum HALF_FLOAT                  = 0x140b;
        /** @brief Equivalent to GL_FIXED.
         */
        static const OpenGL::Enum FIXED                       = 0x140c;
        /** @brief Equivalent to GL_INVERT.
         */
        static const OpenGL::Enum INVERT                      = 0x150a;
        /** @brief Equivalent to GL_RED.
         */
        static const OpenGL::Enum RED                         = 0x1903;
        /** @brief Equivalent to GL_RGB.
         */
        static const OpenGL::Enum RGB                         = 0x1907;
        /** @brief Equivalent to GL_RGBA.
         */
        static const OpenGL::Enum RGBA                        = 0x1908;
        /** @brief Equivalent to GL_KEEP.
         */
        static const OpenGL::Enum KEEP                        = 0x1e00;
        /** @brief Equivalent to GL_INCR.
         */
        static const OpenGL::Enum INCR                        = 0x1e02;
        /** @brief Equivalent to GL_DECR.
         */
        static const OpenGL::Enum DECR                        = 0x1e03;
        /** @brief Equivalent to GL_VENDOR.
         */
        static const OpenGL::Enum VENDOR                      = 0x1f00;
        /** @brief Equivalent to GL_RENDERER.
         */
        static const OpenGL::Enum RENDERER                    = 0x1f01;
        /** @brief Equivalent to GL_VERSION.
         */
        static const OpenGL::Enum VERSION                     = 0x1f02;
        /** @brief Equivalent to GL_EXTENSIONS.
         */
        static const OpenGL::Enum EXTENSIONS                  = 0x1f03;
        /** @brief Equivalent to GL_NEAREST.
         */
        static const OpenGL::Enum NEAREST                     = 0x2600;
        /** @brief Equivalent to GL_LINEAR.
         */
        static const OpenGL::Enum LINEAR                      = 0x2601;
        /** @brief Equivalent to GL_TEXTURE_MAG_FILTER.
         */
        static const OpenGL::Enum TEXTURE_MAG_FILTER          = 0x2800;
        /** @brief Equivalent to GL_TEXTURE_MIN_FILTER.
         */
        static const OpenGL::Enum TEXTURE_MIN_FILTER          = 0x2801;
        /** @brief Equivalent to GL_REPEAT.
         */
        static const OpenGL::Enum REPEAT                      = 0x2901;
        /** @brief Equivalent to GL_COLOR_BUFFER_BIT.
         */
        static const OpenGL::Enum COLOR_BUFFER_BIT            = 0x4000;
        /** @brief Equivalent to GL_CONSTANT_COLOR.
         */
        static const OpenGL::Enum CONSTANT_COLOR              = 0x8001;
        /** @brief Equivalent to GL_ONE_MINUS_CONSTANT_COLOR.
         */
        static const OpenGL::Enum ONE_MINUS_CONSTANT_COLOR    = 0x8002;
        /** @brief Equivalent to GL_CONSTANT_ALPHA.
         */
        static const OpenGL::Enum CONSTANT_ALPHA              = 0x8003;
        /** @brief Equivalent to GL_ONE_MINUS_CONSTANT_ALPHA.
         */
        static const OpenGL::Enum ONE_MINUS_CONSTANT_ALPHA    = 0x8004;
        /** @brief Equivalent to GL_UNSIGNED_BYTE_3_3_2.
         */
        static const OpenGL::Enum UNSIGNED_BYTE_3_3_2         = 0x8032;
        /** @brief Equivalent to GL_UNSIGNED_SHORT_4_4_4_4.
         */
        static const OpenGL::Enum UNSIGNED_SHORT_4_4_4_4      = 0x8033;
        /** @brief Equivalent to GL_UNSIGNED_SHORT_5_5_5_1.
         */
        static const OpenGL::Enum UNSIGNED_SHORT_5_5_5_1      = 0x8034;
        /** @brief Equivalent to GL_UNSIGNED_INT_8_8_8_8.
         */
        static const OpenGL::Enum UNSIGNED_INT_8_8_8_8        = 0x8035;
        /** @brief Equivalent to GL_UNSIGNED_INT_10_10_10_2.
         */
        static const OpenGL::Enum UNSIGNED_INT_10_10_10_2     = 0x8036;
        /** @brief Equivalent to GL_PROXY_TEXTURE_2D.
         */
        static const OpenGL::Enum PROXY_TEXTURE_2D            = 0x8064;
        /** @brief Equivalent to GL_CLAMP_TO_BORDER.
         */
        static const OpenGL::Enum CLAMP_TO_BORDER             = 0x812d;
        /** @brief Equivalent to GL_CLAMP_TO_EDGE.
         */
        static const OpenGL::Enum CLAMP_TO_EDGE               = 0x812f;
         /** @brief Equivalent to GL_DEPTH_STENCIL_ATTACHMENT.
         */
        static const OpenGL::Enum DEPTH_STENCIL_ATTACHMENT    = 0x821a;
        /** @brief Equivalent to GL_MAJOR_VERSION.
         */
        static const OpenGL::Enum MAJOR_VERSION               = 0x821b;
        /** @brief Equivalent to GL_MINOR_VERSION.
         */
        static const OpenGL::Enum MINOR_VERSION               = 0x821c;
        /** @brief Equivalent to GL_RG.
         */
        static const OpenGL::Enum RG                          = 0x8227;
        /** @brief Equivalent to GL_UNSIGNED_BYTE_2_3_3_REV.
         */
        static const OpenGL::Enum UNSIGNED_BYTE_2_3_3_REV     = 0x8362;
        /** @brief Equivalent to GL_UNSIGNED_SHORT_5_6_5.
         */
        static const OpenGL::Enum UNSIGNED_SHORT_5_6_5        = 0x8363;
        /** @brief Equivalent to GL_UNSIGNED_SHORT_5_6_5_REV.
         */
        static const OpenGL::Enum UNSIGNED_SHORT_5_6_5_REV    = 0x8364;
        /** @brief Equivalent to GL_UNSIGNED_SHORT_4_4_4_4_REV.
         */
        static const OpenGL::Enum UNSIGNED_SHORT_4_4_4_4_REV  = 0x8365;
        /** @brief Equivalent to GL_UNSIGNED_SHORT_1_5_5_5_REV.
         */
        static const OpenGL::Enum UNSIGNED_SHORT_1_5_5_5_REV  = 0x8366;
        /** @brief Equivalent to GL_UNSIGNED_INT_8_8_8_8_REV.
         */
        static const OpenGL::Enum UNSIGNED_INT_8_8_8_8_REV    = 0x8367;
        /** @brief Equivalent to GL_UNSIGNED_INT_2_10_10_10_REV.
         */
        static const OpenGL::Enum UNSIGNED_INT_2_10_10_10_REV = 0x8368;
        /** @brief Equivalent to GL_MIRRORED_REPEAT.
         */
        static const OpenGL::Enum MIRRORED_REPEAT             = 0x8370;
        /** @brief Equivalent to GL_TEXTURE_RECTANGLE.
         */
        static const OpenGL::Enum TEXTURE_RECTANGLE           = 0x84f5;
        /** @brief Equivalent to GL_PROXY_TEXTURE_RECTANGLE.
         */
        static const OpenGL::Enum PROXY_TEXTURE_RECTANGLE     = 0x84f7;
        /** @brief Equivalent to GL_INCR_WRAP.
         */
        static const OpenGL::Enum INCR_WRAP                   = 0x8507;
        /** @brief Equivalent to GL_DECR_WRAP.
         */
        static const OpenGL::Enum DECR_WRAP                   = 0x8508;
        /** @brief Equivalent to GL_TEXTURE_CUBE_MAP_POSITIVE_X.
         */
        static const OpenGL::Enum TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
        /** @brief Equivalent to GL_TEXTURE_CUBE_MAP_NEGATIVE_X.
         */
        static const OpenGL::Enum TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
        /** @brief Equivalent to GL_TEXTURE_CUBE_MAP_POSITIVE_Y.
         */
        static const OpenGL::Enum TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
        /** @brief Equivalent to GL_TEXTURE_CUBE_MAP_NEGATIVE_Y.
         */
        static const OpenGL::Enum TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
        /** @brief Equivalent to GL_TEXTURE_CUBE_MAP_POSITIVE_Z.
         */
        static const OpenGL::Enum TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
        /** @brief Equivalent to GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.
         */
        static const OpenGL::Enum TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851a;
        /** @brief Equivalent to GL_PROXY_TEXTURE_CUBE_MAP.
         */
        static const OpenGL::Enum PROXY_TEXTURE_CUBE_MAP      = 0x851b;
        /** @brief Equivalent to GL_ARRAY_BUFFER.
         */
        static const OpenGL::Enum ARRAY_BUFFER                = 0x8892;
        /** @brief Equivalent to GL_ELEMENT_ARRAY_BUFFER.
         */
        static const OpenGL::Enum ELEMENT_ARRAY_BUFFER        = 0x8893;
        /** @brief Equivalent to GL_DEPTH24_STENCIL8.
         */
        static const OpenGL::Enum DEPTH24_STENCIL8            = 0x88f0;
        /** @brief Equivalent to GL_UNIFORM_BUFFER.
         */
        static const OpenGL::Enum UNIFORM_BUFFER              = 0x8a11;
        /** @brief Equivalent to GL_FRAGMENT_SHADER.
         */
        static const OpenGL::Enum FRAGMENT_SHADER             = 0x8b30;
        /** @brief Equivalent to GL_VERTEX_SHADER.
         */
        static const OpenGL::Enum VERTEX_SHADER               = 0x8b31;
        /** @brief Equivalent to GL_GLSL_VERSION.
         */
        static const OpenGL::Enum GLSL_VERSION                = 0x8b8c;
        /** @brief Equivalent to GL_TEXTURE_1D_ARRAY.
         */
        static const OpenGL::Enum TEXTURE_1D_ARRAY            = 0x8c18;
        /** @brief Equivalent to GL_PROXY_TEXTURE_1D_ARRAY.
         */
        static const OpenGL::Enum PROXY_TEXTURE_1D_ARRAY      = 0x8c19;
        /** @brief Equivalent to GL_TEXTURE_BUFFER.
         */
        static const OpenGL::Enum TEXTURE_BUFFER              = 0x8c2a;
        /** @brief Equivalent to GL_TRANSFORM_FEEDBACK_BUFFER.
         */
        static const OpenGL::Enum TRANSFORM_FEEDBACK_BUFFER   = 0x8c8e;
        /** @brief Equivalent to GL_COLOR_ATTACHMENT0.
         */
        static const OpenGL::Enum COLOR_ATTACHMENT0           = 0x8ce0;
        /** @brief Equivalent to GL_FRAMEBUFFER.
         */
        static const OpenGL::Enum FRAMEBUFFER                 = 0x8d40;
        /** @brief Equivalent to GL_INT_2_10_10_10_REV.
         */
        static const OpenGL::Enum INT_2_10_10_10_REV          = 0x8d9f;
        /** @brief Equivalent to GL_GEOMETRY_SHADER.
         */
        static const OpenGL::Enum GEOMETRY_SHADER             = 0x8dd9;
        /** @brief Equivalent to GL_TESS_CONTROL_SHADER.
         */
        static const OpenGL::Enum TESS_CONTROL_SHADER         = 0x8e88;
        /** @brief Equivalent to GL_TESS_EVALUATION_SHADER.
         */
        static const OpenGL::Enum TESS_EVALUATION_SHADER      = 0x8e87;
        /** @brief Equivalent to GL_BGR.
         */
        static const OpenGL::Enum BGR                         = 0x80e0;
        /** @brief Equivalent to GL_BGRA.
         */
        static const OpenGL::Enum BGRA                        = 0x80e1;
        /** @brief Equivalent to GL_RENDERBUFFER.
         */
        static const OpenGL::Enum RENDERBUFFER                = 0x8d41;
        /** @brief Equivalent to GL_STREAM_DRAW.
         */
        static const OpenGL::Enum STREAM_DRAW                 = 0x88e0;
        /** @brief Equivalent to GL_STREAM_READ.
         */
        static const OpenGL::Enum STREAM_READ                 = 0x88e1;
        /** @brief Equivalent to GL_STREAM_COPY.
         */
        static const OpenGL::Enum STREAM_COPY                 = 0x88e2;
        /** @brief Equivalent to GL_STATIC_DRAW.
         */
        static const OpenGL::Enum STATIC_DRAW                 = 0x88e4;
        /** @brief Equivalent to GL_STATIC_READ.
         */
        static const OpenGL::Enum STATIC_READ                 = 0x88e5;
        /** @brief Equivalent to GL_STATIC_COPY.
         */
        static const OpenGL::Enum STATIC_COPY                 = 0x88e6;
        /** @brief Equivalent to GL_DYNAMIC_DRAW.
         */
        static const OpenGL::Enum DYNAMIC_DRAW                = 0x88e8;
        /** @brief Equivalent to GL_DYNAMIC_READ.
         */
        static const OpenGL::Enum DYNAMIC_READ                = 0x88e9;
        /** @brief Equivalent to GL_DYNAMIC_COPY.
         */
        static const OpenGL::Enum DYNAMIC_COPY                = 0x88ea;
        /** @brief Equivalent to GL_PIXEL_PACK_BUFFER.
         */
        static const OpenGL::Enum PIXEL_PACK_BUFFER           = 0x88eb;
        /** @brief Equivalent to GL_PIXEL_UNPACK_BUFFER.
         */
        static const OpenGL::Enum PIXEL_UNPACK_BUFFER         = 0x88ec;
        /** @brief Equivalent to GL_COPY_READ_BUFFER.
         */
        static const OpenGL::Enum COPY_READ_BUFFER            = 0x8f36;
        /** @brief Equivalent to GL_COPY_WRITE_BUFFER.
         */
        static const OpenGL::Enum COPY_WRITE_BUFFER           = 0x8f37;
        /** @brief Equivalent to GL_DRAW_INDIRECT_BUFFER.
         */
        static const OpenGL::Enum DRAW_INDIRECT_BUFFER        = 0x8f3f;
        /** @brief Equivalent to GL_ATOMIC_COUNTER_BUFFER.
         */
        static const OpenGL::Enum ATOMIC_COUNTER_BUFFER       = 0x92c0;
        /** @brief Equivalent to GL_SHADER_STORAGE_BUFFER.
         */
        static const OpenGL::Enum SHADER_STORAGE_BUFFER       = 0x90d2;
    }
}
#include "../External/Undefines.h"