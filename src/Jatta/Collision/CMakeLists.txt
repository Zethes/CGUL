# Jatta - General Utility Library
# Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
# All rights reserved.

ADD_GROUP("Collision")
ADD_SOURCE(AABB2D.cpp)
ADD_HEADER(AABB2D.h include/Jatta/Collision)
ADD_SOURCE(AABB3D.cpp)
ADD_HEADER(AABB3D.h include/Jatta/Collision)
ADD_SOURCE(Circle.cpp)
ADD_HEADER(Circle.h include/Jatta/Collision)
ADD_OTHER(CMakeLists.txt)
ADD_SOURCE(Collision.cpp)
ADD_HEADER(Collision.h include/Jatta/Collision)
ADD_SOURCE(Sphere.cpp)
ADD_HEADER(Sphere.h include/Jatta/Collision)