# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

if (Crypto_FOUND)
    set(CGUL_SOURCES
        ${CGUL_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/HMAC.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MD2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MD4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MD5.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RIPEMD.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SHA.cpp
    )

    set(CGUL_INSTALL
        ${CGUL_INSTALL}
        ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/HMAC.hpp        
        ${CMAKE_CURRENT_SOURCE_DIR}/MD2.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MD4.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MD5.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RIPEMD.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SHA.hpp
    )
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
