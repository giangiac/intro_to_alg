#ifndef	HEAP_TEST_HPP
#define	HEAP_TEST_HPP

#include "../../include/heap.hpp"

//////////////////////////////////////////////////////////////////////////////
// Test fixture class: heap
//////////////////////////////////////////////////////////////////////////////

class HeapTest : public ::testing::Test
{
 protected:

  HeapTest()
  { }

  // just after the 'constructor'
  void SetUp() override {}

  // just before the 'destructor'
  void TearDown() override {}
};

//////////////////////////////////////////////////////////////////////////////
// Test macros:

TEST_F(HeapTest, Creator)
{
  Heap<int> heap("max");
  ASSERT_TRUE(heap.IsMaxHeap());
}

//////////////////////////////////////////////////////////////////////////////

#endif	// header guard HEAP_TEST_HPP
