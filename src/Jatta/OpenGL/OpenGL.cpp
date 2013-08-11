/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "OpenGL.h"

#define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

/** @brief Clears out OpenGL errors.
 *  @details Since the OpenGL portion of Jatta is experimental, this will be a useful tool to
 *  determine where errors are actually occurring.  This is a direct result of OpenGL's utter shit
 *  error system.
 */
_JATTA_EXPORT void Jatta::OpenGL::ClearErrors()
{
    glGetError();
}

/** @brief A developer test function.  Has undefined behavior.
 */
_JATTA_EXPORT void Jatta::OpenGL::Test()
{
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, 0.0f);
    glEnd();
}

_JATTA_EXPORT void Jatta::OpenGL::Enable(Enum cap)
{
    glEnable(cap);
    GLCHECK("Failed to enable OpenGL capability.");
}

_JATTA_EXPORT void Jatta::OpenGL::Disable(Enum cap)
{
    glDisable(cap);
    GLCHECK("Failed to disable OpenGL capability.");
}

_JATTA_EXPORT std::string Jatta::OpenGL::GetString(Enum name)
{
    std::string ret = (const char *)glGetString(name);
    GLCHECK("Failed to get OpenGL string.");
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetStringi(Enum name, unsigned int index)
{
    std::string ret = (const char *)glGetStringi(name, index);
    GLCHECK("Failed to get OpenGL string.");
    return ret;
}

_JATTA_EXPORT std::vector<Jatta::String> Jatta::OpenGL::GetSupportedExtensions()
{
    Jatta::String ret = (const char *)glGetString(GL::EXTENSIONS);
    GLCHECK("Failed to get OpenGL extensions.");
    return ret.Explode(" ");
}

_JATTA_EXPORT bool Jatta::OpenGL::SupportsExtension(Jatta::String ext)
{
    std::vector<String>extensions = OpenGL::GetSupportedExtensions();
    for (unsigned int i = 0; i < extensions.size(); i++)
    {
        if (extensions[i] == ext)
            return true;
    }
    return false;
}

_JATTA_EXPORT int Jatta::OpenGL::GetOpenGLVersionMajor()
{
    int v;
    glGetIntegerv(GL::MAJOR_VERSION, &v);
    GLCHECK("Failed to get OpenGL major version.");
    return v;
}

_JATTA_EXPORT int Jatta::OpenGL::GetOpenGLVersionMinor()
{
    int v;
    glGetIntegerv(GL::MINOR_VERSION, &v);
    GLCHECK("Failed to get OpenGL minor version.");
    return v;
}

_JATTA_EXPORT std::string Jatta::OpenGL::GetOpenGLVersion()
{
    std::string ret = (char *)glGetString(GL::VERSION);
    GLCHECK("Failed to get OpenGL version.");
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetGLSLVersion()
{
    std::string ret = (char *)glGetString(GL::GLSL_VERSION);
    GLCHECK("Failed to get GLSL version.");
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetOpenGLVendor()
{
    std::string ret = (char *)glGetString(GL::VENDOR);
    GLCHECK("Failed to get OpenGL vendor.");
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetOpenGLRenderer()
{
    std::string ret = (char *)glGetString(GL::RENDERER);
    GLCHECK("Failed to get OpenGL renderer.");
    return ret;
}

_JATTA_EXPORT void Jatta::OpenGL::BlendFunc(Enum sfactor, Enum dfactor)
{
    glBlendFunc(sfactor, dfactor);
    GLCHECK("Failed to set blend function.");
}

_JATTA_EXPORT void Jatta::OpenGL::BlendFunci(UInt32 buf, Enum sfactor, Enum dfactor)
{
    glBlendFunci(buf, sfactor, dfactor);
    GLCHECK("Failed to set blend function.");
}

_JATTA_EXPORT void Jatta::OpenGL::BlendFuncSeparate(Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta)
{
    glBlendFuncSeparate(srcrgb, dstrgb, srca, dsta);
    GLCHECK("Failed to set blend function separate.");
}
_JATTA_EXPORT void Jatta::OpenGL::BlendFuncSeparatei(UInt32 buf, Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta)
{
    glBlendFuncSeparatei(buf, srcrgb, dstrgb, srca, dsta);
    GLCHECK("Failed to set blend function separate.");
}
