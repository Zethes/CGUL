# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT PortAudio_FOUND)
    return()
endif()

set(Jatta_SOURCES
    ${Jatta_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Device.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HostApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HostError.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InputStream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PortAudio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SawWave.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SineWave.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Stream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamInfo.cpp
    PARENT_SCOPE
)

set(Jatta_INSTALL
    ${Jatta_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Device.h
    ${CMAKE_CURRENT_SOURCE_DIR}/HostApi.h
    ${CMAKE_CURRENT_SOURCE_DIR}/HostError.h
    ${CMAKE_CURRENT_SOURCE_DIR}/InputStream.h
    ${CMAKE_CURRENT_SOURCE_DIR}/PortAudio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SawWave.h
    ${CMAKE_CURRENT_SOURCE_DIR}/SineWave.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Stream.h
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamData.h
    ${CMAKE_CURRENT_SOURCE_DIR}/StreamInfo.h
    PARENT_SCOPE
)
