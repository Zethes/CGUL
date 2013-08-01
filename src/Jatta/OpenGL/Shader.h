/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "OpenGL.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        /** @brief Blah.
         *  @see Jatta::OpenGL::Program
         */
        class Shader
        {
            UInt32 shader;
        public:
            _JATTA_EXPORT Shader();
            _JATTA_EXPORT ~Shader();

            _JATTA_EXPORT void Create(Enum type);
            _JATTA_EXPORT void Delete();
            _JATTA_EXPORT UInt32 GetID() const;

            _JATTA_EXPORT void SetSource(const String& source);
            _JATTA_EXPORT void Compile();

            _JATTA_EXPORT Enum GetShaderType();
            _JATTA_EXPORT Boolean GetDeleteStatus();
            _JATTA_EXPORT String GetSource();

            // TODO: finish importing opengl shader functions
        };
    }
}

#include "../External/Undefines.h"
