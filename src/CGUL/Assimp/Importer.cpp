// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Importer.cpp
 */

#include "Importer.hpp"
#include "Scene.hpp"

_CGUL_EXPORT CGUL::Assimp::Importer::Importer(const Importer& copy)
{
    // private
}

_CGUL_EXPORT CGUL::Assimp::Importer::Importer() :
    importer(new ::Assimp::Importer()),
    scene(NULL)
{
}

_CGUL_EXPORT CGUL::Assimp::Importer::~Importer()
{
    // TODO: why is this commented out?
    //delete importer;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Importer::RegisterLoader(::Assimp::BaseImporter* import)
{
    aiReturn ret = importer->RegisterLoader(import);
    return (SInt32)ret;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Importer::UnregisterLoader(::Assimp::BaseImporter* import)
{
    aiReturn ret = importer->UnregisterLoader(import);
    return (SInt32)ret;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Importer::RegisterPPStep(::Assimp::BaseProcess* import)
{
    aiReturn ret = importer->RegisterPPStep(import);
    return (SInt32)ret;
}

_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Importer::UnregisterPPStep(::Assimp::BaseProcess* import)
{
    aiReturn ret = importer->UnregisterPPStep(import);
    return (SInt32)ret;
}

_CGUL_EXPORT void CGUL::Assimp::Importer::SetProperty(String name, SInt32 value, bool* existing)
{
    importer->SetPropertyInteger(name.GetCString(), value, existing);
}

_CGUL_EXPORT void CGUL::Assimp::Importer::SetProperty(String name, bool value, bool* existing)
{
    importer->SetPropertyBool(name.GetCString(), value, existing);
}

_CGUL_EXPORT void CGUL::Assimp::Importer::SetProperty(String name, Float32 value, bool* existing)
{
    importer->SetPropertyFloat(name.GetCString(), value, existing);
}

_CGUL_EXPORT void CGUL::Assimp::Importer::SetProperty(String name, String value, bool* existing)
{
    importer->SetPropertyString(name.GetCString(), value.GetData(), existing);
}

_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Importer::GetPropertyInteger(String name, SInt32 errorReturn) const
{
    return (SInt32)importer->GetPropertyInteger(name.GetCString(), errorReturn);
}

_CGUL_EXPORT bool CGUL::Assimp::Importer::GetPropertyBool(String name, bool errorReturn) const
{
    return importer->GetPropertyBool(name.GetCString(), errorReturn);
}

_CGUL_EXPORT CGUL::Float32 CGUL::Assimp::Importer::GetPropertyFloat(String name, Float32 errorReturn) const
{
    return (Float32)importer->GetPropertyFloat(name.GetCString(), errorReturn);
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Importer::GetPropertyString(String name, String errorReturn) const
{
    return String(importer->GetPropertyString(name.GetCString(), errorReturn.GetData()));
}

_CGUL_EXPORT void CGUL::Assimp::Importer::SetIOHandler(::Assimp::IOSystem* pIOHandler)
{
    importer->SetIOHandler(pIOHandler);
}

_CGUL_EXPORT ::Assimp::IOSystem* CGUL::Assimp::Importer::GetIOHandler() const
{
    return importer->GetIOHandler();
}

_CGUL_EXPORT bool CGUL::Assimp::Importer::IsDefaultIOHandler() const
{
    return importer->IsDefaultIOHandler();
}

_CGUL_EXPORT void CGUL::Assimp::Importer::SetProgressHandler(::Assimp::ProgressHandler* handler)
{
    importer->SetProgressHandler(handler);
}

_CGUL_EXPORT ::Assimp::ProgressHandler* CGUL::Assimp::Importer::GetProgressHandler() const
{
    return importer->GetProgressHandler();
}

_CGUL_EXPORT bool CGUL::Assimp::Importer::IsDefaultProgressHandler() const
{
    return importer->IsDefaultProgressHandler();
}

_CGUL_EXPORT bool CGUL::Assimp::Importer::ValidateFlags(Enum flags) const
{
    return importer->ValidateFlags(flags);
}

_CGUL_EXPORT const CGUL::Assimp::Scene* CGUL::Assimp::Importer::ReadFile(const String& fileName, Enum flags)
{
    const aiScene* ret = importer->ReadFile(fileName.GetData(), flags);
    if (ret == NULL)
    {
        return NULL;
    }

    if (scene == NULL)
    {
        scene = new Scene(ret);
    }
    else
    {
        scene->scene = ret;
    }
    return scene;
}

_CGUL_EXPORT const CGUL::Assimp::Scene* CGUL::Assimp::Importer::ReadFileFromMemory(const void* buffer, UInt32 length, Enum flags, const char* hint)
{
    const aiScene* ret = importer->ReadFileFromMemory(buffer, length, flags, hint);
    if (ret == NULL)
    {
        return NULL;
    }

    if (scene == NULL)
    {
        scene = new Scene(ret);
    }
    else
    {
        scene->scene = ret;
    }
    return scene;
}

_CGUL_EXPORT const CGUL::Assimp::Scene* CGUL::Assimp::Importer::ApplyPostProcessing(Enum flags)
{
    const aiScene* ret = importer->ApplyPostProcessing(flags);
    if (ret == NULL)
    {
        return NULL;
    }

    if (scene == NULL)
    {
        scene = new Scene(ret);
    }
    else
    {
        scene->scene = ret;
    }
    return scene;
}

_CGUL_EXPORT void CGUL::Assimp::Importer::FreeScene()
{
    importer->FreeScene();
    scene->scene = NULL;
    delete scene;
    scene = NULL;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Importer::GetErrorString() const
{
    return String(importer->GetErrorString());
}

_CGUL_EXPORT const CGUL::Assimp::Scene* CGUL::Assimp::Importer::GetScene() const
{
    return scene;
}

_CGUL_EXPORT bool CGUL::Assimp::Importer::IsExtensionSupported(String ext) const
{
    return importer->IsExtensionSupported(ext.GetData());
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Importer::GetExtensionList() const
{
    aiString ret;
    importer->GetExtensionList(ret);

    return String(ret.data);
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Importer::GetImporterCount() const
{
    return (UInt32)importer->GetImporterCount();
}

_CGUL_EXPORT const ::aiImporterDesc* CGUL::Assimp::Importer::GetImporterInfo(UInt32 index) const
{
    return importer->GetImporterInfo(index);
}

_CGUL_EXPORT ::Assimp::BaseImporter* CGUL::Assimp::Importer::GetImporter(UInt32 index) const
{
    return importer->GetImporter(index);
}

_CGUL_EXPORT ::Assimp::BaseImporter* CGUL::Assimp::Importer::GetImporter(String extension) const
{
    return importer->GetImporter(extension.GetCString());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Importer::GetImporterIndex(String extension) const
{
    return importer->GetImporterIndex(extension.GetCString());
}

_CGUL_EXPORT ::aiMemoryInfo CGUL::Assimp::Importer::GetMemoryRequirements() const
{
    ::aiMemoryInfo ret;
    importer->GetMemoryRequirements(ret);
    return ret;
}

_CGUL_EXPORT void CGUL::Assimp::Importer::SetExtraVerbose(bool bDo)
{
    importer->SetExtraVerbose(bDo);
}
