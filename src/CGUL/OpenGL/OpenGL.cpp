// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGL.cpp
 */

// Header
#include "OpenGL.hpp"

// CGUL Includes
#include "../Containers/Vector.hpp"

/** @brief Clears out OpenGL errors.
 *  @details Since the OpenGL portion of CGUL is experimental, this will be a useful tool to
 *  determine where errors are actually occurring.  This is a direct result of OpenGL's utter shit
 *  error system.
 */
_CGUL_EXPORT void CGUL::OpenGL::ClearErrors()
{
    glGetError();
}

/** @brief A developer test function.  Has undefined behavior.
 */
_CGUL_EXPORT void CGUL::OpenGL::Test()
{
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
}

_CGUL_EXPORT void CGUL::OpenGL::Enable(Enum cap)
{
    glEnable(cap);
    GLCHECK("Failed to enable OpenGL capability.", glEnable);
}

_CGUL_EXPORT void CGUL::OpenGL::Disable(Enum cap)
{
    glDisable(cap);
    GLCHECK("Failed to disable OpenGL capability.", glDisable);
}

_CGUL_EXPORT CGUL::String CGUL::OpenGL::GetString(Enum name)
{
    String ret = String((const char *)glGetString(name));
    GLCHECK("Failed to get OpenGL string.", glGetString);
    return ret;
}

_CGUL_EXPORT CGUL::String CGUL::OpenGL::GetStringi(Enum name, unsigned int index)
{
    String ret = String((const char *)glGetStringi(name, index));
    GLCHECK("Failed to get OpenGL string.", glGetStringi);
    return ret;
}

_CGUL_EXPORT void CGUL::OpenGL::GetSupportedExtensions(FixedList< String >* extensions)
{
    String ret = String((const char *)glGetString(GL::EXTENSIONS));
    GLCHECK("Failed to get OpenGL extensions.", glGetString);
    ret.Explode(" ", extensions);
}

_CGUL_EXPORT bool CGUL::OpenGL::SupportsExtension(String ext)
{
    Vector< String > extensions;
    OpenGL::GetSupportedExtensions(&extensions);
    for (unsigned int i = 0; i < extensions.size(); i++)
    {
        if (extensions[i] == ext)
        {
            return true;
        }
    }
    return false;
}

_CGUL_EXPORT int CGUL::OpenGL::GetOpenGLVersionMajor()
{
    int v;
    glGetIntegerv(GL::MAJOR_VERSION, &v);
    GLCHECK("Failed to get OpenGL major version.", glGetIntegerv);
    return v;
}

_CGUL_EXPORT int CGUL::OpenGL::GetOpenGLVersionMinor()
{
    int v;
    glGetIntegerv(GL::MINOR_VERSION, &v);
    GLCHECK("Failed to get OpenGL minor version.", glGetIntegerv);
    return v;
}

_CGUL_EXPORT CGUL::String CGUL::OpenGL::GetOpenGLVersion()
{
    String ret = String((const char*)glGetString(GL::VERSION));
    GLCHECK("Failed to get OpenGL version.", glGetString);
    return ret;
}

_CGUL_EXPORT CGUL::String CGUL::OpenGL::GetGLSLVersion()
{
    String ret = String((const char*)glGetString(GL::GLSL_VERSION));
    GLCHECK("Failed to get GLSL version.", glGetString);
    return ret;
}

_CGUL_EXPORT CGUL::String CGUL::OpenGL::GetOpenGLVendor()
{
    String ret = ((const char*)glGetString(GL::VENDOR));
    GLCHECK("Failed to get OpenGL vendor.", glGetString);
    return ret;
}

_CGUL_EXPORT CGUL::String CGUL::OpenGL::GetOpenGLRenderer()
{
    String ret = String((const char*)glGetString(GL::RENDERER));
    GLCHECK("Failed to get OpenGL renderer.", glGetString);
    return ret;
}

_CGUL_EXPORT void CGUL::OpenGL::BlendFunc(Enum sfactor, Enum dfactor)
{
    glBlendFunc(sfactor, dfactor);
    GLCHECK("Failed to set blend function.", glBlendFunc);
}

_CGUL_EXPORT void CGUL::OpenGL::BlendFunci(UInt32 buf, Enum sfactor, Enum dfactor)
{
    glBlendFunci(buf, sfactor, dfactor);
    GLCHECK("Failed to set blend function.", glBlendFunci);
}

_CGUL_EXPORT void CGUL::OpenGL::BlendFuncSeparate(Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta)
{
    glBlendFuncSeparate(srcrgb, dstrgb, srca, dsta);
    GLCHECK("Failed to set blend function separate.", glBlendFuncSeparate);
}

_CGUL_EXPORT void CGUL::OpenGL::BlendFuncSeparatei(UInt32 buf, Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta)
{
    glBlendFuncSeparatei(buf, srcrgb, dstrgb, srca, dsta);
    GLCHECK("Failed to set blend function separate.", glBlendFundSeparatei);
}

// OpenGL Calls Begin

_CGUL_EXPORT void CGUL::GL::ActiveTexture(GL::Enum target)
{
    GLCLEAR();
    GLVERIFY(glActiveTexture);
    glActiveTexture(target);
    GLCHECK("Failed to set active texture.", glActiveTexture);
}

_CGUL_EXPORT void CGUL::GL::AttachShader(GL::UInt program, GL::UInt shader)
{
    GLCLEAR();
    GLVERIFY(glAttachShader);
    glAttachShader(program, shader);
    GLCHECK("Failed to attach shader.", glAttachShader);
}

_CGUL_EXPORT void CGUL::GL::BindAttribLocation(GL::UInt program, GL::UInt index, const GL::Char* name)
{
    GLCLEAR();
    GLVERIFY(glBindAttribLocation);
    glBindAttribLocation(program, index, name);
    GLCHECK("Failed to bind attribute location.", glBindAttribLocation);
}

_CGUL_EXPORT void CGUL::GL::BindAttribLocation(GL::UInt program, GL::UInt index, const String& name)
{
    GLCLEAR();
    GLVERIFY(glBindAttribLocation);
    glBindAttribLocation(program, index, name.GetCString());
    GLCHECK("Failed to bind attribute location.", glBindAttribLocation);
}

_CGUL_EXPORT void CGUL::GL::BindBuffer(GL::Enum target, GL::UInt buffer)
{
    GLCLEAR();
    GLVERIFY(glBindBuffer);
    glBindBuffer(target, buffer);
    GLCHECK("Failed to bind buffer.", glBindBuffer);
}

_CGUL_EXPORT void CGUL::GL::BindTexture(GL::Enum target, GL::UInt texture)
{
    GLCLEAR();
    GLVERIFY(glBindTexture);
    glBindTexture(target, texture);
    GLCHECK("Failed to bind texture.", glBindTexture);
}

_CGUL_EXPORT void CGUL::GL::BindVertexArray(GL::UInt array)
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

_CGUL_EXPORT void CGUL::GL::BlendFunc(GL::Enum sfactor, GL::Enum dfactor)
{
    GLCLEAR();
    GLVERIFY(glBlendFunc);
    glBlendFunc(sfactor, dfactor);
    GLCHECK("Failed to set blend function.", glBlendFunc);
}

_CGUL_EXPORT void CGUL::GL::BlendFunci(GL::UInt buf, GL::Enum sfactor, GL::Enum dfactor)
{
    GLCLEAR();
    GLVERIFY(glBlendFunci);
    glBlendFunci(buf, sfactor, dfactor);
    GLCHECK("Failed to set blend function.", glBlendFunci);
}

_CGUL_EXPORT void CGUL::GL::BufferData(GL::Enum target, GL::SizeIPtr size, const GL::Void* data, GL::Enum usage)
{
    GLCLEAR();
    GLVERIFY(glBufferData);
    glBufferData(target, size, data, usage);
    GLCHECK("Failed to set buffer data.", glBufferData);
}

_CGUL_EXPORT void CGUL::GL::CompileShader(GL::UInt shader)
{
    GLCLEAR();
    GLVERIFY(glCompileShader);
    glCompileShader(shader);
    GLCHECK("Failed to compile shader.", glCompileShader);
}

_CGUL_EXPORT CGUL::GL::UInt CGUL::GL::CreateProgram()
{
    GLCLEAR();
    GLVERIFY(glCreateProgram);
    GL::UInt ret = glCreateProgram();
    GLCHECK("Failed to create program.", glCreateProgram);
    return ret;
}

_CGUL_EXPORT CGUL::GL::UInt CGUL::GL::CreateShader(GL::Enum shaderType)
{
    GLCLEAR();
    GLVERIFY(glCreateShader);
    GL::UInt ret = glCreateShader(shaderType);
    GLCHECK("Failed to create shader.", glCreateShader);
    return ret;
}

_CGUL_EXPORT void CGUL::GL::DeleteBuffers(GL::SizeI n, const GL::UInt* buffers)
{
    GLCLEAR();
    GLVERIFY(glDeleteBuffers);
    glDeleteBuffers(n, buffers);
    GLCHECK("Failed to delete buffers.", glDeleteBuffers);
}

_CGUL_EXPORT void CGUL::GL::DeleteVertexArrays(GL::SizeI n, const GL::UInt* arrays)
{
    GLCLEAR();
    GLVERIFY(glDeleteVertexArrays);
    glDeleteBuffers(n, arrays);
    GLCHECK("Failed to delete vertex arrays.", glDeleteVertexArrays);
}

_CGUL_EXPORT void CGUL::GL::Disable(GL::Enum cap)
{
    GLCLEAR();
    GLVERIFY(glDisable);
    glDisable(cap);
    GLCHECK("Failed to disable capability.", glDisable);
}

_CGUL_EXPORT void CGUL::GL::DisableVertexAttribArray(GL::UInt index)
{
    GLCLEAR();
    GLVERIFY(glDisableVertexAttribArray);
    glDisableVertexAttribArray(index);
    GLCHECK("Failed to disable vertex attribute array.", glDisableVertexAttribArray);
}

_CGUL_EXPORT void CGUL::GL::DrawArrays(GL::Enum mode, GL::Int first, GL::SizeI count)
{
    GLCLEAR();
    GLVERIFY(glDrawArrays);
    glDrawArrays(mode, first, count);
    GLCHECK("Failed to draw arrays.", glDrawArrays);
}

_CGUL_EXPORT void CGUL::GL::DrawElements(GL::Enum mode, GL::SizeI count, GL::Enum type, const GL::Void* indices)
{
    GLCLEAR();
    GLVERIFY(glDrawElements);
    glDrawElements(mode, count, type, indices);
    GLCHECK("Failed to draw elements.", glDrawElements);
}

_CGUL_EXPORT void CGUL::GL::Enable(GL::Enum cap)
{
    GLCLEAR();
    GLVERIFY(glEnable);
    glEnable(cap);
    GLCHECK("Failed to enable capability.", glEnable);
}

_CGUL_EXPORT void CGUL::GL::EnableVertexAttribArray(GL::UInt index)
{
    GLCLEAR();
    GLVERIFY(glEnableVertexAttribArray);
    glEnableVertexAttribArray(index);
    GLCHECK("Failed to enable vertex attribute array.", glEnableVertexAttribArray);
}

_CGUL_EXPORT void CGUL::GL::GenBuffers(GL::SizeI n, GL::UInt* buffers)
{
    GLCLEAR();
    GLVERIFY(glGenBuffers);
    glGenBuffers(n, buffers);
    GLCHECK("Failed to generate buffers.", glGenBuffers);
}

_CGUL_EXPORT void CGUL::GL::GenTextures(GL::SizeI n, GL::UInt* textures)
{
    GLCLEAR();
    GLVERIFY(glGenTextures);
    glGenTextures(n, textures);
    GLCHECK("Failed to generate textures.", glGenTextures);
}

_CGUL_EXPORT void CGUL::GL::GenVertexArrays(GL::SizeI n, GL::UInt* arrays)
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

_CGUL_EXPORT void CGUL::GL::GetProgramInfoLog(GL::UInt program, GL::SizeI maxLength, GL::SizeI* length, GL::Char* infoLog)
{
    GLCLEAR();
    GLVERIFY(glGetProgramInfoLog);
    glGetProgramInfoLog(program, maxLength, (GLsizei*)length, infoLog);
    GLCHECK("Failed to get shader info log.", glGetProgramInfoLog);
}

_CGUL_EXPORT void CGUL::GL::GetProgramInfoLog(GL::UInt program, String* infoLog)
{
    GLCLEAR();
    GL::Int maxLength;
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

_CGUL_EXPORT void CGUL::GL::GetProgramiv(GL::UInt program, GL::Enum pname, GL::Int* params)
{
    GLCLEAR();
    GLVERIFY(glGetProgramiv);
    glGetProgramiv(program, pname, params);
    GLCHECK("Failed to get program parameter.", glGetProgramiv);
}

_CGUL_EXPORT void CGUL::GL::GetShaderInfoLog(GL::UInt shader, GL::SizeI maxLength, GL::SizeI* length, GL::Char* infoLog)
{
    GLCLEAR();
    GLVERIFY(glGetShaderInfoLog);
    glGetShaderInfoLog(shader, maxLength, (GLsizei*)length, infoLog);
    GLCHECK("Failed to get shader info log.", glGetShaderInfoLog);
}

_CGUL_EXPORT void CGUL::GL::GetShaderInfoLog(GL::UInt shader, String* infoLog)
{
    GLCLEAR();
    GL::Int maxLength;
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

_CGUL_EXPORT void CGUL::GL::GetShaderiv(GL::UInt shader, GL::Enum pname, GL::Int* params)
{
    GLCLEAR();
    GLVERIFY(glGetShaderiv);
    glGetShaderiv(shader, pname, params);
    GLCHECK("Failed to get shader parameter.", glGetShaderiv);
}

_CGUL_EXPORT CGUL::GL::Int CGUL::GL::GetUniformLocation(GL::UInt program, const GL::Char* name)
{
    GLCLEAR();
    GLVERIFY(glGetUniformLocation);
    GL::Int ret = glGetUniformLocation(program, name);
    GLCHECK("Failed to get uniform location.", glGetUniformLocation);
    return ret;
}

_CGUL_EXPORT CGUL::GL::Int CGUL::GL::GetUniformLocation(GL::UInt program, String& name)
{
    GLCLEAR();
    GLVERIFY(glGetUniformLocation);
    GL::Int ret = glGetUniformLocation(program, name.GetCString());
    GLCHECK("Failed to get uniform location.", glGetUniformLocation);
    return ret;
}

_CGUL_EXPORT void CGUL::GL::LinkProgram(GL::UInt program)
{
    GLCLEAR();
    GLVERIFY(glLinkProgram);
    glLinkProgram(program);
    GLCHECK("Failed to link program.", glLinkProgram);
}

_CGUL_EXPORT void CGUL::GL::PixelStoref(GL::Enum pname, GL::Float param)
{
    GLCLEAR();
    GLVERIFY(glPixelStoref);
    glPixelStoref(pname, param);
    GLCHECK("Failed to set pixel store.", glPixelStoref);
}

_CGUL_EXPORT void CGUL::GL::PixelStorei(GL::Enum pname, GL::Int param)
{
    GLCLEAR();
    GLVERIFY(glPixelStorei);
    glPixelStorei(pname, param);
    GLCHECK("Failed to set pixel store.", glPixelStorei);
}

_CGUL_EXPORT void CGUL::GL::ShaderSource(GL::UInt shader, GL::SizeI count, const GL::Char** string, const GL::Int* length)
{
    GLCLEAR();
    GLVERIFY(glShaderSource);
    glShaderSource(shader, count, string, length);
    GLCHECK("Failed to set the shader source.", glShaderSource);
}

_CGUL_EXPORT void CGUL::GL::ShaderSource(GL::UInt shader, const GL::Char* string)
{
    GLCLEAR();
    const char** data = &string;
    GL::Int length = (GL::Int)strlen(string);
    GLVERIFY(glShaderSource);
    glShaderSource(shader, 1, data, &length);
    GLCHECK("Failed to set the shader source.", glShaderSource);
}

_CGUL_EXPORT void CGUL::GL::ShaderSource(GL::UInt shader, const CGUL::String& string)
{
    GLCLEAR();
    const char* cstr = string.GetCString();
    const char** data = &cstr;
    GL::Int length = (GL::Int)string.GetLength();
    GLVERIFY(glShaderSource);
    glShaderSource(shader, 1, data, &length);
    GLCHECK("Failed to set the shader source.", glShaderSource);
}

_CGUL_EXPORT void CGUL::GL::SwapInterval(GL::Boolean enable)
{
#   ifdef CGUL_WINDOWS
    GLCLEAR();
    GLVERIFY(wglSwapIntervalEXT);
    wglSwapIntervalEXT(enable ? 1 : 0);
    GLCHECK("Failed to set swap interval.", wglSwapIntervalEXT);
#   endif

#   ifdef CGUL_LINUX
    // TODO: SwapInterval on Linux
#   endif

#   ifdef CGUL_MACOS
    // TODO: SwapInterval on MacOS
#   endif
}

_CGUL_EXPORT void CGUL::GL::TexEnvf(GL::Enum target, GL::Enum pname, GL::Float param)
{
    GLCLEAR();
    GLVERIFY(glTexEnvf);
    glTexEnvf(target, pname, param);
    GLCHECK("Failed to set texture environment parameters.", glTexEnvf);
}

_CGUL_EXPORT void CGUL::GL::TexEnvi(GL::Enum target, GL::Enum pname, GL::Int param)
{
    GLCLEAR();
    GLVERIFY(glTexEnvi);
    glTexEnvi(target, pname, param);
    GLCHECK("Failed to set texture environment parameters.", glTexEnvi);
}

_CGUL_EXPORT void CGUL::GL::TexImage2D(GL::Enum target, GL::Int level, GL::Int internalFormat, GL::SizeI width, GL::SizeI height, GL::Int border, GL::Enum format, GL::Enum type, const GL::Void* data)
{
    GLCLEAR();
    GLVERIFY(glTexImage2D);
    glTexImage2D(target, level, internalFormat, width, height, border, format, type, data);
    GLCHECK("Failed to set texture 2D image.", glTexImage2D);
}

_CGUL_EXPORT void CGUL::GL::TexParameterf(GL::Enum target, GL::Enum pname, GL::Float param)
{
    GLCLEAR();
    GLVERIFY(glTexParameterf);
    glTexParameterf(target, pname, param);
    GLCHECK("Failed to set texture parameter.", glTexParamterf);
}

_CGUL_EXPORT void CGUL::GL::TexParameteri(GL::Enum target, GL::Enum pname, GL::Int param)
{
    GLCLEAR();
    GLVERIFY(glTexParameteri);
    glTexParameteri(target, pname, param);
    GLCHECK("Failed to set texture parameter.", glTexParameteri);
}

_CGUL_EXPORT void CGUL::GL::Uniform1f(GL::Int location, GL::Float v0)
{
    GLCLEAR();
    GLVERIFY(glUniform1f);
    glUniform1f(location, v0);
    GLCHECK("Failed to set shader uniform.", glUniform1f);
}

_CGUL_EXPORT void CGUL::GL::Uniform1fv(GL::Int location, GL::SizeI count, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniform1fv);
    glUniform1fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform1fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform1i(GL::Int location, GL::Int v0)
{
    GLCLEAR();
    GLVERIFY(glUniform1i);
    glUniform1i(location, v0);
    GLCHECK("Failed to set shader uniform.", glUniform1i);
}

_CGUL_EXPORT void CGUL::GL::Uniform1iv(GL::Int location, GL::SizeI count, const GL::Int* value)
{
    GLCLEAR();
    GLVERIFY(glUniform1iv);
    glUniform1iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform1iv);
}

_CGUL_EXPORT void CGUL::GL::Uniform2f(GL::Int location, GL::Float v0, GL::Float v1)
{
    GLCLEAR();
    GLVERIFY(glUniform2f);
    glUniform2f(location, v0, v1);
    GLCHECK("Failed to set shader uniform.", glUniform2f);
}

_CGUL_EXPORT void CGUL::GL::Uniform2f(GL::Int location, const Vector2T< GL::Float >& v)
{
    GLCLEAR();
    GLVERIFY(glUniform2f);
    glUniform2f(location, v.x, v.y);
    GLCHECK("Failed to set shader uniform.", glUniform2f);
}

_CGUL_EXPORT void CGUL::GL::Uniform2fv(GL::Int location, GL::SizeI count, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniform2fv);
    glUniform2fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform2fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform2fv(GL::Int location, GL::SizeI count, const Vector2T< GL::Float >* value)
{
    GLCLEAR();
    GLVERIFY(glUniform2fv);
    glUniform2fv(location, count, (float*)value);
    GLCHECK("Failed to set shader uniform.", glUniform2fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform2i(GL::Int location, GL::Int v0, GL::Int v1)
{
    GLCLEAR();
    GLVERIFY(glUniform2i);
    glUniform2i(location, v0, v1);
    GLCHECK("Failed to set shader uniform.", glUniform2i);
}

_CGUL_EXPORT void CGUL::GL::Uniform2iv(GL::Int location, GL::SizeI count, const GL::Int* value)
{
    GLCLEAR();
    GLVERIFY(glUniform2iv);
    glUniform2iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform2iv);
}

_CGUL_EXPORT void CGUL::GL::Uniform3f(GL::Int location, GL::Float v0, GL::Float v1, GL::Float v2)
{
    GLCLEAR();
    GLVERIFY(glUniform3f);
    glUniform3f(location, v0, v1, v2);
    GLCHECK("Failed to set shader uniform.", glUniform3f);
}

_CGUL_EXPORT void CGUL::GL::Uniform3f(GL::Int location, const Vector3T< GL::Float >& v)
{
    GLCLEAR();
    GLVERIFY(glUniform3f);
    glUniform3f(location, v.x, v.y, v.z);
    GLCHECK("Failed to set shader uniform.", glUniform3f);
}

_CGUL_EXPORT void CGUL::GL::Uniform3f(GL::Int location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform3f);
    glUniform3f(location, v.GetRedFloat(), v.GetGreenFloat(), v.GetBlueFloat());
    GLCHECK("Failed to set shader uniform.", glUniform3f);
}

_CGUL_EXPORT void CGUL::GL::Uniform3fv(GL::Int location, GL::SizeI count, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniform3fv);
    glUniform3fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform3fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform3fv(GL::Int location, GL::SizeI count, const Vector3T< GL::Float >* value)
{
    GLCLEAR();
    GLVERIFY(glUniform3fv);
    glUniform3fv(location, count, (float*)value);
    GLCHECK("Failed to set shader uniform.", glUniform3fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform3i(GL::Int location, GL::Int v0, GL::Int v1, GL::Int v2)
{
    GLCLEAR();
    GLVERIFY(glUniform3i);
    glUniform3i(location, v0, v1, v2);
    GLCHECK("Failed to set shader uniform.", glUniform3i);
}

_CGUL_EXPORT void CGUL::GL::Uniform3i(GL::Int location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform3i);
    glUniform3i(location, v.r, v.g, v.b);
    GLCHECK("Failed to set shader uniform.", glUniform3i);
}

_CGUL_EXPORT void CGUL::GL::Uniform3iv(GL::Int location, GL::SizeI count, const GL::Int* value)
{
    GLCLEAR();
    GLVERIFY(glUniform3iv);
    glUniform3iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform3iv);
}

_CGUL_EXPORT void CGUL::GL::Uniform4f(GL::Int location, GL::Float v0, GL::Float v1, GL::Float v2, GL::Float v3)
{
    GLCLEAR();
    GLVERIFY(glUniform4f);
    glUniform4f(location, v0, v1, v2, v3);
    GLCHECK("Failed to set shader uniform.", glUniform4f);
}

_CGUL_EXPORT void CGUL::GL::Uniform4f(GL::Int location, const Vector4T< GL::Float >& v)
{
    GLCLEAR();
    GLVERIFY(glUniform4f);
    glUniform4f(location, v.x, v.y, v.z, v.w);
    GLCHECK("Failed to set shader uniform.", glUniform4f);
}

_CGUL_EXPORT void CGUL::GL::Uniform4f(GL::Int location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform4f);
    glUniform4f(location, v.GetRedFloat(), v.GetGreenFloat(), v.GetBlueFloat(), v.GetAlphaFloat());
    GLCHECK("Failed to set shader uniform.", glUniform4f);
}

_CGUL_EXPORT void CGUL::GL::Uniform4fv(GL::Int location, GL::SizeI count, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniform4fv);
    glUniform4fv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform4fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform4fv(GL::Int location, GL::SizeI count, const Vector4T< GL::Float >* value)
{
    GLCLEAR();
    GLVERIFY(glUniform4fv);
    glUniform4fv(location, count, (float*)value);
    GLCHECK("Failed to set shader uniform.", glUniform4fv);
}

_CGUL_EXPORT void CGUL::GL::Uniform4i(GL::Int location, GL::Int v0, GL::Int v1, GL::Int v2, GL::Int v3)
{
    GLCLEAR();
    GLVERIFY(glUniform4i);
    glUniform4i(location, v0, v1, v2, v3);
    GLCHECK("Failed to set shader uniform.", glUniform4i);
}

_CGUL_EXPORT void CGUL::GL::Uniform4i(GL::Int location, const Color& v)
{
    GLCLEAR();
    GLVERIFY(glUniform4i);
    glUniform4i(location, v.r, v.g, v.b, v.a);
    GLCHECK("Failed to set shader uniform.", glUniform4i);
}

_CGUL_EXPORT void CGUL::GL::Uniform4iv(GL::Int location, GL::SizeI count, const GL::Int* value)
{
    GLCLEAR();
    GLVERIFY(glUniform4iv);
    glUniform4iv(location, count, value);
    GLCHECK("Failed to set shader uniform.", glUniform4iv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix2fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix2fv);
    glUniformMatrix2fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUniformMatrix2fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix3fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix3fv);
    glUniformMatrix3fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUnofirmMatrix3fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4f(GL::Int location, GL::Boolean transpose, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, 1, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4f(GL::Int location, GL::Boolean transpose, const MatrixT< GL::Float >& value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, 1, transpose, value.GetData());
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const GL::Float* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, count, transpose, value);
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UniformMatrix4fv(GL::Int location, GL::SizeI count, GL::Boolean transpose, const MatrixT< GL::Float >* value)
{
    GLCLEAR();
    GLVERIFY(glUniformMatrix4fv);
    glUniformMatrix4fv(location, count, transpose, value->GetData());
    GLCHECK("Failed to set shader uniform.", glUniformMatrix4fv);
}

_CGUL_EXPORT void CGUL::GL::UseProgram(GL::UInt program)
{
    GLCLEAR();
    GLVERIFY(glUseProgram);
    glUseProgram(program);
    GLCHECK("Failed to use program.", glUseProgram);
}

_CGUL_EXPORT void CGUL::GL::ValidateProgram(GL::UInt program)
{
    GLCLEAR();
    GLVERIFY(glValidateProgram);
    glValidateProgram(program);
    GLCHECK("Failed to validate program.", glValidateProgram);
}

_CGUL_EXPORT void CGUL::GL::VertexAttribIPointer(GL::UInt index, GL::Int size, GL::Enum type, GL::SizeI stride, const GL::Void* pointer)
{
    GLCLEAR();
    GLVERIFY(glVertexAttribIPointer);
    glVertexAttribIPointer(index, size, type, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.", glVertexAttribIPointer);
}

_CGUL_EXPORT void CGUL::GL::VertexAttribLPointer(GL::UInt index, GL::Int size, GL::Enum type, GL::SizeI stride, const GL::Void* pointer)
{
    GLCLEAR();
    GLVERIFY(glVertexAttribLPointer);
    glVertexAttribLPointer(index, size, type, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.", glVertexAttribLPointer);
}

_CGUL_EXPORT void CGUL::GL::VertexAttribPointer(GL::UInt index, GL::Int size, GL::Enum type, GL::Boolean normalized, GL::SizeI stride, const GL::Void* pointer)
{
    GLCLEAR();
    GLVERIFY(glVertexAttribPointer);
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    GLCHECK("Failed to set vertex attribute pointer.", glVertexAttribPointer);
}
