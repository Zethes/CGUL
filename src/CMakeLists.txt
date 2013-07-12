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

# Turn on all warnings and warning to errors in GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    #set(CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")
    # there is a very good reason that this is commented out
    # and it is only 50% because of laziness
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
set_property(TARGET Jatta PROPERTY OUTPUT_NAME "${Jatta_OUTPUT_NAME}")

string(STRIP "${Jatta_LIBRARIES}" Jatta_LIBRARIES)
string(REPLACE " " ";" LIBRARY_LIST "${Jatta_LIBRARIES}")
target_link_libraries(Jatta ${LIBRARY_LIST})

# Get information about the library
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    get_property(Jatta_MODULE_NAME TARGET Jatta PROPERTY LOCATION)
else()
    get_property(Jatta_MODULE_NAME TARGET Jatta PROPERTY LOCATION_${CMAKE_BUILD_TYPE})
endif()
get_filename_component(Jatta_MODULE_NAME ${Jatta_MODULE_NAME} NAME)

# Fix for Xcode to enforce Obj-C++ on all files
if(APPLE AND ${CMAKE_GENERATOR} STREQUAL "Xcode")
    set_target_properties(Jatta PROPERTIES XCODE_ATTRIBUTE_GCC_INPUT_FILETYPE sourcecode.cpp.objcpp)
endif()

# Create the configuration files for importing Jatta
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../resources/JattaConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmake/${Jatta_OUTPUT_NAME}Config.cmake" @ONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../resources/JattaConfigVersion.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/../cmake/${Jatta_OUTPUT_NAME}ConfigVersion.cmake" @ONLY)

# Installation setup
string(LENGTH "${CMAKE_CURRENT_SOURCE_DIR}" DIR_LENGTH)
math(EXPR DIR_LENGTH "${DIR_LENGTH} + 1")
foreach(FILE ${Jatta_INSTALL})
    string(SUBSTRING "${FILE}" ${DIR_LENGTH} -1 INSTALL_FILE)
    get_filename_component(INSTALL_DIR ${INSTALL_FILE} PATH)
    install(FILES ${FILE} DESTINATION include/${INSTALL_DIR}/)
endforeach()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h DESTINATION include/Jatta/)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmake/${Jatta_OUTPUT_NAME}Config.cmake DESTINATION cmake/)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/../cmake/${Jatta_OUTPUT_NAME}ConfigVersion.cmake DESTINATION cmake/)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../license.txt DESTINATION .)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/acknowledgements.txt DESTINATION .)
install(TARGETS Jatta DESTINATION lib/)
if(DOXYGEN_ENABLE)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../html DESTINATION doc)
endif()
