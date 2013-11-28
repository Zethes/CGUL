// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Exporter.cpp
 */

#include "Exporter.hpp"
#include "Scene.hpp"
#include "ExportFormatDesc.hpp"
#include "ExportBlob.hpp"

_CGUL_EXPORT CGUL::Assimp::Exporter::Exporter(const Exporter& exporter)
{
    // private
}

_CGUL_EXPORT CGUL::Assimp::Exporter::Exporter()
{
    exporter = new ::Assimp::Exporter();
    blob = NULL;
}

_CGUL_EXPORT CGUL::Assimp::Exporter::~Exporter()
{
    // TODO: why is this commented out?
    // delete exporter;
    // TODO: delete blob?
}

_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Exporter::Export(Scene* scene, String formatId, String path, UInt32 preprocessing)
{
    aiReturn ret = exporter->Export(scene->scene, formatId.GetData(), path.GetData(), preprocessing);
    blob = new ExportBlob(exporter->GetBlob());
    return (SInt32)ret;
}

_CGUL_EXPORT CGUL::Assimp::ExportBlob* CGUL::Assimp::Exporter::ExportToBlob(Scene* scene, String formatId, UInt32 preprocessing)
{
    delete blob;
    blob = new ExportBlob(exporter->ExportToBlob(scene->scene, formatId.GetData(), preprocessing));
    return blob;
}

_CGUL_EXPORT void CGUL::Assimp::Exporter::FreeBlob()
{
    exporter->FreeBlob();
    blob->Free();
    delete blob;
    blob = NULL;
}

_CGUL_EXPORT CGUL::Assimp::ExportBlob* CGUL::Assimp::Exporter::GetBlob() const
{
    return blob;
}

_CGUL_EXPORT CGUL::String CGUL::Assimp::Exporter::GetErrorString() const
{
    return String(exporter->GetErrorString());
}

_CGUL_EXPORT CGUL::UInt32 CGUL::Assimp::Exporter::GetExportFormatCount() const
{
    return (UInt32)exporter->GetExportFormatCount();
}

_CGUL_EXPORT CGUL::Assimp::ExportFormatDesc CGUL::Assimp::Exporter::GetExportFormatDescription(UInt32 index) const
{
    return ExportFormatDesc(exporter->GetExportFormatDescription(index));
}

_CGUL_EXPORT void CGUL::Assimp::Exporter::SetIOHandler(::Assimp::IOSystem* ioSystem) const
{
    exporter->SetIOHandler(ioSystem);
}

_CGUL_EXPORT ::Assimp::IOSystem* CGUL::Assimp::Exporter::GetIOHandler() const
{
    return exporter->GetIOHandler();
}

_CGUL_EXPORT bool CGUL::Assimp::Exporter::IsDefaultIOHandler() const
{
    return exporter->IsDefaultIOHandler();
}

_CGUL_EXPORT CGUL::SInt32 CGUL::Assimp::Exporter::RegisterExporter(::Assimp::Exporter::ExportFormatEntry &desc)
{
    aiReturn ret = exporter->RegisterExporter(desc);
    return (SInt32)ret;
}

_CGUL_EXPORT void CGUL::Assimp::Exporter::UnregisterExporter(String id)
{
    exporter->UnregisterExporter(id.GetCString());
}
