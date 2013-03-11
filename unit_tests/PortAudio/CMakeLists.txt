# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

ADD_EXECUTABLE(Test_PA_Devices test_Devices.cpp)
TARGET_LINK_LIBRARIES(Test_PA_Devices Jatta)

ADD_EXECUTABLE(Test_PA_Version test_Version.cpp)
TARGET_LINK_LIBRARIES(Test_PA_Version Jatta)