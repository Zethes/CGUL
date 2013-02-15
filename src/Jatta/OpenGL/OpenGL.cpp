/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "OpenGL.h"

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

_JATTA_EXPORT std::string Jatta::OpenGL::GetString(Jatta::OpenGL::Enum name)
{
    std::string ret = (const char *)glGetString(name);
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetStringi(Jatta::OpenGL::Enum name, unsigned int index)
{
    std::string ret = (const char *)glGetStringi(name, index);
    return ret;
}

_JATTA_EXPORT std::vector<Jatta::String> Jatta::OpenGL::GetSupportedExtensions()
{
    Jatta::String ret = (const char *)glGetString(GL::EXTENSIONS);

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
    return v;
}

_JATTA_EXPORT int Jatta::OpenGL::GetOpenGLVersionMinor()
{
    int v;
    glGetIntegerv(GL::MINOR_VERSION, &v);
    return v;
}

_JATTA_EXPORT std::string Jatta::OpenGL::GetOpenGLVersion()
{
    std::string ret = (char *)glGetString(GL::VERSION);
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetGLSLVersion()
{
    std::string ret = (char *)glGetString(GL::GLSL_VERSION);
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetOpenGLVendor()
{
    std::string ret = (char *)glGetString(GL::VENDOR);
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetOpenGLRenderer()
{
    std::string ret = (char *)glGetString(GL::RENDERER);
    return ret;
}