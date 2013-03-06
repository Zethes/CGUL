/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

/** @file Undefines.h
 *  @brief Cleans up defines used in Jatta header files.
 *  @details Each header file sets up some defines to make including them as clean as possible.
 *  This file is included at the end of each Jatta header file to remove left-over defines from this
 *  cleaning process.
 */

#ifdef WINDOWS
#   undef _JATTA_HWND
#   undef _JATTA_DWORD
#   undef _JATTA_PIXELFORMATDESCRIPTOR
#   undef _JATTA_HDC
#   undef _JATTA_HGLRC
#endif

#ifdef LINUX
#   undef _JATTA_DISPLAY
#   undef _JATTA_WINDOW
#   undef _JATTA_GLXCONTEXT
#endif

#ifdef JATTA_USE_FREETYPE
#   undef _JATTA_FT_FACE
#endif

#ifdef JATTA_USE_ASSIMP
#   undef _JATTA_AISCENE
#   undef _JATTA_AIMESH
#   undef _JATTA_AITEXTURE
#   undef _JATTA_AIMATERIAL
#   undef _JATTA_AICAMERA
#	undef _JATTA_AIBONE
#	undef _JATTA_AIVERTEXWEIGHT
#	undef _JATTA_AIANIMATION
#	undef _JATTA_AIMESHANIM
#	undef _JATTA_AINODEANIM
#	undef _JATTA_AIFACE
#endif

#ifdef JATTA_USE_AUDIO
#   undef _JATTA_PASTREAM
#   undef _JATTA_PASTREAM_CALLBACK_TIMEINFO
#   undef _JATTA_PASTREAM_CALLBACK_FLAGS
#   undef _JATTA_PADEVICE_INFO
#   undef _JATTA_PAHOSTAPI_INFO
#endif

#ifdef _JATTA_OBJC
#   undef _JATTA_OBJC
#endif