/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include "../Utility/String.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace OpenGL
    {
        class Shader
        {
            UInt32 shader;
        public:
            enum Type
            {
                VERTEX = 0x8b31, TESS_CONTROL = 0x8e88, TESS_EVALUATION = 0x8e87, GEOMETRY = 0x8dd9, FRAGMENT = 0x8b30
            };

            Shader();
            ~Shader();

            void Create(Type type);
            void Delete();
            UInt32 GetID() const;

            void Source(const String& source);
            void Compile();

            Type GetShaderType();
            Boolean GetDeleteStatus();
            Boolean GetCompileStatus();
            String GetInfoLog();
            String GetSource();
        };
    }
}
#include "../External/Undefines.h"