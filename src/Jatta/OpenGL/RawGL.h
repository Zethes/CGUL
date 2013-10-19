/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "GL.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Matrix;

    // Nitpick: For convenience, these should be in alphabetical order
    namespace GL
    {
        _JATTA_EXPORT void ActiveTexture(Enum target);
        _JATTA_EXPORT void AttachShader(UInt program, UInt shader);

        _JATTA_EXPORT void BindAttribLocation(UInt program, UInt index, const char* name);
        _JATTA_EXPORT void BindAttribLocation(UInt program, UInt index, const String& name);
        _JATTA_EXPORT void BindBuffer(Enum target, UInt buffer);
        _JATTA_EXPORT void BindTexture(Enum target, UInt texture);
        _JATTA_EXPORT void BindVertexArray(UInt array);
        _JATTA_EXPORT void BlendFunc(Enum sfactor, Enum dfactor);
        _JATTA_EXPORT void BlendFunci(UInt buf, Enum sfactor, Enum dfactor);
        _JATTA_EXPORT void BufferData(Enum target, PtrDiff size, const void* data, Enum usage);

        _JATTA_EXPORT void CompileShader(UInt shader);
        _JATTA_EXPORT UInt CreateProgram();
        _JATTA_EXPORT UInt CreateShader(Enum shaderType);

        _JATTA_EXPORT void Disable(Enum cap);
        _JATTA_EXPORT void DrawArrays(Enum mode, SInt first, SignedSize count);

        _JATTA_EXPORT void Enable(Enum cap);
        _JATTA_EXPORT void EnableVertexAttribArray(UInt index);

        _JATTA_EXPORT void GenBuffers(SignedSize n, UInt* buffers);
        _JATTA_EXPORT void GenTextures(SignedSize n, UInt* textures);
        _JATTA_EXPORT void GenVertexArrays(SignedSize n, UInt* arrays);
        _JATTA_EXPORT void GetProgramInfoLog(UInt shader, SignedSize maxLength, SignedSize* length, char* infoLog);
        _JATTA_EXPORT void GetProgramInfoLog(UInt shader, String* infoLog);
        _JATTA_EXPORT void GetProgramiv(UInt program, Enum pname, SInt* params);
        _JATTA_EXPORT void GetShaderInfoLog(UInt shader, SignedSize maxLength, SignedSize* length, char* infoLog);
        _JATTA_EXPORT void GetShaderInfoLog(UInt shader, String* infoLog);
        _JATTA_EXPORT void GetShaderiv(UInt shader, Enum pname, SInt* params);
        _JATTA_EXPORT SInt GetUniformLocation(UInt program, const char* name);
        _JATTA_EXPORT SInt GetUniformLocation(UInt program, String& name);

        _JATTA_EXPORT void LinkProgram(UInt program);

        _JATTA_EXPORT void PixelStoref(Enum pname, Float32 param);
        _JATTA_EXPORT void PixelStorei(Enum pname, SInt param);

        _JATTA_EXPORT UInt ShaderSource(UInt shader, SignedSize count, const char** string, const SInt* length);
        _JATTA_EXPORT UInt ShaderSource(UInt shader, const char* string);
        _JATTA_EXPORT UInt ShaderSource(UInt shader, const String& string);

        _JATTA_EXPORT void TexEnvf(Enum target, Enum pname, Float32 param);
        _JATTA_EXPORT void TexEnvi(Enum target, Enum pname, SInt param);
        _JATTA_EXPORT void TexImage2D(Enum target, SInt level, SInt internalFormat, SignedSize width, SignedSize height, SInt border, Enum format, Enum type, const void* data);
        _JATTA_EXPORT void TexParameterf(Enum target, Enum pname, Float32 param);
        _JATTA_EXPORT void TexParameteri(Enum target, Enum pname, SInt param);

        _JATTA_EXPORT void Uniform1f(SInt location, Float32 v0);
        _JATTA_EXPORT void Uniform1fv(SInt location, SignedSize count, const Float32* value);
        _JATTA_EXPORT void Uniform1i(SInt location, SInt v0);
        _JATTA_EXPORT void Uniform1iv(SInt location, SignedSize count, const SInt* value);
        _JATTA_EXPORT void Uniform2f(SInt location, Float32 v0, Float32 v1);
        _JATTA_EXPORT void Uniform2fv(SInt location, SignedSize count, const Float32* value);
        _JATTA_EXPORT void Uniform2i(SInt location, SInt v0, SInt v1);
        _JATTA_EXPORT void Uniform2iv(SInt location, SignedSize count, const SInt* value);
        _JATTA_EXPORT void Uniform3f(SInt location, Float32 v0, Float32 v1, Float32 v2);
        _JATTA_EXPORT void Uniform3fv(SInt location, SignedSize count, const Float32* value);
        _JATTA_EXPORT void Uniform3i(SInt location, SInt v0, SInt v1, SInt v2);
        _JATTA_EXPORT void Uniform3iv(SInt location, SignedSize count, const SInt* value);
        _JATTA_EXPORT void Uniform4f(SInt location, Float32 v0, Float32 v1, Float32 v2, Float32 v3);
        _JATTA_EXPORT void Uniform4fv(SInt location, SignedSize count, const Float32* value);
        _JATTA_EXPORT void Uniform4i(SInt location, SInt v0, SInt v1, SInt v2, SInt v3);
        _JATTA_EXPORT void Uniform4iv(SInt location, SignedSize count, const SInt* value);
        _JATTA_EXPORT void UniformMatrix2fv(SInt location, SignedSize count, bool transpose, const Float32* value);
        _JATTA_EXPORT void UniformMatrix3fv(SInt location, SignedSize count, bool transpose, const Float32* value);
        _JATTA_EXPORT void UniformMatrix4f(SInt location, bool transpose, const Float32* value);
        _JATTA_EXPORT void UniformMatrix4f(SInt location, bool transpose, const Matrix& value);
        _JATTA_EXPORT void UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const Float32* value);
        _JATTA_EXPORT void UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const Matrix* value);
        _JATTA_EXPORT void UseProgram(UInt program);

        _JATTA_EXPORT void ValidateProgram(UInt program);
        _JATTA_EXPORT void VertexAttribIPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer);
        _JATTA_EXPORT void VertexAttribLPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer);
        _JATTA_EXPORT void VertexAttribPointer(UInt index, SInt size, Enum type, bool normalized, SignedSize stride, const void* pointer);
    }
}
#include "../External/Undefines.h"
