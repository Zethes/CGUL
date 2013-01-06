# Jatta - General Utility Library
# Copyright (c) 2012-2013, Joshua Brookover
# All rights reserved.

if(NOT JATTA_NO_FONTS)
    ADD_GROUP("Fonts")
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(Font.cpp)
    ADD_HEADER(Font.h include/Jatta/Fonts)
endif()