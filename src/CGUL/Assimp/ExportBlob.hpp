// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ExportBlog.hpp
 */

#pragma once
#include <CGUL/Config.h>
#include "Assimp.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

namespace CGUL
{
    namespace Assimp
    {
        class ExportBlob
        {
            const _CGUL_AIEXPORTDATABLOB blob;
            ExportBlob* next;
        public:
            _CGUL_EXPORT ExportBlob(const _CGUL_AIEXPORTDATABLOB blob);

            _CGUL_EXPORT void* GetData();
            _CGUL_EXPORT String GetName();
            _CGUL_EXPORT ExportBlob* GetNext();
            _CGUL_EXPORT UInt32 GetSize();
            _CGUL_EXPORT void Free();
        };
    }
}

#include "../External/Undefines.h"
