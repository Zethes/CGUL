# Generate configuration file
include(Config/Config.cmake)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config/Config.h.in ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h)

# Include the source tree
add_subdirectory(Jatta)
set(Jatta_INSTALL ${Jatta_INSTALL} ${CMAKE_CURRENT_SOURCE_DIR}/Jatta.h)

# Determine dependencies
include(dependencies.cmake)

# Determine library type
set(Jatta_LIBRARY_TYPE SHARED)
if(Jatta_STATIC)

    set(Jatta_LIBRARY_TYPE STATIC)

endif()

set(DEFINE_DEBUG ${MSVC})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_REQUIRED_INCLUDES})
if(APPLE)

    include_directories(/Developer/Headers/FlatCarbon)

endif()
add_definitions(-DJATTA_BUILD -DJATTA_INCLUDES ${CMAKE_REQUIRED_FLAGS})
add_library(Jatta ${Jatta_LIBRARY_TYPE} ${Jatta_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/Jatta/Config.h)

set_property(TARGET Jatta PROPERTY OUTPUT_NAME "${Jatta_OUTPUT_NAME}")
set_property(TARGET Jatta PROPERTY ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${Jatta_LIB_DIR}")
set_property(TARGET Jatta PROPERTY LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${Jatta_LIB_DIR}")
foreach(__CONFIGURATION ${CMAKE_CONFIGURATION_TYPES})

    string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION)
    set_property(TARGET Jatta PROPERTY OUTPUT_NAME_${__CONFIGURATION} "${Jatta_OUTPUT_NAME}${Jatta_POSTFIX_${__CONFIGURATION}}")
    set_property(TARGET Jatta PROPERTY ARCHIVE_OUTPUT_DIRECTORY_${__CONFIGURATION} "${CMAKE_BINARY_DIR}/${Jatta_LIB_DIR}")
    set_property(TARGET Jatta PROPERTY LIBRARY_OUTPUT_DIRECTORY_${__CONFIGURATION} "${CMAKE_BINARY_DIR}/${Jatta_LIB_DIR}")

endforeach()


string(STRIP "${Jatta_LIBRARIES}" Jatta_LIBRARIES)
string(REPLACE " " ";" LIBRARY_LIST "${Jatta_LIBRARIES}")
target_link_libraries(Jatta ${LIBRARY_LIST})

# Get information about the library
if(${DEFINE_DEBUG})

    get_property(Jatta_MODULE_NAME_PATH TARGET Jatta PROPERTY LOCATION)
    get_property(Jatta_MODULE_NAME_PATH_DEBUG TARGET Jatta PROPERTY LOCATION_DEBUG)
    get_filename_component(Jatta_MODULE_NAME_DEBUG ${Jatta_MODULE_NAME_PATH_DEBUG} NAME)

else()

    if("${CMAKE_BUILD_TYPE}" STREQUAL "")

        get_property(Jatta_MODULE_NAME_PATH TARGET Jatta PROPERTY LOCATION)

    else()

        get_property(Jatta_MODULE_NAME_PATH TARGET Jatta PROPERTY LOCATION_${CMAKE_BUILD_TYPE})

    endif()

endif()

get_filename_component(Jatta_MODULE_NAME ${Jatta_MODULE_NAME_PATH} NAME)

# Version info
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/Jatta/Utility/Version.cpp PROPERTIES COMPILE_DEFINITIONS "_JATTA_MAJOR=${Jatta_VERSION_MAJOR};_JATTA_MINOR=${Jatta_VERSION_MINOR};_JATTA_PATCH=${Jatta_VERSION_PATCH};_COMPILER_NAME=\"${Compiler_NAME_SIMPLE}${Compiler_VERSION}\"")

# Installation setup
include(../cmake/Install.cmake)
