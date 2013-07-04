# Generate configuration file
include(Config/Config.cmake)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config/Config.h.in ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h)

# Include the source tree
add_subdirectory(Jatta)
set(Jatta_INSTALL ${Jatta_INSTALL} ${CMAKE_CURRENT_SOURCE_DIR}/Jatta.h)

# Make all of the files Obj-C++ on Mac
if(APPLE AND NOT ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set(CMAKE_CXX_FLAGS "-ObjC++ ${CMAKE_CXX_FLAGS}")
endif()

# Determine dependencies
include(dependencies.cmake)

# Determine library type
set(Jatta_LIBRARY_TYPE SHARED)
if (Jatta_STATIC)
    set(Jatta_LIBRARY_TYPE STATIC)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${Jatta_DEPENDENCY_INCLUDE_DIRS})
if(APPLE)
    include_directories(/Developer/Headers/FlatCarbon)
endif()
add_definitions(-DJATTA_BUILD -DJATTA_INCLUDES ${CMAKE_REQUIRED_FLAGS})
add_library(Jatta ${Jatta_LIBRARY_TYPE} ${Jatta_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h)

string(STRIP "${Jatta_LIBRARIES}" Jatta_LIBRARIES)
string(REPLACE " " ";" LIBRARY_LIST "${Jatta_LIBRARIES}")
target_link_libraries(Jatta ${LIBRARY_LIST})

# Fix for Xcode to enforce Obj-C++ on all files
if(APPLE AND ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set_target_properties(Jatta PROPERTIES XCODE_ATTRIBUTE_GCC_INPUT_FILETYPE sourcecode.cpp.objcpp)
endif()

# Create the configuration files for importing Jatta
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../JattaConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmake/JattaConfig.cmake" @ONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../JattaConfigVersion.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmake/JattaConfigVersion.cmake" @ONLY)

# Installation setup
set(INSTALL_PREFIX "Jatta")
string(LENGTH "${CMAKE_CURRENT_SOURCE_DIR}" DIR_LENGTH)
math(EXPR DIR_LENGTH "${DIR_LENGTH} + 1")
foreach(FILE ${Jatta_INSTALL})
    string(SUBSTRING "${FILE}" ${DIR_LENGTH} -1 INSTALL_FILE)
    get_filename_component(INSTALL_DIR ${INSTALL_FILE} PATH)
    install(FILES ${FILE} DESTINATION include/${INSTALL_DIR}/)
endforeach()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h DESTINATION include/Jatta/)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmake/JattaConfig.cmake DESTINATION cmake/)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmake/JattaConfigVersion.cmake DESTINATION cmake/)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../license.md DESTINATION .)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/acknowledgements.txt DESTINATION .)
install(TARGETS Jatta DESTINATION lib/)
if(DOXYGEN_ENABLE AND EXISTS ${CMAKE_CURRENT_BINARY_DIR}/../html)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../html DESTINATION doc)
endif()
