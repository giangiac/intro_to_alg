/// @file heap.hpp Declaration of max- and min-heap class.

#ifndef I2A_HEAP_HPP
#define I2A_HEAP_HPP

#include <string>
#include <vector>

namespace i2a {

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

    bool is_max_heap_ = true;	// the alternative being a min_heap
    std::vector<Type> A_;

  public:

    // Creators and annihilators.
    Heap(std::string style = "max");
    Heap(std::vector<Type> A, std::string style = "max");
    ~Heap() {}

    // Return basic info or members.
    bool IsMaxHeap() const {return is_max_heap_;}
    bool IsMinHeap() const {return ~is_max_heap_;}
    std::vector<Type> & A() {return A_;}
    std::size_t HeapSize() const {return A_.size();}

    // Print the heap.
    void Print() const;

    // Enforce the heap property on the subtree roted at index i.
    // It assumes that Left(i) and Right(i) are roots of heaps.
    // Implemented with recursion: one can avoid it using for loop.
    // Run in O(log heap_size)
    void Heapify(std::size_t i);

    // Order the elements of A_ to form a heap.
    // Run in O(heap_size)
    void BuildHeap();
    void BuildHeap(std::vector<Type> A_new) {A_=A_new; this->BuildHeap();}

  private:

    // In C++, indices starts from 0. Therefore:
    //   Parent(i) = floor((i-1)/2)
    //     Left(i) = i*2 + 1
    //    Right(i) = (i+1)*2
    std::size_t Parent(std::size_t i) { return (i-1) >> 1; }
    std::size_t Left  (std::size_t i) { return (i << 1) | 1UL ; }
    std::size_t Right (std::size_t i) { return (i+1) << 1 ; }

};

} // close namespace i2a

#endif	// head guards I2A_HEAP_HPP
