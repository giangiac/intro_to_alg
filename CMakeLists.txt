cmake_minimum_required(VERSION 3.10)

################################################################################
# Define our package information.
################################################################################

set(PACKAGE_AUTHOR "Gian Giacomo Guerreschi")
project(intro_to_alg CXX)

# Out-of-source builds only
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

# Set the location of helper CMake modules in the source tree.
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Set some compiler options related to C++.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

################################################################################
# Options for the build.
################################################################################

option(i2aMPI "Enable MPI?" OFF)
option(i2aUtest "Enable unit test?" ON)

################################################################################

# Enable MPI, yes or not?
if(IqsMPI)
    message(FATAL_ERROR "No MPI in this repo.")
endif()

# This option allows AVX 256 and 512 instructions to be used.
if(CMAKE_CXX_COMPILER_ID MATCHES Intel)
    add_compile_options(-xhost)
elseif(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    add_compile_options(-march=native)
endif()

############################################################################
# List the object files that will be contained in the statically linked
# library archive. Also, place the archive in the lib subdir. 
################################################################################

add_subdirectory(src)

# INFO: when below flag is defined, checks of the form "assert(condition)" are skipped.
#target_compile_definitions(i2a NDEBUG)

################################################################################
# Build the suite of unit-tests for intro_to_alg.
# Approach suggested in:
# https://github.com/google/googletest/blob/master/googletest/README.md
################################################################################

# Add the unit test contained in /unit_test
# If required, googletest framework is downloaded and configured.
if (i2aUtest)
    message(STATUS "Unit test : enabled.")
    add_subdirectory(unit_test)
else()
    message(STATUS "Unit test : disabled.")
endif()

################################################################################
