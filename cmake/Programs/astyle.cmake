# Find the program
find_program(astyle_EXECUTABLE astyle DOC "A tool to stylize the code.")

# Add a custom target
add_custom_target("style" COMMAND
  "${astyle_EXECUTABLE}"
  --options=${CMAKE_CURRENT_SOURCE_DIR}/resources/astyle
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Jatta/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Jatta/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Jatta/*.mm
  VERBATIM
)
