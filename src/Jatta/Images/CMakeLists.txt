# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

ADD_GROUP("Images")
ADD_OTHER(CMakeLists.txt)
ADD_SOURCE(Color.cpp)
ADD_HEADER(Color.h include/Jatta/Images/)
ADD_HEADER(Colors.h include/Jatta/Images/)
ADD_SOURCE(Image.cpp)
ADD_HEADER(Image.h include/Jatta/Images/)
IF(NOT JATTA_NO_JPEG)
    ADD_SOURCE(Jpg.cpp)
ENDIF()
IF(NOT JATTA_NO_PNG)
    ADD_SOURCE(Png.cpp)
ENDIF()
ADD_SOURCE(Bmp.cpp)