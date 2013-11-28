# Find the program
find_program(cloc_EXECUTABLE cloc DOC "A tool for counting lines of code.")

# Cloc directories/files
set(__CLOC__LOCATIONS
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/src/CGUL
  ${CMAKE_CURRENT_SOURCE_DIR}/src/CGUL.h
)

# Add custom targets
add_custom_target("cloc" COMMAND
  "${cloc_EXECUTABLE}"
  ${__CLOC__LOCATIONS}
)
add_custom_target("clocfiles" COMMAND
  "${cloc_EXECUTABLE}"
  ${__CLOC__LOCATIONS}
  --by-file
)
