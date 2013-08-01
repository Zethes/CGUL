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
    _JATTA_EXPORT String GetJattaVersion();
    _JATTA_EXPORT UInt32 GetJattaVersionMajor();
    _JATTA_EXPORT UInt32 GetJattaVersionMinor();
    _JATTA_EXPORT UInt32 GetJattaVersionPatch();
    _JATTA_EXPORT String GetJattaCompilerName();
}

#include "../External/Undefines.h"
