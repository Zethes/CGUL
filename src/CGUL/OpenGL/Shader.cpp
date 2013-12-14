// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Shader.cpp
 */

#include "Shader.hpp"
#include "../Exceptions/FatalException.hpp"
#include "../Exceptions/OpenGLException.hpp"

_CGUL_EXPORT CGUL::OpenGL::Shader::Shader()
{
    shader = 0;
}

_CGUL_EXPORT CGUL::OpenGL::Shader::~Shader()
{
}

/** @brief Equivalent to
 *  <a href="http://www.opengl.org/sdk/docs/man/xhtml/glCreateShader.xml">glCreateShader()</a>.
 *  @param type An enumeration type which can be GL::VERTEX_SHADER, GL::TESS_CONTROL_SHADER,
 *  GL::TESS_EVALUATION_SHADER, GL::GEOMETRY_SHADER, or GL::FRAGMENT_SHADER.
 */
_CGUL_EXPORT void CGUL::OpenGL::Shader::Create(Enum type)
{
    shader = glCreateShader((GLenum)type);
    GLCHECK("Failed to create shader.", glCreateShader);
}

/** @brief Equivalent to
 *  <a href="http://www.opengl.org/sdk/docs/man/xhtml/glDeleteShader.xml">glDeleteShader()</a>.
 */
_CGUL_EXPORT void CGUL::OpenGL::Shader::Delete()
{
    glDeleteShader((GLuint)shader);
    GLCHECK("Failed to delete shader.", glDeleteShader);
    shader = 0;
}

_CGUL_EXPORT CGUL::UInt32 CGUL::OpenGL::Shader::GetID() const
{
    return shader;
}

_CGUL_EXPORT void CGUL::OpenGL::Shader::SetSource(const CGUL::String& source)
{
    const char* characters = source.GetCString();
    const GLchar** data = &characters;
    GLint count = (GLint)source.GetSize();
    glShaderSource((GLuint)shader, (GLsizei)1, data, &count);
    GLCHECK("Failed to set shader source.", glShaderSource);
}

_CGUL_EXPORT void CGUL::OpenGL::Shader::Compile()
{
    GLint status;
    glCompileShader(shader);
    GLCHECK("Failed to compile shader.", glCompileShader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    GLCHECK("Failed to get shader compile status.", glGetShaderiv);
    if (status != GL_TRUE)
    {
        GLint size;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
        GLCHECK("Failed to get shader info log length.", glGetShaderiv);
        GLsizei length;
        GLchar* buffer = new GLchar[size];
        glGetShaderInfoLog(shader, (GLsizei)size, &length, buffer);
        GLCHECK("Failed to get shader info log.", glGetShaderInfoLog);
        String log((char*)buffer);
        delete[] buffer;
        log.Trim();
        throw FatalException(U8("Failed to compile shader:\n") + log);
    }
}

_CGUL_EXPORT CGUL::Enum CGUL::OpenGL::Shader::GetShaderType()
{
    // TODO: OpenGL::Shader::GetShaderType
    return 0;
}

_CGUL_EXPORT CGUL::Boolean CGUL::OpenGL::Shader::GetDeleteStatus()
{
    GLint status;
    glGetShaderiv(shader, GL_DELETE_STATUS, &status);
    GLCHECK("Failed to get delete status of shader.", glGetShaderiv);
    return status == GL_TRUE;
}

_CGUL_EXPORT CGUL::String CGUL::OpenGL::Shader::GetSource()
{
    GLint size;
    glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &size);
    GLCHECK("Failed to get shader source length.", glGetShaderiv);
    GLsizei length;
    GLchar* buffer = new GLchar[size];
    glGetShaderSource(shader, (GLsizei)size, &length, buffer);
    GLCHECK("Failed to get shader source.", glGetShaderSource);
    String source((char*)buffer);
    delete[] buffer;
    return source;
}
