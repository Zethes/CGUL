// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGL.cpp
 */

#include "OpenGL.hpp"

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
    GLCHECK("Failed to enable OpenGL capability.");
}

_CGUL_EXPORT void CGUL::OpenGL::Disable(Enum cap)
{
    glDisable(cap);
    GLCHECK("Failed to disable OpenGL capability.");
}

_CGUL_EXPORT std::string CGUL::OpenGL::GetString(Enum name)
{
    std::string ret = (const char *)glGetString(name);
    GLCHECK("Failed to get OpenGL string.");
    return ret;
}
_CGUL_EXPORT std::string CGUL::OpenGL::GetStringi(Enum name, unsigned int index)
{
    std::string ret = (const char *)glGetStringi(name, index);
    GLCHECK("Failed to get OpenGL string.");
    return ret;
}

_CGUL_EXPORT std::vector<CGUL::String> CGUL::OpenGL::GetSupportedExtensions()
{
    CGUL::String ret = (const char *)glGetString(GL::EXTENSIONS);
    GLCHECK("Failed to get OpenGL extensions.");
    return ret.Explode(" ");
}

_CGUL_EXPORT bool CGUL::OpenGL::SupportsExtension(CGUL::String ext)
{
    std::vector<String>extensions = OpenGL::GetSupportedExtensions();
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
    GLCHECK("Failed to get OpenGL major version.");
    return v;
}

_CGUL_EXPORT int CGUL::OpenGL::GetOpenGLVersionMinor()
{
    int v;
    glGetIntegerv(GL::MINOR_VERSION, &v);
    GLCHECK("Failed to get OpenGL minor version.");
    return v;
}

_CGUL_EXPORT std::string CGUL::OpenGL::GetOpenGLVersion()
{
    std::string ret = (char *)glGetString(GL::VERSION);
    GLCHECK("Failed to get OpenGL version.");
    return ret;
}
_CGUL_EXPORT std::string CGUL::OpenGL::GetGLSLVersion()
{
    std::string ret = (char *)glGetString(GL::GLSL_VERSION);
    GLCHECK("Failed to get GLSL version.");
    return ret;
}
_CGUL_EXPORT std::string CGUL::OpenGL::GetOpenGLVendor()
{
    std::string ret = (char *)glGetString(GL::VENDOR);
    GLCHECK("Failed to get OpenGL vendor.");
    return ret;
}
_CGUL_EXPORT std::string CGUL::OpenGL::GetOpenGLRenderer()
{
    std::string ret = (char *)glGetString(GL::RENDERER);
    GLCHECK("Failed to get OpenGL renderer.");
    return ret;
}

_CGUL_EXPORT void CGUL::OpenGL::BlendFunc(Enum sfactor, Enum dfactor)
{
    glBlendFunc(sfactor, dfactor);
    GLCHECK("Failed to set blend function.");
}

_CGUL_EXPORT void CGUL::OpenGL::BlendFunci(UInt32 buf, Enum sfactor, Enum dfactor)
{
    glBlendFunci(buf, sfactor, dfactor);
    GLCHECK("Failed to set blend function.");
}

_CGUL_EXPORT void CGUL::OpenGL::BlendFuncSeparate(Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta)
{
    glBlendFuncSeparate(srcrgb, dstrgb, srca, dsta);
    GLCHECK("Failed to set blend function separate.");
}
_CGUL_EXPORT void CGUL::OpenGL::BlendFuncSeparatei(UInt32 buf, Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta)
{
    glBlendFuncSeparatei(buf, srcrgb, dstrgb, srca, dsta);
    GLCHECK("Failed to set blend function separate.");
}
