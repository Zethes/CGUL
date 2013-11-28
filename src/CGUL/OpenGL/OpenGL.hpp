// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGL.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "GL.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

/* OpenGL is an experimental namespace in CGUL! */
namespace CGUL
{
    /** @brief Experimental OpenGL wrapper.
     */
    namespace OpenGL
    {
        _CGUL_EXPORT void ClearErrors();
        _CGUL_EXPORT void Test();

        _CGUL_EXPORT void Enable(Enum cap);
        _CGUL_EXPORT void Disable(Enum cap);

        _CGUL_EXPORT std::string GetString(Enum name);
        _CGUL_EXPORT std::string GetStringi(Enum name, unsigned int index);
        _CGUL_EXPORT std::vector<CGUL::String> GetSupportedExtensions();
        _CGUL_EXPORT bool SupportsExtension(CGUL::String ext);
        _CGUL_EXPORT int GetOpenGLVersionMajor();
        _CGUL_EXPORT int GetOpenGLVersionMinor();
        _CGUL_EXPORT std::string GetOpenGLVersion();
        _CGUL_EXPORT std::string GetGLSLVersion();
        _CGUL_EXPORT std::string GetOpenGLVendor();
        _CGUL_EXPORT std::string GetOpenGLRenderer();

        _CGUL_EXPORT void BlendFunc(Enum sfactor, Enum dfactor);
        _CGUL_EXPORT void BlendFunci(UInt32 buf, Enum sfactor, Enum dfactor);

        _CGUL_EXPORT void BlendFuncSeparate(Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta);
        _CGUL_EXPORT void BlendFuncSeparatei(UInt32 buf, Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta);
    }
}
#include "../External/Undefines.hpp"
