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
