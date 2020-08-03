#ifndef	HEAP_TEST_HPP
#define	HEAP_TEST_HPP

#include "../../include/heap.hpp"

#include <vector>

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

TEST_F(HeapTest, Create)
{
  Heap<int> heap("max");
  ASSERT_TRUE(heap.IsMaxHeap());
}

//////////////////////////////////////////////////////////////////////////////

TEST_F(HeapTest, Build)
{
  Heap<int> heap("max");
  std::vector<int> B = {4, 7, 1, 9, 8, 2, 16, 3, 10, 14};
  heap.BuildHeap(B);

  heap.Print(); 
 
  ASSERT_TRUE(heap.IsMaxHeap());
}

//////////////////////////////////////////////////////////////////////////////

#endif	// header guard HEAP_TEST_HPP
