# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

ADD_GROUP("Utility")
ADD_OTHER(CMakeLists.txt)
#ADD_SOURCE(Object.cpp)
ADD_HEADER(Object.h include/Jatta/Utility/)
ADD_SOURCE(Regex.cpp)
ADD_HEADER(Regex.h include/Jatta/Utility/)
ADD_SOURCE(String.cpp)
ADD_HEADER(String.h include/Jatta/Utility/)
ADD_SOURCE(Timer.cpp)
ADD_HEADER(Timer.h include/Jatta/Utility/)