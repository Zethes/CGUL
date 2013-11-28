// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Exporter.hpp
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
        class Scene;
        class ExportFormatDesc;
        class ExportBlob;

        class Exporter
        {
            _CGUL_AIEXPORTER exporter;
            ExportBlob* blob;

            _CGUL_EXPORT Exporter(const Exporter& exporter);
        public:
            _CGUL_EXPORT Exporter();
            _CGUL_EXPORT ~Exporter();

            _CGUL_EXPORT SInt32 Export(Scene* scene, String formatId, String path, UInt32 preprocessing = 0u);

            _CGUL_EXPORT ExportBlob* ExportToBlob(Scene* scene, String formatId, UInt32 preprocessing = 0u);
            _CGUL_EXPORT void FreeBlob();
            _CGUL_EXPORT ExportBlob* GetBlob() const;

            _CGUL_EXPORT String GetErrorString() const;
            _CGUL_EXPORT UInt32 GetExportFormatCount() const;
            _CGUL_EXPORT ExportFormatDesc GetExportFormatDescription(UInt32 index) const;

            _CGUL_EXPORT void SetIOHandler(_CGUL_AIIOHANDLER system) const;
            _CGUL_EXPORT _CGUL_AIIOHANDLER GetIOHandler() const;
            _CGUL_EXPORT bool IsDefaultIOHandler() const;

            _CGUL_EXPORT SInt32 RegisterExporter(_CGUL_AIEXPORTFORMATENTRY &desc);
            _CGUL_EXPORT void UnregisterExporter(String id);
        };
    }
}

#include "../External/Undefines.hpp"
