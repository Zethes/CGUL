# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

ADD_EXECUTABLE(Test_Utility_CRC32 test_CRC32.cpp)
TARGET_LINK_LIBRARIES(Test_Utility_CRC32 Jatta)

ADD_EXECUTABLE(Test_Utility_MD5 test_MD5.cpp)
TARGET_LINK_LIBRARIES(Test_Utility_MD5 Jatta)

ADD_EXECUTABLE(Test_Utility_String test_String.cpp)
TARGET_LINK_LIBRARIES(Test_Utility_String Jatta)

ADD_EXECUTABLE(Test_Utility_Timer test_Timer.cpp)
TARGET_LINK_LIBRARIES(Test_Utility_Timer Jatta)