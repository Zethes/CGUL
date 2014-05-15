// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Undefines.hpp
 *  @brief Cleans up defines used in CGUL header files.
 *  @details Each header file sets up some defines to make including them as clean as possible.
 *  This file is included at the end of each CGUL header file to remove left-over defines from this
 *  cleaning process.
 */

#ifdef CGUL_WINDOWS
#   undef _CGUL_HWND
#   undef _CGUL_HANDLE
#   undef _CGUL_CRITICAL_SECTION
#   undef _CGUL_CONDITION_VARIABLE
#   undef _CGUL_DWORD
#   undef _CGUL_PIXELFORMATDESCRIPTOR
#   undef _CGUL_HDC
#   undef _CGUL_HGLRC
#   undef _CGUL_HGDIOBJ
#endif

#ifdef CGUL_LINUX
#   undef _CGUL_DISPLAY
#   undef _CGUL_WINDOW
#   undef _CGUL_GLXCONTEXT
#endif

#ifdef FreeType_FOUND
#   undef _CGUL_FT_FACE
#   undef _CGUL_FT_GLYPH
#endif

#ifdef Assimp_FOUND
#   undef _CGUL_AISCENE
#   undef _CGUL_AIMESH
#   undef _CGUL_AITEXTURE
#   undef _CGUL_AIMATERIAL
#   undef _CGUL_AICAMERA
#   undef _CGUL_AIBONE
#   undef _CGUL_AIVERTEXWEIGHT
#   undef _CGUL_AIANIMATION
#   undef _CGUL_AIMESHANIM
#   undef _CGUL_AINODEANIM
#   undef _CGUL_AIFACE
#   undef _CGUL_AILIGHT
#   undef _CGUL_AINODE
#   undef _CGUL_AIUVTRANSFORM
#   undef _CGUL_AIMATERIALPROPERTY
#   undef _CGUL_AIBASEPROCESS
#   undef _CGUL_AIBASEIMPORTER
#   undef _CGUL_AIIOHANDLER
#   undef _CGUL_AIPROGRESHANDLER
#   undef _CGUL_AIIMPORTERDESC
#   undef _CGUL_AIMEMORYINFO
#   undef _CGUL_AIIMPORTER
#   undef _CGUL_AIEXPORTER
#   undef _CGUL_AIEXPORTFORMATDESC
#   undef _CGUL_AIEXPORTDATABLOB
#   undef _CGUL_AIEXPORTFORMATENTRY
#endif

#ifdef PortAudio_FOUND
#   undef _CGUL_PASTREAM
#   undef _CGUL_PASTREAM_CALLBACK_TIMEINFO
#   undef _CGUL_PASTREAM_CALLBACK_FLAGS
#   undef _CGUL_PADEVICE_INFO
#   undef _CGUL_PAHOSTAPI_INFO
#   undef _CGUL_PASTREAM_INFO
#   undef _CGUL_PAHOSTERROR_INFO
#endif

#ifdef PCRE_FOUND
#   undef _CGUL_PCRE
#   undef _CGUL_PCRE_EXTRA
#endif

#ifdef OpenSSL_FOUND
#   undef _CGUL_SSL
#   undef _CGUL_SSL_CTX
#   undef _CGUL_SSL_BIO
#endif

#ifdef Crypto_FOUND
#   undef _CGUL_BIGNUM 
#   undef _CGUL_SHA_CTX
#   undef _CGUL_HMAC_CTX
#   undef _CGUL_MD2_CTX
#   undef _CGUL_MD4_CTX
#   undef _CGUL_MD5_CTX
#   undef _CGUL_RIPEMD_CTX
#endif

#ifdef pthread_FOUND
#   undef _CGUL_PTHREAD_T
#   undef _CGUL_PTHREAD_MUTEX_T
#   undef _CGUL_PTHREAD_COND_T
#endif

#ifdef _CGUL_OBJC
#   undef _CGUL_OBJC
#endif
