# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Array.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Array_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Container.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FixedList.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HashMap.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/HashMap_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/List.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector_Implement.hpp
    PARENT_SCOPE
)
