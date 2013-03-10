/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Exporter.h"
#include "Scene.h"

_JATTA_EXPORT Jatta::Assimp::ExportFormatDesc::ExportFormatDesc(const ::aiExportFormatDesc* desc)
{
    this->desc = desc;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportFormatDesc::GetID()
{
    return String(desc->id);
}
_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportFormatDesc::GetDescription()
{
    return String(desc->description);
}
_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportFormatDesc::GetFileExtension()
{
    return String(desc->fileExtension);
}
 
///////////////////////////////////////////////////////////////

_JATTA_EXPORT Jatta::Assimp::ExportBlob::ExportBlob(const ::aiExportDataBlob* blob)
{
    this->blob = blob;
    if (this->blob->next == NULL)
        next = NULL;
    else
        next = new ExportBlob(this->blob->next);
}

_JATTA_EXPORT void* Jatta::Assimp::ExportBlob::GetData()
{
    return (void*)blob->data;
}
_JATTA_EXPORT Jatta::String Jatta::Assimp::ExportBlob::GetName()
{
    return String(blob->name.C_Str());
}
_JATTA_EXPORT Jatta::Assimp::ExportBlob* Jatta::Assimp::ExportBlob::GetNext()
{
    return next;
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::ExportBlob::GetSize()
{
    return (UInt32)blob->size;
}
_JATTA_EXPORT void Jatta::Assimp::ExportBlob::Free()
{
    if (next != NULL)
    {
        next->Free();
        delete next;
        next = NULL;
    }
}

///////////////////////////////////////////////////////////////

_JATTA_EXPORT Jatta::Assimp::Exporter::Exporter()
{
      exporter = new ::Assimp::Exporter();
}
_JATTA_EXPORT Jatta::Assimp::Exporter::~Exporter()
{
      //delete exporter;
}

_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Exporter::Export(Scene* scene, String formatId, String path, UInt32 preprocessing)
{
    aiReturn ret = exporter->Export(scene->scene, formatId.GetData(), path.GetData(), preprocessing);
    blob = new ExportBlob(exporter->GetBlob());
    return (SInt32) ret;
}

_JATTA_EXPORT Jatta::Assimp::ExportBlob* Jatta::Assimp::Exporter::ExportToBlob(Scene* scene, String formatId, UInt32 preprocessing)
{
    blob = new ExportBlob(exporter->ExportToBlob(scene->scene, formatId.GetData(), preprocessing)); 
    return blob;
}
_JATTA_EXPORT void Jatta::Assimp::Exporter::FreeBlob()
{
    exporter->FreeBlob();
    blob->Free();
    delete blob;
    blob = NULL;
}
_JATTA_EXPORT Jatta::Assimp::ExportBlob* Jatta::Assimp::Exporter::GetBlob() const
{
    return blob;
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Exporter::GetErrorString() const
{
    return String(exporter->GetErrorString());
}
_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Exporter::GetExportFormatCount() const
{
    return (UInt32)exporter->GetExportFormatCount();
}
_JATTA_EXPORT Jatta::Assimp::ExportFormatDesc Jatta::Assimp::Exporter::GetExportFormatDescription(UInt32 index) const
{
    return ExportFormatDesc(exporter->GetExportFormatDescription(index));
}

_JATTA_EXPORT void Jatta::Assimp::Exporter::SetIOHandler(::Assimp::IOSystem* ioSystem) const
{
    exporter->SetIOHandler(ioSystem);
}
_JATTA_EXPORT ::Assimp::IOSystem* Jatta::Assimp::Exporter::GetIOHandler() const
{
    return exporter->GetIOHandler();
}
_JATTA_EXPORT bool Jatta::Assimp::Exporter::IsDefaultIOHandler() const
{
    return exporter->IsDefaultIOHandler();
}

_JATTA_EXPORT Jatta::SInt32 Jatta::Assimp::Exporter::RegisterExporter(::Assimp::Exporter::ExportFormatEntry &desc)
{
    aiReturn ret = exporter->RegisterExporter(desc);
    return (SInt32) ret;
}
_JATTA_EXPORT void Jatta::Assimp::Exporter::UnregisterExporter(String id)
{
    exporter->UnregisterExporter(id.GetCString());
}