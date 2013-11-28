// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Buffer.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "OpenGL.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    namespace OpenGL
    {
        class Buffer
        {
            UInt32 buffer;
            Enum type;
        public:
            DEPRECATED(_CGUL_EXPORT Buffer(), "Use Raw GL wrappers instead.");

            _CGUL_EXPORT void Create(Enum type);
            _CGUL_EXPORT void Delete();
            _CGUL_EXPORT UInt32 GetID();

            _CGUL_EXPORT void Bind();
            _CGUL_EXPORT void Unbind();

            _CGUL_EXPORT void Data(Size size, void* data, Enum usage);

            // TODO: finish importing opengl buffer functions
        };
    }
}
#include "../External/Undefines.hpp"
