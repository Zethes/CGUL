# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

if (NOT JATTA_NO_NETWORK)
    ADD_GROUP("Network")
    ADD_OTHER(CMakeLists.txt)
    ADD_SOURCE(DNS.cpp)
    ADD_HEADER(DNS.h include/Jatta/Network/)
    ADD_SOURCE(Network.cpp)
    ADD_SOURCE(SocketTCP.cpp)
    ADD_HEADER(SocketTCP.h include/Jatta/Network/)
ENDIF()