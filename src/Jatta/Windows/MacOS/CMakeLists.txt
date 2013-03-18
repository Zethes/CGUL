# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

ADD_GROUP("MacOS")
ADD_HEADER_NO_INSTALL(Application.h)
ADD_SOURCE(Application.mm)
ADD_HEADER_NO_INSTALL(ApplicationDelegate.h)
ADD_SOURCE(ApplicationDelegate.mm)
ADD_OTHER(CMakeLists.txt)
ADD_HEADER_NO_INSTALL(WindowDelegate.h)
ADD_SOURCE(WindowDelegate.mm)