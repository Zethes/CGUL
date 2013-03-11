# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(JATTA_USE_AUDIO)
    ADD_GROUP("PortAudio")
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(Device.cpp)
    ADD_HEADER(Device.h include/Jatta/PortAudio/)
    ADD_SOURCE(HostApi.cpp)
    ADD_HEADER(HostApi.h include/Jatta/PortAudio/)
    ADD_SOURCE(PortAudio.cpp)
    ADD_HEADER(PortAudio.h include/Jatta/PortAudio/)
ENDIF()
