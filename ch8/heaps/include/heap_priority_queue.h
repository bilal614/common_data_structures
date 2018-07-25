#ifndef HEAP_QUEUE

#include "binary_tree.h"

#define HEAP_QUEUE


template <typename T, typename C>
class HeapPriorityQueue
{
	public:
		int size() const;	//number of elements
		bool empty() const;	//is the queue empty?
		void insert(const T& t);	//insert element
		const T& min();	//minimum element
		void removeMin();	//remove minimum
	private:
		CompleteTree<T> T;	//priority queue contents
		C isLess;	//less-than comparator
}

template <typename T, typename C>
int HeapPriorityQueue< T, C>::size() const
{
	return T.size();
}


#endif
