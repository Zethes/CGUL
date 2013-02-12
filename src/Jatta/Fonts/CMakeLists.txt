# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(JATTA_USE_FREETYPE)
    ADD_GROUP("Fonts")
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(Font.cpp)
    ADD_HEADER(Font.h include/Jatta/Fonts)
endif()