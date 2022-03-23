# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QTPLIS_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QTPLIS_autogen.dir\\ParseCache.txt"
  "QTPLIS_autogen"
  )
endif()
