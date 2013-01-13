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
            _JATTA_EXPORT Program();
            _JATTA_EXPORT ~Program();

            _JATTA_EXPORT void Create();
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID();

            _JATTA_EXPORT void Bind();
            _JATTA_EXPORT void Unbind();

            _JATTA_EXPORT void AttachShader(const Shader& shader);
            _JATTA_EXPORT void DetachShader(const Shader& shader);

            _JATTA_EXPORT void BindAttribLocation(UInt32 index, const String& name);

            _JATTA_EXPORT void Link();
            _JATTA_EXPORT void Validate();

            _JATTA_EXPORT Boolean GetDeleteStatus();
            _JATTA_EXPORT Boolean GetLinkStatus();
            _JATTA_EXPORT Boolean GetValidateStatus();
            _JATTA_EXPORT String GetInfoLog();
            // TODO: GL_ATTACHED_SHADERS
            // TODO: GL_ACTIVE_ATTRIBUTES
            // TODO: GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
            // TODO: GL_ACTIVE_UNIFORMS
            // TODO: GL_ACTIVE_UNIFORM_MAX_LENGTH

            _JATTA_EXPORT SInt32 GetUniformLocation(const String& name);
        };
    }
}
#include "../External/Undefines.h"