/// @file heapsort.hpp Declaration of heapsort algorithm.

#ifndef I2A_HEAPSORT_HPP
#define I2A_HEAPSORT_HPP

#include <string>
#include <vector>

#include "heap.hpp"

namespace i2a {

/// Function implementing heapsort.
/// 
/// Input: vector<int> A (by reference)
/// Output: sort A (by default, increasing order)

void Heapsort (std::vector<int> & B, std::string style = "max")
{
  Heap<int> heap(B, style);
  for (unsigned i=B.size()-1; i>=1; --i)
  {
      B[i] = heap.A()[0];
      heap.A()[0] = heap.A()[i];
      heap.A().pop_back();
      heap.Heapify(0);
  }
  B[0] = heap.A()[0];
}

} // close namespace i2a

#endif	// head guards I2A_HEAPSORT_HPP
