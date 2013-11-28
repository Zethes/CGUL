// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file RawGL.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "GL.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    template< typename Type>
    struct MatrixT;

    // Nitpick: For convenience, these should be in alphabetical order
    namespace GL
    {
        _CGUL_EXPORT void ActiveTexture(Enum target);
        _CGUL_EXPORT void AttachShader(UInt program, UInt shader);

        _CGUL_EXPORT void BindAttribLocation(UInt program, UInt index, const char* name);
        _CGUL_EXPORT void BindAttribLocation(UInt program, UInt index, const String& name);
        _CGUL_EXPORT void BindBuffer(Enum target, UInt buffer);
        _CGUL_EXPORT void BindTexture(Enum target, UInt texture);
        _CGUL_EXPORT void BindVertexArray(UInt array);
        _CGUL_EXPORT void BlendFunc(Enum sfactor, Enum dfactor);
        _CGUL_EXPORT void BlendFunci(UInt buf, Enum sfactor, Enum dfactor);
        _CGUL_EXPORT void BufferData(Enum target, PtrDiff size, const void* data, Enum usage);

        _CGUL_EXPORT void CompileShader(UInt shader);
        _CGUL_EXPORT UInt CreateProgram();
        _CGUL_EXPORT UInt CreateShader(Enum shaderType);

        _CGUL_EXPORT void Disable(Enum cap);
        _CGUL_EXPORT void DisableVertexAttribArray(UInt index);
        _CGUL_EXPORT void DrawArrays(Enum mode, SInt first, SignedSize count);
        _CGUL_EXPORT void DrawElements(Enum mode, SignedSize count, Enum type, const void* indices);

        _CGUL_EXPORT void Enable(Enum cap);
        _CGUL_EXPORT void EnableVertexAttribArray(UInt index);

        _CGUL_EXPORT void GenBuffers(SignedSize n, UInt* buffers);
        _CGUL_EXPORT void GenTextures(SignedSize n, UInt* textures);
        _CGUL_EXPORT void GenVertexArrays(SignedSize n, UInt* arrays);
        _CGUL_EXPORT void GetProgramInfoLog(UInt shader, SignedSize maxLength, SignedSize* length, char* infoLog);
        _CGUL_EXPORT void GetProgramInfoLog(UInt shader, String* infoLog);
        _CGUL_EXPORT void GetProgramiv(UInt program, Enum pname, SInt* params);
        _CGUL_EXPORT void GetShaderInfoLog(UInt shader, SignedSize maxLength, SignedSize* length, char* infoLog);
        _CGUL_EXPORT void GetShaderInfoLog(UInt shader, String* infoLog);
        _CGUL_EXPORT void GetShaderiv(UInt shader, Enum pname, SInt* params);
        _CGUL_EXPORT SInt GetUniformLocation(UInt program, const char* name);
        _CGUL_EXPORT SInt GetUniformLocation(UInt program, String& name);

        _CGUL_EXPORT void LinkProgram(UInt program);

        _CGUL_EXPORT void PixelStoref(Enum pname, Float32 param);
        _CGUL_EXPORT void PixelStorei(Enum pname, SInt param);

        _CGUL_EXPORT void ShaderSource(UInt shader, SignedSize count, const char** string, const SInt* length);
        _CGUL_EXPORT void ShaderSource(UInt shader, const char* string);
        _CGUL_EXPORT void ShaderSource(UInt shader, const String& string);

        _CGUL_EXPORT void TexEnvf(Enum target, Enum pname, Float32 param);
        _CGUL_EXPORT void TexEnvi(Enum target, Enum pname, SInt param);
        _CGUL_EXPORT void TexImage2D(Enum target, SInt level, SInt internalFormat, SignedSize width, SignedSize height, SInt border, Enum format, Enum type, const void* data);
        _CGUL_EXPORT void TexParameterf(Enum target, Enum pname, Float32 param);
        _CGUL_EXPORT void TexParameteri(Enum target, Enum pname, SInt param);

        _CGUL_EXPORT void Uniform1f(SInt location, Float32 v0);
        _CGUL_EXPORT void Uniform1fv(SInt location, SignedSize count, const Float32* value);
        _CGUL_EXPORT void Uniform1i(SInt location, SInt v0);
        _CGUL_EXPORT void Uniform1iv(SInt location, SignedSize count, const SInt* value);
        _CGUL_EXPORT void Uniform2f(SInt location, Float32 v0, Float32 v1);
        _CGUL_EXPORT void Uniform2fv(SInt location, SignedSize count, const Float32* value);
        _CGUL_EXPORT void Uniform2i(SInt location, SInt v0, SInt v1);
        _CGUL_EXPORT void Uniform2iv(SInt location, SignedSize count, const SInt* value);
        _CGUL_EXPORT void Uniform3f(SInt location, Float32 v0, Float32 v1, Float32 v2);
        _CGUL_EXPORT void Uniform3fv(SInt location, SignedSize count, const Float32* value);
        _CGUL_EXPORT void Uniform3i(SInt location, SInt v0, SInt v1, SInt v2);
        _CGUL_EXPORT void Uniform3iv(SInt location, SignedSize count, const SInt* value);
        _CGUL_EXPORT void Uniform4f(SInt location, Float32 v0, Float32 v1, Float32 v2, Float32 v3);
        _CGUL_EXPORT void Uniform4fv(SInt location, SignedSize count, const Float32* value);
        _CGUL_EXPORT void Uniform4i(SInt location, SInt v0, SInt v1, SInt v2, SInt v3);
        _CGUL_EXPORT void Uniform4iv(SInt location, SignedSize count, const SInt* value);
        _CGUL_EXPORT void UniformMatrix2fv(SInt location, SignedSize count, bool transpose, const Float32* value);
        _CGUL_EXPORT void UniformMatrix3fv(SInt location, SignedSize count, bool transpose, const Float32* value);
        _CGUL_EXPORT void UniformMatrix4f(SInt location, bool transpose, const Float32* value);
        _CGUL_EXPORT void UniformMatrix4f(SInt location, bool transpose, const MatrixT< Float32 >& value);
        _CGUL_EXPORT void UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const Float32* value);
        _CGUL_EXPORT void UniformMatrix4fv(SInt location, SignedSize count, bool transpose, const MatrixT< Float32 >* value);
        _CGUL_EXPORT void UseProgram(UInt program);

        _CGUL_EXPORT void ValidateProgram(UInt program);
        _CGUL_EXPORT void VertexAttribIPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer);
        _CGUL_EXPORT void VertexAttribLPointer(UInt index, SInt size, Enum type, SignedSize stride, const void* pointer);
        _CGUL_EXPORT void VertexAttribPointer(UInt index, SInt size, Enum type, bool normalized, SignedSize stride, const void* pointer);
    }
}
#include "../External/Undefines.hpp"
