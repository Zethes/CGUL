/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "RawGL.h"
#include "../Math/Matrix.h"

_JATTA_EXPORT void Jatta::GL::ActiveTexture(Enum target)
{
    GLCLEAR();
    glActiveTexture(target);
    GLCHECK("Failed to set active texture.");
}

_JATTA_EXPORT void Jatta::GL::AttachShader(UInt program, UInt shader)
{
    GLCLEAR();
    glAttachShader(program, shader);
    GLCHECK("Failed to attach shader.");
}

_JATTA_EXPORT void Jatta::GL::BindAttribLocation(UInt program, UInt index, const char* name)
{
    GLCLEAR();
    glBindAttribLocation(program, index, name);
    GLCHECK("Failed to bind attribute location.");
}

_JATTA_EXPORT void Jatta::GL::BindAttribLocation(UInt program, UInt index, const String& name)
{
    GLCLEAR();
    glBindAttribLocation(program, index, name.GetCString());
    GLCHECK("Failed to bind attribute location.");
}

_JATTA_EXPORT void Jatta::GL::BindBuffer(Enum target, UInt buffer)
{
    GLCLEAR();
    glBindBuffer(target, buffer);
    GLCHECK("Failed to bind buffer.");
}

_JATTA_EXPORT void Jatta::GL::BindTexture(Enum target, UInt texture)
{
    GLCLEAR();
    glBindTexture(target, texture);
    GLCHECK("Failed to bind texture.");
}

_JATTA_EXPORT void Jatta::GL::BindVertexArray(UInt array)
{
    GLCLEAR();
#   ifdef APPLE
    glBindVertexArrayAPPLE(array);
#   else
    glBindVertexArray(array);
#   endif
    GLCHECK("Failed to bind vertex array.");
}

_JATTA_EXPORT void Jatta::GL::BlendFunc(Enum sfactor, Enum dfactor)
{
    GLCLEAR();
    glBlendFunc(sfactor, dfactor);
    GLCHECK("Failed to set blend function.");
}

_JATTA_EXPORT void Jatta::GL::BlendFunci(UInt buf, Enum sfactor, Enum dfactor)
{
    GLCLEAR();
    glBlendFunci(buf, sfactor, dfactor);
    GLCHECK("Failed to set blend function.");
}

_JATTA_EXPORT void Jatta::GL::BufferData(Enum target, PtrDiff size, const void* data, Enum usage)
{
    GLCLEAR();
    glBufferData(target, size, data, usage);
    GLCHECK("Failed to set buffer data.");
}

_JATTA_EXPORT void Jatta::GL::CompileShader(UInt shader)
{
    GLCLEAR();
    glCompileShader(shader);
    GLCHECK("Failed to compile shader.");
}

_JATTA_EXPORT Jatta::UInt Jatta::GL::CreateProgram()
{
    GLCLEAR();
    Jatta::UInt ret = glCreateProgram();
    GLCHECK("Failed to create program.");
    return ret;
}

_JATTA_EXPORT Jatta::UInt Jatta::GL::CreateShader(Enum shaderType)
{
    GLCLEAR();
    Jatta::UInt ret = glCreateShader(shaderType);
    GLCHECK("Failed to create shader.");
    return ret;
}

_JATTA_EXPORT void Jatta::GL::Disable(Enum cap)
{
    GLCLEAR();
    glDisable(cap);
    GLCHECK("Failed to disable capability.");
}

_JATTA_EXPORT void Jatta::GL::DisableVertexAttribArray(UInt index)
{
    GLCLEAR();
    glDisableVertexAttribArray(index);
    GLCHECK("Failed to disable vertex attribute array.");
}

_JATTA_EXPORT void Jatta::GL::DrawArrays(Enum mode, SInt first, SignedSize count)
{
    GLCLEAR();
    glDrawArrays(mode, first, count);
    GLCHECK("Failed to draw arrays.");
}

_JATTA_EXPORT void Jatta::GL::DrawElements(Enum mode, SignedSize count, Enum type, const void* indices)
{
	GLCLEAR();
    glDrawElements(mode, count, type, indices);
    GLCHECK("Failed to draw elements.");
}

_JATTA_EXPORT void Jatta::GL::Enable(Enum cap)
{
    GLCLEAR();
    glEnable(cap);
    GLCHECK("Failed to enable capability.");
}

_JATTA_EXPORT void Jatta::GL::EnableVertexAttribArray(UInt index)
{
    GLCLEAR();
    glEnableVertexAttribArray(index);
    GLCHECK("Failed to enable vertex attribute array.");
}

_JATTA_EXPORT void Jatta::GL::GenBuffers(SignedSize n, UInt* buffers)
{
    GLCLEAR();
    glGenBuffers(n, buffers);
    GLCHECK("Failed to generate buffers.");
}

_JATTA_EXPORT void Jatta::GL::GenTextures(SignedSize n, UInt* textures)
{
    GLCLEAR();
    glGenTextures(n, textures);
    GLCHECK("Failed to generate textures.");
}

_JATTA_EXPORT void Jatta::GL::GenVertexArrays(SignedSize n, UInt* arrays)
{
    GLCLEAR();
#   ifdef APPLE
    glGenVertexArraysAPPLE(n, arrays);
#   else
    glGenVertexArrays(n, arrays);
#   endif
    GLCHECK("Failed to generate vertex arrays.");
}

_JATTA_EXPORT void Jatta::GL::GetProgramInfoLog(UInt program, SignedSize maxLength, SignedSize* length, char* infoLog)
{
    GLCLEAR();
    glGetProgramInfoLog(program, maxLength, (GLsizei*)length, infoLog);
    GLCHECK("Failed to get shader info log.");
}

_JATTA_EXPORT void Jatta::GL::GetProgramInfoLog(UInt program, String* infoLog)
{
    GLCLEAR();
    SInt maxLength;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
    // TODO: length could be 0 if there is no log info, need to handle that case
    char* buffer = new char[maxLength];
    SignedSize length;
    glGetProgramInfoLog(program, maxLength, (GLsizei*)&length, buffer);
    *infoLog = buffer;
    delete[] buffer;
    GLCHECK("Failed to get shader info log.");
}

_JATTA_EXPORT void Jatta::GL::GetProgramiv(UInt program, Enum pname, SInt* params)
{
    GLCLEAR();
    glGetProgramiv(program, pname, params);
    GLCHECK("Failed to get program parameter.");
}

_JATTA_EXPORT void Jatta::GL::GetShaderInfoLog(UInt shader, SignedSize maxLength, SignedSize* length, char* infoLog)
{
    GLCLEAR();
    glGetShaderInfoLog(shader, maxLength, (GLsizei*)length, infoLog);
    GLCHECK("Failed to get shader info log.");
}

_JATTA_EXPORT void Jatta::GL::GetShaderInfoLog(UInt shader, String* infoLog)
{
    GLCLEAR();
    SInt maxLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
    // TODO: length could be 0 if there is no log info, need to handle that case
    char* buffer = new char[maxLength];
    SignedSize length;
    glGetShaderInfoLog(shader, maxLength, (GLsizei*)&length, buffer);
    *infoLog = buffer;
    delete[] buffer;
    GLCHECK("Failed to get shader info log.");
}

_JATTA_EXPORT void Jatta::GL::GetShaderiv(UInt shader, Enum pname, SInt* params)
{
    GLCLEAR();
    glGetShaderiv(shader, pname, params);
    GLCHECK("Failed to get shader parameter.");
}

_JATTA_EXPORT Jatta::SInt Jatta::GL::GetUniformLocation(UInt program, const char* name)
{
    SInt ret = glGetUniformLocation(program, name);
    GLCHECK("Failed to get uniform location.");
    return ret;
}

_JATTA_EXPORT Jatta::SInt Jatta::GL::GetUniformLocation(UInt program, String& name)
{
    SInt ret = glGetUniformLocation(program, name.GetCString());
    GLCHECK("Failed to get uniform location.");
    return ret;
}

_JATTA_EXPORT void Jatta::GL::LinkProgram(UInt program)
{
    GLCLEAR();
    glLinkProgram(program);
    GLCHECK("Failed to link program.");
}

_JATTA_EXPORT void Jatta::GL::PixelStoref(Enum pname, Float32 param)
{
    glPixelStoref(pname, param);
}

_JATTA_EXPORT void Jatta::GL::PixelStorei(Enum pname, SInt param)
{
    glPixelStorei(pname, param);
}

_JATTA_EXPORT Jatta::UInt Jatta::GL::ShaderSource(UInt shader, SignedSize count, const char** string, const SInt* length)
{
    GLCLEAR();
    glShaderSource(shader, count, string, length);
    GLCHECK("Failed to set the shader source.");
}

_JATTA_EXPORT Jatta::UInt Jatta::GL::ShaderSource(UInt shader, const char* string)
{
    GLCLEAR();
    const char** data = &string;
    SInt length = (SInt)strlen(string);
    glShaderSource(shader, 1, data, &length);
    GLCHECK("Failed to set the shader source.");
}

_JATTA_EXPORT Jatta::UInt Jatta::GL::ShaderSource(UInt shader, const Jatta::String& string)
{
    GLCLEAR();
    const char* cstr = string.GetCString();
    const char** data = &cstr;
    SInt length = (SInt)string.GetLength();
    glShaderSource(shader, 1, data, &length);
    GLCHECK("Failed to set the shader source.");
}

_JATTA_EXPORT void Jatta::GL::TexEnvf(Enum target, Enum pname, Float32 param)
{
    GLCLEAR();
    glTexEnvf(target, pname, param);
    GLCHECK("Failed to set texture environment parameters.");
}

_JATTA_EXPORT void Jatta::GL::TexEnvi(Enum target, Enum pname, SInt param)
{
    GLCLEAR();
    glTexEnvf(target, pname, param);
    GLCHECK("Failed to set texture environment parameters.");
}

_JATTA_EXPORT void Jatta::GL::TexImage2D(Enum target, SInt level, SInt internalFormat, SignedSize width, SignedSize height, SInt border, Enum format, Enum type, const void* data)
{
    GLCLEAR();
    glTexImage2D(target, level, internalFormat, width, height, border, format, type, data);
    GLCHECK("Failed to set texture 2D image.");
}

_JATTA_EXPORT void Jatta::GL::TexParameterf(Enum target, Enum pname, Float32 param)
{
    GLCLEAR();
    glTexParameterf(target, pname, param);
    GLCHECK("Failed to set texture parameter.");
}

_JATTA_EXPORT void Jatta::GL::TexParameteri(Enum target, Enum pname, SInt param)
{
    GLCLEAR();
    glTexParameteri(target, pname, param);
    GLCHECK("Failed to set texture parameter.");
}

_JATTA_EXPORT void Jatta::GL::Uniform1f(SInt location, Float32 v0)
{
    GLCLEAR();
    glUniform1f(location, v0);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform1fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    glUniform1fv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform1i(SInt location, SInt v0)
{
    GLCLEAR();
    glUniform1i(location, v0);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform1iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    glUniform1iv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform2f(SInt location, Float32 v0, Float32 v1)
{
    GLCLEAR();
    glUniform2f(location, v0, v1);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform2fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    glUniform2fv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform2i(SInt location, SInt v0, SInt v1)
{
    GLCLEAR();
    glUniform2i(location, v0, v1);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform2iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    glUniform2iv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform3f(SInt location, Float32 v0, Float32 v1, Float32 v2)
{
    GLCLEAR();
    glUniform3f(location, v0, v1, v2);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform3fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    glUniform3fv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform3i(SInt location, SInt v0, SInt v1, SInt v2)
{
    GLCLEAR();
    glUniform3i(location, v0, v1, v2);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform3iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    glUniform3iv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform4f(SInt location, Float32 v0, Float32 v1, Float32 v2, Float32 v3)
{
    GLCLEAR();
    glUniform4f(location, v0, v1, v2, v3);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform4fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    glUniform4fv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform4i(SInt location, SInt v0, SInt v1, SInt v2, SInt v3)
{
    GLCLEAR();
    glUniform4i(location, v0, v1, v2, v3);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::Uniform4iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    glUniform4iv(location, count, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::UniformMatrix2fv(SInt location, SignedSize count, bool transpose, const Float32* value)
{
    GLCLEAR();
    glUniformMatrix2fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::UniformMatrix3fv(SInt location, SignedSize count, bool transpose, const Float32* value)
{
    GLCLEAR();
    glUniformMatrix3fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::UniformMatrix4f(SInt location, bool transpose, const Float32* value)
{
    GLCLEAR();
    glUniformMatrix4fv(location, 1, transpose, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::UniformMatrix4f(SInt location, bool transpose, const Matrix& value)
{
    GLCLEAR();
    glUniformMatrix4fv(location, 1, transpose, value.GetData());
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const Float32* value)
{
    GLCLEAR();
    glUniformMatrix4fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const Matrix* value)
{
    GLCLEAR();
    glUniformMatrix4fv(location, count, transpose, value->GetData());
    GLCHECK("Failed to set shader uniform.");
}

_JATTA_EXPORT void Jatta::GL::UseProgram(UInt program)
{
    GLCLEAR();
    glUseProgram(program);
    GLCHECK("Failed to use program.");
}

_JATTA_EXPORT void Jatta::GL::ValidateProgram(UInt program)
{
    GLCLEAR();
    glValidateProgram(program);
    GLCHECK("Failed to validate program.");
}

_JATTA_EXPORT void Jatta::GL::VertexAttribIPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer)
{
    GLCLEAR();
    glVertexAttribIPointer(index, size, type, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.");
}

_JATTA_EXPORT void Jatta::GL::VertexAttribLPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer)
{
    GLCLEAR();
    glVertexAttribLPointer(index, size, type, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.");
}

_JATTA_EXPORT void Jatta::GL::VertexAttribPointer(UInt index, SInt size, Enum type, bool normalized, SignedSize stride, const void* pointer)
{
    GLCLEAR();
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.");
}
