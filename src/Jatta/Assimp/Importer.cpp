/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Importer.h"
#include "Scene.h"

_JATTA_EXPORT Jatta::Assimp::Importer::Importer(const Importer& copy)
{
    // private
}

_JATTA_EXPORT Jatta::Assimp::Importer::Importer() :
    importer(new ::Assimp::Importer()),
    scene(NULL)
{
}

_JATTA_EXPORT Jatta::Assimp::Importer::~Importer()
{
    // TODO: why is this commented out?
    //delete importer;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Importer::RegisterLoader(::Assimp::BaseImporter* import)
{
    aiReturn ret = importer->RegisterLoader(import);
    return (SInt32)ret;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Importer::UnregisterLoader(::Assimp::BaseImporter* import)
{
    aiReturn ret = importer->UnregisterLoader(import);
    return (SInt32)ret;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Importer::RegisterPPStep(::Assimp::BaseProcess* import)
{
    aiReturn ret = importer->RegisterPPStep(import);
    return (SInt32)ret;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Importer::UnregisterPPStep(::Assimp::BaseProcess* import)
{
    aiReturn ret = importer->UnregisterPPStep(import);
    return (SInt32)ret;
}

_JATTA_EXPORT void Jatta::Assimp::Importer::SetProperty(String name, SInt32 value, bool* existing)
{
    importer->SetPropertyInteger(name.GetCString(), value, existing);
}

_JATTA_EXPORT void Jatta::Assimp::Importer::SetProperty(String name, bool value, bool* existing)
{
    importer->SetPropertyBool(name.GetCString(), value, existing);
}

_JATTA_EXPORT void Jatta::Assimp::Importer::SetProperty(String name, Float32 value, bool* existing)
{
    importer->SetPropertyFloat(name.GetCString(), value, existing);
}

_JATTA_EXPORT void Jatta::Assimp::Importer::SetProperty(String name, String value, bool* existing)
{
    importer->SetPropertyString(name.GetCString(), value.GetData(), existing);
}

_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Importer::GetPropertyInteger(String name, SInt32 errorReturn) const
{
    return (SInt32)importer->GetPropertyInteger(name.GetCString(), errorReturn);
}

_JATTA_EXPORT bool Jatta::Assimp::Importer::GetPropertyBool(String name, bool errorReturn) const
{
    return importer->GetPropertyBool(name.GetCString(), errorReturn);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Assimp::Importer::GetPropertyFloat(String name, Float32 errorReturn) const
{
    return (Float32)importer->GetPropertyFloat(name.GetCString(), errorReturn);
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Importer::GetPropertyString(String name, String errorReturn) const
{
    return String(importer->GetPropertyString(name.GetCString(), errorReturn.GetData()));
}

_JATTA_EXPORT void Jatta::Assimp::Importer::SetIOHandler(::Assimp::IOSystem* pIOHandler)
{
    importer->SetIOHandler(pIOHandler);
}

_JATTA_EXPORT ::Assimp::IOSystem* Jatta::Assimp::Importer::GetIOHandler() const
{
    return importer->GetIOHandler();
}

_JATTA_EXPORT bool Jatta::Assimp::Importer::IsDefaultIOHandler() const
{
    return importer->IsDefaultIOHandler();
}

_JATTA_EXPORT void Jatta::Assimp::Importer::SetProgressHandler(::Assimp::ProgressHandler* handler)
{
    importer->SetProgressHandler(handler);
}

_JATTA_EXPORT ::Assimp::ProgressHandler* Jatta::Assimp::Importer::GetProgressHandler() const
{
    return importer->GetProgressHandler();
}

_JATTA_EXPORT bool Jatta::Assimp::Importer::IsDefaultProgressHandler() const
{
    return importer->IsDefaultProgressHandler();
}

_JATTA_EXPORT bool Jatta::Assimp::Importer::ValidateFlags(Enum flags) const
{
    return importer->ValidateFlags(flags);
}

_JATTA_EXPORT const Jatta::Assimp::Scene* Jatta::Assimp::Importer::ReadFile(const String& fileName, Enum flags)
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

_JATTA_EXPORT const Jatta::Assimp::Scene* Jatta::Assimp::Importer::ReadFileFromMemory(const void* buffer, UInt32 length, Enum flags, const char* hint)
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

_JATTA_EXPORT const Jatta::Assimp::Scene* Jatta::Assimp::Importer::ApplyPostProcessing(Enum flags)
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

_JATTA_EXPORT void Jatta::Assimp::Importer::FreeScene()
{
    importer->FreeScene();
    scene->scene = NULL;
    delete scene;
    scene = NULL;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Importer::GetErrorString() const
{
    return String(importer->GetErrorString());
}

_JATTA_EXPORT const Jatta::Assimp::Scene* Jatta::Assimp::Importer::GetScene() const
{
    return scene;
}

_JATTA_EXPORT bool Jatta::Assimp::Importer::IsExtensionSupported(String ext) const
{
    return importer->IsExtensionSupported(ext.GetData());
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Importer::GetExtensionList() const
{
    aiString ret;
    importer->GetExtensionList(ret);

    return String(ret.data);
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Importer::GetImporterCount() const
{
    return (UInt32)importer->GetImporterCount();
}

_JATTA_EXPORT const ::aiImporterDesc* Jatta::Assimp::Importer::GetImporterInfo(UInt32 index) const
{
    return importer->GetImporterInfo(index);
}

_JATTA_EXPORT ::Assimp::BaseImporter* Jatta::Assimp::Importer::GetImporter(UInt32 index) const
{
    return importer->GetImporter(index);
}

_JATTA_EXPORT ::Assimp::BaseImporter* Jatta::Assimp::Importer::GetImporter(String extension) const
{
    return importer->GetImporter(extension.GetCString());
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Importer::GetImporterIndex(String extension) const
{
    return importer->GetImporterIndex(extension.GetCString());
}

_JATTA_EXPORT ::aiMemoryInfo Jatta::Assimp::Importer::GetMemoryRequirements() const
{
    ::aiMemoryInfo ret;
    importer->GetMemoryRequirements(ret);
    return ret;
}

_JATTA_EXPORT void Jatta::Assimp::Importer::SetExtraVerbose(bool bDo)
{
    importer->SetExtraVerbose(bDo);
}
