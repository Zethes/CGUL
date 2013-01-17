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
/** @brief A developer test function.  Has undefined behavior.
 */
_JATTA_EXPORT void Jatta::OpenGL::Test()
{
    std::cout << std::hex;
    /*std::cout << "GL_TEXTURE_2D = 0x" << GL_TEXTURE_2D << std::endl;
    std::cout << "GL_PROXY_TEXTURE_2D = 0x" << GL_PROXY_TEXTURE_2D << std::endl;
    std::cout << "GL_TEXTURE_1D_ARRAY = 0x" << GL_TEXTURE_1D_ARRAY << std::endl;
    std::cout << "GL_PROXY_TEXTURE_1D_ARRAY = 0x" << GL_PROXY_TEXTURE_1D_ARRAY << std::endl;
    std::cout << "GL_TEXTURE_RECTANGLE = 0x" << GL_TEXTURE_RECTANGLE << std::endl;
    std::cout << "GL_PROXY_TEXTURE_RECTANGLE = 0x" << GL_PROXY_TEXTURE_RECTANGLE << std::endl;
    std::cout << "GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x" << GL_TEXTURE_CUBE_MAP_POSITIVE_X << std::endl;
    std::cout << "GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x" << GL_TEXTURE_CUBE_MAP_NEGATIVE_X << std::endl;
    std::cout << "GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x" << GL_TEXTURE_CUBE_MAP_POSITIVE_Y << std::endl;
    std::cout << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x" << GL_TEXTURE_CUBE_MAP_NEGATIVE_Y << std::endl;
    std::cout << "GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x" << GL_TEXTURE_CUBE_MAP_POSITIVE_Z << std::endl;
    std::cout << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x" << GL_TEXTURE_CUBE_MAP_NEGATIVE_Z << std::endl;
    std::cout << "GL_PROXY_TEXTURE_CUBE_MAP = 0x" << GL_PROXY_TEXTURE_CUBE_MAP << std::endl;*/
}

#endif