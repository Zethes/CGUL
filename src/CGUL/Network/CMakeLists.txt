# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT CGUL_USE_NETWORK)
    return()
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Adapter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DNS.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HTTPRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/IPAddress.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Network.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SocketTCP.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SocketUDP.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Adapter.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DNS.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HTTPEnums.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HTTPRequest.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/IPAddress.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SocketTCP.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SocketUDP.hpp
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
