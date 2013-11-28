

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
        class ExportBlob
        {
            const _JATTA_AIEXPORTDATABLOB blob;
            ExportBlob* next;
        public:
            _JATTA_EXPORT ExportBlob(const _JATTA_AIEXPORTDATABLOB blob);

            _JATTA_EXPORT void* GetData();
            _JATTA_EXPORT String GetName();
            _JATTA_EXPORT ExportBlob* GetNext();
            _JATTA_EXPORT UInt32 GetSize();
            _JATTA_EXPORT void Free();
        };
    }
}

#include "../External/Undefines.h"
