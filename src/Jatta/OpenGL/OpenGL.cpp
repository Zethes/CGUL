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
    std::cout << GL_ARRAY_BUFFER << std::endl;
    std::cout << GL_ATOMIC_COUNTER_BUFFER << std::endl;
    std::cout << GL_COPY_READ_BUFFER << std::endl;
    std::cout << GL_COPY_WRITE_BUFFER << std::endl;
    std::cout << GL_DRAW_INDIRECT_BUFFER << std::endl;
    std::cout << GL_ELEMENT_ARRAY_BUFFER << std::endl;
    std::cout << GL_PIXEL_PACK_BUFFER << std::endl;
    std::cout << GL_PIXEL_UNPACK_BUFFER << std::endl;
    std::cout << GL_SHADER_STORAGE_BUFFER << std::endl;
    std::cout << GL_TEXTURE_BUFFER << std::endl;
    std::cout << GL_TRANSFORM_FEEDBACK_BUFFER << std::endl;
    std::cout << GL_UNIFORM_BUFFER << std::endl;
}