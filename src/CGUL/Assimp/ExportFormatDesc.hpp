// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ExportFormatDesc.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "Assimp.hpp"
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace Assimp
    {
        class ExportFormatDesc
        {
            const _CGUL_AIEXPORTFORMATDESC desc;
        public:
            _CGUL_EXPORT ExportFormatDesc(const _CGUL_AIEXPORTFORMATDESC desc);

            _CGUL_EXPORT String GetID();
            _CGUL_EXPORT String GetDescription();
            _CGUL_EXPORT String GetFileExtension();
        };
    }
}

#include "../External/Undefines.hpp"
