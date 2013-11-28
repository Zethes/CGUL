# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT PortAudio_FOUND)
    return()
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Device.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HostApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HostError.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InputStream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OutputStream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PortAudio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Stream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamInfo.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Device.h
    ${CMAKE_CURRENT_SOURCE_DIR}/HostApi.h
    ${CMAKE_CURRENT_SOURCE_DIR}/HostError.h
    ${CMAKE_CURRENT_SOURCE_DIR}/InputStream.h
    ${CMAKE_CURRENT_SOURCE_DIR}/OutputStream.h
    ${CMAKE_CURRENT_SOURCE_DIR}/PortAudio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Stream.h
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamData.h
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamInfo.h
    PARENT_SCOPE
)
