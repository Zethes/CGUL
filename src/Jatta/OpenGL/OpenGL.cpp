/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_OPENGL
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

#include <iostream>
#include <fstream>
/** @brief A developer test function.  Has undefined behavior.
 */
_JATTA_EXPORT void Jatta::OpenGL::Test()
{
    /*std::fstream extensionsFile;
    extensionsFile.open("gl.txt", std::fstream::out);
    std::cout << std::hex;
    //std::cout << "GL_EXTENSIONS = 0x" << GL_EXTENSIONS << std::endl;
    extensionsFile << "GL_MAJOR_VERSION = 0x" << GL_MAJOR_VERSION << std::endl;
    extensionsFile << "GL_MINOR_VERSION = 0x" << GL_MINOR_VERSION << std::endl;
    extensionsFile << "GL_VERSION = 0x" << GL_VERSION << std::endl;
    extensionsFile << "GL_SHADING_LANGUAGE_VERSION = 0x" << GL_SHADING_LANGUAGE_VERSION << std::endl;
    extensionsFile << "GL_VENDOR = 0x" << GL_VENDOR << std::endl;
    extensionsFile << "GL_RENDERER = 0x" << GL_RENDERER << std::endl;
    extensionsFile << "GL_TEXTURE_2D = 0x" << GL_TEXTURE_2D << std::endl;
    extensionsFile << "GL_PROXY_TEXTURE_2D = 0x" << GL_PROXY_TEXTURE_2D << std::endl;
    extensionsFile << "GL_TEXTURE_1D_ARRAY = 0x" << GL_TEXTURE_1D_ARRAY << std::endl;
    extensionsFile << "GL_PROXY_TEXTURE_1D_ARRAY = 0x" << GL_PROXY_TEXTURE_1D_ARRAY << std::endl;
    extensionsFile << "GL_TEXTURE_RECTANGLE = 0x" << GL_TEXTURE_RECTANGLE << std::endl;
    extensionsFile << "GL_PROXY_TEXTURE_RECTANGLE = 0x" << GL_PROXY_TEXTURE_RECTANGLE << std::endl;
    extensionsFile << "GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x" << GL_TEXTURE_CUBE_MAP_POSITIVE_X << std::endl;
    extensionsFile << "GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x" << GL_TEXTURE_CUBE_MAP_NEGATIVE_X << std::endl;
    extensionsFile << "GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x" << GL_TEXTURE_CUBE_MAP_POSITIVE_Y << std::endl;
    extensionsFile << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x" << GL_TEXTURE_CUBE_MAP_NEGATIVE_Y << std::endl;
    extensionsFile << "GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x" << GL_TEXTURE_CUBE_MAP_POSITIVE_Z << std::endl;
    extensionsFile << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x" << GL_TEXTURE_CUBE_MAP_NEGATIVE_Z << std::endl;
    extensionsFile << "GL_PROXY_TEXTURE_CUBE_MAP = 0x" << GL_PROXY_TEXTURE_CUBE_MAP << std::endl;

    extensionsFile << std::endl << "Supported Extensions: " << std::endl;
    std::vector<String>extensions = OpenGL::GetSupportedExtensions();
    for (unsigned int i = 0; i < extensions.size(); i++)
    {
        extensionsFile << "\t" << extensions[i].GetData().c_str() << " = 0x" << i << std::endl;
    }*/
    glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(1, 1);
    glEnd();
}

_JATTA_EXPORT std::string Jatta::OpenGL::GetString(Jatta::OpenGL::Enum name)
{
    std::string ret = (const char *)glGetString(name);
    return ret;
}
_JATTA_EXPORT std::string Jatta::OpenGL::GetStringi(Jatta::OpenGL::Enum name, unsigned int index)
{
    std::string ret;// = (const char *)glGetStringi(name, index);
    return ret;
}

_JATTA_EXPORT std::vector<Jatta::String> Jatta::OpenGL::GetSupportedExtensions()
{
    Jatta::String ret = (const char *)glGetString(GL::EXTENSIONS);

    return ret.Explode(" ");
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

#endif
