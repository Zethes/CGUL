/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

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
