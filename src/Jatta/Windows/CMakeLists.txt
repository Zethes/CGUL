# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

IF(APPLE)
    ADD_SUBDIRECTORY(MacOS)
ENDIF()

ADD_GROUP("Windows")
ADD_OTHER(CMakeLists.txt)
ADD_SOURCE(Input.cpp)
ADD_HEADER(Input.h include/Jatta/Windows/)
ADD_HEADER(Inputs.h include/Jatta/Windows/)
ADD_SOURCE(InputState.cpp)
ADD_HEADER(InputState.h include/Jatta/Windows/)
ADD_SOURCE(Window.cpp)
ADD_HEADER(Window.h include/Jatta/Windows/)
ADD_SOURCE(WindowStyle.cpp)
ADD_HEADER(WindowStyle.h include/Jatta/Windows/)