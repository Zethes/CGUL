# Find the program
find_program(astyle_EXECUTABLE astyle DOC "A tool to stylize the code.")

# Enforce linux line endings if on a Unix machine
# Note: Doing this on windows is a bad idea! Some git configurations checkout as windows line
#       endings and check in as unix. Converting everything to unix with that configuration marks
#       every file as a change and is a huge pain...
if(UNIX AND NOT CYGWIN)
    set(__LINEENDINGS "--lineend=windows")
endif()

# Add a custom target
add_custom_target("style" COMMAND
  "${astyle_EXECUTABLE}"
  --options=${CMAKE_CURRENT_SOURCE_DIR}/resources/astyle
  ${CMAKE_CURRENT_SOURCE_DIR}/src/CGUL/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/CGUL/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/CGUL/*.mm
  ${__LINEENDINGS}
  VERBATIM
)
