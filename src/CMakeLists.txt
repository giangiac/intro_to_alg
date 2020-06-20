################################################################################
# Construction of intro_to_alg as a shared library
################################################################################

set(i2a_FILES 
  heap.cpp
  CACHE INTERNAL "" FORCE)

add_library(i2a SHARED ${i2a_FILES})

target_include_directories(i2a PUBLIC ../include)

target_include_directories(i2a INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>)

set_target_properties(i2a
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
    POSITION_INDEPENDENT_CODE 1
)

################################################################################
