# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "5_checkbox_autogen"
  "CMakeFiles\\5_checkbox_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\5_checkbox_autogen.dir\\ParseCache.txt"
  )
endif()
