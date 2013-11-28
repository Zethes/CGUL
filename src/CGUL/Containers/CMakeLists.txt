# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

set(Jatta_INSTALL
    ${Jatta_INSTALL}
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
