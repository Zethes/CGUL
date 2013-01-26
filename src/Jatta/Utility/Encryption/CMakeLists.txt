# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

ADD_GROUP("Encryption")
ADD_OTHER(CMakeLists.txt)
ADD_HEADER(Encryption.h include/Jatta/Utility/Encryption/)
ADD_SOURCE(MD5.cpp)
ADD_SOURCE(CRC32.cpp)