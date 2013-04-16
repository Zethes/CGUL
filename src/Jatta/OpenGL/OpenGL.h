/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "GL.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* OpenGL is an experimental namespace in Jatta! */
namespace Jatta
{
    /** @brief Experimental OpenGL wrapper.
     */
    namespace OpenGL
    {
        _JATTA_EXPORT void ClearErrors();
        _JATTA_EXPORT void Test();

        _JATTA_EXPORT void Enable(Enum cap);
        _JATTA_EXPORT void Disable(Enum cap);

        _JATTA_EXPORT std::string GetString(Enum name);
        _JATTA_EXPORT std::string GetStringi(Enum name, unsigned int index);
        _JATTA_EXPORT std::vector<Jatta::String> GetSupportedExtensions();
        _JATTA_EXPORT bool SupportsExtension(Jatta::String ext);
        _JATTA_EXPORT int GetOpenGLVersionMajor();
        _JATTA_EXPORT int GetOpenGLVersionMinor();
        _JATTA_EXPORT std::string GetOpenGLVersion();
        _JATTA_EXPORT std::string GetGLSLVersion();
        _JATTA_EXPORT std::string GetOpenGLVendor();
        _JATTA_EXPORT std::string GetOpenGLRenderer();

        _JATTA_EXPORT void BlendFunc(Enum sfactor, Enum dfactor);
        _JATTA_EXPORT void BlendFunci(UInt32 buf, Enum sfactor, Enum dfactor);

        _JATTA_EXPORT void BlendFuncSeparate(Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta);
        _JATTA_EXPORT void BlendFuncSeparatei(UInt32 buf, Enum srcrgb, Enum dstrgb, Enum srca, Enum dsta);
    }
}
#include "../External/Undefines.h"