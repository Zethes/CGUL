// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Importer.hpp
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

        class Importer
        {
            _CGUL_AIIMPORTER importer;
            Scene* scene;

            _CGUL_EXPORT Importer(const Importer& copy);
        public:
            _CGUL_EXPORT Importer();
            _CGUL_EXPORT ~Importer();

            _CGUL_EXPORT SInt32 RegisterLoader(_CGUL_AIBASEIMPORTER importer);
            _CGUL_EXPORT SInt32 UnregisterLoader(_CGUL_AIBASEIMPORTER importer);
            _CGUL_EXPORT SInt32 RegisterPPStep(_CGUL_AIBASEPROCESS importer);
            _CGUL_EXPORT SInt32 UnregisterPPStep(_CGUL_AIBASEPROCESS importer);

            _CGUL_EXPORT void SetProperty(String name, SInt32 value, bool* existing = NULL);
            _CGUL_EXPORT void SetProperty(String name, bool value, bool* existing = NULL);
            _CGUL_EXPORT void SetProperty(String name, Float32 value, bool* existing = NULL);
            _CGUL_EXPORT void SetProperty(String name, String value, bool* existing = NULL);

            _CGUL_EXPORT SInt32 GetPropertyInteger(String name, SInt32 errorReturn = 0xffffffff) const;
            _CGUL_EXPORT bool GetPropertyBool(String name, bool errorReturn = false) const;
            _CGUL_EXPORT Float32 GetPropertyFloat(String name, Float32 errorReturn = 10e10f) const;
            _CGUL_EXPORT String GetPropertyString(String name, String errorReturn = "") const;

            _CGUL_EXPORT void SetIOHandler(_CGUL_AIIOHANDLER pIOHandler);
            _CGUL_EXPORT _CGUL_AIIOHANDLER GetIOHandler() const;
            _CGUL_EXPORT bool IsDefaultIOHandler() const;

            _CGUL_EXPORT void SetProgressHandler(_CGUL_AIPROGRESHANDLER handler);
            _CGUL_EXPORT _CGUL_AIPROGRESHANDLER GetProgressHandler() const;
            _CGUL_EXPORT bool IsDefaultProgressHandler() const;

            _CGUL_EXPORT bool ValidateFlags(Enum flags) const;

            _CGUL_EXPORT const Scene* ReadFile(const String& fileName, Enum flags);
            _CGUL_EXPORT const Scene* ReadFileFromMemory(const void* buffer, UInt32 length, Enum flags, const char* hint="");
            _CGUL_EXPORT const Scene* ApplyPostProcessing(Enum flags);
            _CGUL_EXPORT void FreeScene();

            _CGUL_EXPORT String GetErrorString() const;
            _CGUL_EXPORT const Scene* GetScene() const;

            _CGUL_EXPORT bool IsExtensionSupported(String ext) const;
            _CGUL_EXPORT String GetExtensionList() const;
            _CGUL_EXPORT UInt32 GetImporterCount() const;
            _CGUL_EXPORT const _CGUL_AIIMPORTERDESC GetImporterInfo(UInt32 index) const;
            _CGUL_EXPORT _CGUL_AIBASEIMPORTER GetImporter(UInt32 index) const;
            _CGUL_EXPORT _CGUL_AIBASEIMPORTER GetImporter(String extension) const;
            _CGUL_EXPORT UInt32 GetImporterIndex(String extension) const;

            _CGUL_EXPORT _CGUL_AIMEMORYINFO GetMemoryRequirements() const;
            _CGUL_EXPORT void SetExtraVerbose(bool bDo);
        };
    }
}

#include "../External/Undefines.hpp"
