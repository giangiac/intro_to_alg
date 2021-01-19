/// @file suit_of_tests.cpp Define unit tests for the repo

#include <cmath>	// std::abs(), std::cos(), std::pow(), ...
#include <iostream>

// googletest
#include "gtest/gtest.h"

// To compare complex values in an approximated way.
#define ASSERT_COMPLEX_NEAR(val1,val2,error)   \
ASSERT_NEAR(val1.real(),val2.real(),error);    \
ASSERT_NEAR(val1.imag(),val2.imag(),error);

// Headers with the implementation of the various tests.
#include "include/compiler_flags_test.hpp"
#include "include/heap_test.hpp"
#include "include/heapsort_test.hpp"

//////////////////////////////////////////////////////////////////////////////
// main
// We want to unit_test an MPI program.

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//////////////////////////////////////////////////////////////////////////////
