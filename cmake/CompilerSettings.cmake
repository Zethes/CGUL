# Make all of the files Obj-C++ on Mac
if(APPLE AND NOT ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set(CMAKE_CXX_FLAGS "-ObjC++ ${CMAKE_CXX_FLAGS}")
endif()

# Fix for Xcode to enforce Obj-C++ on all files
if(APPLE AND ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set_target_properties(Jatta PROPERTIES XCODE_ATTRIBUTE_GCC_INPUT_FILETYPE sourcecode.cpp.objcpp)
endif()

# Turn on all warnings and warning to errors in GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    if(Jatta_STRICT)
        set(CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")
    endif()
endif()
