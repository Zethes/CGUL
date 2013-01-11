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

        static UInt32 COLOR_BUFFER_BIT = 0x4000;
        static UInt32 DEPTH_BUFFER_BIT = 0x100;
        static UInt32 STENCIL_BUFFER_BIT = 0x400;

        static UInt32 VERTEX_SHADER = 0x8b31;
        static UInt32 TESS_CONTROL_SHADER = 0x8e88;
        static UInt32 TESS_EVALUATION_SHADER = 0x8e87;
        static UInt32 GEOMETRY_SHADER = 0x8dd9;
        static UInt32 FRAGMENT_SHADER = 0x8b30;

        _JATTA_EXPORT void ClearErrors();
        _JATTA_EXPORT void Test();
    }
}
#include "../External/Undefines.h"