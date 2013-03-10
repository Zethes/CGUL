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
        class Scene;

        class Importer
        {
            _JATTA_AIIMPORTER importer;
            Scene*scene;

        public:
            _JATTA_EXPORT Importer();
            _JATTA_EXPORT ~Importer();

            _JATTA_EXPORT SInt32 RegisterLoader(_JATTA_AIBASEIMPORTER importer);
            _JATTA_EXPORT SInt32 UnregisterLoader(_JATTA_AIBASEIMPORTER importer);
            _JATTA_EXPORT SInt32 RegisterPPStep(_JATTA_AIBASEPROCESS importer); 
            _JATTA_EXPORT SInt32 UnregisterPPStep(_JATTA_AIBASEPROCESS importer);

            _JATTA_EXPORT void SetProperty(String name, SInt32 value, bool* existing = NULL);
            _JATTA_EXPORT void SetProperty(String name, bool value, bool* existing = NULL);
            _JATTA_EXPORT void SetProperty(String name, Float32 value, bool* existing = NULL);
            _JATTA_EXPORT void SetProperty(String name, String value, bool* existing = NULL);

            _JATTA_EXPORT SInt32 GetPropertyInteger(String name, SInt32 errorReturn = 0xffffffff) const;
            _JATTA_EXPORT bool GetPropertyBool(String name, bool errorReturn = false) const;
            _JATTA_EXPORT Float32 GetPropertyFloat(String name, Float32 errorReturn = 10e10f) const;
            _JATTA_EXPORT String GetPropertyString(String name, String errorReturn = "") const;

            _JATTA_EXPORT void SetIOHandler(_JATTA_AIIOHANDLER pIOHandler);
            _JATTA_EXPORT _JATTA_AIIOHANDLER GetIOHandler() const;
            _JATTA_EXPORT bool IsDefaultIOHandler() const;

            _JATTA_EXPORT void SetProgressHandler(_JATTA_AIPROGRESHANDLER handler);
            _JATTA_EXPORT _JATTA_AIPROGRESHANDLER GetProgressHandler() const;
            _JATTA_EXPORT bool IsDefaultProgressHandler() const;

            _JATTA_EXPORT bool ValidateFlags(Enum flags) const;

            _JATTA_EXPORT const Scene* ReadFile(const String& fileName, Enum flags);
            _JATTA_EXPORT const Scene* ReadFileFromMemory(const void* buffer, UInt32 length, Enum flags, const char* hint="");
            _JATTA_EXPORT const Scene* ApplyPostProcessing(Enum flags);
            _JATTA_EXPORT void FreeScene();

            _JATTA_EXPORT String GetErrorString() const;
            _JATTA_EXPORT const Scene* GetScene() const;

            _JATTA_EXPORT bool IsExtensionSupported(String ext) const;
            _JATTA_EXPORT Jatta::String GetExtensionList() const;
            _JATTA_EXPORT UInt32 GetImporterCount() const;
            _JATTA_EXPORT const _JATTA_AIIMPORTERDESC GetImporterInfo(UInt32 index) const;
            _JATTA_EXPORT _JATTA_AIBASEIMPORTER GetImporter(UInt32 index) const;
            _JATTA_EXPORT _JATTA_AIBASEIMPORTER GetImporter(String extension) const;
            _JATTA_EXPORT UInt32 GetImporterIndex(String extension) const;  

            _JATTA_EXPORT _JATTA_AIMEMORYINFO GetMemoryRequirements() const;
            _JATTA_EXPORT void SetExtraVerbose(bool bDo);
        };
    }
}

#include "../External/Undefines.h"
