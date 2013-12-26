// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file RawGL.cpp
 */

#include "RawGL.hpp"
#include "../Math/Matrix.hpp"

_CGUL_EXPORT void CGUL::GL::ActiveTexture(Enum target)
{
    GLCLEAR();
    GLVERIFY(glActiveTexture);
    glActiveTexture(target);
    GLCHECK("Failed to set active texture.", glActiveTexture);
}

_CGUL_EXPORT void CGUL::GL::AttachShader(UInt program, UInt shader)
{
    GLCLEAR();
    GLVERIFY(glAttachShader);
    glAttachShader(program, shader);
    GLCHECK("Failed to attach shader.", glAttachShader);
}

_CGUL_EXPORT void CGUL::GL::BindAttribLocation(UInt program, UInt index, const char* name)
{
    GLCLEAR();
    GLVERIFY(glBindAttribLocation);
    glBindAttribLocation(program, index, name);
    GLCHECK("Failed to bind attribute location.", glBindAttribLocation);
}

_CGUL_EXPORT void CGUL::GL::BindAttribLocation(UInt program, UInt index, const String& name)
{
    GLCLEAR();
    GLVERIFY(glBindAttribLocation);
    glBindAttribLocation(program, index, name.GetCString());
    GLCHECK("Failed to bind attribute location.", glBindAttribLocation);
}

_CGUL_EXPORT void CGUL::GL::BindBuffer(Enum target, UInt buffer)
{
    GLCLEAR();
    GLVERIFY(glBindBuffer);
    glBindBuffer(target, buffer);
    GLCHECK("Failed to bind buffer.", glBindBuffer);
}

_CGUL_EXPORT void CGUL::GL::BindTexture(Enum target, UInt texture)
{
    GLCLEAR();
    GLVERIFY(glBindTexture);
    glBindTexture(target, texture);
    GLCHECK("Failed to bind texture.", glBindTexture);
}

_CGUL_EXPORT void CGUL::GL::BindVertexArray(UInt array)
{
    GLCLEAR();
#   ifdef CGUL_MACOS
    GLVERIFY(glBindVertexArrayAPPLE);
    glBindVertexArrayAPPLE(array);
    GLCHECK("Failed to bind vertex array.", glBindVertexArrayAPPLE);
#   else
    GLVERIFY(glBindVertexArray);
    glBindVertexArray(array);
    GLCHECK("Failed to bind vertex array.", glBindVertexArray);
#   endif
}

_CGUL_EXPORT void CGUL::GL::BlendFunc(Enum sfactor, Enum dfactor)
{
    GLCLEAR();
    GLVERIFY(glBlendFunc);
    glBlendFunc(sfactor, dfactor);
    GLCHECK("Failed to set blend function.", glBlendFunc);
}

_CGUL_EXPORT void CGUL::GL::BlendFunci(UInt buf, Enum sfactor, Enum dfactor)
{
    GLCLEAR();
    GLVERIFY(glBlendFunci);
    glBlendFunci(buf, sfactor, dfactor);
    GLCHECK("Failed to set blend function.", glBlendFunci);
}

_CGUL_EXPORT void CGUL::GL::BufferData(Enum target, PtrDiff size, const void* data, Enum usage)
{
    GLCLEAR();
    GLVERIFY(glBufferData);
    glBufferData(target, size, data, usage);
    GLCHECK("Failed to set buffer data.", glBufferData);
}

_CGUL_EXPORT void CGUL::GL::CompileShader(UInt shader)
{
    GLCLEAR();
    GLVERIFY(glCompileShader);
    glCompileShader(shader);
    GLCHECK("Failed to compile shader.", glCompileShader);
}

_CGUL_EXPORT CGUL::UInt CGUL::GL::CreateProgram()
{
    GLCLEAR();
    GLVERIFY(glCreateProgram);
    CGUL::UInt ret = glCreateProgram();
    GLCHECK("Failed to create program.", glCreateProgram);
    return ret;
}

_CGUL_EXPORT CGUL::UInt CGUL::GL::CreateShader(Enum shaderType)
{
    GLCLEAR();
    GLVERIFY(glCreateShader);
    CGUL::UInt ret = glCreateShader(shaderType);
    GLCHECK("Failed to create shader.", glCreateShader);
    return ret;
}

_CGUL_EXPORT void CGUL::GL::DeleteBuffers(SignedSize n, const UInt* buffers)
{
    GLCLEAR();
    GLVERIFY(glDeleteBuffers);
    glDeleteBuffers(n, buffers);
    GLCHECK("Failed to delete buffers.", glDeleteBuffers);
}

_CGUL_EXPORT void CGUL::GL::DeleteVertexArrays(SignedSize n, const UInt* arrays)
{
    GLCLEAR();
    GLVERIFY(glDeleteVertexArrays);
    glDeleteBuffers(n, arrays);
    GLCHECK("Failed to delete vertex arrays.", glDeleteVertexArrays);
}

_CGUL_EXPORT void CGUL::GL::Disable(Enum cap)
{
    GLCLEAR();
    GLVERIFY(glDisable);
    glDisable(cap);
    GLCHECK("Failed to disable capability.", glDisable);
}

_CGUL_EXPORT void CGUL::GL::DisableVertexAttribArray(UInt index)
{
    GLCLEAR();
    GLVERIFY(glDisableVertexAttribArray);
    glDisableVertexAttribArray(index);
    GLCHECK("Failed to disable vertex attribute array.", glDisableVertexAttribArray);
}

_CGUL_EXPORT void CGUL::GL::DrawArrays(Enum mode, SInt first, SignedSize count)
{
    GLCLEAR();
    GLVERIFY(glDrawArrays);
    glDrawArrays(mode, first, count);
    GLCHECK("Failed to draw arrays.", glDrawArrays);
}

_CGUL_EXPORT void CGUL::GL::DrawElements(Enum mode, SignedSize count, Enum type, const void* indices)
{
    GLCLEAR();
    GLVERIFY(glDrawElements);
    glDrawElements(mode, count, type, indices);
    GLCHECK("Failed to draw elements.", glDrawElements);
}

_CGUL_EXPORT void CGUL::GL::Enable(Enum cap)
{
    GLCLEAR();
    GLVERIFY(glEnable);
    glEnable(cap);
    GLCHECK("Failed to enable capability.", glEnable);
}

_CGUL_EXPORT void CGUL::GL::EnableVertexAttribArray(UInt index)
{
    GLCLEAR();
    GLVERIFY(glEnableVertexAttribArray);
    glEnableVertexAttribArray(index);
    GLCHECK("Failed to enable vertex attribute array.", glEnableVertexAttribArray);
}

_CGUL_EXPORT void CGUL::GL::GenBuffers(SignedSize n, UInt* buffers)
{
    GLCLEAR();
    GLVERIFY(glGenBuffers);
    glGenBuffers(n, buffers);
    GLCHECK("Failed to generate buffers.", glGenBuffers);
}

_CGUL_EXPORT void CGUL::GL::GenTextures(SignedSize n, UInt* textures)
{
    GLCLEAR();
    GLVERIFY(glGenTextures);
    glGenTextures(n, textures);
    GLCHECK("Failed to generate textures.", glGenTextures);
}

_CGUL_EXPORT void CGUL::GL::GenVertexArrays(SignedSize n, UInt* arrays)
{
    GLCLEAR();
#   ifdef CGUL_MACOS
    GLVERIFY(glGenVertexArraysAPPLE);
    glGenVertexArraysAPPLE(n, arrays);
    GLCHECK("Failed to generate vertex arrays.", glGenVertexArraysAPPLE);
#   else
    GLVERIFY(glGenVertexArrays);
    glGenVertexArrays(n, arrays);
    GLCHECK("Failed to generate vertex arrays.", glGenVertexArrays);
#   endif
}

_CGUL_EXPORT void CGUL::GL::GetProgramInfoLog(UInt program, SignedSize maxLength, SignedSize* length, char* infoLog)
{
    GLCLEAR();
    GLVERIFY(glGetProgramInfoLog);
    glGetProgramInfoLog(program, maxLength, (GLsizei*)length, infoLog);
    GLCHECK("Failed to get shader info log.", glGetProgramInfoLog);
}

_CGUL_EXPORT void CGUL::GL::GetProgramInfoLog(UInt program, String* infoLog)
{
    GLCLEAR();
    SInt maxLength;
    GLVERIFY(glGetProgramiv);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
    // TODO: length could be 0 if there is no log info, need to handle that case
    char* buffer = new char[maxLength];
    SignedSize length;
    GLVERIFY(glGetProgramInfoLog);
    glGetProgramInfoLog(program, maxLength, (GLsizei*)&length, buffer);
    *infoLog = buffer;
    delete[] buffer;
    GLCHECK("Failed to get shader info log.", glGetProgramInfoLog);
}

_CGUL_EXPORT void CGUL::GL::GetProgramiv(UInt program, Enum pname, SInt* params)
{
    GLCLEAR();
    GLVERIFY(glGetProgramiv);
    glGetProgramiv(program, pname, params);
    GLCHECK("Failed to get program parameter.", glGetProgramiv);
}

_CGUL_EXPORT void CGUL::GL::GetShaderInfoLog(UInt shader, SignedSize maxLength, SignedSize* length, char* infoLog)
{
    GLCLEAR();
    GLVERIFY(glGetShaderInfoLog);
    glGetShaderInfoLog(shader, maxLength, (GLsizei*)length, infoLog);
    GLCHECK("Failed to get shader info log.", glGetShaderInfoLog);
}

_CGUL_EXPORT void CGUL::GL::GetShaderInfoLog(UInt shader, String* infoLog)
{
    GLCLEAR();
    SInt maxLength;
    GLVERIFY(glGetShaderiv);
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
    // TODO: length could be 0 if there is no log info, need to handle that case
    char* buffer = new char[maxLength];
    SignedSize length;
    GLVERIFY(glGetShaderInfoLog);
    glGetShaderInfoLog(shader, maxLength, (GLsizei*)&length, buffer);
    *infoLog = buffer;
    delete[] buffer;
    GLCHECK("Failed to get shader info log.", glGetShaderInfoLog);
}

_CGUL_EXPORT void CGUL::GL::GetShaderiv(UInt shader, Enum pname, SInt* params)
{
    GLCLEAR();
    GLVERIFY(glGetShaderiv);
    glGetShaderiv(shader, pname, params);
    GLCHECK("Failed to get shader parameter.", glGetShaderiv);
}

_CGUL_EXPORT CGUL::SInt CGUL::GL::GetUniformLocation(UInt program, const char* name)
{
    GLCLEAR();
    GLVERIFY(glGetUniformLocation);
    SInt ret = glGetUniformLocation(program, name);
    GLCHECK("Failed to get uniform location.", glGetUniformLocation);
    return ret;
}

_CGUL_EXPORT CGUL::SInt CGUL::GL::GetUniformLocation(UInt program, String& name)
{
    GLCLEAR();
    GLVERIFY(glGetUniformLocation);
    SInt ret = glGetUniformLocation(program, name.GetCString());
    GLCHECK("Failed to get uniform location.", glGetUniformLocation);
    return ret;
}

_CGUL_EXPORT void CGUL::GL::LinkProgram(UInt program)
{
    GLCLEAR();
    GLVERIFY(glLinkProgram);
    glLinkProgram(program);
    GLCHECK("Failed to link program.", glLinkProgram);
}

_CGUL_EXPORT void CGUL::GL::PixelStoref(Enum pname, Float32 param)
{
    GLCLEAR();
    GLVERIFY(glPixelStoref);
    glPixelStoref(pname, param);
    GLCHECK("Failed to set pixel store.", glPixelStoref);
}

_CGUL_EXPORT void CGUL::GL::PixelStorei(Enum pname, SInt param)
{
    GLCLEAR();
    GLVERIFY(glPixelStorei);
    glPixelStorei(pname, param);
    GLCHECK("Failed to set pixel store.", glPixelStorei);
}

_CGUL_EXPORT void CGUL::GL::ShaderSource(UInt shader, SignedSize count, const char** string, const SInt* length)
{
    GLCLEAR();
    GLVERIFY(glShaderSource);
    glShaderSource(shader, count, string, length);
    GLCHECK("Failed to set the shader source.", glShaderSource);
}

_CGUL_EXPORT void CGUL::GL::ShaderSource(UInt shader, const char* string)
{
    GLCLEAR();
    const char** data = &string;
    SInt length = (SInt)strlen(string);
    GLVERIFY(glShaderSource);
    glShaderSource(shader, 1, data, &length);
    GLCHECK("Failed to set the shader source.", glShaderSource);
}

_CGUL_EXPORT void CGUL::GL::ShaderSource(UInt shader, const CGUL::String& string)
{
    GLCLEAR();
    const char* cstr = string.GetCString();
    const char** data = &cstr;
    SInt length = (SInt)string.GetLength();
    GLVERIFY(glShaderSource);
    glShaderSource(shader, 1, data, &length);
    GLCHECK("Failed to set the shader source.", glShaderSource);
}

_CGUL_EXPORT void CGUL::GL::TexEnvf(Enum target, Enum pname, Float32 param)
{
    GLCLEAR();
    GLVERIFY(glTexEnvf);
    glTexEnvf(target, pname, param);
    GLCHECK("Failed to set texture environment parameters.", glTexEnvf);
}

_CGUL_EXPORT void CGUL::GL::TexEnvi(Enum target, Enum pname, SInt param)
{
    GLCLEAR();
    GLVERIFY(glTexEnvi);
    glTexEnvi(target, pname, param);
    GLCHECK("Failed to set texture environment parameters.", glTexEnvi);
}

_CGUL_EXPORT void CGUL::GL::TexImage2D(Enum target, SInt level, SInt internalFormat, SignedSize width, SignedSize height, SInt border, Enum format, Enum type, const void* data)
{
    GLCLEAR();
    GLVERIFY(glTexImage2D);
    glTexImage2D(target, level, internalFormat, width, height, border, format, type, data);
    GLCHECK("Failed to set texture 2D image.", glTexImage2D);
}

_CGUL_EXPORT void CGUL::GL::TexParameterf(Enum target, Enum pname, Float32 param)
{
    GLCLEAR();
    GLVERIFY(glTexParameterf);
    glTexParameterf(target, pname, param);
    GLCHECK("Failed to set texture parameter.", glTexParamterf);
}

_CGUL_EXPORT void CGUL::GL::TexParameteri(Enum target, Enum pname, SInt param)
{
    GLCLEAR();
    GLVERIFY(glTexParameteri);
    glTexParameteri(target, pname, param);
    GLCHECK("Failed to set texture parameter.", glTexParameteri);
}

_CGUL_EXPORT void CGUL::GL::Uniform1f(SInt location, Float32 v0)
{
    GLCLEAR();
    GLVERIFY(glUniform1f);
    glUniform1f(location, v0);
    GLCHECK("Failed to set shader uniform.", glUniform1f);
}

_CGUL_EXPORT void CGUL::GL::Uniform1fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniform1fv);
    glUniform1fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform1fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform1i(SInt location, SInt v0)
{
    GLCLEAR();
    GLVERIFY(glUniform1i);
    glUniform1i(location, v0);
    GLCHECK("Failed to set shader uniform.", glUniform1i);
}

_CGUL_EXPORT void CGUL::GL::Uniform1iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    GLVERIFY(glUniform1iv);
    glUniform1iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform1iv);
}

_CGUL_EXPORT void CGUL::GL::Uniform2f(SInt location, Float32 v0, Float32 v1)
{
    GLCLEAR();
    GLVERIFY(glUniform2f);
    glUniform2f(location, v0, v1);
    GLCHECK("Failed to set shader uniform.", glUniform2f);
}

_CGUL_EXPORT void CGUL::GL::Uniform2f(SInt location, const Vector2& v)
{
    GLCLEAR();
    GLVERIFY(glUniform2f);
    glUniform2f(location, v.x, v.y);
    GLCHECK("Failed to set shader uniform.", glUniform2f);
}

_CGUL_EXPORT void CGUL::GL::Uniform2fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniform2fv);
    glUniform2fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform2fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform2fv(SInt location, SignedSize count, const Vector2* value)
{
    GLCLEAR();
    GLVERIFY(glUniform2fv);
    glUniform2fv(location, count, (float*)value);
    GLCHECK("Failed to set shader uniform.", glUniform2fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform2i(SInt location, SInt v0, SInt v1)
{
    GLCLEAR();
    GLVERIFY(glUniform2i);
    glUniform2i(location, v0, v1);
    GLCHECK("Failed to set shader uniform.", glUniform2i);
}

_CGUL_EXPORT void CGUL::GL::Uniform2iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    GLVERIFY(glUniform2iv);
    glUniform2iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform2iv);
}

_CGUL_EXPORT void CGUL::GL::Uniform3f(SInt location, Float32 v0, Float32 v1, Float32 v2)
{
    GLCLEAR();
    GLVERIFY(glUniform3f);
    glUniform3f(location, v0, v1, v2);
    GLCHECK("Failed to set shader uniform.", glUniform3f);
}

_CGUL_EXPORT void CGUL::GL::Uniform3f(SInt location, const Vector3& v)
{
    GLCLEAR();
    GLVERIFY(glUniform3f);
    glUniform3f(location, v.x, v.y, v.z);
    GLCHECK("Failed to set shader uniform.", glUniform3f);
}

_CGUL_EXPORT void CGUL::GL::Uniform3f(SInt location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform3f);
    glUniform3f(location, v.GetRedFloat(), v.GetGreenFloat(), v.GetBlueFloat());
    GLCHECK("Failed to set shader uniform.", glUniform3f);
}

_CGUL_EXPORT void CGUL::GL::Uniform3fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniform3fv);
    glUniform3fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform3fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform3fv(SInt location, SignedSize count, const Vector3* value)
{
    GLCLEAR();
    GLVERIFY(glUniform3fv);
    glUniform3fv(location, count, (float*)value);
    GLCHECK("Failed to set shader uniform.", glUniform3fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform3i(SInt location, SInt v0, SInt v1, SInt v2)
{
    GLCLEAR();
    GLVERIFY(glUniform3i);
    glUniform3i(location, v0, v1, v2);
    GLCHECK("Failed to set shader uniform.", glUniform3i);
}

_CGUL_EXPORT void CGUL::GL::Uniform3i(SInt location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform3i);
    glUniform3i(location, v.r, v.g, v.b);
    GLCHECK("Failed to set shader uniform.", glUniform3i);
}

_CGUL_EXPORT void CGUL::GL::Uniform3iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    GLVERIFY(glUniform3iv);
    glUniform3iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform3iv);
}

_CGUL_EXPORT void CGUL::GL::Uniform4f(SInt location, Float32 v0, Float32 v1, Float32 v2, Float32 v3)
{
    GLCLEAR();
    GLVERIFY(glUniform4f);
    glUniform4f(location, v0, v1, v2, v3);
    GLCHECK("Failed to set shader uniform.", glUniform4f);
}

_CGUL_EXPORT void CGUL::GL::Uniform4f(SInt location, const Vector4& v)
{
    GLCLEAR();
    GLVERIFY(glUniform4f);
    glUniform4f(location, v.x, v.y, v.z, v.w);
    GLCHECK("Failed to set shader uniform.", glUniform4f);
}

_CGUL_EXPORT void CGUL::GL::Uniform4f(SInt location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform4f);
    glUniform4f(location, v.GetRedFloat(), v.GetGreenFloat(), v.GetBlueFloat(), v.GetAlphaFloat());
    GLCHECK("Failed to set shader uniform.", glUniform4f);
}

_CGUL_EXPORT void CGUL::GL::Uniform4fv(SInt location, SignedSize count, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniform4fv);
    glUniform4fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform4fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform4fv(SInt location, SignedSize count, const Vector4* value)
{
    GLCLEAR();
    GLVERIFY(glUniform4fv);
    glUniform4fv(location, count, (float*)value);
    GLCHECK("Failed to set shader uniform.", glUniform4fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform4i(SInt location, SInt v0, SInt v1, SInt v2, SInt v3)
{
    GLCLEAR();
    GLVERIFY(glUniform4i);
    glUniform4i(location, v0, v1, v2, v3);
    GLCHECK("Failed to set shader uniform.", glUniform4i);
}

_CGUL_EXPORT void CGUL::GL::Uniform4i(SInt location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform4i);
    glUniform4i(location, v.r, v.g, v.b, v.a);
    GLCHECK("Failed to set shader uniform.", glUniform4i);
}

_CGUL_EXPORT void CGUL::GL::Uniform4iv(SInt location, SignedSize count, const SInt* value)
{
    GLCLEAR();
    GLVERIFY(glUniform4iv);
    glUniform4iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform4iv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix2fv(SInt location, SignedSize count, bool transpose, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix2fv);
    glUniformMatrix2fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUniformMatrix2fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix3fv(SInt location, SignedSize count, bool transpose, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix3fv);
    glUniformMatrix3fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUnofirmMatrix3fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4f(SInt location, bool transpose, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, 1, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4f(SInt location, bool transpose, const MatrixT< Float32 >& value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, 1, transpose, value.GetData());
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const Float32* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const Matrix* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, count, transpose, value->GetData());
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UseProgram(UInt program)
{
    GLCLEAR();
    GLVERIFY(glUseProgram);
    glUseProgram(program);
    GLCHECK("Failed to use program.", glUseProgram);
}

_CGUL_EXPORT void CGUL::GL::ValidateProgram(UInt program)
{
    GLCLEAR();
    GLVERIFY(glValidateProgram);
    glValidateProgram(program);
    GLCHECK("Failed to validate program.", glValidateProgram);
}

_CGUL_EXPORT void CGUL::GL::VertexAttribIPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer)
{
    GLCLEAR();
    GLVERIFY(glVertexAttribIPointer);
    glVertexAttribIPointer(index, size, type, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.", glVertexAttribIPointer);
}

_CGUL_EXPORT void CGUL::GL::VertexAttribLPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer)
{
    GLCLEAR();
    GLVERIFY(glVertexAttribLPointer);
    glVertexAttribLPointer(index, size, type, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.", glVertexAttribLPointer);
}

_CGUL_EXPORT void CGUL::GL::VertexAttribPointer(UInt index, SInt size, Enum type, bool normalized, SignedSize stride, const void* pointer)
{
    GLCLEAR();
    GLVERIFY(glVertexAttribPointer);
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.", glVertexAttribPointer);
}
