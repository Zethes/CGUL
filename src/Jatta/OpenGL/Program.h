/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "Shader.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Program
        {
            UInt32 program;
        public:
            Program();
            ~Program();

            void Generate();
            void Delete();
            UInt32 GetID();

            void Bind();
            void Unbind();

            void AttachShader(const Shader& shader);
            void DetachShader(const Shader& shader);

            void Link();
        };
    }
}
#include "../External/Undefines.h"