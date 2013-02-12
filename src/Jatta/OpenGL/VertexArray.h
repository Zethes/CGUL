/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "OpenGL.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class VertexArray
        {
            UInt32 vertexArray;
        public:
            _JATTA_EXPORT VertexArray();

            _JATTA_EXPORT void Create();
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID();

            _JATTA_EXPORT void Bind();
            _JATTA_EXPORT void Unbind();

            _JATTA_EXPORT void AttribPointer(UInt32 index, SInt32 size, Enum type, Boolean normalized, Size stride, const void* pointer);
            _JATTA_EXPORT void EnableAttribArray(UInt32 index);
            _JATTA_EXPORT void DisableAttribArray(UInt32 index);

            _JATTA_EXPORT void DrawArrays(Enum mode, SInt32 first, Size count);
            _JATTA_EXPORT void DrawElements(Enum mode, Size count, Enum type, const void* indices);

            // TODO: finish importing opengl vertex array functions
        };
    }
}
#include "../External/Undefines.h"