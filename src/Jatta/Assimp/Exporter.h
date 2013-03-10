/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Assimp.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        class Scene;

        class ExportFormatDesc
        {
            const _JATTA_AIEXPORTFORMATDESC desc;
        public:
            _JATTA_EXPORT ExportFormatDesc(const _JATTA_AIEXPORTFORMATDESC desc);

            _JATTA_EXPORT String GetID();
            _JATTA_EXPORT String GetDescription();
            _JATTA_EXPORT String GetFileExtension();
        };

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

        class Exporter
        {
            _JATTA_AIEXPORTER exporter;
            ExportBlob*blob;
        public:
            _JATTA_EXPORT Exporter();
            _JATTA_EXPORT ~Exporter();

            _JATTA_EXPORT SInt32 Export(Scene* scene, String formatId, String path, UInt32 preprocessing = 0u);

            _JATTA_EXPORT ExportBlob* ExportToBlob(Scene* scene, String formatId, UInt32 preprocessing = 0u);
            _JATTA_EXPORT void FreeBlob();
            _JATTA_EXPORT ExportBlob* GetBlob() const;

            _JATTA_EXPORT String GetErrorString() const;
            _JATTA_EXPORT UInt32 GetExportFormatCount() const;
            _JATTA_EXPORT ExportFormatDesc GetExportFormatDescription(UInt32 index) const;

            _JATTA_EXPORT void SetIOHandler(_JATTA_AIIOHANDLER system) const;
            _JATTA_EXPORT _JATTA_AIIOHANDLER GetIOHandler() const;
            _JATTA_EXPORT bool IsDefaultIOHandler() const;

            _JATTA_EXPORT SInt32 RegisterExporter(_JATTA_AIEXPORTFORMATENTRY &desc);
            _JATTA_EXPORT void UnregisterExporter(String id);
        };
    }
}

#include "../External/Undefines.h"
