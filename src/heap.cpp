/// @file heap.hpp

#include "heap.hpp"

#include <algorithm>    // std::swap

////////////////////////////////////////////////////////////////////

template <class Type>
Heap<Type>::Heap(std::string style)
{
  if (style == "max")
      is_max_heap_ = true;
  else if (style == "min")
      is_max_heap_ = false;
  else
      throw "Wrong option provided";
}

////////////////////////////////////////////////////////////////////

template <class Type>
Heap<Type>::Heap(std::vector<Type> A, std::string style)
{
  if (style == "max")
      is_max_heap_ = true;
  else if (style == "min")
      is_max_heap_ = false;
  else
      throw "Wrong option provided";

  A_ = A;
  this->BuildHeap();
}

////////////////////////////////////////////////////////////////////

template <class Type>
void Heap<Type>::Heapify(std::size_t i)
{
  std::size_t l=Left(i), r=Right(i);
  std::size_t root;
  if (l < heap_size_  &&  is_max_heap_ ? A_[l] > A_[i] : A_[l] < A_[i])
      root = l;
  else
      root = i;
  if (r < heap_size_  &&  is_max_heap_ ? A_[r] > A_[root] : A_[r] < A_[root])
      root = r;

  if (root != i)
  {
      std::swap(A_[root], A_[i]);
      this->Heapify(root);
  }
}

////////////////////////////////////////////////////////////////////

template <class Type>
void Heap<Type>::BuildHeap()
{
  heap_size_ = A_.size();
  for (std::size_t i=A_.size()/2; i>0; --i)
      this->Heapify(i);
  this->Heapify(0);
}

////////////////////////////////////////////////////////////////////

template class Heap<int>;
template class Heap<double>;
