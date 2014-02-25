// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Defines.hpp
 *  @brief Sets up the build environment for header files.
 *  @details The goal of this file was to exclude system files which dump defines to the global
 *  namespace from applications which relied on CGUL.  An example of this is Window's CreateWindow
 *  function which is commonly defined as either CreateWindowA or CreateWindowW.  Since this same
 *  define does not exist on Linux or Mac it creates issues only present on Windows.  By excluding
 *  the inclusion of Windows.h in the final product, OS-specific defines are minimized.
 */

#include "Once.hpp"

#ifndef DOXYGEN

#ifdef CGUL_WINDOWS
#   define _CGUL_HWND void*
#   define _CGUL_HANDLE void*
#   define _CGUL_CRITICAL_SECTION CGUL::_CGUL_CRITICAL_SECTION
#   define _CGUL_DWORD long
#   define _CGUL_PIXELFORMATDESCRIPTOR CGUL::_CGUL_PIXELFORMATDESCRIPTOR
#   define _CGUL_HDC int
#   define _CGUL_HGLRC int
#   define _CGUL_HGDIOBJ void*
#endif

#ifdef CGUL_LINUX
#   define _CGUL_DISPLAY void*
#   define _CGUL_WINDOW void*
#   define _CGUL_GLXCONTEXT void*
#endif

#ifdef FreeType_FOUND
#   define _CGUL_FT_FACE void*
#endif

#ifdef Assimp_FOUND
#   define _CGUL_AISCENE void*
#   define _CGUL_AIMESH void*
#   define _CGUL_AITEXTURE void*
#   define _CGUL_AIMATERIAL void*
#   define _CGUL_AICAMERA void*
#   define _CGUL_AIBONE void*
#   define _CGUL_AIVERTEXWEIGHT void*
#   define _CGUL_AIANIMATION void*
#   define _CGUL_AIMESHANIM void*
#   define _CGUL_AINODEANIM void*
#   define _CGUL_AIFACE void*
#   define _CGUL_AILIGHT void*
#   define _CGUL_AINODE void*
#   define _CGUL_AIUVTRANSFORM void*
#   define _CGUL_AIMATERIALPROPERTY void*
#   define _CGUL_AIBASEPROCESS void*
#   define _CGUL_AIBASEIMPORTER void*
#   define _CGUL_AIIOHANDLER void*
#   define _CGUL_AIPROGRESHANDLER void*
#   define _CGUL_AIIMPORTERDESC void*
#   define _CGUL_AIMEMORYINFO void*
#   define _CGUL_AIIMPORTER void*
#   define _CGUL_AIEXPORTER void*
#   define _CGUL_AIEXPORTFORMATDESC void*
#   define _CGUL_AIEXPORTDATABLOB void*
#   define _CGUL_AIEXPORTFORMATENTRY void*
#endif

#ifdef PortAudio_FOUND
#   define _CGUL_PASTREAM void*
#   define _CGUL_PASTREAM_CALLBACK_TIMEINFO void*
#   define _CGUL_PASTREAM_CALLBACK_FLAGS unsigned long
#   define _CGUL_PADEVICE_INFO void*
#   define _CGUL_PAHOSTAPI_INFO void*
#   define _CGUL_PASTREAM_INFO void*
#   define _CGUL_PAHOSTERROR_INFO void*
#endif

#ifdef PCRE_FOUND
#   define _CGUL_PCRE void*
#   define _CGUL_PCRE_EXTRA void*
#endif

#ifdef OpenSSL_FOUND
#   define _CGUL_SSL void*
#   define _CGUL_SSL_CTX void*
#   define _CGUL_SSL_BIO void*
#endif

#ifdef pthread_FOUND
#   define _CGUL_PTHREAD_T void*
#   define _CGUL_PTHREAD_MUTEX_T CGUL::_CGUL_PTHREAD_MUTEX_T
#   define _CGUL_PTHREAD_COND_T CGUL::_CGUL_PTHREAD_COND_T
#endif

#if defined(CGUL_INCLUDES)
#   ifdef CPP_HAS_STATIC_ASSERT
#       define CHECK(x, y) static_assert(sizeof(x) == sizeof(y), "sizeof(" #x ") != sizeof(" #y ")");
#   else
#       define CHECK(x, y)
#   endif
#   ifdef CGUL_WINDOWS
CHECK(::HWND, _CGUL_HWND)
CHECK(::HANDLE, _CGUL_HANDLE)
CHECK(::CRITICAL_SECTION, _CGUL_CRITICAL_SECTION)
CHECK(::DWORD, _CGUL_DWORD)
CHECK(::PIXELFORMATDESCRIPTOR, _CGUL_PIXELFORMATDESCRIPTOR)
CHECK(::HDC, _CGUL_HDC)
CHECK(::HGLRC, _CGUL_HGLRC)
CHECK(::HGDIOBJ, _CGUL_HGDIOBJ)
#   endif
#   ifdef CGUL_LINUX
CHECK(::Display*, _CGUL_DISPLAY)
CHECK(::Window, _CGUL_WINDOW)
CHECK(::GLXContext, _CGUL_GLXCONTEXT)
#   endif
#   ifdef Assimp_FOUND
CHECK(::FT_Face, _CGUL_FT_FACE)
CHECK(::aiScene*, _CGUL_AISCENE)
CHECK(::aiMesh*, _CGUL_AIMESH)
CHECK(::aiTexture*, _CGUL_AITEXTURE)
CHECK(::aiTexture*, _CGUL_AIMATERIAL)
#   endif
#   ifdef PortAudio_FOUND
CHECK(::PaStreamCallbackTimeInfo*, _CGUL_PASTREAM_CALLBACK_TIMEINFO)
CHECK(::PaStreamCallbackFlags, _CGUL_PASTREAM_CALLBACK_FLAGS)
CHECK(::PaDeviceInfo*, _CGUL_PADEVICE_INFO)
CHECK(::PaHostApiInfo*, _CGUL_PAHOSTAPI_INFO)
#   endif
#   ifdef PCRE_FOUND
CHECK(::pcre*, _CGUL_PCRE)
CHECK(::pcre_extra*, _CGUL_PCRE_EXTRA)
#   endif
#   ifdef pthread_FOUND
CHECK(::pthread_t, _CGUL_PTHREAD_T)
CHECK(::pthread_mutex_t, _CGUL_PTHREAD_MUTEX_T)
CHECK(::pthread_cond_t, _CGUL_PTHREAD_COND_T)
#   endif
#   undef CHECK
#   include "Undefines.hpp"
#   ifdef CGUL_WINDOWS
#       define _CGUL_HWND ::HWND
#       define _CGUL_HANDLE ::HANDLE
#       define _CGUL_CRITICAL_SECTION ::CRITICAL_SECTION
#       define _CGUL_DWORD ::DWORD
#       define _CGUL_PIXELFORMATDESCRIPTOR ::PIXELFORMATDESCRIPTOR
#       define _CGUL_HDC ::HDC
#       define _CGUL_HGLRC ::HGLRC
#       define _CGUL_HGDIOBJ ::HGDIOBJ
#    endif
#    ifdef CGUL_LINUX
#       define _CGUL_DISPLAY ::Display*
#       define _CGUL_WINDOW ::Window
#       ifdef CGUL_USE_OPENGL
#           define _CGUL_GLXCONTEXT ::GLXContext
#       endif
#   endif
#   ifdef FreeType_FOUND
#       define _CGUL_FT_FACE ::FT_Face
#   endif
#   ifdef Assimp_FOUND
#       define _CGUL_AISCENE ::aiScene*
#       define _CGUL_AIMESH ::aiMesh*
#       define _CGUL_AITEXTURE ::aiTexture*
#       define _CGUL_AIMATERIAL ::aiMaterial*
#       define _CGUL_AICAMERA ::aiCamera*
#       define _CGUL_AIBONE ::aiBone*
#       define _CGUL_AIVERTEXWEIGHT ::aiVertexWeight*
#       define _CGUL_AIANIMATION ::aiAnimation*
#       define _CGUL_AIMESHANIM ::aiMeshAnim*
#       define _CGUL_AINODEANIM ::aiNodeAnim*
#       define _CGUL_AIFACE ::aiFace*
#       define _CGUL_AILIGHT ::aiLight*
#       define _CGUL_AINODE ::aiNode*
#       define _CGUL_AIUVTRANSFORM ::aiUVTransform*
#       define _CGUL_AIMATERIALPROPERTY ::aiMaterialProperty*
#       define _CGUL_AIBASEPROCESS ::Assimp::BaseProcess*
#       define _CGUL_AIBASEIMPORTER ::Assimp::BaseImporter*
#       define _CGUL_AIIOHANDLER ::Assimp::IOSystem*
#       define _CGUL_AIPROGRESHANDLER ::Assimp::ProgressHandler*
#       define _CGUL_AIIMPORTERDESC ::aiImporterDesc*
#       define _CGUL_AIMEMORYINFO ::aiMemoryInfo
#       define _CGUL_AIIMPORTER ::Assimp::Importer*
#       define _CGUL_AIEXPORTER ::Assimp::Exporter*
#       define _CGUL_AIEXPORTFORMATDESC ::aiExportFormatDesc*
#       define _CGUL_AIEXPORTDATABLOB ::aiExportDataBlob*
#       define _CGUL_AIEXPORTFORMATENTRY ::Assimp::Exporter::ExportFormatEntry
#   endif
#   ifdef PortAudio_FOUND
#       define _CGUL_PASTREAM ::PaStream*
#       define _CGUL_PASTREAM_CALLBACK_TIMEINFO ::PaStreamCallbackTimeInfo*
#       define _CGUL_PASTREAM_CALLBACK_FLAGS ::PaStreamCallbackFlags
#       define _CGUL_PADEVICE_INFO ::PaDeviceInfo*
#       define _CGUL_PAHOSTAPI_INFO ::PaHostApiInfo*
#       define _CGUL_PASTREAM_INFO ::PaStreamInfo*
#       define _CGUL_PAHOSTERROR_INFO ::PaHostErrorInfo*
#   endif
#   ifdef PCRE_FOUND
#       define _CGUL_PCRE ::pcre*
#       define _CGUL_PCRE_EXTRA ::pcre_extra*
#   endif
#   ifdef OpenSSL_FOUND
#       define _CGUL_SSL ::SSL*
#       define _CGUL_SSL_CTX ::SSL_CTX*
#       define _CGUL_SSL_BIO ::BIO*
#   endif
#   ifdef pthread_FOUND
#       define _CGUL_PTHREAD_T ::pthread_t
#       define _CGUL_PTHREAD_MUTEX_T ::pthread_mutex_t
#       define _CGUL_PTHREAD_COND_T ::pthread_cond_t
#   endif
#endif

#ifndef NULL
#   define NULL 0
#endif

#ifdef CGUL_BUILD
#   ifdef CGUL_SAFE
#       define GLCLEAR() { glGetError(); }
#   else
#       define GLCLEAR()
#   endif
#   ifdef CGUL_CAUTIOUS
#       define GLCHECK(str, command) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error("OpenGL (" #command "): " str); }
#   else
#       define GLCHECK(str, command)
#   endif
#   ifdef CGUL_SAFE
#       define GLVERIFY(command) if ((void*)command == 0) { throw std::runtime_error("OpenGL command " #command " is not available."); }
#   else
#       define GLVERIFY(command)
#   endif
#endif

#endif
