# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Array.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Array_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Container.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FixedList.h
    ${CMAKE_CURRENT_SOURCE_DIR}/HashMap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/HashMap_Implement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/List.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector_Implement.h
    PARENT_SCOPE
)
