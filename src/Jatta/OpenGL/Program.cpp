/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Program.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

Jatta::OpenGL::Program::Program()
{
    program = 0;
}

Jatta::OpenGL::Program::~Program()
{
}

void Jatta::OpenGL::Program::Generate()
{
    program = glCreateProgram();
    GLCHECK("Failed to create program.");
}

void Jatta::OpenGL::Program::Delete()
{
    glDeleteProgram(program);
    GLCHECK("Failed to delete program.");
    program = 0;
}

Jatta::UInt32 Jatta::OpenGL::Program::GetID()
{
    return program;
}

void Jatta::OpenGL::Program::Bind()
{
    glUseProgram(program);
    GLCHECK("Failed to bind program.");
}

void Jatta::OpenGL::Program::Unbind()
{
    glUseProgram(0);
    GLCHECK("Failed to unbind program.");
}

void Jatta::OpenGL::Program::AttachShader(const Shader& shader)
{
    glAttachShader(program, shader.GetID());
    GLCHECK("Failed to attach shader to program.");
}

void Jatta::OpenGL::Program::DetachShader(const Shader& shader)
{
    glDetachShader(program, shader.GetID());
    GLCHECK("Failed to detach shader to program.");
}