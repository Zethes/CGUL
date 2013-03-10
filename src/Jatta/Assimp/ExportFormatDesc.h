/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Assimp.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace Jatta
{
    namespace Assimp
    {
        class ExportFormatDesc
        {
            const _JATTA_AIEXPORTFORMATDESC desc;
        public:
            _JATTA_EXPORT ExportFormatDesc(const _JATTA_AIEXPORTFORMATDESC desc);

            _JATTA_EXPORT String GetID();
            _JATTA_EXPORT String GetDescription();
            _JATTA_EXPORT String GetFileExtension();
        };
    }
}

#include "../External/Undefines.h"
