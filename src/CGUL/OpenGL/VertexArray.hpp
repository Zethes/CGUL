// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file VertexArray.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "OpenGL.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    namespace OpenGL
    {
        class VertexArray
        {
            UInt32 vertexArray;
        public:
            DEPRECATED(_CGUL_EXPORT VertexArray(), "Use Raw GL wrappers instead.");

            _CGUL_EXPORT void Create();
            _CGUL_EXPORT void Delete();
            _CGUL_EXPORT UInt32 GetID();

            _CGUL_EXPORT void Bind();
            _CGUL_EXPORT void Unbind();

            _CGUL_EXPORT void AttribPointer(UInt32 index, SInt32 size, Enum type, Boolean normalized, Size stride, const void* pointer);
            _CGUL_EXPORT void EnableAttribArray(UInt32 index);
            _CGUL_EXPORT void DisableAttribArray(UInt32 index);

            _CGUL_EXPORT void DrawArrays(Enum mode, SInt32 first, Size count);
            _CGUL_EXPORT void DrawElements(Enum mode, Size count, Enum type, const void* indices);
            _CGUL_EXPORT void DrawElementsBaseVertex(Enum mode, Size count, Enum type, void* indices, UInt32 baseVertex);

            // TODO: finish importing opengl vertex array functions
        };
    }
}
#include "../External/Undefines.hpp"
