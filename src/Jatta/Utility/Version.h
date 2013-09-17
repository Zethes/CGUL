/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    // @brief Gets the Jatta version as a string.
    _JATTA_EXPORT String GetJattaVersion();
    // @brief Gets the Jatta major version.
    _JATTA_EXPORT UInt32 GetJattaVersionMajor();
    // @brief Gets the Jatta minor version.
    _JATTA_EXPORT UInt32 GetJattaVersionMinor();
    // @brief Gets the Jatta patch version.
    _JATTA_EXPORT UInt32 GetJattaVersionPatch();
    // @brief Gets the name of the compiler used to build Jatta.
    _JATTA_EXPORT String GetJattaCompilerName();
}

#include "../External/Undefines.h"
