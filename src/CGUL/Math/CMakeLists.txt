# C++ General Utility Library (mailto:cgul@zethes.com)
# Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
# All rights reserved.

set(CGUL_SOURCES
    ${CGUL_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/Angle.cpp
    PARENT_SCOPE
)

set(CGUL_INSTALL
    ${CGUL_INSTALL}
    ${CMAKE_CURRENT_SOURCE_DIR}/Angle.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Math.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Math_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Random.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Random_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector2_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3_Implement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector4_Implement.hpp
    PARENT_SCOPE
)

set(CGUL_PROJECT_FILES
    ${CGUL_PROJECT_FILES}
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    PARENT_SCOPE
)
