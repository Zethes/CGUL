# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if(NOT JATTA_NO_AUDIO)
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(HostApiInfo.cpp)
    ADD_HEADER(HostApiInfo.h include/Jatta/Audio/)
    ADD_SOURCE(Device.cpp)
    ADD_HEADER(Device.h include/Jatta/Audio/)
    ADD_SOURCE(PortAudio.cpp)
    ADD_HEADER(PortAudio.h include/Jatta/Audio/)
    ADD_SOURCE(Stream.cpp)
    ADD_HEADER(Stream.h include/Jatta/Audio/)
    ADD_SOURCE(Sine.cpp)
   # ADD_SOURCE(Ogg.cpp)
ENDIF()