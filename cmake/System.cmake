if(MINGW)
    set(System_TYPE          ${CMAKE_SYSTEM_NAME})
    set(System_TYPE_SIMPLE   ${CMAKE_SYSTEM_NAME})
    set(System_DISTRO        "MinGW")
    set(System_DISTRO_SIMPLE "MinGW")
else()
    set(System_TYPE          ${CMAKE_SYSTEM_NAME})
    set(System_TYPE_SIMPLE   ${CMAKE_SYSTEM_NAME})
    set(System_DISTRO        ${CMAKE_SYSTEM_NAME})
    set(System_DISTRO_SIMPLE ${CMAKE_SYSTEM_NAME})
endif()
string(TOLOWER ${System_TYPE_SIMPLE} System_TYPE_LOWER)
string(TOLOWER ${System_DISTRO_SIMPLE} System_DISTRO_LOWER)

math(EXPR System_BITNESS "${CMAKE_SIZEOF_VOID_P} * 8")

# Determine number of cores
  set(System_PROCESSOR_COUNT 0)

# Determine core count on Linux
set(cpuinfo_file "/proc/cpuinfo")
if(EXISTS "${cpuinfo_file}")
    file(STRINGS "${cpuinfo_file}" procs REGEX "^processor.: [0-9]+$")
    list(LENGTH procs System_PROCESSOR_COUNT)
endif()

# Determine core count on MacOS
if(APPLE)
    find_program(cmd_sys_pro "system_profiler")
    if(cmd_sys_pro)
        execute_process(COMMAND ${cmd_sys_pro} OUTPUT_VARIABLE info)
        string(REGEX REPLACE "^.*Total Number Of Cores: ([0-9]+).*$" "\\1"
            System_PROCESSOR_COUNT "${info}")
    endif()
endif()

# Determine core count on Windows
if(WIN32)
    set(System_PROCESSOR_COUNT "$ENV{NUMBER_OF_PROCESSORS}")
endif()
