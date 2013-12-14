// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file VertexArray.cpp
 */

#include "VertexArray.hpp"

_CGUL_EXPORT CGUL::OpenGL::VertexArray::VertexArray()
{
    vertexArray = 0;
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::Create()
{
#   ifdef CGUL_MACOS
    glGenVertexArraysAPPLE(1, &vertexArray);
    GLCHECK("Failed to generate vertex array.", glGenVertexArraysAPPLE);
#   else
    glGenVertexArrays(1, &vertexArray);
    GLCHECK("Failed to generate vertex array.", glGenVertexArrays);
#   endif
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::Delete()
{
#   ifdef CGUL_MACOS
    glDeleteVertexArraysAPPLE(1, &vertexArray);
    GLCHECK("Failed to delete vertex array.", glDeleteVertexArraysAPPLE);
#   else
    glDeleteVertexArrays(1, &vertexArray);
    GLCHECK("Failed to delete vertex array.", glDeleteVertexArrays);
#   endif
}

_CGUL_EXPORT CGUL::UInt32 CGUL::OpenGL::VertexArray::GetID()
{
    return vertexArray;
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::Bind()
{
    if (vertexArray == 0)
    {
        throw std::runtime_error("Cannot bind invalid vertex array.");
    }
#   ifdef CGUL_MACOS
    glBindVertexArrayAPPLE(vertexArray);
    GLCHECK("Failed to bind vertex array.", glBindVertexArrayAPPLE);
#   else
    glBindVertexArray(vertexArray);
    GLCHECK("Failed to bind vertex array.", glBindVertexArray);
#   endif
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::Unbind()
{
#   ifdef CGUL_MACOS
    glBindVertexArrayAPPLE(0);
    GLCHECK("Failed to unbind vertex array.", glBindVertexArrayAPPLE);
#   else
    glBindVertexArray(0);
    GLCHECK("Failed to unbind vertex array.", glBindVertexArray);
#   endif
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::AttribPointer(UInt32 index, SInt32 size, Enum type, Boolean normalized, Size stride, const void* pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    GLCHECK("Failed to defined vertex attribute array data.", glVertexAttribPointer);
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::EnableAttribArray(UInt32 index)
{
    glEnableVertexAttribArray(index);
    GLCHECK("Failed to enable vertex attrib array.", glEnableVertexAttribArray);
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::DisableAttribArray(UInt32 index)
{
    glDisableVertexAttribArray(index);
    GLCHECK("Failed to disable vertex attrib array.", glDisableVertexAttribArray);
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::DrawArrays(Enum mode, SInt32 first, Size count)
{
    glDrawArrays(mode, first, (GLsizei)count);
    GLCHECK("Failed to draw arrays.", glDrawArrays);
}

_CGUL_EXPORT void CGUL::OpenGL::VertexArray::DrawElements(Enum mode, Size count, Enum type, const void* indices)
{
    glDrawElements(mode, count, type, indices);
    GLCHECK("Failed to draw elements.", glDrawElements);
}
_CGUL_EXPORT void CGUL::OpenGL::VertexArray::DrawElementsBaseVertex(Enum mode, Size count, Enum type, void* indices, UInt32 baseVertex)
{
    glDrawElementsBaseVertex(mode, count, type, indices, baseVertex);
    GLCHECK("Failed to draw elements.", glDrawElementsBaseVertex);
}
