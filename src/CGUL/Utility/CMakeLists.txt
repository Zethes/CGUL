# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/ConditionVariable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CRC32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DateTime.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/File.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileFinder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/JSON.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MD5.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mutex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Regex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/String.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Timezones.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Version.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/AutoRelease.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AutoRelease_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConditionVariable.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DateTime.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Encryption.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Endian.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Endian_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Event.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Event_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/File.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FileFinder.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/JSON.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Memory.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Memory_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Move.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Move_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Mutex.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Regex.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/String.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Thread.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Timer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Timezones.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Version.hpp
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
