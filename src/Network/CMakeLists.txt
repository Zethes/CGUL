# Jatta - General Utility Library
# Copyright (c) 2012-2013, Joshua Brookover
# All rights reserved.

ADD_GROUP("Network")
ADD_SOURCE(DNS.cpp)
ADD_HEADER(DNS.h include/Jatta/Network/)
ADD_SOURCE(Network.cpp)
ADD_SOURCE(TCP.cpp)
ADD_HEADER(TCP.h include/Jatta/Network/)