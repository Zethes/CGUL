/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Program.h"
#include "../Exceptions/FatalException.h"
#include "../Exceptions/OpenGLException.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform1f(SInt32 location, Float32 value0)
{
    glUniform1f(location, value0);
    GLCHECK("glUniform1f failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2f(SInt32 location, Float32 value0, Float32 value1)
{
    glUniform2f(location, value0, value1);
    GLCHECK("glUniform2f failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2f(SInt32 location, Vector2 value)
{
    glUniform2f(location, value.x, value.y);
    GLCHECK("glUniform2f failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3f(SInt32 location, Float32 value0, Float32 value1, Float32 value2)
{
    glUniform3f(location, value0, value1, value2);
    GLCHECK("glUniform3f failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3f(SInt32 location, Vector3 value)
{
    glUniform3f(location, value.x, value.y, value.z);
    GLCHECK("glUniform3f failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4f(SInt32 location, Float32 value0, Float32 value1, Float32 value2, Float32 value3)
{
    glUniform4f(location, value0, value1, value2, value3);
    GLCHECK("glUniform4f failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4f(SInt32 location, Vector4 value)
{
    glUniform4f(location, value.x, value.y, value.z, value.w);
    GLCHECK("glUniform4f failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform1i(SInt32 location, SInt32 value0)
{
    glUniform1i(location, value0);
    GLCHECK("glUniform1i failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2i(SInt32 location, SInt32 value0, SInt32 value1)
{
    glUniform2i(location, value0, value1);
    GLCHECK("glUniform2i failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3i(SInt32 location, SInt32 value0, SInt32 value1, SInt32 value2)
{
    glUniform3i(location, value0, value1, value2);
    GLCHECK("glUniform3i failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4i(SInt32 location, SInt32 value0, SInt32 value1, SInt32 value2, SInt32 value3)
{
    glUniform4i(location, value0, value1, value2, value3);
    GLCHECK("glUniform4i failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform1ui(UInt32 location, UInt32 value0)
{
    glUniform1ui(location, value0);
    GLCHECK("glUniform1ui failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2ui(UInt32 location, UInt32 value0, UInt32 value1)
{
    glUniform2ui(location, value0, value1);
    GLCHECK("glUniform2ui failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3ui(UInt32 location, UInt32 value0, UInt32 value1, UInt32 value2)
{
    glUniform3ui(location, value0, value1, value2);
    GLCHECK("glUniform3ui failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4ui(UInt32 location, UInt32 value0, UInt32 value1, UInt32 value2, UInt32 value3)
{
    glUniform4ui(location, value0, value1, value2, value3);
    GLCHECK("glUniform4ui failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform1fv(SInt32 location, Size count, const Float32* value)
{
    glUniform1fv(location, count, value);
    GLCHECK("glUniform1fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2fv(SInt32 location, Size count, const Float32* value)
{
    glUniform2fv(location, count, value);
    GLCHECK("glUniform2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2fv(SInt32 location, Size count, const Vector2* value)
{
    glUniform2fv(location, count * 2, (float*)value);
    GLCHECK("glUniform2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3fv(SInt32 location, Size count, const Float32* value)
{
    glUniform3fv(location, count, value);
    GLCHECK("glUniform3fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3fv(SInt32 location, Size count, const Vector3* value)
{
    glUniform3fv(location, count * 3, (float*)value);
    GLCHECK("glUniform3fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4fv(SInt32 location, Size count, const Float32* value)
{
    glUniform4fv(location, count, value);
    GLCHECK("glUniform4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4fv(SInt32 location, Size count, const Vector4* value)
{
    glUniform4fv(location, count * 4, (float*)value);
    GLCHECK("glUniform4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform1iv(SInt32 location, Size count, const SInt32* value)
{
    glUniform1iv(location, count, value);
    GLCHECK("glUniform1iv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2iv(SInt32 location, Size count, const SInt32* value)
{
    glUniform2iv(location, count, value);
    GLCHECK("glUniform2iv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3iv(SInt32 location, Size count, const SInt32* value)
{
    glUniform3iv(location, count, value);
    GLCHECK("glUniform3iv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4iv(SInt32 location, Size count, const SInt32* value)
{
    glUniform4iv(location, count, value);
    GLCHECK("glUniform4iv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform1uiv(SInt32 location, Size count, const UInt32* value)
{
    glUniform1uiv(location, count, value);
    GLCHECK("glUniform1uiv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform2uiv(SInt32 location, Size count, const UInt32* value)
{
    glUniform2uiv(location, count, value);
    GLCHECK("glUniform2uiv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform3uiv(SInt32 location, Size count, const UInt32* value)
{
    glUniform3uiv(location, count, value);
    GLCHECK("glUniform3uiv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Uniform4uiv(SInt32 location, Size count, const UInt32* value)
{
    glUniform4uiv(location, count, value);
    GLCHECK("glUniform4uiv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix2f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix2fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix3f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix3fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix3fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix4fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4f(SInt32 location, Boolean transpose, const Matrix& value)
{
    glUniformMatrix4fv(location, 1, transpose, value.GetData());
    GLCHECK("glUniformMatrix4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix2x3f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix2x3fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix2x3fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix3x2f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix3x2fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix3x2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix2x4f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix2x4fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix2x4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4x2f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix4x2fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix4x2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix3x4f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix3x4fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix3x4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4x3f(SInt32 location, Boolean transpose, const Float32* value)
{
    glUniformMatrix4x3fv(location, 1, transpose, value);
    GLCHECK("glUniformMatrix4x3fv failed!");
}


_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix2fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix2fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix3fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix3fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix3fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix4fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4fv(SInt32 location, Size count, Boolean transpose, const Matrix* value)
{
    glUniformMatrix4fv(location, count, transpose, value->GetData());
    GLCHECK("glUniformMatrix4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix2x3fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix2x3fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix2x3fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix3x2fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix3x2fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix3x2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix2x4fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix2x4fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix2x4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4x2fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix4x2fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix4x2fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix3x4fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix3x4fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix3x4fv failed!");
}

_JATTA_EXPORT void Jatta::OpenGL::Program::UniformMatrix4x3fv(SInt32 location, Size count, Boolean transpose, const Float32* value)
{
    glUniformMatrix4x3fv(location, count, transpose, value);
    GLCHECK("glUniformMatrix4x3fv failed!");
}

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
    if (program == 0)
    {
        throw std::runtime_error("Cannot bind invalid program.");
    }
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
    GLint status;
    glLinkProgram(program);
    GLCHECK("Failed to link program.");
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    GLCHECK("Failed to get link status of program.");
    if (status != GL_TRUE)
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
        log.Trim();
        throw FatalException(U8("Failed to link program:\n") + log);
    }
}

_JATTA_EXPORT void Jatta::OpenGL::Program::Validate()
{
    GLint status;
    glValidateProgram(program);
    GLCHECK("Failed to validate program.");
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
    GLCHECK("Failed to get validate status of program.");
    if (status != GL_TRUE)
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
        log.Trim();
        throw FatalException(U8("Failed to validate program:\n") + log);
    }
}

_JATTA_EXPORT Jatta::Boolean Jatta::OpenGL::Program::GetDeleteStatus()
{
    GLint status;
    glGetProgramiv(program, GL_DELETE_STATUS, &status);
    GLCHECK("Failed to get delete status of program.");
    return status == GL_TRUE;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::OpenGL::Program::GetUniformLocation(const String& name)
{
    SInt32 location = glGetUniformLocation(program, name.GetData().c_str());
    GLCHECK("Failed to get uniform location.");
    return location;
}
