/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_OPENGL
#include "VertexArray.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

_JATTA_EXPORT Jatta::OpenGL::VertexArray::VertexArray()
{
    vertexArray = 0;
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::Create()
{
    glGenVertexArrays(1, &vertexArray);
    GLCHECK("Failed to generate vertex array.");
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::Delete()
{
    glDeleteVertexArrays(1, &vertexArray);
    GLCHECK("Failed to delete vertex array.");
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::VertexArray::GetID()
{
    return vertexArray;
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::Bind()
{
    glBindVertexArray(vertexArray);
    GLCHECK("Failed to bind vertex array.");
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::Unbind()
{
    glBindVertexArray(0);
    GLCHECK("Failed to unbind vertex array.");
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::AttribPointer(UInt32 index, SInt32 size, Enum type, Boolean normalized, Size stride, const void* pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    GLCHECK("Failed to defined vertex attribute array data.");
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::EnableAttribArray(UInt32 index)
{
    glEnableVertexAttribArray(index);
    GLCHECK("Failed to enable vertex attrib array.");
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::DisableAttribArray(UInt32 index)
{
    glDisableVertexAttribArray(index);
    GLCHECK("Failed to disable vertex attrib array.");
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::DrawArrays(Enum mode, SInt32 first, Size count)
{
    glDrawArrays(mode, first, (GLsizei)count);
    GLCHECK("Failed to draw arrays.");
}

_JATTA_EXPORT void Jatta::OpenGL::VertexArray::DrawElements(Enum mode, Size count, Enum type, const void* indices)
{
    glDrawElements(mode, count, type, indices);
    GLCHECK("Failed to draw elements.");
}

#endif