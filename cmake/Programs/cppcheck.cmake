# Workaround for cmake parser bug
set(__PROGRAMFILESX86 "ProgramFiles(x86)")

# Find the program
find_program(cppcheck_EXECUTABLE cppcheck DOC "A tool for C++ code analysis."
  PATHS
  $ENV{${__PROGRAMFILESX86}}/Cppcheck
  $ENV{PROGRAMFILES}/Cppcheck
)

# Create list of defines
string(REPLACE " " ";" __DEFINE_LIST ${CMAKE_REQUIRED_DEFINITIONS})
foreach(__DEFINE ${__DEFINE_LIST})

    list(APPEND __CPPCHECK_DEFINES ${__DEFINE})

endforeach()

# Set number of jobs flag (-j) if number of cores is known
if(System_PROCESSOR_COUNT)

    set(__JOBS_FLAG -j ${System_PROCESSOR_COUNT})

endif()

# Add a custom target
add_custom_target("check" COMMAND
  "${cppcheck_EXECUTABLE}"
  --enable=warning
  --enable=style
  --enable=performance
  --enable=portability
#  --enable=information
  -q
  ${__CPPCHECK_DEFINES}
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Jatta"
  ${__JOBS_FLAG}
)
