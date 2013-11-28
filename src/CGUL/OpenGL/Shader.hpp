// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Shader.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "OpenGL.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    namespace OpenGL
    {
        /** @brief Blah.
         *  @see CGUL::OpenGL::Program
         */
        class Shader
        {
            UInt32 shader;
        public:
            DEPRECATED(_CGUL_EXPORT Shader(), "Use Raw GL wrappers instead.");
            DEPRECATED(_CGUL_EXPORT ~Shader(), "Use Raw GL wrappers instead.");

            _CGUL_EXPORT void Create(Enum type);
            _CGUL_EXPORT void Delete();
            _CGUL_EXPORT UInt32 GetID() const;

            _CGUL_EXPORT void SetSource(const String& source);
            _CGUL_EXPORT void Compile();

            _CGUL_EXPORT Enum GetShaderType();
            _CGUL_EXPORT Boolean GetDeleteStatus();
            _CGUL_EXPORT String GetSource();

            // TODO: finish importing opengl shader functions
        };
    }
}

#include "../External/Undefines.hpp"
