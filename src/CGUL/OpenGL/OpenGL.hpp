// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGL.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../OpenGL/GL.hpp"
#include "../Images/Color.hpp"
#include "../Math/Vector2.hpp"
#include "../Math/Vector3.hpp"
#include "../Math/Vector4.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    /** @brief Experimental OpenGL wrapper.
     */
    namespace OpenGL
    {
        _CGUL_EXPORT void ClearErrors();
        _CGUL_EXPORT void Test();

        _CGUL_EXPORT void Enable(Enum cap);
        _CGUL_EXPORT void Disable(Enum cap);

        _CGUL_EXPORT String GetString(Enum name);
        _CGUL_EXPORT String GetStringi(Enum name, unsigned int index);
        _CGUL_EXPORT void GetSupportedExtensions(FixedList< String >* extensions);
        _CGUL_EXPORT bool SupportsExtension(String ext);
        _CGUL_EXPORT int GetOpenGLVersionMajor();
        _CGUL_EXPORT int GetOpenGLVersionMinor();
        _CGUL_EXPORT String GetOpenGLVersion();
        _CGUL_EXPORT String GetGLSLVersion();
        _CGUL_EXPORT String GetOpenGLVendor();
        _CGUL_EXPORT String GetOpenGLRenderer();

        _CGUL_EXPORT void BlendFunc(Enum sfactor, Enum dfactor);
        _CGUL_EXPORT void BlendFunci(UInt32 buf, Enum sfactor, Enum dfactor);

        _CGUL_EXPORT void BlendFuncSeparate(Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta);
        _CGUL_EXPORT void BlendFuncSeparatei(UInt32 buf, Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta);
    }

    // Nitpick: For convenience, these should be in alphabetical order
    namespace GL
    {
        typedef unsigned int   Bitfield;
        typedef unsigned char  Boolean;
        typedef signed char    Byte;
        typedef char           Char;
        typedef double         ClampD;
        typedef float          ClampF;
        typedef double         Double;
        typedef unsigned int   Enum;
        typedef float          Float;
        typedef int            Int;
        typedef CGUL::SInt64   Int64;
        typedef CGUL::PtrDiff  IntPtr;
        typedef short          Short;
        typedef int            SizeI;
        typedef CGUL::PtrDiff  SizeIPtr;
        typedef unsigned char  UByte;
        typedef unsigned int   UInt;
        typedef CGUL::UInt64   UInt64;
        typedef unsigned long  ULong;
        typedef unsigned short UShort;
        typedef void           Void;

        _CGUL_EXPORT void ActiveTexture(GL::Enum target);
        _CGUL_EXPORT void AlphaFunc(GL::Enum func, GL::ClampF ref);
        _CGUL_EXPORT void AttachShader(GL::UInt program, GL::UInt shader);

        _CGUL_EXPORT void Begin(GL::Enum mode);
        _CGUL_EXPORT void BindAttribLocation(GL::UInt program, GL::UInt index, const GL::Char* name);
        _CGUL_EXPORT void BindAttribLocation(GL::UInt program, GL::UInt index, const String& name);
        _CGUL_EXPORT void BindBuffer(GL::Enum target, GL::UInt buffer);
        _CGUL_EXPORT void BindFramebuffer(GL::Enum target, GL::UInt framebuffer);
        _CGUL_EXPORT void BindTexture(GL::Enum target, GL::UInt texture);
        _CGUL_EXPORT void BindVertexArray(GL::UInt array);
        _CGUL_EXPORT void BlendFunc(GL::Enum sfactor, GL::Enum dfactor);
        _CGUL_EXPORT void BlendFunci(GL::UInt buf, GL::Enum sfactor, GL::Enum dfactor);
        _CGUL_EXPORT void BufferData(GL::Enum target, GL::SizeIPtr size, const GL::Void* data, GL::Enum usage);

        _CGUL_EXPORT GL::Enum CheckFramebufferStatus(GL::Enum target);
        _CGUL_EXPORT void Clear(GL::Bitfield mask);
        _CGUL_EXPORT void ClearColor(GL::ClampF red, GL::ClampF green, GL::ClampF blue, GL::ClampF alpha);
        _CGUL_EXPORT void Color3b(GL::Byte red, GL::Byte green, GL::Byte blue);
        _CGUL_EXPORT void Color3s(GL::Short red, GL::Short green, GL::Short blue);
        _CGUL_EXPORT void Color3i(GL::Int red, GL::Int green, GL::Int blue);
        _CGUL_EXPORT void Color3f(GL::Float red, GL::Float green, GL::Float blue);
        _CGUL_EXPORT void Color3d(GL::Double red, GL::Double green, GL::Double blue);
        _CGUL_EXPORT void Color3ub(GL::UByte red, GL::UByte green, GL::UByte blue);
        _CGUL_EXPORT void Color3us(GL::UShort red, GL::UShort green, GL::UShort blue);
        _CGUL_EXPORT void Color3ui(GL::UInt red, GL::UInt green, GL::UInt blue);
        _CGUL_EXPORT void Color4b(GL::Byte red, GL::Byte green, GL::Byte blue, GL::Byte alpha);
        _CGUL_EXPORT void Color4s(GL::Short red, GL::Short green, GL::Short blue, GL::Short alpha);
        _CGUL_EXPORT void Color4i(GL::Int red, GL::Int green, GL::Int blue, GL::Int alpha);
        _CGUL_EXPORT void Color4f(GL::Float red, GL::Float green, GL::Float blue, GL::Float alpha);
        _CGUL_EXPORT void Color4d(GL::Double red, GL::Double green, GL::Double blue, GL::Double alpha);
        _CGUL_EXPORT void Color4ub(GL::UByte red, GL::UByte green, GL::UByte blue, GL::UByte alpha);
        _CGUL_EXPORT void Color4us(GL::UShort red, GL::UShort green, GL::UShort blue, GL::UShort alpha);
        _CGUL_EXPORT void Color4ui(GL::UInt red, GL::UInt green, GL::UInt blue, GL::UInt alpha);
        _CGUL_EXPORT void CompileShader(GL::UInt shader);
        _CGUL_EXPORT GL::UInt CreateProgram();
        _CGUL_EXPORT GL::UInt CreateShader(GL::Enum shaderType);

        _CGUL_EXPORT void DeleteBuffers(GL::SizeI n, const GL::UInt* buffers);
        _CGUL_EXPORT void DeleteTextures(GL::SizeI n, const GL::UInt* textures);
        _CGUL_EXPORT void DeleteVertexArrays(GL::SizeI n, const GL::UInt* arrays);
        _CGUL_EXPORT void Disable(GL::Enum cap);
        _CGUL_EXPORT void DisableVertexAttribArray(GL::UInt index);
        _CGUL_EXPORT void DrawArrays(GL::Enum mode, GL::Int first, GL::SizeI count);
        _CGUL_EXPORT void DrawElements(GL::Enum mode, GL::SizeI count, GL::Enum type, const GL::Void* indices);

        _CGUL_EXPORT void Enable(GL::Enum cap);
        _CGUL_EXPORT void EnableVertexAttribArray(GL::UInt index);
        _CGUL_EXPORT void End();

        _CGUL_EXPORT void FramebufferTexture2D(GL::Enum target, GL::Enum attachment, GL::Enum textarget, GL::UInt texture, GL::Int level);

        _CGUL_EXPORT void GenBuffers(GL::SizeI n, GL::UInt* buffers);
        _CGUL_EXPORT void GenTextures(GL::SizeI n, GL::UInt* textures);
        _CGUL_EXPORT void GenFramebuffers(GL::SizeI n, GL::UInt* ids);
        _CGUL_EXPORT void GenVertexArrays(GL::SizeI n, UInt* arrays);
        _CGUL_EXPORT void GetBooleanv(GL::Enum pname, GL::Boolean* params);
        _CGUL_EXPORT void GetFloatv(GL::Enum pname, GL::Float* params);
        _CGUL_EXPORT void GetIntegerv(GL::Enum pname, GL::Int* params);
        _CGUL_EXPORT void GetProgramInfoLog(GL::UInt program, GL::SizeI maxLength, GL::SizeI* length, GL::Char* infoLog);
        _CGUL_EXPORT void GetProgramInfoLog(GL::UInt program, String* infoLog);
        _CGUL_EXPORT void GetProgramiv(GL::UInt program, Enum pname, GL::Int* params);
        _CGUL_EXPORT void GetShaderInfoLog(GL::UInt shader, GL::SizeI maxLength, GL::SizeI* length, GL::Char* infoLog);
        _CGUL_EXPORT void GetShaderInfoLog(GL::UInt shader, String* infoLog);
        _CGUL_EXPORT void GetShaderiv(GL::UInt shader, GL::Enum pname, GL::Int* params);
        _CGUL_EXPORT const GL::UByte* GetString(GL::Enum pname);
        _CGUL_EXPORT GL::Int GetUniformLocation(GL::UInt program, const GL::Char* name);
        _CGUL_EXPORT GL::Int GetUniformLocation(GL::UInt program, String& name);

        _CGUL_EXPORT void LinkProgram(GL::UInt program);
        _CGUL_EXPORT void LoadIdentity();

        _CGUL_EXPORT void MatrixMode(GL::Enum mode);

        _CGUL_EXPORT void Ortho(GL::Double left, GL::Double right, GL::Double bottom, GL::Double top, GL::Double nearVal, GL::Double farVal);

        _CGUL_EXPORT void PixelStoref(GL::Enum pname, GL::Float param);
        _CGUL_EXPORT void PixelStorei(GL::Enum pname, GL::Int param);
        _CGUL_EXPORT void PopMatrix();
        _CGUL_EXPORT void PushMatrix();

        _CGUL_EXPORT void Rotated(GL::Double angle, GL::Double x, GL::Double y, GL::Double z);
        _CGUL_EXPORT void Rotatef(GL::Float angle, GL::Float x, GL::Float y, GL::Float z);

        _CGUL_EXPORT void ShadeModel(GL::Enum mode);
        _CGUL_EXPORT void ShaderSource(GL::UInt shader, GL::SizeI count, const char** string, const GL::Int* length);
        _CGUL_EXPORT void ShaderSource(GL::UInt shader, const GL::Char* string);
        _CGUL_EXPORT void ShaderSource(GL::UInt shader, const String& string);
        _CGUL_EXPORT void SwapInterval(GL::Boolean enable);

        _CGUL_EXPORT void TexCoord1s(GL::Short s);
        _CGUL_EXPORT void TexCoord1i(GL::Int s);
        _CGUL_EXPORT void TexCoord1f(GL::Float s);
        _CGUL_EXPORT void TexCoord1d(GL::Double s);
        _CGUL_EXPORT void TexCoord2s(GL::Short s, GL::Short t);
        _CGUL_EXPORT void TexCoord2i(GL::Int s, GL::Int t);
        _CGUL_EXPORT void TexCoord2f(GL::Float s, GL::Float t);
        _CGUL_EXPORT void TexCoord2d(GL::Double s, GL::Double t);
        _CGUL_EXPORT void TexCoord3s(GL::Short s, GL::Short t, GL::Short r);
        _CGUL_EXPORT void TexCoord3i(GL::Int s, GL::Int t, GL::Int r);
        _CGUL_EXPORT void TexCoord3f(GL::Float s, GL::Float t, GL::Float r);
        _CGUL_EXPORT void TexCoord3d(GL::Double s, GL::Double t, GL::Double r);
        _CGUL_EXPORT void TexCoord4s(GL::Short s, GL::Short t, GL::Short r, GL::Short q);
        _CGUL_EXPORT void TexCoord4i(GL::Int s, GL::Int t, GL::Int r, GL::Int q);
        _CGUL_EXPORT void TexCoord4f(GL::Float s, GL::Float t, GL::Float r, GL::Float q);
        _CGUL_EXPORT void TexCoord4d(GL::Double s, GL::Double t, GL::Double r, GL::Double q);
        _CGUL_EXPORT void TexEnvf(GL::Enum target, GL::Enum pname, GL::Float param);
        _CGUL_EXPORT void TexEnvi(GL::Enum target, GL::Enum pname, GL::Int param);
        _CGUL_EXPORT void TexImage2D(GL::Enum target, GL::Int level, GL::Int internalFormat, GL::SizeI width, GL::SizeI height, GL::Int border, GL::Enum format, GL::Enum type, const GL::Void* data);
        _CGUL_EXPORT void TexParameterf(GL::Enum target, GL::Enum pname, GL::Float param);
        _CGUL_EXPORT void TexParameteri(GL::Enum target, GL::Enum pname, GL::Int param);
        _CGUL_EXPORT void TexSubImage2D(GL::Enum target, GL::Int level, GL::Int xoffset, GL::Int yoffset, GL::SizeI width, GL::SizeI height, GL::Enum format, GL::Enum type, const GL::Void* data);
        _CGUL_EXPORT void Translated(GL::Double x, GL::Double y, GL::Double z);
        _CGUL_EXPORT void Translatef(GL::Float x, GL::Float y, GL::Float z);

        _CGUL_EXPORT void Uniform1f(GL::Int location, GL::Float v0);
        _CGUL_EXPORT void Uniform1fv(GL::Int location, GL::SizeI count, const GL::Float* value);
        _CGUL_EXPORT void Uniform1i(GL::Int location, GL::Int v0);
        _CGUL_EXPORT void Uniform1iv(GL::Int location, GL::SizeI count, const GL::Int* value);
        _CGUL_EXPORT void Uniform2f(GL::Int location, GL::Float v0, GL::Float v1);
        _CGUL_EXPORT void Uniform2f(GL::Int location, const Vector2T< GL::Float >& v);
        _CGUL_EXPORT void Uniform2fv(GL::Int location, GL::SizeI count, const GL::Float* value);
        _CGUL_EXPORT void Uniform2fv(GL::Int location, GL::SizeI count, const Vector2T< GL::Float >* value);
        _CGUL_EXPORT void Uniform2i(GL::Int location, GL::Int v0, GL::Int v1);
        _CGUL_EXPORT void Uniform2iv(GL::Int location, GL::SizeI count, const GL::Int* value);
        _CGUL_EXPORT void Uniform3f(GL::Int location, GL::Float v0, GL::Float v1, GL::Float v2);
        _CGUL_EXPORT void Uniform3f(GL::Int location, const Vector3T< GL::Float >& v);
        _CGUL_EXPORT void Uniform3f(GL::Int location, const Color& v);
        _CGUL_EXPORT void Uniform3fv(GL::Int location, GL::SizeI count, const GL::Float* value);
        _CGUL_EXPORT void Uniform3fv(GL::Int location, GL::SizeI count, const Vector3T< GL::Float >* value);
        _CGUL_EXPORT void Uniform3i(GL::Int location, GL::Int v0, GL::Int v1, GL::Int v2);
        _CGUL_EXPORT void Uniform3i(GL::Int location, const Color& color);
        _CGUL_EXPORT void Uniform3iv(GL::Int location, GL::SizeI count, const GL::Int* value);
        _CGUL_EXPORT void Uniform4f(GL::Int location, GL::Float v0, GL::Float v1, GL::Float v2, GL::Float v3);
        _CGUL_EXPORT void Uniform4f(GL::Int location, const Vector4T< GL::Float >& v);
        _CGUL_EXPORT void Uniform4f(GL::Int location, const Color& v);
        _CGUL_EXPORT void Uniform4fv(GL::Int location, GL::SizeI count, const GL::Float* value);
        _CGUL_EXPORT void Uniform4fv(GL::Int location, GL::SizeI count, const Vector4T< GL::Float >* value);
        _CGUL_EXPORT void Uniform4i(GL::Int location, GL::Int v0, GL::Int v1, GL::Int v2, GL::Int v3);
        _CGUL_EXPORT void Uniform4i(GL::Int location, const Color& color);
        _CGUL_EXPORT void Uniform4iv(GL::Int location, GL::SizeI count, const GL::Int* value);
        _CGUL_EXPORT void UniformMatrix2v(GL::Int location, GL::SizeI count, GL::Boolean transpose, const GL::Float* value);
        _CGUL_EXPORT void UniformMatrix2fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const GL::Float* value);
        _CGUL_EXPORT void UniformMatrix3fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const GL::Float* value);
        _CGUL_EXPORT void UniformMatrix4f(GL::Int location, GL::Boolean transpose, const GL::Float* value);
        _CGUL_EXPORT void UniformMatrix4f(GL::Int location, GL::Boolean transpose, const MatrixT< GL::Float >& value);
        _CGUL_EXPORT void UniformMatrix4fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const GL::Float* value);
        _CGUL_EXPORT void UniformMatrix4fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const MatrixT< GL::Float >* value);
        _CGUL_EXPORT void UseProgram(GL::UInt program);

        _CGUL_EXPORT void ValidateProgram(GL::UInt program);
        _CGUL_EXPORT void Vertex2s(GL::Short x, GL::Short y);
        _CGUL_EXPORT void Vertex2i(GL::Int x, GL::Int y);
        _CGUL_EXPORT void Vertex2f(GL::Float x, GL::Float y);
        _CGUL_EXPORT void Vertex2d(GL::Double x, GL::Double y);
        _CGUL_EXPORT void Vertex3s(GL::Short x, GL::Short y, GL::Short z);
        _CGUL_EXPORT void Vertex3i(GL::Int x, GL::Int y, GL::Int z);
        _CGUL_EXPORT void Vertex3f(GL::Float x, GL::Float y, GL::Float z);
        _CGUL_EXPORT void Vertex3d(GL::Double x, GL::Double y, GL::Double z);
        _CGUL_EXPORT void Vertex4s(GL::Short x, GL::Short y, GL::Short z, GL::Short w);
        _CGUL_EXPORT void Vertex4i(GL::Int x, GL::Int y, GL::Int z, GL::Int w);
        _CGUL_EXPORT void Vertex4f(GL::Float x, GL::Float y, GL::Float z, GL::Float w);
        _CGUL_EXPORT void Vertex4d(GL::Double x, GL::Double y, GL::Double z, GL::Double w);
        _CGUL_EXPORT void VertexAttribIPointer(GL::UInt index, GL::Int size, GL::Enum type, GL::SizeI stride, const GL::Void* pointer);
        _CGUL_EXPORT void VertexAttribLPointer(GL::UInt index, GL::Int size, GL::Enum type, GL::SizeI stride, const GL::Void* pointer);
        _CGUL_EXPORT void VertexAttribPointer(GL::UInt index, GL::Int size, GL::Enum type, GL::Boolean normalized, GL::SizeI stride, const GL::Void* pointer);
        _CGUL_EXPORT void Viewport(GL::Int x, GL::Int y, GL::SizeI width, GL::SizeI height);
    }
}

// Undefines
#include "../External/Undefines.hpp"
