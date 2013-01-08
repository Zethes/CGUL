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
void Jatta::OpenGL::ClearErrors()
{
    glGetError();
}