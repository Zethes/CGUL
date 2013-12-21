# Generate configuration file
include(Config/Config.cmake)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config/Config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/CGUL/Config.hpp)

# Include the source tree
add_subdirectory(CGUL)
set(CGUL_INSTALL ${CGUL_INSTALL} ${CMAKE_CURRENT_SOURCE_DIR}/CGUL.hpp)

# Determine dependencies
include(dependencies.cmake)

# Determine library type
set(CGUL_LIBRARY_TYPE SHARED)
if(CGUL_STATIC)

    set(CGUL_LIBRARY_TYPE STATIC)

endif()

set(DEFINE_DEBUG ${MSVC})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_REQUIRED_INCLUDES})
if(APPLE)

    include_directories(/Developer/Headers/FlatCarbon)

endif()
add_definitions(-DCGUL_BUILD -DCGUL_INCLUDES ${CMAKE_REQUIRED_FLAGS})
add_library(CGUL ${CGUL_LIBRARY_TYPE} ${CGUL_SOURCES} ${CGUL_INSTALL} ${CGUL_PROJECT_FILES} ${CMAKE_CURRENT_BINARY_DIR}/CGUL/Config.hpp)

# Organize the files for IDE's
string(LENGTH "${CMAKE_CURRENT_SOURCE_DIR}/" __PATHLENGTH)
foreach(__FILE ${CGUL_SOURCES} ${CGUL_INSTALL} ${CGUL_PROJECT_FILES})

    get_filename_component(__FILEPATH "${__FILE}" PATH)
    set(__FILEPATH "${__FILEPATH}/")
    string(SUBSTRING ${__FILEPATH} ${__PATHLENGTH} -1 __GROUP)

    get_filename_component(__SOURCE_NAME "${__FILE}" NAME)
    string(REGEX MATCHALL "\\.hpp" __IS_HEADER "${__SOURCE_NAME}")
    string(REGEX MATCH "\\_Implement.hpp" __IS_IMPLEMENTATION "${__SOURCE_NAME}")
    string(REGEX MATCH "\\.((cpp)|(mm))" __IS_SOURCE "${__SOURCE_NAME}")
    string(REGEX MATCH "CMakeLists.txt" __IS_CMAKE "${__SOURCE_NAME}")
    if(__IS_IMPLEMENTATION)
        set(__GROUP "Implementation Files/${__GROUP}")
    elseif(__IS_HEADER)
        set(__GROUP "Header Files/${__GROUP}")
    elseif(__IS_SOURCE)
        set(__GROUP "Source Files/${__GROUP}")
    elseif(__IS_CMAKE)
        set(__GROUP "CMake Files/${__GROUP}")
    else()
        set(__GROUP "Resource Files/${__GROUP}")
    endif()

    string(REPLACE "CGUL/" "" __GROUP ${__GROUP})
    string(REPLACE "/" "\\\\" __GROUP ${__GROUP})

    source_group(${__GROUP} FILES ${__FILE})

endforeach()

set_property(TARGET CGUL PROPERTY OUTPUT_NAME "${CGUL_OUTPUT_NAME}")
set_property(TARGET CGUL PROPERTY ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CGUL_LIB_DIR}")
set_property(TARGET CGUL PROPERTY LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CGUL_LIB_DIR}")
set_property(TARGET CGUL PROPERTY RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CGUL_LIB_DIR}")
foreach(__CONFIGURATION ${CMAKE_CONFIGURATION_TYPES})

    string(TOUPPER "${__CONFIGURATION}" __CONFIGURATION)
    set_property(TARGET CGUL PROPERTY OUTPUT_NAME_${__CONFIGURATION} "${CGUL_OUTPUT_NAME}${CGUL_POSTFIX_${__CONFIGURATION}}")
    set_property(TARGET CGUL PROPERTY ARCHIVE_OUTPUT_DIRECTORY_${__CONFIGURATION} "${CMAKE_BINARY_DIR}/${CGUL_LIB_DIR}")
    set_property(TARGET CGUL PROPERTY LIBRARY_OUTPUT_DIRECTORY_${__CONFIGURATION} "${CMAKE_BINARY_DIR}/${CGUL_LIB_DIR}")

endforeach()

string(STRIP "${CGUL_LIBRARIES}" CGUL_LIBRARIES)
string(REPLACE " " ";" LIBRARY_LIST "${CGUL_LIBRARIES}")
target_link_libraries(CGUL ${LIBRARY_LIST} ${INSTALL_LIBRARIES_SYSTEM})

# Get information about the library
if(${DEFINE_DEBUG})

    get_property(CGUL_MODULE_NAME_PATH TARGET CGUL PROPERTY LOCATION)
    get_property(CGUL_MODULE_NAME_PATH_DEBUG TARGET CGUL PROPERTY LOCATION_DEBUG)
    get_filename_component(CGUL_MODULE_NAME_DEBUG ${CGUL_MODULE_NAME_PATH_DEBUG} NAME)

else()

    if("${CMAKE_BUILD_TYPE}" STREQUAL "")

        get_property(CGUL_MODULE_NAME_PATH TARGET CGUL PROPERTY LOCATION)

    else()

        get_property(CGUL_MODULE_NAME_PATH TARGET CGUL PROPERTY LOCATION_${CMAKE_BUILD_TYPE})

    endif()

endif()

get_filename_component(CGUL_MODULE_NAME ${CGUL_MODULE_NAME_PATH} NAME)

# Version info
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/CGUL/Utility/Version.cpp PROPERTIES COMPILE_DEFINITIONS "_CGUL_MAJOR=${CGUL_VERSION_MAJOR};_CGUL_MINOR=${CGUL_VERSION_MINOR};_CGUL_PATCH=${CGUL_VERSION_PATCH};_COMPILER_NAME=\"${Compiler_NAME_SIMPLE}${Compiler_VERSION}\"")

# Installation setup
include(../cmake/Install.cmake)
