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
    ${CMAKE_CURRENT_SOURCE_DIR}/Device.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HostApi.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HostError.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InputStream.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OutputStream.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PortAudio.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Stream.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamData.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamInfo.hpp
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
