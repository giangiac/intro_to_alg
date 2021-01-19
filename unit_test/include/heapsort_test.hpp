#ifndef	I2A_HEAPSORT_TEST_HPP
#define	I2A_HEAPSORT_TEST_HPP

#include "../../include/heapsort.hpp"

#include <vector>

//////////////////////////////////////////////////////////////////////////////
// Test fixture class: HeapsortTest
//////////////////////////////////////////////////////////////////////////////

class HeapsortTest : public ::testing::Test
{
 protected:

  HeapsortTest()
  { }

  // just after the 'constructor'
  void SetUp() override {}

  // just before the 'destructor'
  void TearDown() override {}
};

//////////////////////////////////////////////////////////////////////////////
// Test macros:

TEST_F(HeapsortTest, Example)
{
  std::vector<int> B = {4, 7, 1, 9, 8, 2, 16, 3, 10, 14};
  i2a::Heapsort(B);
  std::vector<int> expected = {1, 2, 3, 4, 7, 8, 9, 10, 14, 16};
  for (unsigned i=0; i<B.size(); ++i)
      ASSERT_EQ(expected[i], B[i]);
}

//////////////////////////////////////////////////////////////////////////////

#endif	// header guard I2A_HEAPSORT_TEST_HPP
