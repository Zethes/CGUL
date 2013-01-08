/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Shader.h"

 #define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

Jatta::OpenGL::Shader::Shader()
{
    shader = 0;
}

Jatta::OpenGL::Shader::~Shader()
{
    if (shader != 0)
    {
        glDeleteShader((GLuint)shader);
    }
}

void Jatta::OpenGL::Shader::Create(Type type)
{
    shader = glCreateShader((GLenum)type);
    GLCHECK("Failed to create shader.");
}

void Jatta::OpenGL::Shader::Delete()
{
    glDeleteShader((GLuint)shader);
    GLCHECK("Failed to delete shader.");
    shader = 0;
}

Jatta::UInt32 Jatta::OpenGL::Shader::GetID() const
{
    return shader;
}

void Jatta::OpenGL::Shader::Source(const Jatta::String& source)
{
    const char* characters = &(source.GetData()[0]);
    const GLchar** data = &characters;
    glShaderSource((GLuint)shader, (GLsizei)1, data, nullptr);
    GLCHECK("Failed to set shader source.");
}

void Jatta::OpenGL::Shader::Compile()
{
    glCompileShader(shader);
    GLCHECK("Failed to compile shader.");
}

Jatta::OpenGL::Shader::Type Jatta::OpenGL::Shader::GetShaderType()
{
    // TODO: this
}

Jatta::Boolean Jatta::OpenGL::Shader::GetDeleteStatus()
{
    GLint status;
    glGetShaderiv(shader, GL_DELETE_STATUS, &status);
    GLCHECK("Failed to get delete status of shader.");
    return status == GL_TRUE;
}

Jatta::Boolean Jatta::OpenGL::Shader::GetCompileStatus()
{
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    GLCHECK("Failed to get compile status of shader.");
    return status == GL_TRUE;
}

Jatta::String Jatta::OpenGL::Shader::GetInfoLog()
{
    GLint size;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
    GLCHECK("Failed to get shader info log length.");
    GLsizei length;
    GLchar* buffer = new GLchar[size];
    glGetShaderInfoLog(shader, (GLsizei)size, &length, buffer);
    GLCHECK("Failed to get shader info log.");
    return String((char*)buffer);
}

Jatta::String Jatta::OpenGL::Shader::GetSource()
{
}