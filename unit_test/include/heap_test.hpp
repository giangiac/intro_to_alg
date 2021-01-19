#ifndef	I2A_HEAP_TEST_HPP
#define	I2A_HEAP_TEST_HPP

#include "../../include/heap.hpp"

#include <vector>

//////////////////////////////////////////////////////////////////////////////
// Test fixture class: HeapTest
//////////////////////////////////////////////////////////////////////////////

using namespace i2a;

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
  // Based on vector B, there are many possible max-heaps.
  // According to the current implementation, one expects:
  //           16
  //      14         4
  //  10     8     2   1 
  // 3  9  7
  std::vector<int> expected = {16, 14, 4, 10, 8, 2, 1, 3, 9, 7};
  for (unsigned i=0; i<B.size(); ++i)
      ASSERT_EQ(expected[i], heap.A()[i]);
  heap.Print(); 
}

//////////////////////////////////////////////////////////////////////////////

TEST_F(HeapTest, Heapify)
{
  Heap<int> heap("max");
  std::vector<int> B = {4, 7, 1, 9, 8, 2, 16, 3, 10, 14};
  heap.BuildHeap(B);
  // The expected order inside the max-heap is: {16, 14, 4, 10, 8, 2, 1, 3, 9, 7}
  // Introduce an error in position 1: 14-->5
  ASSERT_EQ(heap.A()[1], 14);
  heap.A()[1]=5;
  heap.Heapify(1);
  std::vector<int> expected = {16, 10, 4, 9, 8, 2, 1, 3, 5, 7};
  for (unsigned i=0; i<B.size(); ++i)
      ASSERT_EQ(expected[i], heap.A()[i]);
}

//////////////////////////////////////////////////////////////////////////////

#endif	// header guard I2A_HEAP_TEST_HPP
