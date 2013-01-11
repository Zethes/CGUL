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

#include <iostream>
/** @brief A developer test function.  Has undefined behavior.
 */
_JATTA_EXPORT void Jatta::OpenGL::Test()
{
    std::cout << std::hex;
    std::cout << GL_COLOR_BUFFER_BIT << std::endl;
    std::cout << GL_DEPTH_BUFFER_BIT << std::endl;
    std::cout << GL_STENCIL_BUFFER_BIT << std::endl;
}