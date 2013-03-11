/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

 /** @file Defines.h
  *  @brief Sets up the build environment for header files.
  *  @details The goal of this file was to exclude system files which dump defines to the global
  *  namespace from applications which relied on Jatta.  An example of this is Window's CreateWindow
  *  function which is commonly defined as either CreateWindowA or CreateWindowW.  Since this same
  *  define does not exist on Linux or Mac it creates issues only present on Windows.  By excluding
  *  the inclusion of Windows.h in the final product, OS-specific defines are minimized.
  */

#include "Once.h"

#ifndef DOXYGEN

#ifdef WINDOWS
#   define _JATTA_HWND void*
#   define _JATTA_DWORD long
#   define _JATTA_PIXELFORMATDESCRIPTOR Jatta::_JATTA_PIXELFORMATDESCRIPTOR
#   define _JATTA_HDC int
#   define _JATTA_HGLRC int
#   define _JATTA_HGDIOBJ void*
#endif

#ifdef LINUX
#   define _JATTA_DISPLAY void*
#   define _JATTA_WINDOW void*
#   define _JATTA_GLXCONTEXT void*
#endif

#define _JATTA_FT_FACE void*
#define _JATTA_AISCENE void*
#define _JATTA_AIMESH void*
#define _JATTA_AITEXTURE void*
#define _JATTA_AIMATERIAL void*
#define _JATTA_AICAMERA void*
#define _JATTA_AIBONE void*
#define _JATTA_AIVERTEXWEIGHT void*
#define _JATTA_AIANIMATION void*
#define _JATTA_AIMESHANIM void*
#define _JATTA_AINODEANIM void*
#define _JATTA_AIFACE void*
#define _JATTA_AILIGHT void*
#define _JATTA_AINODE void*
#define _JATTA_AIUVTRANSFORM void*
#define _JATTA_AIMATERIALPROPERTY void*
#define _JATTA_AIBASEPROCESS void*
#define _JATTA_AIBASEIMPORTER void*
#define _JATTA_AIIOHANDLER void*
#define _JATTA_AIPROGRESHANDLER void*
#define _JATTA_AIIMPORTERDESC void*
#define _JATTA_AIMEMORYINFO void*
#define _JATTA_AIIMPORTER void*
#define _JATTA_AIEXPORTER void*
#define _JATTA_AIEXPORTFORMATDESC void*
#define _JATTA_AIEXPORTDATABLOB void*
#define _JATTA_AIEXPORTFORMATENTRY void*
#define _JATTA_PASTREAM void*
#define _JATTA_PASTREAM_CALLBACK_TIMEINFO void*
#define _JATTA_PASTREAM_CALLBACK_FLAGS unsigned long
#define _JATTA_PADEVICE_INFO void*
#define _JATTA_PAHOSTAPI_INFO void*
#define _JATTA_PASTREAM_INFO void*
#define _JATTA_PAHOSTERROR_INFO void*

#if defined(JATTA_INCLUDES)
#   ifdef _CPP_STATIC_ASSERT
#       define CHECK(x, y) static_assert(sizeof(x) == sizeof(y), "sizeof(" #x ") != sizeof(" #y ")");
#   else
#       define CHECK(x, y)
#   endif
#   ifdef WINDOWS
        CHECK(::HWND, _JATTA_HWND);
        CHECK(::DWORD, _JATTA_DWORD);
        CHECK(::PIXELFORMATDESCRIPTOR, _JATTA_PIXELFORMATDESCRIPTOR);
        CHECK(::HDC, _JATTA_HDC);
        CHECK(::HGLRC, _JATTA_HGLRC);
        CHECK(::HGDIOBJ, _JATTA_HGDIOBJ);
#   endif
#   ifdef LINUX
        CHECK(::Display*, _JATTA_DISPLAY);
        CHECK(::Window, _JATTA_WINDOW);
        CHECK(::GLXContext, _JATTA_GLXCONTEXT);
#   endif
#   ifdef JATTA_USE_ASSIMP
      CHECK(::FT_Face, _JATTA_FT_FACE);
      CHECK(::aiScene*, _JATTA_AISCENE);
      CHECK(::aiMesh*, _JATTA_AIMESH);
      CHECK(::aiTexture*, _JATTA_AITEXTURE);
      CHECK(::aiTexture*, _JATTA_AIMATERIAL);
#   endif
#   ifdef JATTA_USE_AUDIO
      CHECK(::PaStreamCallbackTimeInfo*, _JATTA_PASTREAM_CALLBACK_TIMEINFO);
      CHECK(::PaStreamCallbackFlags, _JATTA_PASTREAM_CALLBACK_FLAGS);
      CHECK(::PaDeviceInfo*, _JATTA_PADEVICE_INFO);
      CHECK(::PaHostApiInfo*, _JATTA_PAHOSTAPI_INFO);
#   endif
#   undef CHECK
#   include "Undefines.h"
#   ifdef WINDOWS
#       define _JATTA_HWND ::HWND
#       define _JATTA_DWORD ::DWORD
#       define _JATTA_PIXELFORMATDESCRIPTOR ::PIXELFORMATDESCRIPTOR
#       define _JATTA_HDC ::HDC
#       define _JATTA_HGLRC ::HGLRC
#       define _JATTA_HGDIOBJ ::HGDIOBJ
#    endif
#    ifdef LINUX
#       define _JATTA_DISPLAY ::Display*
#       define _JATTA_WINDOW ::Window
#       ifdef JATTA_USE_OPENGL
#           define _JATTA_GLXCONTEXT ::GLXContext
#       endif
#   endif
#   ifdef JATTA_USE_FREETYPE
#       define _JATTA_FT_FACE ::FT_Face
#   endif
#   ifdef JATTA_USE_ASSIMP
#       define _JATTA_AISCENE ::aiScene*
#       define _JATTA_AIMESH ::aiMesh*
#       define _JATTA_AITEXTURE ::aiTexture*
#       define _JATTA_AIMATERIAL ::aiMaterial*
#       define _JATTA_AICAMERA ::aiCamera*
#       define _JATTA_AIBONE ::aiBone*
#       define _JATTA_AIVERTEXWEIGHT ::aiVertexWeight*
#       define _JATTA_AIANIMATION ::aiAnimation*
#       define _JATTA_AIMESHANIM ::aiMeshAnim*
#       define _JATTA_AINODEANIM ::aiNodeAnim*
#       define _JATTA_AIFACE ::aiFace*
#       define _JATTA_AILIGHT ::aiLight*
#       define _JATTA_AINODE ::aiNode*
#       define _JATTA_AIUVTRANSFORM ::aiUVTransform*
#       define _JATTA_AIMATERIALPROPERTY ::aiMaterialProperty*
#       define _JATTA_AIBASEPROCESS ::Assimp::BaseProcess*
#       define _JATTA_AIBASEIMPORTER ::Assimp::BaseImporter*
#       define _JATTA_AIIOHANDLER ::Assimp::IOSystem*
#       define _JATTA_AIPROGRESHANDLER ::Assimp::ProgressHandler*
#       define _JATTA_AIIMPORTERDESC ::aiImporterDesc*
#       define _JATTA_AIMEMORYINFO ::aiMemoryInfo
#       define _JATTA_AIIMPORTER ::Assimp::Importer*
#       define _JATTA_AIEXPORTER ::Assimp::Exporter*
#       define _JATTA_AIEXPORTFORMATDESC ::aiExportFormatDesc*
#       define _JATTA_AIEXPORTDATABLOB ::aiExportDataBlob*
#       define _JATTA_AIEXPORTFORMATENTRY ::Assimp::Exporter::ExportFormatEntry
#   endif
#   ifdef JATTA_USE_AUDIO
#       define _JATTA_PASTREAM ::PaStream*
#       define _JATTA_PASTREAM_CALLBACK_TIMEINFO ::PaStreamCallbackTimeInfo*
#       define _JATTA_PASTREAM_CALLBACK_FLAGS ::PaStreamCallbackFlags
#       define _JATTA_PADEVICE_INFO ::PaDeviceInfo*
#       define _JATTA_PAHOSTAPI_INFO ::PaHostApiInfo*
#       define _JATTA_PASTREAM_INFO ::PaStreamInfo*
#       define _JATTA_PAHOSTERROR_INFO ::PaHostErrorInfo*
#   endif
#endif

#ifndef NULL
#   define NULL 0
#endif

#endif
