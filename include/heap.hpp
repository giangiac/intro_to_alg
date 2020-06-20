/// @file heap.hpp Declaration of max- and min-heap class.

#ifndef I2A_HEAP_HPP
#define I2A_HEAP_HPP

#include <string>
#include <vector>

/// @class Heap Binary heap, either max or min.
/// 
/// Example of indices for the tree:
///                       0   
///                   /       \
///                1             2
///             /     \       /     \
///            3       4     5       6
///           / \     / \   / 
///          7   8   9  10  11

template <class Type = int>
class Heap
{
  private:

    std::vector<Type> A_;
    bool is_max_heap_ = true;	// the alternative being a min_heap
    std::size_t heap_size_ = 0;

  public:

    Heap(std::string style = "max");
    Heap(std::vector<Type> A, std::string style = "max");
    ~Heap() {}

    // Enforce the heap property on index i assuming that Left(i) and Right(i) are roots of heaps.
    // Implemented with recursion: one can avoid it using for loop.
    void Heapify(std::size_t i);

    // Order the elements of A_ to form a heap.
    void BuildHeap();

  private:

    // In C++, indices starts from 0. Therefore:
    //   Parent(i) = floor((i-1)/2)
    //     Left(i) = i*2 + 1
    //    Right(i) = (i+1)*2
    std::size_t Parent(std::size_t i) { return (i-1) >> 1; }
    std::size_t Left  (std::size_t i) { return (i << 1) | 1UL ; }
    std::size_t Right (std::size_t i) { return (i+1) << 1 ; }

};

#endif	// head guards I2A_HEAP_HPP
