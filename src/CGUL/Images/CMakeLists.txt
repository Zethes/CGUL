# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

if (PNG_FOUND)
    set(CGUL_SOURCES
        ${CGUL_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/PNG.cpp
    )

    set(CGUL_INSTALL
        ${CGUL_INSTALL}
        ${CMAKE_CURRENT_SOURCE_DIR}/PNG.hpp
    )
endif()

if (JPEG_FOUND)
    set(CGUL_SOURCES
        ${CGUL_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/JPEG.cpp
    )

    set(CGUL_INSTALL
        ${CGUL_INSTALL}
        ${CMAKE_CURRENT_SOURCE_DIR}/JPEG.hpp
    )
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Format.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Loader.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Color_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Colors.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Format.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Image.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ImageHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Loader.hpp
    PARENT_SCOPE
)
