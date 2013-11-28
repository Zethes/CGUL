// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Version.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    // @brief Gets the CGUL version as a string.
    _CGUL_EXPORT String GetCGULVersion();
    // @brief Gets the CGUL major version.
    _CGUL_EXPORT UInt32 GetCGULVersionMajor();
    // @brief Gets the CGUL minor version.
    _CGUL_EXPORT UInt32 GetCGULVersionMinor();
    // @brief Gets the CGUL patch version.
    _CGUL_EXPORT UInt32 GetCGULVersionPatch();
    // @brief Gets the name of the compiler used to build CGUL.
    _CGUL_EXPORT String GetCGULCompilerName();
}

#include "../External/Undefines.hpp"
