/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Program.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

_JATTA_EXPORT Jatta::OpenGL::Program::Program()
{
    program = 0;
}

_JATTA_EXPORT Jatta::OpenGL::Program::~Program()
{
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Create()
{
    program = glCreateProgram();
    GLCHECK("Failed to create program.");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Delete()
{
    glDeleteProgram(program);
    GLCHECK("Failed to delete program.");
    program = 0;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::Program::GetID()
{
    return program;
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Bind()
{
    glUseProgram(program);
    GLCHECK("Failed to bind program.");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Unbind()
{
    glUseProgram(0);
    GLCHECK("Failed to unbind program.");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::AttachShader(const Shader& shader)
{
    glAttachShader(program, shader.GetID());
    GLCHECK("Failed to attach shader to program.");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::DetachShader(const Shader& shader)
{
    glDetachShader(program, shader.GetID());
    GLCHECK("Failed to detach shader to program.");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::BindAttribLocation(UInt32 index, const String& name)
{
    glBindAttribLocation(program, index, name.GetData().c_str());
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Link()
{
    glLinkProgram(program);
    GLCHECK("Failed to link program.");
}

_JATTA_EXPORT Jatta::Boolean Jatta::OpenGL::Program::GetDeleteStatus()
{
    GLint status;
    glGetProgramiv(program, GL_DELETE_STATUS, &status);
    GLCHECK("Failed to get delete status of program.");
    return status == GL_TRUE;
}

_JATTA_EXPORT Jatta::Boolean Jatta::OpenGL::Program::GetLinkStatus()
{
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    GLCHECK("Failed to get link status of program.");
    return status == GL_TRUE;
}

_JATTA_EXPORT Jatta::Boolean Jatta::OpenGL::Program::GetValidateStatus()
{
    GLint status;
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
    GLCHECK("Failed to get validate status of program.");
    return status == GL_TRUE;
}

_JATTA_EXPORT Jatta::String Jatta::OpenGL::Program::GetInfoLog()
{
    GLint size;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &size);
    GLCHECK("Failed to get program info log length.");
    GLsizei length;
    GLchar* buffer = new GLchar[size];
    glGetProgramInfoLog(program, (GLsizei)size, &length, buffer);
    GLCHECK("Failed to get program info log.");
    String log((char*)buffer);
    delete[] buffer;
    return log;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::OpenGL::Program::GetUniformLocation(const String& name)
{
    return glGetUniformLocation(program, name.GetData().c_str());
}