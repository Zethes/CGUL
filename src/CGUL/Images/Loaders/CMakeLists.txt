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
        ${CMAKE_CURRENT_SOURCE_DIR}/PNG.h
    )
endif()

if (JPEG_FOUND)
    set(CGUL_SOURCES
        ${CGUL_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/JPEG.cpp
    )

set(CGUL_INSTALL
    ${CGUL_INSTALL}
        ${CMAKE_CURRENT_SOURCE_DIR}/JPEG.h
    )
endif()

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/BMP.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/BMP.h
    PARENT_SCOPE
)
