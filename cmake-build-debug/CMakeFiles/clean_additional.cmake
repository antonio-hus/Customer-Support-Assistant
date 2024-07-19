# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Customer_Support_Assistant_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Customer_Support_Assistant_autogen.dir\\ParseCache.txt"
  "Customer_Support_Assistant_autogen"
  )
endif()
